#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int *p;
	p = new int;
	*p = 0;
	cout<<*p<<endl;
	delete p;
	
	int n=41234512;
	char *str = new char[n];
	cin.getline(str,12);
	cout<<str[8]<<endl;	
	delete []str;

}
