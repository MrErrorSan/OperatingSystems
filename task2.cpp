#include<iostream>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<unistd.h>
#include<string>
#include<fcntl.h>
#include<cstring>
#include <stdlib.h>
using namespace std;
int main()
{
int listSize=3; int buff=60;
char arr[3][60] = { "This is Ahmad", "Red", "Orange" };
int fd[2];
int pipe(int fd[2]);//creating pipe
pid_t pid;
pid= fork();
if(pid==0)
{
	for(int i=0;i<listSize;i++)
	{
	//Encripter
		for(int i1=0;arr[i][i1]!='\0';i1++)
		{
			arr[i][i1]=arr[i][i1]+10;
		}
		
		close(fd[0]);
		int n= write(fd[1],arr[i],buff);
		close(fd[1]);
	}
}
else if (pid>0)
{
	wait(NULL);
	char earr[3][60];
	close(fd[1]);
	int n;
	for(int j=0;j<listSize;j++)
	n=read(fd[0],earr[j],buff);
}



return 0;
}
