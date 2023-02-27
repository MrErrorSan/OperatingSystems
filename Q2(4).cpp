#include <sys/types.h>
#include <stdio.h>
#include <cstring>
#include<string>
#include<string.h>
#include<fstream>
#include <unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<iostream>
using namespace std;

int main(int argc,char* argv[])
{
int sum=0;
	int no = atoi(argv[1]);
	for(int i=0;i<no;i++)
	{
		sum=sum+atoi(argv[2+i])
	}
	cout<<"SUM : "<<sum<<endl;
	int avg=sum/no;
	cout<<"AVERAGE : "<<avg<<endl;
	
return 0;
}
