 ///
 /// @file    pointer.cc
 /// @author  Mrchen20121231(392911409@qq.com)
 /// @date    2016-04-18 20:00:32
 ///
 
#include <iostream>
using std::cout;
using std::endl;
class Point
{
	public:
          Point(int idx,int idy,double & z)
		  :_idx(idx)
		  ,_idy(idy)
		  ,_rf1(_idx)
		  ,_rf2(z)
	      {

		  }
		  Point(const Point & rhs)
		  :_idx(rhs._idx)
		  ,_idy(rhs._idy)
		  ,_rf1(rhs._rf1)
		  ,_rf2(rhs._rf2)
          {
	       cout << "const Point & rhs"  << endl; 
		  }
				  
          void print()
		  {
            cout << "(" << _idx
				 << "," << _idy
				 << "," << _rf1
				 << "," << _rf2
                 << ")" << endl;


		  }
     private:
		    int _idx;
			int _idy;
            int &_rf1;
			double &_rf2;

};
int main()
{
   double dval=4.0;
   Point p1(1,2,dval);
   p1.print();

   Point p2(p1);
   p2.print();
   cout << endl;
   
  

}
