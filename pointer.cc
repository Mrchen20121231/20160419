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
          Point(int idx,int idy)
		  :_idx(idx)
		  ,_idy(idy)
	      {

		  }
		  Point(const Point & rhs)
		  :_idx(rhs._idx)
		  ,_idy(rhs._idy)
          {
	       cout << "const Point & rhs"  << endl; 
		  }
				  
          void print()
		  {
            cout << "(" << _idx
				 << "," << _idy
				 << ")" << endl;


		  }
     private:
		    int _idx;
			int _idy;


};
int main()
{
    Point po(1,2);
    po.print();	
    Point p2(po);
	p2.print();
}
