 ///
 /// @file    overload.cc
 /// @author  Norland(norland.xw@gmail.com)
 /// @date    2017-10-25 18:38:03
 ///
 
#include <stdio.h>

//C++支持函数重载, 实现原理是:名字改编(name mangling)
//操作步骤:当函数名称相同时，根据函数参数的类型、个数、顺序来进行名字改编
int add(int a,int b){
	return a+b;
}

int add(int a,int b,int c){
	return a+b+c;
}

int add(int a,double b,float c){
	return a+b+c;
}

int main(){
	int x = 1,y = 2,z = 3;
	double j = 11.1;
	float k = 12.3;
	printf("add(x,y) = %d\n", add(x,y));
	printf("add(x,y,z) = %d\n",add(x,y,z));
	printf("add(x,j,k) = %d\n",add(x,j,k));
	return 0;
}
