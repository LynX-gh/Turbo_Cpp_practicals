#include<iostream.h>
#include<conio.h>
#include<stdio.h>
void main() {
	clrscr();
		 for(int i=1;i<=100;i++)
		 {
			if(i%5==0)
				continue;
			cout<<i<<"   ";
		 }
	getch();
	}
