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
bool isPrime(int num);

int main()
{
	int n=open("mypipe",O_RDONLY);
	char r[4];
	for(int i=0;i<5000;i++)
		for(int j=0;j<29;j++)
		{
		int res=read(n,r,4);
		
			for(int k=0;k<4;k++)
				{
					if(isPrime((r[k]-'0')))
					cout<<r[k]<<",";
				}
		}
	cout<<"Done\n";
	return 0;
}

bool isPrime(int num)
{
    bool flag=true;
    for(int i = 2; i <= num / 2; i++) 
    {
       if(num % i == 0 || num==1 || num==0) 
       {
          flag = false;
          break;
       }
    }
    return flag;
}
