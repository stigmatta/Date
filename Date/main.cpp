#include <iostream>
#include "Date.h"
using namespace std;
int main()
{
	Date a(2004, 12,5);
	a++;
	a.print(); //postfix increm.
	++a;
	a.print(); //prefix increm.
	a--;
	a.print(); //postfix increm.
	--a;
	a.print(); // prefix increm.
	Date b(2004, 12, 17);
	Date c = a - b; // one obj minus second obj
	c.print();
	Date d = a + 10; // obj+days;
	d.print();
	Date e = a - 10; // obj-days;
	e.print();
	e += 10; //simplified +
	e.print();
	e -= 10; //simplified -
	e.print();
	bool test1 = a > b;
	cout << test1 << endl;

	bool test2 = a < b;
	cout << test2 << endl;
	bool test3 = a == b;
	cout << test3 << endl;
	bool test4 = a != b;
	cout << test4 << endl;

};