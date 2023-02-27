#include  <iostream>
#include <stdlib.h>
#include  <fcntl.h>
#include  <semaphore.h>
#include   <sys/types.h>
#include <stdio.h>
#include  <sys/ipc.h>
#include  <sys/shm.h>
#include  <unistd.h>
#include <sys/shm.h>
#include <pthread.h>
#include<sys/stat.h>
#include <sys/wait.h>
#include  < unistd.h>
#include  <cstring>
#include  <stdlib.h>
using namespace std;
bool check_file(string str, string str1)
{
	int check=1;
	for(int i=0;i<str.length();i++)
	{
		for(int j=0;j<str1.length();j++)
		{
			if(str[i]!=str[j])
			{
				check=0;
				break;
			}
			check=1;
		}
		if(check==1)
		return true;
	}
	return false;
}

int main()
{
	key_t key = ftok("shrfile",1770);
	int shmid = shmget(key,1024,0666|IPC_CREAT);
	char *str = (char*) shmat(shmid,(void*)0,0);
	


	shmdt(str);
	shmctl(shmid,IPC_RMID,NULL);
return 0;
}
