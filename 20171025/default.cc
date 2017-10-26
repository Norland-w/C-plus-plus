 ///
 /// @file    default.cc
 /// @author  Norland(norland.xw@gmail.com)
 /// @date    2017-10-25 18:55:51
 ///
 
#include <iostream>
using std::cout;
using std::endl;


//默认参数使用时，要避免产生二义性
int add(int a,int b = 0){
	return a+b;
}


//设置默认参数时，只能从右到左的顺序进行设置
int add(int a,int b,int c = 0){
	return a+b+c;
}

int main(){
	int x = 1,y = 2,z = 3;
	cout << add(x,y,z) << endl;
	cout << add(x) << endl;
	return 0;
}
