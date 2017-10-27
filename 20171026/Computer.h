 ///
 /// @file    Computer.h
 /// @author  Norland(norland.xw@gmail.com)
 /// @date    2017-10-27 15:13:00
 ///

#include <stdio.h>
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class Computer{
	public://该类对外提供的服务 ->接口
		//在类定义同时完成了成员函数的定义 
		void setBrand(const char * brand){
			strcpy(_brand,brand);
		//	setPrice(5000);//在类内部可以访问私有成员函数
		}

		void setPrice(float price){
			_price = price;
		}

		void print(){
			cout << "brand: " << _brand << endl;
			cout << "price: " << _price << endl;
			printf("brand =%p\n",_brand);
			printf("price = %p\n",&_price);
		
			void (Computer::*p)(float);//成员指针
			p = &Computer::setPrice;//获取成员函数地址
			
			void (Computer::*p1)() = &Computer::print;
			printf("p = %p\n",p);
			printf("p1 = %p\n", p1); 
			//cout << "p= " << p << endl;
			//printf("setPrice = %p\n",p);
		}

	private:
		char _brand[20];//数据成员
		float _price;
};
