#include<iostream>
#include<string.h>
using namespace std;
char *work(char array[])
{
	int i;
	for(i = 0;i<strlen(array);i++)
	{
		if(array[i] == ' ')
		{
			array[i] = '!';
		}
	}
	return &array[0];
} 
int main()
{
	char array[7];
	cin.getline(array,8);
	cout<<array<<endl;
	cout<<work(array); 
	return 0;
} 

