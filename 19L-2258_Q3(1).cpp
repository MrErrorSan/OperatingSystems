#include<iostream>
#include<string>
#include<unistd.h>
#include<sys/wait.h>
#include<pthread.h>
using namespace std;
void* fibnocci(void * n);
void* fibnocci(void * n)
{
 	int limit=(int)n;
	if(limit==1)
	{
		cout<<"0 ";
	}
	if(limit==2)
	{
		cout<<"0 1 ";
	}
	if(limit>2)
	{
		int a1=0;int a2=1;
		cout<<"0 1 ";
		for(int i=0;a2<=limit;i++)
		{	
			int a3=a1+a2;
			cout<<a3<<" "<<endl;
			a1=a2;
			a2=a3;
		}	
	}
	return 0;
}
int main(int argc, char*agrv[])
{
	pthread_t pid;
	int no=atoi(agrv[1]);
	int res= pthread_create(&pid,NULL,&fibnocci,&no);
	pthread_exit(NULL);
	return 0;
}

