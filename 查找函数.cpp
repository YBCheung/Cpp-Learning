#include<iostream> 
#include<string>
using namespace std;
int main()
{
	string array("ABC");
	string str3;
	int x;
	str3 = array;
	
	x = str3.find('A');
	str3.insert(x-1,"123");
	//cout<<array;
	cout<<str3;
	return 0;
}
