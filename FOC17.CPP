#include<iostream.h>
#include<conio.h>
#include<stdio.h>
void main() {
	clrscr();
		int ctr,no,flag=1;

		for(no=2;no<=1000;no++)
		{	for(flag=1,ctr=2;ctr<no;ctr++)
			if(no%ctr==0)
			{	flag=0;
				break;
			}
			if(flag=1)
				cout<<no<<'\t';
		}
	getch();
	}
