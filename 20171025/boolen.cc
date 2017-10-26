 ///
 /// @file    boolen.cc
 /// @author  Norland(norland.xw@gmail.com)
 /// @date    2017-10-25 14:26:31
 ///
 
#include <iostream>
using std::cout;
using std::endl;

void test(){
	if(1){
		cout << "This is true!" << endl;
	}
	if(0){
		cout << "This is false!" << endl;
	}
}

void test1(){
	bool a = true;
	bool b = false;
	bool c = -1;
	bool d = 10;
	bool e = 0;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	cout << "d = " << d << endl;
	cout << "e = " << e << endl;
	cout << "sizeof(bool) = " << sizeof(bool) << endl;
}

int main()
{
	test();
	test1();
	return 0;
}
