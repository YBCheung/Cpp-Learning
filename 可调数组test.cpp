#include "CArray.h"

int main()
{
	CArray a(0);
	a.add(1);
	a.add(2);
	a.add(3);
	a.Display();
	CArray b(a);
	// b=a;
	b[1]= 100;
	b.Display();
	cout<<b[2];
	return 0;
}