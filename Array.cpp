#include"Array.h"

Array::Array()
{
	arr=nullptr;
}
void Array::read()
{
	fstream in;
	string str; int size=0; int arr_index=0;
	in.open("Task1.txt",ios::in);
	if(in.is_open())
	{
		while(!in.eof())
		{
			getline(in,str);
			size++;
		}
	in.close();
	arr_size=size;
	arr= new int [arr_size];
	}else{cout<<"Error Opening File"<<endl;}
	in.open("Task1.txt");
	if(in.is_open())
	{
	while(!in.eof())
	{
		getline(in,str);
		arr[arr_index]= stoi(str);
		arr_index++;
	}
	in.close();
	}else{cout<<"Error Opening File"<<endl;}
}
void Array::set_avg()
{
	fstream out;
	out.open("Task1_out.txt",ios::ate);
	out<<"The Average is "<<get_avg()<<endl;
	out.close();
}
void Array::set_max()
{
	fstream out;
	out.open("Task1_out.txt",ios::ate);
	out<<"The Maximum Marks are "<<get_max()<<endl;
	out.close();
}
void Array::set_min()
{
	fstream out;
	out.open("Task1_out.txt",ios::ate);
	out<<"The Minimum Marks are "<<get_min()<<endl;
	out.close();
}
void Array::set_values()
{
	ofstream out;
	out.open("Task1_out.txt");
	out << "The Average is : " << get_avg() << endl << "The Maximum Marks are : " << get_max() << endl << "The Minimum Marks are : " << get_min() << endl;
	out.close();
}
int Array::get_max()
{
	int max=-1;
if(arr_size>0)
{
max= arr[0];
	for(int i=0;i<arr_size;i++)
	{
	if(max < arr[i])
           max = arr[i];
	}
}
return max;
}
int Array::get_min()
{
	int min=-1;
if(arr_size>0)
{
min= arr[0];
	for(int i=0;i<arr_size;i++)
	{
	if(min > arr[i])
           min = arr[i];
	}
}
return min;
}
int Array::get_avg()
{
	if(arr_size==0)
		return -1;
int sum = 0;
	for(int i=0;i<arr_size;i++)
	{
		sum=sum+arr[i];
	}
	return sum/arr_size;
}
Array::~Array()
{
	delete [] arr;
	arr=nullptr;
}
