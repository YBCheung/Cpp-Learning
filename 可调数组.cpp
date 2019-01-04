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
	int length()
		{return size;}
	void add(int num);
	void Display(void);
	// CArray& operator=(const CArray &A);
};
CArray::CArray(int s)
{
	if(size>=0)
		size = s;
}
inline void CArray::Display()
{
	int i=0;
	for(i=0;i<size;i++)
		printf("%d",ptr[i]);
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
// inline CArray& CArray::operator=(const CArray &A)????
// {
// 	if(A.size==0) //赋值为一个空数组
// 	{
// 		if(size)
// 			{delete []ptr;size=0;}
// 		ptr = NULL;
// 		return *this;
// 	}
// 	size = A.size;
// 	delete []ptr;
// 	cout<<"hh";
// 	ptr = new int[size];
// 	cout<<"hh";
// 	memcpy(ptr,A.ptr,sizeof(int)*size);
// 	return *this;
// }

int main()
{
	CArray a(0);
	a.add(1);
	a.add(2);
	CArray b(a);
	b.Display();
	return 0;
}