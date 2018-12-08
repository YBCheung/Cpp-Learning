#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class Complex{
	private: 
		int real, imag;  //参数缺省则默认为private）
	public:
		Complex(void);
		Complex(int a,int b = 0);
		Complex(Complex c1,Complex c2);   //可有多个构造函数，根据形参类型匹配对应函数。
		Display();
};
Complex::Complex(void) //构造函数直接对类进行初始化
{
	cout<<"real=";
    cin>>real;
    cout<<"imag=";
    cin>>imag;
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
	Complex *c2 = new Complex(3,4);
	Complex sum = Complex(c1,*c2);
	c1.Display();
	c2->Display();
	sum.Display();
	delete []c2;
	return 0;
}
