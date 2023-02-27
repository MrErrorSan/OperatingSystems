#include<fstream>
#include<pthread.h>
#include<string>
#include<iostream>
using namespace std;

string chartostr(char *a, int size)
{
    int i;
    string s = "";
    for (i = 0; i < size; i++)
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
///////////////////////////////////////////////////
void *fun(void* a)
{
    int size=100;
    ifstream f1(chartostr((char*)a,42));
    f1.open((char *)a);
    cout << "... Theard Function is running" << endl;
    int *arr = new int [size];
    string s;

    if(f1.is_open())
    {
        int index=0;
        while/*(f1.good())*/(!f1.eof())
        {
            int x;
            getline(f1,s);
            x = atoi(strtochar(s));
            cout << x;
            arr[index] = x;
            cout<<"index (loop1) = "<<index<<endl;

        }
    }
    f1.close();
    cout << "... Theard Function is running" << endl;
    int n=0;
    int *ret = new int [size];
    for(int i=0;i<size;i++)
    {
        if(arr[size]>0)
        {
            for(int j=i;j>0;j--)
            {
                if(arr[i]==arr[j])
                {
                    ret[n]=arr[i];
                }
            }
        }
    }
    cout<<"... Theard Function is Ended"<<endl;
    return (void*)ret;
    return 0;
}

int main()
{
    string str = "/home/mrerror/Documents/Visual Code/f1.txt";
    char *f1 = strtochar(str);
    char *f2 = strtochar("/home/mrerror/Documents/Visual Code/f2.txt");
    void *file1;
    void *file2;
    int n;
    pthread_t p;
    n= pthread_create(&p,NULL,&fun,f1);
    pthread_exit(NULL);
    n = pthread_join(p, &file1);
    cout << "End of Thread 1(main)" << endl;
    n = pthread_create(&p, NULL, &fun, f2);
    pthread_exit(NULL);
    n= pthread_join(p,&file2);
    cout << "End of Thread2" << endl;
    return 0;
}
