#include <iostream>
using namespace std;

template <class T1,class T2> 
void number(T1 &,T2 &);

int main()
{
	int a;
	double b;
	cin>>a;
	fflush(stdin);
	cin>>b;
	cout<<a<<endl<<b<<endl;
	number(a,b);
	cout<<a<<endl<<b<<endl;
	return 0;	
}
template <class T1,class T2> 
/*
三种类型：
typename T1
class T1
int T1 
*/
void number(T1 &num1,T2 &num2)
{
	T1 temp;
	temp = num1;
	num1 = (T1)num2;
	num2 = (T2)temp;
}
