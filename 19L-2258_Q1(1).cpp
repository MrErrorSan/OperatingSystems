#include<iostream>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <pthread.h>
#include <fcntl.h>
#include <time.h>
#include <semaphore.h>
#include <sys/types.h>
#include <stdio.h>
using namespace std;
void* thread (void * a)
{
	long n= (long)a;
	int* arr=new int [30];
	int index=0;
	for(int i=1;i<=n;i++)
	{
		if(n%i==0)
		{
			arr[index]=i;
			//cout<<arr[index]<<" ";
		}
	}
	//cout<<endl;
	return arr;
}
int main(int argc,char* argv[])
{
	int N=argc-1;
	pthread_t p[N];
	const int buff=30;
	int arr[buff];
	long i=0;
	for(;i<N;i++)
	{
		long n=atoi(argv[i+1]);
		pthread_create(&p[i],NULL,&thread,(void*)n);	
		pthread_join(p[i],(void**)arr);
		cout<<"The Divisors of "<<n<<" are ";
		for(int j=0;j<buff;j++)
			cout<<arr[buff]<<" ";
		cout<<endl; 
	}
	return 0;	
}
