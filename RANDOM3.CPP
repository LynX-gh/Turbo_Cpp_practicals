#include<conio.h>
#include<iostream.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main(){
	clrscr();
	char name[10][20];
	int n=0;
	cout<<"Enter the name of 10 students"<<endl;
	for(int i=0;i<10;i++)
	{	gets(name[i]);
	}
	randomize();
	cout<<"\n\n\t The output is ";
	for(i=0;i<3;i++)
	{       n=random(9);
		cout<<"\n\t\t\t: "<<name[n];
		n=0;
	}
	getch();
	}