 ///
 /// @file    copyConstructor1.cc
 /// @author  Norland(norland.xw@gmail.com)
 /// @date    2017-10-27 21:40:37
 ///
 
#include <stdio.h>
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class Computer
{
	public:
#if 0
		Computer( char * brand, float price)
		: _brand(brand)//浅拷贝 -> 直接传地址 -> 无法取到字符串
		, _price(price)
		{		}
#endif
	
		Computer(const char * brand, float price)//通用构造函数
		: _brand(new char[strlen(brand) + 1])//开堆空间
		, _price(price)
		{
			strcpy(_brand, brand);//深拷贝 -> 拷贝数据内容
			cout << "Computer(const char *, float)" << endl;
		}

#if 0
		Computer(const Computer & rhs)//默认复制构造函数
		: _brand(rhs._brand)   //浅拷贝 -> 指向同一块空间 -> double free
		, _price(rhs._price)
		{
			cout << "Computer(const Computer & rhs)" << endl;
		}
#endif
		
		Computer(const Computer & rhs)//复制构造函数
		: _brand(new char [strlen(rhs._brand) + 1]) //深拷贝 -> 开辟空间去接收数据
		, _price(rhs._price)
		{
			strcpy(_brand, rhs._brand);
			cout << "Computer(const Computer & rhs)" << endl;
		}
		
		
		void print()
		{
			printf("brand : %p\n",_brand);
			cout << "brand : " << _brand << endl;
			cout << "price : " << _price << endl;
		}

		~Computer()
		{
			delete [] _brand;//释放堆空间
			cout << "~Computer() " << endl;
		}

	private:
		char * _brand;
		float _price;

};

//当实参与形参都是对象，进行实参与形参结合时，会调用复制构造函数
void test(Computer pc)
{
	pc.print();
}

//当函数返回值是对象，函数调用完成返回时，会调用复制构造函数
//默认g++ 编译，编译器会优化，减少调用时间，直接调用通用构造函数进行
//g++ -fno-elide-constructors 编译会解除优化，此时调用的是复制构造函数
Computer test1()
{
	Computer pc("Thinkpad", 7000);
	pc.print();
	return pc;
}
int main()
{
    const char * a = "Mac";
	cout << "com:" << endl;
	Computer com(a, 10000);
	com.print();

//当把一个已经存在的对象赋值给另一个新的对象时，会调用复制构造函数
	cout << "com1:" << endl;
	Computer com1 = com;
	com1.print();
	
	cout << "com2: " << endl;
	Computer com2("lenovo",5000);//文字常量区数据，不属于类
	com2.print();                //浅拷贝只传了地址过去，拿不到数据，必须用深拷贝

	cout << "test: " << endl;
	test(com2);

	cout << "test1: " << endl;
	test1();
//	Computer t = test1();

	return 0;
}
