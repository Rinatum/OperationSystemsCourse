#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
int main(){
   const char* str = "This is a nice day";
   int fd = open("ex1.txt", O_RDWR);
   int str_size = strlen(str);
   ftruncate(fd, str_size);
   void* maper = mmap("ex1.txt", str_size, PROT_WRITE | PROT_READ, MAP_SHARED, fd, 0);
   memcpy(maper, str, str_size);
   msync(maper, str_size, MS_SYNC);
   munmap(maper, str_size);
   close(fd);
   return 0;
}
