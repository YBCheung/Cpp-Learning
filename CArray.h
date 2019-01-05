#ifndef CARRAY_H
#define CARRAY_H
#include <iostream>
#include <string.h>
using std::cin;
using std::cout;
using std::endl;

class CArray
{
private:
	int size;
	int *ptr;
public:
	CArray(int s=0);
	CArray(const CArray &A);
	~CArray()
		{if(size) delete []ptr; ptr=NULL;}
	int length()
		{return size;}
	void Display(void);
	void add(int num);
	int& operator[](int i);
	CArray& operator=(const CArray &A);
};

CArray::CArray(int s)
{
	if(size>=0)
	{
		size = s;
		ptr = new int[s];
	}
	else if(size==0)
		ptr=NULL;
}
CArray::CArray(const CArray &A)
{
	size=A.size;	
	if(A.ptr==NULL)
	{
		ptr=NULL;
	}
	else
	{
		ptr=new int[size];
		memcpy(ptr,A.ptr,sizeof(int)*size);
	}
}
inline void CArray::Display()
{
	int i=0;
	for(i=0;i<size;i++)
		printf("%-3d ",ptr[i]);
	cout<<endl;
}

inline void CArray::add(int num)
{
	if(size)
	{
		int *newptr = new int[size+1];
		memcpy(newptr,ptr,sizeof(int)*size);
		delete []ptr;
		ptr = newptr;
	}
	else
	{
		ptr = new int[1];
	}
	ptr[size++] = num;
}

inline int& CArray::operator[](int i)  //返回引用的函数可作为等式的左值
{
	if(i<size && i>=0)
		return ptr[i];
	else if(i>=-size && i<0)
		return ptr[size+i];
	else
		cout<<"Error input of ";
	return i;  //有没有更好的方法？这个返回的是形参的指针
}
inline CArray& CArray::operator=(const CArray &A)
{
	if(A.size==0) //赋值为一个空数组
	{
		if(size)
			{delete []ptr;size=0;}
		ptr = NULL;
		return *this;
	}
	if(size)
		delete []ptr;      //指针数组没有内容时，不可删除！
	size = A.size;
	ptr = new int[size];
	memcpy(ptr,A.ptr,sizeof(int)*size);
	return *this;
}
#endif