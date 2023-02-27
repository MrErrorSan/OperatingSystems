#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include<pthread.h>
#include<fcntl.h>
#include<semaphore.h>
#include<sys/types.h>
#include <stdio.h>
using namespace std;
  void*
int main()
{
    // ftok to generate unique key
    key_t key = ftok("shmfile",65);
    // shmget returns an identifier in shmid
    int shmid = shmget(key,1024,0666|IPC_CREAT);
    // shmat to attach to shared memory
    char *str = (char*) shmat(shmid,(void*)0,0);
    cout<<"Write Data : ";
    int n= open ("Array.txt",O_WRONLY | O_RDONLY);
    pthread_t t1;
    pthread_t t2;
    pthread_t t3;
    read(n,str,50);
    int a1= pthread_create(t1,NULL,&thread1,NULL);
    int a2= pthread_create(t2,NULL,&thread2,NULL);
    int a3= pthread_create(t3,NULL,&thread3,NULL);
    
    
    //detach from shared memory 
    shmdt(str);
  
    return 0;
}
