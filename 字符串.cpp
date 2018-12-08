#include <iostream>
using namespace std;
int main()
{
	char ch1[6];
	char ch2[6];
	char ch3[6];
	int i;
	for(i = 0;i<5;i++)
	{
		cin.get(ch1[i]);
		cout<<ch1[i];
	}
	fflush(stdin);
	cout<<endl;
	for(i = 0;i<5;i++)
	{
		cin>>ch2[i];
		cout<<ch2[i];
	}
	fflush(stdin);
	cout<<endl;
	cin>>ch3;
	cout<<ch3;
	cout<<endl;
	fflush(stdin);
	
} 
