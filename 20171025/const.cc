 ///
 /// @file    const.cc
 /// @author  Norland(norland.xw@gmail.com)
 /// @date    2017-10-25 20:46:07
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//预处理时,的简单字符串替换
#define A 10//C定义常量

//int *p [];     int (*p)[];
//指针数组       数组指针
//int * func();  int (*func)();
//指针函数       函数指针

int main()
{
	cout << A << endl;
	
	//编译时,会进行类型检查
	const int B=20;//C++定义常量,B是只读变量,无法被修改
	cout << B << endl;
	int a= 30,b= 40;
	
	const int * const pc = &a;//常量指针常量,都不能改变
	cout << *pc <<endl;
	
	int * const pa = &a;//指针常量(const pointer)
	*pa=50;//指针常量 -> 指针是常量 -> 指针指向不能改变,指向变量值可以改变
	cout << *pa << endl;
	
	const int * pb = &b;//常量指针(pointer to const)
	pb = &b;//常量指针 ->指向常量的指针 ->指针指向可以改变,指向变量值不能改变
	cout << *pb << endl;
	
	return 0;
}

