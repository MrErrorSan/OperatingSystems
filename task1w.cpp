#include<iostream>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<string>
#include <cstring>
#include<sys/wait.h>
#include <stdlib.h>
using namespace std;
int main()
{
	int res=mkfifo("mypipe",0777);
	int r=open("mypipe",O_WRONLY);
	int wrt[4];
	char w[4];
	for(int i=0;i<5000;i++)
		for(int j=0;j<29;j++)
		{
			for(int k=0;k<4;k++)
				{
					int z=(rand() % 9);
					w[k]=z+'0';
				}
				int n=write(r,w,4);
		}
	cout<<"Done\n";
	return 0;
}
