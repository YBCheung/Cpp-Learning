/******************************使用说明********************************/
//1.CArry_any可为任意类型（类、结构体、指针等），使用时，须宏定义any为目标类，包含此类的H文件
//2.新定义CArray数组时，括号里写数组长度。如CArray_int a[3];
//3.可按照数组习惯使用，另有附加功能：
//	a.length();  //显示数组长度
//  a.Display(); //改%d
//  a.add(3);    //加元素
//  a[1];a[-2];  //下标定位
//  a=b;         //深复制


#include <iostream>
#include <string.h>

using std::cin;
using std::cout;
using std::endl;

#define any char
class CArray
{
private:
	int size;
public:
	int length()
		{return size;}
	friend class CArray_int;
	friend class CArray_float;
	friend class CArray_char;
	friend class CArray_any;
};

/*************************CArray_int*****************************/
class CArray_int:public CArray
{
private:
	int *ptr=NULL;  //改类型
public:
	CArray_int(int s=0);
	~CArray_int()  //改类型
		{if(size) delete []ptr; ptr=NULL;}
	void Display(void); //改%d
	void add(int num);  //改int
	int& operator[](int i); //改int，判断类型
	CArray_int& operator=(const CArray_int &A); //判断类型
};

inline CArray_int::CArray_int(int s)
{
	int i;
	if(size>=0) 
	{
		size = s;
		for(i=0;i<size;i++)
			ptr[i]=0;
	}
}
inline void CArray_int::Display()
{
	int i=0;
	for(i=0;i<size;i++)
		printf("%d",ptr[i]);
	cout<<endl;
}

inline void CArray_int::add(int num)
{
	if(size)
	{
		int *newptr = new int[size+1];
		memcpy(newptr,ptr,sizeof(int)*size);
		delete []ptr;
		ptr = newptr;
	}
	else
		ptr = new int[1];
	ptr[size++] = num;
}

inline int& CArray_int::operator[](int i)
{
	if(i<size && i>=0)
		return ptr[i];
	else if(i>=-size && i<0)
		return ptr[size+i];
	else
	{
		cout<<"Input error!";
		exit(0);
	}
}
inline CArray_int& CArray_int::operator=(const CArray_int &A)
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
/*************************CArray_float*****************************/
class CArray_float:public CArray
{
private:
	float *ptr=NULL;  //改类型
public:
	CArray_float(int s=0);
	~CArray_float()  //改类型
		{if(size) delete []ptr; ptr=NULL;}
	void Display(void); //改%d
	void add(float num);  //改float
	float& operator[](int i); //改float，判断类型
	CArray_float& operator=(const CArray_float &A); //判断类型
};

CArray_float::CArray_float(int s)
{
	int i;
	if(size>=0)
	{
		size = s;
		ptr=new float[s];
		for(i=0;i<size;i++)
			ptr[i]=0;
	}
}
inline void CArray_float::Display()
{
	int i=0;
	for(i=0;i<size;i++)
		cout<<ptr[i]<<" ";
	cout<<endl;
}

inline void CArray_float::add(float num)
{
	if(size)
	{
		float *newptr = new float[size+1];
		memcpy(newptr,ptr,sizeof(float)*size);
		delete []ptr;
		ptr = newptr;
	}
	else
		ptr = new float[1];
	ptr[size++] = num;
}

inline float& CArray_float::operator[](int i)
{
	if(i<size && i>=0)
		return ptr[i];
	else if(i>=-size && i<0)
		return ptr[size+i];
	else
	{
		cout<<"Input error!";
		exit(0);
	}
}
inline CArray_float& CArray_float::operator=(const CArray_float &A)
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
	ptr = new float[size];
	memcpy(ptr,A.ptr,sizeof(float)*size);
	return *this;
}
/*************************CArray_char*****************************/
class CArray_char:public CArray
{
private:
	char *ptr=NULL;  //改类型
public:
	CArray_char(int s=0);
	~CArray_char()  //改类型
		{if(size) delete []ptr; ptr=NULL;}
	void Display(void); //改%d
	void add(char num);  //改char
	char& operator[](int i); //改char，判断类型
	CArray_char& operator=(const CArray_char &A); //判断类型
};

CArray_char::CArray_char(int s)
{
	int i;
	if(size>=0)
	{
		size = s;
		ptr=new char[s];
		for(i=0;i<size;i++)
			ptr[i]=0;
	}
}
inline void CArray_char::Display()
{
	int i=0;
	for(i=0;i<size;i++)
		cout<<ptr[i]<<" ";
	cout<<endl;
}

inline void CArray_char::add(char num)
{
	if(size)
	{
		char *newptr = new char[size+1];
		memcpy(newptr,ptr,sizeof(char)*size);
		delete []ptr;
		ptr = newptr;
	}
	else
		ptr = new char[1];
	ptr[size++] = num;
}

inline char& CArray_char::operator[](int i)
{
	if(i<size && i>=0)
		return ptr[i];
	else if(i>=-size && i<0)
		return ptr[size+i];
	else
	{
		cout<<"Input error!";
		exit(0);
	}
}
inline CArray_char& CArray_char::operator=(const CArray_char &A)
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
	ptr = new char[size];
	memcpy(ptr,A.ptr,sizeof(char)*size);
	return *this;
}

/*************************CArray_anyr*****************************/
class CArray_any:public CArray
{
private:
	any *ptr=NULL;  //改类型
public:
	CArray_any(int s=0);
	~CArray_any()  //改类型
		{if(size) delete []ptr; ptr=NULL;}
	void Display(void); //改%d
	void add(any num);  //改any
	any& operator[](int i); //改any，判断类型
	CArray_any& operator=(const CArray_any &A); //判断类型
};

CArray_any::CArray_any(int s)
{
	int i;
	if(size>=0)
	{
		size = s;
		ptr=new any(s);
		for(i=0;i<size;i++)
			ptr[i]=0;
	}
}
inline void CArray_any::Display()
{
	int i=0;
	for(i=0;i<size;i++)
		cout<<ptr[i]<<" ";
	cout<<endl;
}

inline void CArray_any::add(any num)
{
	if(size)
	{
		any *newptr = new any(size+1);
		memcpy(newptr,ptr,sizeof(any)*size);
		delete []ptr;
		ptr = newptr;
	}
	else
		ptr = new any(1);
	ptr[size++] = num;
}

inline any& CArray_any::operator[](int i)
{
	if(i<size && i>=0)
		return ptr[i];
	else if(i>=-size && i<0)
		return ptr[size+i];
	else
	{
		cout<<"Input error!";
		exit(0);
	}
}
inline CArray_any& CArray_any::operator=(const CArray_any &A)
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
	ptr = new any(size);
	memcpy(ptr,A.ptr,sizeof(any)*size);
	return *this;
}

int main()
{
	CArray_char a(3);
	a[0]='2';
	a.add('1');
	a.add('a');
	a.add('3');
	a.Display();
	CArray_char b;
	b=a;
	b.Display();
	cout<<b[-3];
	return 0;
}