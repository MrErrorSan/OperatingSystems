#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
	ifstream in; fstream out; string str;
	in.open("input.txt");
	out.open("output.txt", ios::out);
	char arr[30];
	if(in.is_open())
	{
		while(!in.eof())
		{
			getline(in,str);
			///////////////////////////////////////////////
			/*int words=1;
			for(int i=0;i<str.length();i++)
				if(str[i]==' ')
					words++;*/
			int z=0;
			string str2;int i2=0;
			for(int i=0;i<str.length();i++)
			{
				if(str[i]!=' ')
				{
					arr[z]=str[i];
				}
				else
				if(str[i]==' ' || str[i]=='\0')
				{

					for(int j=z;j>0;j--)
					{
						out<<arr[j];
					}
					if(str[i]=='\0')
						out<<" "<<endl;
					else
						out<<" ";
				}
			}
				//out<<;
			//	
			//	if(str[i]=='\0')
			//		out<<str[i]<<endl;
			//	//arr[arr_index][index]=str[i];
			//		//index++;
			//	//}else if(str[i]==' ')
			//	//{
			//		//if(arr_index<words)
			//		//{
			//			//arr_index++;
			//			//index=0;
			//		//}else {cerr<<"Reversing Error"<<endl;}
			//	//}
			//}
			//////////////////////////////////////////////////
			////string a;
			////for(int i=words;i>0;i--)
			////{
			////	//a=a+arr[i];
			////	cout<<arr[i];
			////	if(i-1 != 0)
			////		cout<<" ";
			////}
			////cout<<a<<endl;
			//////out<<endl;
			////cout<<endl;
		}
	}else
	{
		cerr<<"Error Opening File"<<endl;
	}
	system("pause");
	return 0;
}