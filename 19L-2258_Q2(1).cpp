#include<iostream>
#include<string>
#include<studio.h>
#include<unistd.h>
#include<sys/wait.h>
# define p 2
using namespace std;
int main(int argc,char*argv[])
{
int buf = 50;
	int fd[2];
	int fd1[2];
	int fd2[2];
	pipe(fd);
	pipe(fd1);
	pipe(fd2);
	close fd[0];
	int n= write(fd[1],argv[1],buf);
	close fd[1];
	pid_t p1;
	p1=fork();
	if(p1==0)
	{
		close fd[1];
		char* arr= new char[buf];
		int r= read(fd[0],arr,buf);
		close fd[0];
		char* arr2= new char[buf];\
		int index=0;
		for(int i=0;i<buf;i++)
		{
			if(arr[i]<33||arr[i]>47)
			{
				if(arr[i]<58||arr[i]>64)
				{
					if(arr[i]<91||arr[i]>96)
					{
						arr2[index]=arr[i];
						index++;
					}
				}
			}
		}
		close fd1[0];
		int a=write(fd1[1],arr2,buf);
		close fd1[1];
	pid_t p2;
	p2=fork();
	if(p2==0)
	{
		char* arr = new char[buf];
		close fd1[1];
		int r= read(fd1[0],arr,buf);
		close fd1[0];
		for(int j=1;j<buf;j++)
		{
			for(int i=1;i<buf;i++)
			{
			if(arr[i]<arr[i-1])
			{
				char swap;
				swap=arr[i-1];
				arr[i-1]=arr[i];
				arr[i]=swap;
			}
			}		
					
		}
		close fd2[0];
		int z= write(fd2[1],arr,buf)
		close fd2[1];
	}
	pid_t p3;
	p3=fork();
	if(p3==0)
	{
		char* arr = new char[buf];
		close fd2[1];
		int r= read(fd1[0],arr,buf);
		close fd2[0];
		for(int i=0;i<buf;i++)
		cout<<arr[i]<<" ";
	}
	pid_t p4;
	p4=fork();
	if(p4==0)
	{
		close fd2[0];
		int r= read(fd1[1],"Output.txt",buf);
		close fd2[1];
		
	}
return 0;
}
