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

int main(){
   int num;
   bool flag;
   cout<<"Enter any number(should be positive integer): ";
   cin>>num;
   flag = isPrime(num);
   if (flag==true)
      cout<<num<<" is a prime number";
   else
      cout<<num<<" is not a prime number";
   return 0;
}
bool isPrime(int num){
    bool flag=true;
    for(int i = 2; i <= num / 2; i++) {
       if(num % i == 0) {
          flag = false;
          break;
       }
    }
    return flag;
}
int main()
{
	int r[4];
	for(int i=0;i<5000;i++)
		for(int j=0;j<29;j++)
		{
		int n=read("mypipe",r,4)
			for(int k=0;k<4;k++)
				{
					if(isPrime(r[k]))
					cout<<r[k]<<",";
				}
		}
	cout<<"Done\n";
	return 0;
}
