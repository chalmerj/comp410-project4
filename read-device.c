/* Sample code to access our char device */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>


int main (int argc, const char * argv[])
{
	time_t start; 
	time_t finish;
	time_t now;
	double runTime;
	double totalTime;
	double cyclesPerSecond;

	int fd=0,ret=0;
	char buff[20]="";
  
	int cycle = 0;
	
  time(&start);

	do
	{
		time(&now);
		
		fd=open("/dev/time",O_RDONLY);
		ret=read(fd,buff,19);
		buff[ret]='\0';
		printf("buff: %s ;length: %d bytes\n",buff,ret);
		close(fd);
		
		runTime  = ((double) difftime(now,start));
		cycle++;
		
	} while (runTime < 5);

	time(&finish);
	
	totalTime = ((double)difftime(finish, start));
	
	cyclesPerSecond = 0;
	
	cyclesPerSecond = cycle/totalTime;
	
	printf("Total Time: %.0fs | Cycles: %d | Cycles/s:%.2f\n",totalTime,cycle,cyclesPerSecond);
	
	return 0;
}
