#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int main()
{
	ifstream in; string str;
	in.open("Q1.txt");
	if (in.is_open())
	{
		while (!in.eof())
		{
			getline(in, str);
			for (int i = 0; str[i] != '\0'; i++)
			{
				if (str[i] >= '0' && str[i] <= '8')
				{
					str[i] = str[i] + 1;
				}
				ofstream out;
				out.open("Q1_out.txt");
				out << str << endl;
			}
		}
	}
	else {cout << "Error Opening file" << endl;}
	return 0;
}