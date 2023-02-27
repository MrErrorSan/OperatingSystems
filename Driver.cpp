#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include"Array.h"
int main()
{
	Array A;
	A.read();
	pid\_t pid = 0;
	pid = fork();
	if (pid == 0) 
	{
		//child
		cout << "Average : " << A.get_avg() << endl;
		cout << "Min  : " << A.get_min() << endl;
		cout << "Max  : " << A.get_max() << endl;
	}
	else if (pid > 0)
	{
		//parent
		wait(NULL);
		A.set_values();
	}
	else { cerr << "Error" << endl << endl; }
	return 0;
}