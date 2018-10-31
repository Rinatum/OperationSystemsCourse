#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
int main(){
   int fd_from = open("ex1.txt", O_RDWR);
   int fd_to = open("ex1.memcpy.txt", O_RDWR);
   struct stat* fd_from_stat = malloc(sizeof(struct stat));
   stat("ex1.txt", fd_from_stat);
   off_t str_size = fd_from_stat->st_size;
   ftruncate(fd_to, str_size);
   void* maper_from = mmap("ex1.txt", str_size, PROT_WRITE | PROT_READ, MAP_SHARED, fd_from, 0);
   void* maper_to = mmap("ex1.memcpy.txt", str_size, PROT_WRITE | PROT_READ, MAP_SHARED, fd_to, 0);
   memcpy(maper_to, maper_from, str_size);
   munmap(maper_to, str_size);
   munmap(maper_from, str_size);
   close(fd_to);
   close(fd_from);
   return 0;
}
