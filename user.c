#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFSIZE 100

int main() {
	int fd;
	ssize_t fc = 0;
	char *buf1 = "Hi I'm scull0\n";
	char buf2[BUFSIZE];
	
	if((fd = open("/dev/scull0", O_RDWR, 0777)) < 0) {
		perror("open error!");
		exit(1);
	}

	if((fc = write(fd, buf1, strlen(buf1))) < 0) {
		perror("write error!");
		exit(1);
	}

	close(fd);

	if((fd = open("/dev/scull0", O_RDWR, 0777)) < 0) {
		perror("open error!");
		exit(1);
	}
	
	if((fc = read(fd, buf2, fc)) < 0) {
		perror("read error!");
		exit(1);
	}

	printf("fc : %d\n", fc);	
	printf("buf : %s\n", buf2);

	return 0;
}
