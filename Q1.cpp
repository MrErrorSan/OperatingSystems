#include <sys/types.h>
#include <stdio.h>
#include <cstring>
#include<string>
#include<string.h>
#include<fstream>
#include <unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<iostream>
using namespace std;

int main(int argc,char* argv[])
{
	int res, n;char a[30]; int s=30;
	res= open(argv[1],O_RDONLY,0);
	n= read (res,a,s);
	string p(a);
	string c(argv[2]);
	int count=0; 
	size_t nPos= p.find(c,0);
	while(nPos != string::npos)
	{
		count++;
		nPos= p.find(c,nPos+1);
	}
	cout<<"Ouccerance : "<<count<<endl;
return 0;
}
