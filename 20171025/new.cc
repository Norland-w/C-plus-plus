 ///
 /// @file    new.cc
 /// @author  Norland(norland.xw@gmail.com)
 /// @date    2017-10-25 22:26:15
 ///

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using std::cout;
using std::endl;

//malloc/free 与 new/delete 区别
//1.malloc/free是库函数,而new/delete是表达式;
//2.malloc只开辟空间,不会进行初始化;
//new不仅开辟空间,还进行初始化.
int test()
{
	int * pa =(int *)malloc(sizeof(int));
	::memset(pa,0,sizeof(int));
	*pa=10;
	cout << *pa << endl;

	int * pb = (int *)::malloc(10 * sizeof(int));//malloc 空间,只开辟了空间而不初始化
	::memset(pb, 0, sizeof(int) * 10);//初始化空间
	for(int i = 0; i < 10; i++)//循环赋值打印
	{
		pb[i] = i;
		cout << pb[i] << " ";
	}
	cout << endl;
//	free(pb);//malloc 与 free 对应
	return 0;
}


int main()
{
	test();
	int * pa = new int(10);//new创建空间,并初始化为10
	cout << *pa << endl;
	delete pa;//delete释放空间

	int * pb = new int[10];//new开辟了空间,且全部初始化为0
	for(int i = 0; i < 10; i++)
	{
//		pb[i] = i;
		cout << pb[i] << " ";
	}
	cout << endl;
	delete []pb;
	return 0;
}

