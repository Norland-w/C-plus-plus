 ///
 /// @file    reference2.cc
 /// @author  Norland(norland.xw@gmail.com)
 /// @date    2017-10-25 22:23:11
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//引用与指针的异同点:
//相同点:都有"地址"的概念;
//不同点:1.指针是一个独立的个体,引用不能单独存在,必须依赖与一个实体;
//	     2.指针可以不进行初始化,引用必须要进行初始化;
//	     3.指针可以设置为NULL,引用不行.

int arr[5]={0,1,2,3,4};

//函数返回值为引用,执行return语句时不会进行复制
//直接返回变量本身
int & func0(int i)
{
	return arr[i];
}

//
int func1()
{
	int a = 10;
	return a;
}

//返回值为局部变量栈空间变量的地址,也是不能获得其内容的
//局部变量在函数执行完毕时，其生命周期已经结束
#if 0
int * func2()
{
	int a=20;
	return &a;
}
#endif

//不能返回局部变量的引用
//局部变量在函数执行完毕时，其生命周期已经结束
#if 0
int & func3()
{
	int a = 30;
	return a;
}
#endif


//不要返回一个堆空间变量的引用,除非已经有了回收内存的策略
int & func4()
{
	int *pa = new int(40);
	return *pa;
}

void test()
{
	cout << "func0() = " << func0(1) << endl;
	func0(1) = 10;//返回的是变量本身,可直接修改变量
	cout << "func0() = " << func0(1) << endl;
	cout << "arr[1] = " << arr[1] << endl;
	cout << "func1() = " << func1() << endl;
//	cout << "func2() = " << func2() << endl;
//	cout << "func3() = " << func3() << endl;
	int &  p4 = func4();//返回堆空间变量引用,要回收内存
	//返回什么就用什么接
	cout << "func4() = " << p4 << endl;//堆空间
	delete &p4;//释放空间,要取地址&
}



int main()
{
	test();
	int a =1,b =2;
	int c = a + func4() + b;//申请空间没有回收,会发生内存泄漏
	cout << "c = " << c << endl;
	return 0;
}
