#include<iostream>
using namespace std;
int main()
{
	int b = 20;
	int c = 30;
	int *a = new int;
	*a = 10;
	cout<<b;
	delete a;
	return 0;
} 
