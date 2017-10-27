 ///
 /// @file    Memory_allocation.cc
 /// @author  Norland(norland.xw@gmail.com)
 /// @date    2017-10-27 09:12:22
 ///

#include <string.h>
#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;

int a = 0;//全局/静态区
char str[10] = "hello";

int main()
{
	int b = 1;//栈空间
	char * p;//野指针
	const int c = 2 ;//栈空间,const型不能修改
	static int d = 3;//全局/静态区,读写区，可修改
	char * pa = "I am";//栈空间
	const char *pb = "world";//文字常量区,不能修改 
	char s[] = "world";//栈空间
	char * pc = new char [10];//堆空间
	 
	printf("p = %p\n",p);
	printf("&a = %p\n",&a);
	printf("&b = %p\n",&b);
	printf("&c = %p\n",&c);
	printf("&d = %p\n",&d);
	printf("pa = %p\n",pa);
	printf("pb = %p\n",pb);
	printf("s = %p\n",s);
	printf("pc = %p\n",pc);
	printf("str = %p\n",str);
	return 0;
}
