#include<iostream.h>
#include<conio.h>
#include<stdio.h>
void main() {
	clrscr();
		 int x=1;
		 do{
			cout<<x<<"\t";
			if(x%5==0)
				break;
			x++;
		 }while(x<=50);
	getch();
	}
