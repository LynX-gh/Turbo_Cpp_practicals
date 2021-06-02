#include<iostream.h>
#include<conio.h>
#include<stdio.h>

void main(){
	clrscr();
	int a;
	cout<<"Enter age"<<endl;
	cin>>a;
	if (a>=18 && a<=60)
	{	cout<<"You can donate blood"<<endl;
		cout<<"Visit Red Cross "<<char(1)<<endl;
	}
	else
	{	cout<<"You cannot donate blood"<<endl;
		cout<<"Fuck off"<<endl;
	}
	getch();
	}