/* Sample code to access our char device */

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
	int fd=0,ret=0;
	char buff[80]="";
	
	fd=open("/dev/time",O_RDONLY);
	
	printf("fd :%d\n",fd);
	
	int cycle = 0;
	do {
		ret=read(fd,buff,19);
		buff[ret]='\0';
		printf("buff: %s ;length: %d bytes\n",buff,ret);
		cycle++;
	}while (cycle < 100);
	
	
	close(fd);
}