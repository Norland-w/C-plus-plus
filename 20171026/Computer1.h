 ///
 /// @file    Computer1.h
 /// @author  Norland(norland.xw@gmail.com)
 /// @date    2017-10-27 16:11:17
 ///
 //
#include <string.h>  
#include <iostream>
using std::cout;
using std::endl;

class Computer1{
	public://只在类中声明成员函数
		void setBrand(const char *);

		void setPrice(float);

		void print();

	private:
		char _brand[20];
		float _price;
};

//在类定义外部定义成员函数(即实现成员函数)
void Computer1::setBrand(const char * brand){
	strcpy(_brand, brand);
}

void Computer1::setPrice(float price){
	_price = price;
}

void Computer1::print(){
	cout << "brand: " << _brand << endl;
	cout << "price: " << _price << endl;
}
