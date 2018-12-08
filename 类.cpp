#include <iostream>
using std::cout;
using std::endl;

class test
{
	int x,y;
public:
	test(int a=0,int b=1);  //此函数专门用来初始化private变量
};
test::test(int a, int b)
{
	x=a;
	y=b;
	cout<<a<<endl<<b<<endl;
}

int main(int argc, char const *argv[])
{	
	test x(1,2);
	return 0;
}