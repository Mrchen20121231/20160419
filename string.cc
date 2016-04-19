 ///
 /// @file    string.cc
 /// @author  Mrchen20121231(392911409@qq.com)
 /// @date    2016-04-19 05:17:29
 ///
 
#include <iostream>
#include <stdio.h>
#include <string.h>
using std::cout;
using std::endl;
class String
{
  public :
	      String()
		  {
              cout << "String()" << endl;
		  }

		  String(const char *pstr)
		  {
               cout << "const char *pstr" << endl;
               pStr_=new char[strlen(pstr)+1];
			   strcpy(pStr_,pstr);
		  }
          String(const String & rhs)
		  :pStr_(rhs.pStr_)
		  {
			   cout << "const String & rhs" << endl;
               pStr_=new char[strlen(pStr_)+1];
			   strcpy(pStr_,rhs.pStr_);
                   

		  }
		  String & operator=(const String & rhs)
		  {
                if(this==&rhs)
				{
                    cout << "自复制" << endl;
					return *this;
				}
				delete [] pStr_;//释放之前的内存空间
               pStr_=new char[strlen(pStr_)+1];//赋值
			   strcpy(pStr_,rhs.pStr_);
			   return *this;

    
		  }
		  ~String()
		  {
              cout << "~String()" << endl;
			  delete [] pStr_;
		  }
		  void print()
		  {
              cout << "pStr_=" << pStr_ << endl;
		  }
   private:
		   char *pStr_;

};
int main()
{
    String str1;
	String str2 ="Hello,world";
	String str3 ="wangdao";
	str2 = str3;
	String str4 = str3;

	str1.print();
	str2.print();
    str3.print();
	str4.print();
   

}




