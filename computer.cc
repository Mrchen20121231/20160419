 ///
 /// @file    computer.cc
 /// @author  Mrchen20121231(392911409@qq.com)
 /// @date    2016-04-18 00:39:49
 ///
#include <cstring> 
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
using std::cout;
using std::cin;
using std::endl;
class Computer
{
	public:
		  Computer()
		  {
             cout << "Computer()" << endl;
		  }
		  Computer(const Computer & rhs)
           :_price(rhs._price)//深拷贝
          {
            cout << "Computer(const char & rhs)" << endl;
            _brand = new char[strlen(rhs._brand)+1];
            strcpy(_brand,rhs._brand);
          }
		  Computer & operator=(const Computer & rhs) 
	      {
			   cout << "Computer operator" << endl;
                  if(this==& rhs)//1.自复制
				  {
                      cout << "自复制" << endl;
                      return *this;

				  }

			delete [] _brand; //2.释放前内存空间
    		_brand = new char[strlen(rhs._brand)+1];//赋值
            strcpy(_brand,rhs._brand);
			_price=rhs._price;
			return *this;
					   
		  }

		  ~Computer()
		  {
            cout << "~Computer()" << endl;
              if(_brand)
               {
                 delete [] _brand;
               }
            
		  }
		  void print()
          {
             cout << "品牌=" << _brand << endl;
	         cout << "价格=" << _price << endl;
			 cout << "&_brand=%p"<<&_brand << endl;
          }
		  void  setBrand(const char * brand);
		  void  setPrice(float price);
    private:
		   char * _brand;
		   float _price;
};
void Computer::setBrand(const char * brand)
{
	 _brand=new char[strlen(brand)+1];
     strcpy(_brand,brand);             
}
void Computer::setPrice(float price)
{
      _price=price;
}
int main()
{
    Computer pc;
	pc.setBrand("thinkpad");
	pc.setPrice(7999);
	pc.print();
	Computer p2=pc;//复制析构函数
	p2.print();
	Computer p3(pc);
	p3.print();
    cout << endl;
	Computer p4;
	p4=pc; //赋值析构函数
	p4.print();
    	

}


