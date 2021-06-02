#include<conio.h>
#include<iostream.h>
class base1{
	protected:
		int a;
	public:
		base1(int x){	a=x;
		cout<<"Constructing base1 \n";	}
		~base1()	{	cout<<"Destructing base1 \n";}
		};
class base2{
	protected:
		int b;
	public:
		base2(){cout<<"Default constructor ";}
		base2(int y)
		{	b=y;
			cout<<"Constructing base2 \n";	}
		~base2()
		{	cout<<"Destructing base2 \n";	}
	};
class derived : public base1, public base2
	{	int c;
		public:
			derived(int i,int j, int k=60)	: base1(i), base2(j)
			{	c=k;
				cout<<"constructing derived \n";
			};
			~derived()
			{	cout<<"Destructing derived \n";
			}
			void show(){
				cout<<"\n1. "<<a<<" 2. "<<b<<" 3."<<c<<endl;
			}
		};
int main(){
	clrscr();
	derived ob(10,20,30);
	base2 a;
	derived ob2(ob);
	ob.show();
	ob2.show();
	getch();
	return 0;
	}
