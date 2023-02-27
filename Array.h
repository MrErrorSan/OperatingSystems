#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class Array
{
int* arr;
int arr_size;
//string file;
public:
Array();
void read();
void set_avg();
void set_max();
void set_min();
void set_values();
int get_max();
int get_min();
int get_avg();
~Array();
};
