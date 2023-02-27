#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <fcntl.h>
#include <semaphore.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include < cstring>
#include <stdlib.h>
using namespace std;
sem_t s;
void* threads(void * i)
{
	sem_wait(&s);
	long x= (long)i;
	cout<<"This is new thread "<<x+1<<endl;
	return 0;
}
int main()
{
	int n=0;
	cout<<"Enter valid numbers of threads you want to create : ";
	cin>>n;
	sem_init(&s,0,1);
	pthread_t t;
	long i=0;
	for(;i<n;i++)		
	{
		int n=pthread_create(&t,NULL,&threads,(void*)i);
	}
	cout<<"  Threads initilizion finished\n";
	for(int a=0;a<n;a++)
	{
		sem_post(&s);
	}
	pthread_exit(NULL);
	return 0;
}












