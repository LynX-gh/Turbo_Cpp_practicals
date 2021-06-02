#include<iostream.h>
#include<conio.h>
#include<stdio.h>
void main() {
	clrscr();
		int n,a,b;
		cout<<"Enter any number : ";
		cin>>n;
		for(a=n-1;a<n;a--)
		{     if(a%n==0)
			cout<<"The no. is a composite no.";
		      else
			cout<<"The no. is a prime no.";
		      }
	getch();
	}
