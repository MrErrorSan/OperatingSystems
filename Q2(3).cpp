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
	for(int i=1;i<argc;i++)
	{
		sum=sum+atoi(argv[i]);
	}
	cout<<"SUM : "<<sum<<endl;
	int avg=sum/(argc-1);
	cout<<"AVERAGE : "<<avg<<endl;
	int max = atoi(argv[1]);
    for (int i = 1; i < argc; i++)
        if (atoi(argv[i]) > max)
            max = atoi(argv[i]);
   cout<<"Maximum Value is : "<<max<<endl;
   int min = atoi(argv[1]);
    for (int i = 1; i < argc; i++)
        if (atoi(argv[i]) < min)
            min = atoi(argv[i]);
 cout<<"Minimum Value is : "<<min<<endl;
return 0;
}
