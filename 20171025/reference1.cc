 ///
 /// @file    reference1.cc
 /// @author  Norland(norland.xw@gmail.com)
 /// @date    2017-10-25 22:23:11
 ///
 
#include <iostream>
using std::cout;
using std::endl;

void test()
{
	int a = 10;
	//int & ref = 10;//error, 10是常量,字面值,无法取地址, 所以不能绑定到引用上面
	cout << a << endl;
	int & ref = a;//引用本质上就是一个变量的别名
	//引用必须绑定到一个实体上，不能单独存在，必须进行初始化
	ref = 20;//修改引用变量的值实际上就是修改原变量
	cout << a << endl;
}


//传参方式:值传递 -> 复制
void swap1(int a,int b)
{
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}


//传参方式:地址传递 -> 值(地址值)传递 -> 复制
void swap2(int * a,int * b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}


//传参方式:引用传递 -> 直接操作实参本身
//相当于为实参创建了对应的引用,即形参
//优点:1.效率更高,引用不会开辟额外的空间
//	   2.更加直观，操作方便
void swap3(int & a,int & b)
{
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}

int main()
{
	test();
	int x=30,y=40;
	swap1(x,y);
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
	swap2(&x, &y);
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
	swap3(x,y);
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
	return 0;
}
