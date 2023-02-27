#include<iostream>
#include<string>
#include<fstream>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include<sys/wait.h>
using namespace std;
int main()
{
	pid_t = pid1, pid2;
	pid1=fork();
	if(pid1==0)
	execlp("/bin/ls", "mkdir", "./my_Folder1", "./my_Folder2");
	if(pid1>0)
	execlp("/bin/ls", "mkdir", "./myFolder_1/mySubFolder");
	pid2=fork();
	if(pid2==0)
	execlp("/bin/ls", "ls", "-S");
	if(pid2>0)
	execlp("/bin/ls", "ps");

	return 0;
}