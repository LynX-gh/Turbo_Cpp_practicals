#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<iostream.h>

void main(){
	clrscr();
	int t;
	float h,m;
	cout<<"Enter any amount of minutes"<<endl;
	cin>>t;
	h=t/60;
	m=t%60;
	clrscr();
	cout<<"Your time in hours and minutes is :  "<<h<<" hours "<<m<<" minutes"<<endl;
	getch();	}