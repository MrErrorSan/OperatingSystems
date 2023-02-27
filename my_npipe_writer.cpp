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
	int res; int w[4];
	res=mkfifo("mypipe",0777);
	res=open("mypipe",O_WRONLY);
	for(int i=0;i<5000;i++)
		for(int j=0;j<29;j++)
		{
			for(int k=0;k<4;k++)
				{
					int z=(rand() % 2500)
					w[k]=z;
				}
				int n=write("mypipe",w,4)
		}
	cout<<"Done\n";
	return 0;
}
