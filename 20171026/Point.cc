 ///
 /// @file    Point.cc
 /// @author  Norland(norland.xw@gmail.com)
 /// @date    2017-10-27 19:27:16
 ///

#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;


//构造函数与析构函数都是特殊的成员函数
class Point{
	public:
		Point()//无参(默认)构造函数
		: _ix(0)//初始化表达式进行初始化
		, _iy(0)
		{
		//	_ix = 0;//赋值操作进行初始化
		//	_iy = 0;
			cout << "Point() " << endl;
		}
		
		//构造函数可以进行重载  
		//自定义了有参构造函数,编译器就不会再提供默认构造函数,必须自己手动定义
		Point(int x, int y){//重载的有参构造函数
			_ix = x;
			_iy = y;
			cout << "Point(int,int) " << endl;
		}
		
		//显式定义析构函数
#if 1
		~Point(){
			cout << "~Point() " << endl;
		}
#endif

		void print(){
			cout << "( " << _ix;
			cout << " , " << _iy;
			cout << " ) " << endl;
		}

	private:
		int _ix;
		int _iy;
};

Point p4(3, 4);//全局对象

int main(){

	int a(10);//C++初始化方式
	cout << "a = " << a << endl;

	//1.对象的生命周期是到最近的大括号，生命周期结束后，将会调用析构函数~Point()
	//括号外将无法看到该对象的存在;
	//2.如果要自动调用析构函数，该对象必须是一个栈对象(存储在栈上);
	{
		Point p1;//自动调用默认构造函数
		p1.print();
	}

	Point p2(1, 2);//调用有参构造函数
	p2.print();
//	p2.~Point();//析构函数可以显式调用
				//由于析构函数的作用是用来做回收工作的，所以一般不会显式调用
	
	Point *p3 = new Point(2, 3);
	p3 ->print();
	//堆对象必须要执行delete 表达式才能回收
	//堆对象的生命周期到delete结束
	delete p3;

	p4.print();//全局对象生命周期也随程序结束而结束

	return 0;
}
