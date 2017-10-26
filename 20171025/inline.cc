 ///
 /// @file    inline.cc
 /// @author  Norland(norland.xw@gmail.com)
 /// @date    2017-10-25 19:00:54
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//带参数的宏定义: 简单的字符串的替换
#define Max(a,b) ((a)>(b)?(a):(b))


//内联函数: 调用时会直接用函数体里面的语句替换函数
////在效果上，是与带参数的宏定义相同
inline int max(int a,int b){
	return a > b ? a : b;
}

int main(){
	int x = 1,y = 2;
	cout << Max(x,y) << endl;
	cout << max(x,y) << endl;
	return 0;
}
