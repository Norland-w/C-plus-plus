 ///
 /// @file    string.cc
 /// @author  Norland(norland.xw@gmail.com)
 /// @date    2017-10-25 19:45:31
 ///

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <string>//C++头文件没有.h
using std::cout;
using std::endl;
using std::string;

//C字符串操作
int Cstring()
{
	char str[] = "hello world!";
	const char * pstr = "home";

	//C字符串拼接
	int size = strlen(str) + strlen(pstr) + 1;
	char str1[size];
	strcpy(str1,str);
	strcat(str1,pstr);
	printf("str = %s\n",str);
	printf("pstr = %s\n",pstr);
	printf("str1 = %s\n",str1);

	//C查找子串
	const char *psub = "world";
	char *p1 = strstr(str1 , psub);
	printf("p1 = %s\n",p1);

	//C截取子串
	size = strlen(psub) + 1;
	char * p2 = (char *)malloc(size);
	memset(p2, 0, size);
	strcpy(p2, psub);
	printf("p2 = %s\n",p2);
	free(p2);
	return 0;
}


//C++字符串操作
int Cppstring()
{
	string s1 = "hello world!";//C++字符串定义
	string s2 = "I am norland";
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;

	//遍历字符串每个字符元素
	for(size_t i = 0; i < s1.size(); i++)
	{
		cout << s1[i] << endl;
	}

	//字符串拼接
	string s3 = s1 + s2 + "home";//直接+
	cout << "s3 = " << s3 << endl;
	string s4 = "round";
	s4.append(" and round");//通过append函数追加
	cout << "s4 = " << s4 << endl;

	//字符串查找,截取子串
	string subs = "world";
	size_t pos = s3.find(subs);
	string s5 = s3.substr(pos,s3.size());
	//C++求字符串长度.size()和.length()都可以用
	//size() 一般用作返回容器大小的方法
	//length() 一般用作返回一个序列的长度
	cout << "s5 = " << s5 <<endl;
	
	//将C++风格字符串转换成C风格字符串
	const char *pC = s4.c_str();
	printf("pC = %s\n", pC);
	return 0;
}

int main()
{
	Cstring();
	Cppstring();
	return 0;
}

