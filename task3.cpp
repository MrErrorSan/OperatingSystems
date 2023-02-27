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
//Create 4 processes (with unique pid) and call them in such manner thatall the childs executesfirst then their parents and then their parents and so on.
pid_t pid1;
pid1 = fork();
if(pid1==0)
{
	cout<<"Child Process 1"<<endl;
	pid_t pid2;
	pid2 = fork();
	if(pid2==0)
	{
		cout<<"Child Process 2"<<endl;
		pid_t pid3;
		pid3 = fork();
		if(pid3==0)
		{
			cout<<"Child Process 3"<<endl;
			pid_t pid4;
			pid4 = fork();
			if(pid4==0)
			{
				cout<<"Child Process 4"<<endl;
			}else if(pid4 > 0){cout<<"Parent Process 4"<<endl;}
		}else if(pid3 > 0){cout<<"Parent Process 3"<<endl;}
	}else if(pid2 > 0){cout<<"Parent Process 2"<<endl;}
}else if(pid1 > 0){cout<<"Parent Process 1"<<endl;}
return 0;
}