///
/// @file    copyConstructor.cc
/// @author  Norland(norland.xw@gmail.com)
/// @date    2017-10-27 20:38:07
///

#include <iostream>
using std::cout;
using std::endl;

class Point
{
	public:
		Point()
			: _ix(0)//实际初始化顺序与声明顺序有关,与定义的初始化顺序无关
			  , _iy(0)
	{
		cout << "Point () " << endl;  
	}

		Point(int ix, int iy)
		{
			_ix = ix;
			_iy = iy;
		}

		//复制构造函数
		//1.其参数中的引用符号不能去掉，如果去掉之后，根据复制构造函数的
		//调用规则，它会不断的去初始化形参；在初始化形参时，又会调用复制构造函数本身，
		//从而导致函数调用的无穷递归，直到栈溢出;使用引用传参就能打破无穷递归
		//2.const关键字不能少，如果没有const关键字，对于临时对象而言，就不能正常传参了
#if 1
		Point(const Point & rhs)//1.const Point rhs = pt;
			: _ix(rhs._ix)		//2.Point & rhs = Point(1, 2);
			, _iy(rhs._iy)
		{
			cout << "Point (const Point & rhs ) " << endl;
		}
#endif

		~Point()
		{
			cout << "~Point () " << endl;
		}

		void print() const //const成员函数 
		{
			cout << "(" << _ix
				 << "," << _iy
				 << ")" << endl;
		}

	private:
		int _ix;
		int _iy;
};

int main()
{
	Point p1(1, 2);
	cout << "p1 = ";
	p1.print();
		
	//编译器会提供一个默认的复制构造函数，从而可以进行赋值
	//默认的复制构造函数时无参的，基本的复制可以完成
	Point p2 = p1;//类似于 int b = 1; int a = b;
	cout << "p2 = ";
	p2.print();

	Point p3(p1);//类似于 int b = 1;  int a(b);
	cout << "copy p2, p3= ";
	p2.print();
	
	Point p4 = Point(3, 4);//临时对象,不加const限制在赋值前已经执行了~Point(),生命周期就结束了
	cout << "p4 = ";
	p4.print();

	//&Point(1, 2);//error，无法取地址 --> 临时对象/右值
	const Point & ref = Point(5, 6);//只有const引用能够绑定到右值
	cout << "ref = ";
	ref.print();


	return 0;


}
