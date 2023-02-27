#include<iostream>
#include<pthread.h>
#include<fcntl.h>
#include<semaphore.h>
#include<sys/types.h>
using namespace std;

sem_t s1,s2,s3;


void* thread1(void*a)
{	while(1)
	//for(int i=0;i<10;i++)
	{
		
		//sem_wait();
		sem_wait(&s1);
		for(int i=0;i<3;i++)
		cout<<"a";
			sem_post(&s2);
		
		
	}
	return 0;
}
void* thread2(void*a)
{
	while(1)
	//for(int i=0;i<10;i++)
	{
		
		//sem_wait();
		sem_wait(&s3);
		cout<<"b";
		sem_post(&s1);
	}
	return 0;
}
void* thread3(void*a)
{
	while(1)
	//for(int i=0;i<10;i++)
	{
		
		//sem_wait();
		sem_wait(&s2);
		cout<<"c";
		sem_post(&s3);
		
	}
	return 0;
}
int main(int argc, char* argv[])
{
sem_init(&s1,0,1);
sem_init(&s2,0,0);
sem_init(&s3,0,0);
pthread_t t1, t2,t3;

int n=pthread_create(&t1,NULL,&thread1,NULL);
int n2=pthread_create(&t2,NULL,&thread2,NULL);
int n3=pthread_create(&t3,NULL,&thread3,NULL);
	pthread_exit(NULL);
return 0;
}
