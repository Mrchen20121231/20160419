 ///
 /// @file    singleton.cc
 /// @author  Mrchen20121231(392911409@qq.com)
 /// @date    2016-04-19 02:11:43
 ///
 
#include <iostream>
#include <stdio.h>
#include "afxmt.h"
using std::cout;
using std::endl;
class MutexLock
{
  public:
	     MutexLock(CCriticalSection cs):mutex_cs(cs)
		 {
            mutex_cs.Lock();

		 }
		 ~MutexLock()

		 {

               mutex_cs.Unlock();
		 }
   private:
		  CCriticalSertion  mutex_cs;
};


class Singleton
{
   private:
	       Singleton()//构造函数私有
		   {

		   }
		   Singleton(const Singleton &);
		   Singleton & operator=(const Singleton &);
   
   public:
           static Singleton * pInstance;
		   static CCriticalSection cs;
		   static Singleton * Instantialize()
		   {
			    if(pInstance==NULL)
				{
					MutexLock lock(cs);
                if(pInstance==NULL)//如果对象为空则创建
					{
                            pInstance=new Singleton();//创建一个堆对象
					}
				}
				return pInstance;//返回指针类型的对象
		   }


};
 Singleton * Singleton:: pInstance=NULL;
int main()
{
      Singleton * s1=Singleton::GetInstance();
      Singleton * s2=Singleton::GetInstance();
	  printf("s1=%p\n",s1);
	  printf("s2=%p\n",s2);
}


