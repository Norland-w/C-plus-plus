///
/// @file    String.cc
/// @author  Norland(norland.xw@gmail.com)
/// @date    2017-10-26 08:15:58
///

#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class String
{
	public:
		String()//初始化构造函数
		{
			_pstr = new char [1];
			*_pstr = '\0';
		}

		String(const char *pstr)//通用构造函数
		{
			if(NULL == pstr)
			{
				_pstr = new char [1];
				*_pstr = '\0';
			}
			else
			{
				int len = strlen(pstr);
				_pstr = new char [len + 1];
				strcpy(_pstr, pstr);
			}
		}
		String(const String & rhs)//复制构造函数
		{
			int len = strlen(rhs._pstr);
			_pstr = new char [len + 1];
			strcpy(_pstr, rhs._pstr);
		}
		//String & operator=(const String & rhs);
		~String()//析构函数
		{
			delete [] _pstr;
		}

		void print()//输出函数
		{
			cout << "str = " << _pstr << endl;
		}

	private:
		char * _pstr;
};

int main(void)
{
	String str1;
	str1.print();

	String str2 = "Hello,world!";
	String str3("I am norland!");

	str2.print();		
	str3.print();	

	String str4 = str3;
	str4.print();

	str4 = str2;
	str4.print();

	return 0;
}
