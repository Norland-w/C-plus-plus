///
/// @file    namespace.cc
/// @author  Norland(norland.xw@gmail.com)
/// @date    2017-10-25 10:27:25
///

#include <iostream>
using std::cout;
using std::endl;//using 声明机制

int num=10;

namespace a{
	int num=20;
	void display(int num){
		cout << "display num= " << num <<endl;
		cout << "a num= " << a::num <<endl;
		cout << "num= " << ::num<<endl;
	}
}

int main()
{
	a::display(30);
	return 0;
}




