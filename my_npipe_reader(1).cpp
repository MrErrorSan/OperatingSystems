#include<iostream>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<unistd.h>
#include<fcntl.h>
#include<cstring>
#include <stdlib.h>
using namespace std;
int main()
{
	int res;
	res=mkfifo("mypipe",0777);
	cout<<"Creating Named Pipe: mypipe"<<endl;;
	int n; char Read[80];
	n=open("mypipe",O_RDONLY);
	bool check = false; char exitstr[5] = "exit";
	while(!check)
	{
		pid_t pid = fork();		
		if(pid>0)
		{
			wait(NULL);
			int s = read(n,Read,80);
			cout<<Read<<"\""<<endl;
			if(strcmp(Read,exitstr) == 0)
			{
				check=true;
				cout<<"Exiting"<<endl;
			}
		}else
		if(pid==0)
		{
			cout<<"Waiting for Input : ";
			int m = execlp("./my_npipe_writer.out","./",NULL) ;
			cout<<"... Got it : \""<<endl;
		}
	}
	return 0;
}
