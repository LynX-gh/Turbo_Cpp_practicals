#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<stdio.h>
void main()
{	clrscr();
	long a,b,c,flag=0;
	cin>>a;
	b=sqrt(a);
	for(c=b;c>1;c--)
	{	if(b%c==0)
			flag=1;
		else
			flag=0;
	}
	cout<<b<<"\n";
	(flag==0)? cout<<"Sqrt of "<<a<<" is prime" : cout<<"Sqrt of "<<a<<" is not prime";
	getch();
}
