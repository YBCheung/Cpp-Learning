#ifndef array_H
#define array_H
#include <iostream>
#include <string.h>
using std::cout;
using std::endl;
using std::cin;

class Array
{
private:
	int length;
	int size;
	int *ptr;
public:
	Array(int len=0);
	Array(Array& a);
	~Array(){};
	int& operator[](int i);
	void add(int c);
	void Display(void);
	void Display(int i);
	Array& operator=(const Array& a);
};

Array::Array(int len)
{
	if(len<=0)
	{
		// ptr=NULL;
		ptr=new int[0];
		length=0;
		size=0;
	}
	else
	{
		for(size=16;size<len;size*=2);
		ptr=new int[size];
		length=len;
	}
}
Array::Array(Array& a)
{
	if(!a.length)
	{
		length=0;
		ptr=new int[0];
		return;
	}
	// int i;
	length=a.length;
	size=a.size;
	ptr=new int[size];
	memcpy(ptr,a.ptr,sizeof(int)*a.size);
	// for(i=0;i<length;i++)
	// {
	// 	*(ptr+i)=a[i];
	// }
}
inline int& Array::operator[](int i)
{
	if(i>=length)
		cout<<"超位啦！"<<endl;
		return *(ptr+length-1);
	return *(ptr+i);
}
inline void Array::add(int i)
{
	// *(ptr+length) = i;
	// length++;
	// 不可以这么写，若ptr++对应已有存储内容，则出错。
	// 应该写，新建一个更大的，删除原来的。
	// 高效的方法：首先创建大小32，超了则新建64，然后128.减少新建、删除次数。
	if((++length)>=size)
	{
		if(size==0)
			size=16;
		else
			size*=2;
		int *tmpptr=new int[size];
		memcpy(tmpptr,ptr,sizeof(int)*(length-1));
		delete []ptr;
		ptr=tmpptr;
	}
	*(ptr+length-1)=i;
}
inline void Array::Display(void)
{
	int i;
	for(i=0;i<length;i++)
		cout<<*(ptr+i)<<',';
	cout<<endl<<"length: "<<length<<"  size: "<<size<<endl;
}
inline void Array::Display(int i)
{
	cout<<*(ptr+i)<<endl;
}
inline Array& Array::operator=(const Array& a)
{
	delete []ptr;
	length=a.length;
	size=a.size;
	ptr=new int[size];
	memcpy(ptr,a.ptr,sizeof(int)*length);
	return *this;
}
#endif