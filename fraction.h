#ifndef fraction_H
#define fraction_H
#include <iostream>
#include <cmath>

using std::cout;
using std::endl;
using std::cin;

class fraction
{
private:
	int inter;
	int num;
	int den;
public:
	fraction(int a,int b=1);
	~fraction(){};
	void Display();
	fraction operator-();
	fraction operator++();
	fraction operator--();
	fraction& operator=(fraction f);
	operator float() const	{return num*1.0/den;}
	fraction operator+=(fraction f);
	fraction operator-=(fraction f);	
	friend fraction operator++(fraction& f,int);
	friend fraction operator--(fraction& f,int);
	friend fraction operator-(fraction a,fraction b);
	friend fraction operator+(fraction a,fraction b);
	friend fraction operator*(fraction a,fraction b);
	friend fraction operator/(fraction a,fraction b);
//	fraction operator++(int)   //¶þÕß½Ô¿É 
//	{
//		num+=den;
//		return fraction(num-den,den);
//	}
//	fraction operator--(int)
//	{
//		num-=den;
//		return fraction(num+den,den);
//	}
};

int gcd(int a,int b)
{
	int c=1;
	while(b)
	{
		c=a;
		a=b;
		b=c%b;
	}
	return abs(a);
}
inline fraction::fraction(int a,int b)
{
	int p;
	if(b==0)
	{
		cout<<"error"<<endl;
		return;
	}
	if(a==0) b=1;
	if(b<0){b=-b;a=-a;}
	p = gcd(a,b);	
	num=a/p;
	den=b/p;		
}
inline fraction fraction::operator-()
{
	return fraction(num,den);
}
inline fraction fraction::operator++()
{
	num+=den;
	return fraction(num,den);
}
inline fraction fraction::operator--()
{
	num-=den;
	return fraction(num,den);
}
inline fraction fraction::operator+=(fraction f)
{
	num=num*f.den+den*f.num;
	den*=f.den;
	return fraction(num,den);
}
inline fraction fraction::operator-=(fraction f)
{
	num=num*f.den-den*f.num;
	den*=f.den;
	return fraction(num,den);
}
inline fraction& fraction::operator=(fraction f)
{
	num=f.num;
	den=f.den;
	return *this; 
}

inline void fraction::Display()
{
	cout<<num<<"/"<<den<<endl;
}

inline fraction operator+(fraction a,fraction b)
{
	return fraction(a.num*b.den+b.num*a.den,a.den*b.den);
}
inline fraction operator-(fraction a,fraction b)
{
	return fraction(a.num*b.den-b.num*a.den,a.den*b.den);
}
inline fraction operator*(fraction a,fraction b)
{
	return fraction(a.num*b.num,a.den*b.den);
}
inline fraction operator/(fraction a,fraction b)
{
	return fraction(a.num/b.num,a.den/b.den);
}
inline fraction operator++(fraction& f,int)
{
	f.num+=f.den;
	return fraction(f.num-f.den,f.den);
}
inline fraction operator--(fraction& f,int)
{
	f.num-=f.den;
	return fraction(f.num+f.den,f.den);
}
#endif
