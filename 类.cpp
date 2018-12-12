#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class Complex{
	private: 
		float real, imag;  //参数缺省则默认为private）
	public:
		Complex(void);
		Complex(float a,float b=0);
		Complex(const Complex c1,const Complex c2);   //可有多个构造函数，根据形参类型匹配对应函数。
		Display();
		Complex(const Complex & c)  
		//复制构造函数，要是不写也会默认生成复制。
		//不可另外构造“Complex(Complex c1),与构造函数冲突”。
		//调用复制构造函数情形：（最好别瞎自定义）
		//1、构造函数有类的形参
		//2、赋值语句，Complex c1 = c2
		//当类中成员有指针变量、类中有动态内存分配时常常需要用户自己定义拷贝构造函数
		{
			real = c.real;
			imag= c.imag;
			cout<<"Copy successfully:"<<real<<"+"<<imag<<"j"<<endl;
		}
		~Complex()     
		//析构函数，每次类消亡（子函数跑完形参消亡；赋值时临时类消亡；main函数结束类消亡；调用delete函数；数组类每个元素；每个类）
		//可写入释放动态指针语句
		{
			cout<<"destruction"<<endl;
		}
};
Complex::Complex(void) //构造函数直接对类进行初始化
{
	// cout<<"real=";
 //    cin>>real;
 //    fflush(stdin);
 //    cout<<"imag=";
 //    cin>>imag;
 //    fflush(stdin);
}
Complex::Complex(float a,float b) //构造函数直接对类进行初始化
{
	real = a;imag = b;
}
Complex::Complex(const Complex c1,const Complex c2) //构造函数直接对类进行初始化
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
	cout<<"Line 1"<<endl;
	Complex c1;
	c1 = 6;  //临时类，调用析构函数
	c1.Display();
	cout<<"Line 2"<<endl;
	Complex *c2 = new Complex(1,2);   // 动态指针生成类
	c2->Display();  //指针，需要用->
	cout<<"Line 3"<<endl;
	Complex c3(*c2);  //复制构造
	c3.Display(); 
	cout<<"Line 4"<<endl;
	Complex *psum1 = new Complex(c1,*c2);  //只要构造函数的形参、返回值有类（dev不会复制），就会跑一次复制构造函数（最好别瞎自定义）
	psum1->Display();
	cout<<"Line 5"<<endl;
	Complex array[2] = {1,Complex(1,2)};  //数组类结束时会调用析构函数；
	array[0].Display();
	array[1].Display();
	cout<<"Line 6"<<endl;
	delete c2;
	c2 = NULL;
	cout<<"Line 7"<<endl;
	delete psum1;
	psum1 = NULL;  //动态指针用完要指向NULL（0）
	cout<<"Line 8"<<endl;
	//c1,c3,array[2]消亡调用析构函数
	return 0;
}
