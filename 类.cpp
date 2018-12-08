#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class Complex{
	private: 
		int real, imag;  //参数缺省则默认为private）
	public:
		Complex(void);
		Complex(int a,int b=0);
		Complex(Complex c1,Complex c2);   //可有多个构造函数，根据形参类型匹配对应函数。
		Display();
};
Complex::Complex(void) //构造函数直接对类进行初始化
{
	cout<<"real=";
    cin>>real;
    fflush(stdin);
    cout<<"imag=";
    cin>>imag;
    fflush(stdin);
}
Complex::Complex(int a,int b) //构造函数直接对类进行初始化
{
	real = a;imag = b;
}
Complex::Complex(Complex c1,Complex c2) //构造函数直接对类进行初始化
{
	real = c1.real+c2.real;
	imag = c1.imag+c2.imag;
}
Complex::Display(void)
{	
	cout<<real<<'+'<<imag<<'j'<<endl;
	return 0;
}

int main(int argc, char const *argv[])
{	
	Complex c1;
	Complex *c2 = new Complex(1,2);
	Complex *psum1 = new Complex(c1,*c2);
	c1.Display();
	c2->Display();
	psum1->Display();
	delete []c2;
	delete psum1;
	psum1 = NULL;
	
	Complex array[3] = {1,Complex(1,2)};
	Complex *psum2 = new Complex(array[0],array[1]);
	array[0].Display();
	array[1].Display();
	array[2].Display();
	psum2->Display();
	delete []psum2; //此处删除，只是消除此指针变量与对应存储空间的关联，并不能删除此变量，会变成野指针，影响下一个指针变量。
	psum2=NULL;     //此处将变量变为0，空指针。但这个变量还在，不可重复定义
	return 0;
}
