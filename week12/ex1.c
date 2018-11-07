#include <fcntl.h>
#include <stdio.h>
int main(){
	int rand_data = open("/dev/urandom", O_RDONLY);
	unsigned char buffer[20];
	ssize_t random_value = read(rand_data, buffer, sizeof buffer);
	printf("%s\n", buffer);
	for (int i = 0; i < 20; i++){
		printf("%u ",buffer[i]);	
	}
	printf("\n");
	return 0;
}
