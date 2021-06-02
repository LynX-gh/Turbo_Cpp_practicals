#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
void main() {
	clrscr();
		float b=1;
		int x,a,fact,n;
		cout<<"Enter two numbers x and n"<<endl;
		cin>>x>>n;
		for(a=n;a>0;a--)
		{	if(a%2==0)
			{	for( ;fact<=a;a--)
				fact=fact*a;
			}
			else
				break;
			b+=pow(x,n)/fact;
		}
		cout<<"The answer is : "<<b;
	getch();
}
