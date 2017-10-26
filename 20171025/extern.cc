 ///
 /// @file    extern.cc
 /// @author  Norland(norland.xw@gmail.com)
 /// @date    2017-10-25 19:15:11
 ///
 
#include <stdio.h>


//实现C和C++的混合编程
#ifdef __cplusplus
extern "C"{//以C方式进行编译
#endif
int add(int a,int b)//.o文件可以看到没有和下面两个函数一样实行名称改编
{
	return a + b;
}
#ifdef __cplusplus
}
#endif

int add(int a,int b,int c){
	return a + b + c;
}

int add(int a, double b, float c){
	return a + b + c;
}


int main(){
	int x = 1 ,y = 2;
	double z = 12.3;
	float j = 11.1;
	printf("add(int,int)=%d\n",add(x,y));
	printf("add(int,int,int)=%d\n",add(x,y,z));
	printf("add(int,double,float)=%d\n",add(x,z,j));
	return 0;
}
