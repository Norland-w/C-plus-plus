 ///
 /// @file    static_cast.cc
 /// @author  Norland(norland.xw@gmail.com)
 /// @date    2017-10-25 15:36:46
 ///
#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;

//强制转换
//C:float b= 11.1; int a=(int)b;
//C++:int a=static_cast<int>a;
//C++有四种类型转换:
//1.static_cast;2.const_cast;3.dynamic_cast;4.reinterpret_cast

int test(){
	double a = 12.34;
	int b = (int) a;//C强制转换
	int c = int (a);//C强制转换
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	return 0;
}

int test1(){
	double a = 12.34;
	int b = static_cast<int>(a);//数据类型转换
	cout << "b = " << b << endl;
	return 0;
}


int main()
{
	test();
	test1();
	void * p1 =malloc(4);
	int * p2 = static_cast<int *>(p1);//指针类型转换
	*p2 = 10;
	cout << "p2 = " << *p2 << endl;
	return 0;
}
