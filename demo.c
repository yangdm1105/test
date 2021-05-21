#include<stdio.h>  
#include<sys/stat.h>
#include<sys/uio.h>  
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<sys/types.h>  
#include<stdlib.h>
#include<string.h>

int main()
{
	int fd;
	char buf[100]={0};
	pid_t cld_pid;
        par_fd=getpid();
	//par_fd=getpid();
	printf("yuanshi pid is %d\n",par_fd);
	if((fd=open("temp",O_CREAT|O_RDWR|O_TRUNC,0664))==-1)
	{
		perror("\nCreat file failure\n");
	}
	strcpy(buf,"Father process data");
	if((cld_pid=fork())==0)
	{
		strcpy(buf,"Parent process data");
		printf("Parent pid is %d\n",getpid());
		printf("Father pid is %d\n",getppid());
		write(fd,buf,strlen(buf));
		close(fd);
		exit(0);
	}
	else
	{
		printf("Father pid is %d\n",getpid());
		printf("pather pid is %d\n",cld_pid);
		write(fd,buf,strlen(buf));
		close(fd);
		exit(0);
	}
	
	return 0;
}
