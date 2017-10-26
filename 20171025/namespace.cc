///
/// @file    namespace.cc
/// @author  Norland(norland.xw@gmail.com)
/// @date    2017-10-25 10:27:25
///
//#include "func.h"//自定义头文件一般放最前面(搜索路径)
#include <stdio.h>//C的头文件一般放在C++头文件前面
#include <iostream>
using std::cout;
using std::endl;//using 声明机制

//1.using namespace std;      //using编译指令
//2.using std::cout;          //using声明机制
//3.std::cout<<a<<std::endl;  //作用域限定符


int num=10;

namespace a{
	int num=20;
	void displaya(int num){
		cout << "display num= " << num <<endl;
		cout << "a num= " << a::num <<endl;
		cout << "num= " << ::num<<endl;//匿名空间::(全局变量)
		::printf("I am C Anonymous entity\n");//匿名空间::(C标准输出匿名实体)
	}
}

namespace b{
	using std::cin;//局部范围可见性
	int num=30;
	void displayb()
	{
		a::displaya(num);
	}
}

//using a::num;//声明不当，二义性
//using b::num;

int main()
{
	b::displayb();//作用域限定符

	return 0;
}




