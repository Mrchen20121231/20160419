 ///
 /// @file    1.cc
 /// @author  Mrchen20121231(392911409@qq.com)
 /// @date    2016-04-19 00:20:34
 ///
 
#include <iostream>
using std::cout;
using std::endl;
class Empty{


};
class Empty1
{
     private :
		       int a;
			   char b;
			   float c;
			   double d;
			   short e[5];
			   char &f;
			   double &g;
			   static int h;


};
int main()
{
   cout << "empty1:" << sizeof(Empty) << endl;
   cout << "empty1:" << sizeof(Empty1) << endl;



}
