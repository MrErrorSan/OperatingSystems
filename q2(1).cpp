#include <pthread.h>
#include <string>
#include <unistd.h>
#include<iostream>
#define M 30
using namespace std;
void* CreateThread (void* i)
{
    long x = (long)i;
    cout<<"Created new thread ("<<x++<<")";
    cout<<"Hello from thread"<<x++<<"- I was created in itration "<<x-1<<" ";
    sleep(4);
    pthread_exit(NULL);
}
int main(int argc, char **arg)
{
    int a = atoi(arg[1]);
    pthread_t p[M];
    //int count=0;
    long i;
    for (i = 1; i <= a; i++)
    {
        cout<<"I am Thread "<<i<<" ";
        int n= pthread_create(&p[i],NULL,&CreateThread,(void*)i);
    }
    pthread_exit(NULL);
    return 0;
}