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
	int res; char writestr[80];
	cout<<"Opening Named Pipe: mypipe"<<endl;	
	res=open("mypipe",O_WRONLY);
	cout<<"Enter Input : ";
	cin.getline(writestr,40);
	cout<<"Writing Buffer to Pipe... ";
	int s = write(res,writestr,80);
	cout<<"Done\n";
	return 0;
}
