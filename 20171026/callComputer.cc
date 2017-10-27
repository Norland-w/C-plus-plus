 ///
 /// @file    callComputer.cc
 /// @author  Norland(norland.xw@gmail.com)
 /// @date    2017-10-27 16:03:30
 ///

#include "Computer1.h"
#include "Computer.h"
#include <iostream>
using std::cout;
using std::endl;

int main()
{

	Computer com;
	com.setBrand("Mac");
	com.setPrice(10000);
	com.print();
	
	cout << "----------" << endl;

	Computer1 com1;
	com1.setBrand("lenovo");
	com1.setPrice(5000);
	com1.print();
	return 0;
}
