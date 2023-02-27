#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <pthread.h>
#include <fcntl.h>
#include <semaphore.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <cstring>
#include <stdlib.h>
#define buff 999
using namespace std;

int main()
{

int fd[2];
int pipe(fd[2]);
int a=0;
cout<<"Enter '1' for parent to child \nEnter '2' for child to parent \n";
cin>>a;
pid_t p;
p=fork();
if(a==1)
{
	if(p>0)
	{
		cout<<getpid()<<endl;
		cout<<"Enter the file path : ";
		string str;
		cin>>str;
		char * snd= new char [buff];
		//close(fd[1]);
		//int n= read(str,snd,buff);
		ifstream in;
		in.open(str);
		int index =0;
		string str;
		while(in.eof())
		{
			cin.getline(in,str);
			for(int i=0;str[i]!='\0';i++,index++)
			{
				if(index<buff)
				snd[index]=str[i];
			}
		}
		close(fd[0]);
		n= write(fd[1],snd,buff);
	}else
	{
	//Child Process
		cout<<getpid()<<endl;
		cout<<"Recieving Data : "<<endl;
		char* rsv = new char [buff];
		close(fd[1]);
		int n= read (fd[0],rsv,buff);
		cout<<"Recieved Data : "<<endl;
		n= write(1,rsv,buff);
	}
}else if(a==2)
{
	if(p==0)
	{
		//Child Process
		cout<<getpid()<<endl;
		cout<<"Enter the file path : ";
		string str;
		cin>>str;
		char * snd= new char [buff];
		//close(fd[1]);
		//int n= read(str,snd,buff);
		ifstream in;
		in.open(str);
		int index =0;
		string str;
		while(in.eof())
		{
			cin.getline(in,str);
			for(int i=0;str[i]!='\0';i++,index++)
			{
				if(index<buff)
				snd[index]=str[i];
			}
		}
		close(fd[0]);
		n= write(fd[1],snd,buff);
	}else
	{
		cout<<getpid()<<endl;
		cout<<"Recieving Data : "<<endl;
		char* rsv = new char [buff];
		close(fd[1]);
		int n= read (fd[0],rsv,buff);
		cout<<"Recieved Data : "<<endl;
		n= write(1,rsv,buff);
	}

}else cout<<"\n Invalid Input"<<endl;
return 0;
}
