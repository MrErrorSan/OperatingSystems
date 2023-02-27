#include<fstream>
#include<pthread.h>
#include<string>
#include<iostream>
#include<sstream>
using namespace std;
//Utility Functions
int strtoINT(string s)
{
    stringstream g(s);
    int x = 0;
    g >> x;
    return x;
}
string chartostr(char *a)
{
    int i;
    string s = "";
    for (i = 0; a[i]!='\0'; i++)
    {
        s = s + a[i];
    }
    return s;
}
char *strtochar(string s)
{
    char *p = new char[s.length()];
    for (int i = 0; i < s.length(); i++)
    {
        p[i] = s[i];
    }
    return p;
}
/////////////////////////
void* remover(void* a)
{
    ifstream f1(chartostr((char*)a));
    string arr[100];
    int i1 = 0;
    if (f1.is_open())
    {

        while (!f1.eof())
        {
            getline(f1, arr[i1]);
            i1++;
        }
    }
    f1.close();
    bool flag = 1;
    string res[i1];
    int p = 0;
    for (int i = 0; i < i1; i++)
    {
        if (arr[i][0] != '-')
        {
            for (int j = 0; j < i; j++)
            {
                if (arr[i] == arr[j])
                {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1)
            {
                res[p] = arr[i];
                p++;
            }
            else
                flag = 1;
        }
    }
    int* ret= new int[p];
    for(int i=0;i<p;i++)
    {
        ret[i] = strtoINT(res[i]);
    }
    return (void*)ret;
}
int avg(int* a)
{
    int size = sizeof(a) / sizeof(a[0]);
    int sum=0;int av=0;
    for(int i=0;i<size;i++)
    sum= sum + a[i];
    av= sum/size;
    return av;
}
int main()
{
    char *file1 = strtochar("f1.txt");
    char *file2 = strtochar("f2.txt");
    void *result1;
    void *result2;
    int n;
    pthread_t p;
    n= pthread_create(&p,NULL,&remover,file1);
    n = pthread_join(p, &result1);
    cout << "Average of f1.txt is  : " << avg((int*)result1)<<endl;

    n = pthread_create(&p, NULL, &remover, file2);
    n = pthread_join(p, &result2);
    cout << "Average of f2.txt is  : " << avg((int *)result2) << endl;

    return 0;
}
