#include<conio.h>
#include<iostream.h>
#include<stdio.h>

struct stu{
	int rno;
	char name[20];
	float mks[5];
	};
stu s;

void main(){
	clrscr;
	cout<<"Enter the rno for student :";
	cin>>s.rno;
	cout<<"Enter the name of thae student :";
	gets(s.name);
	for(int i=0;i<5;i++)
	{	cout<<"Enter the marks for "<<i+1<<" subject :";
		cin>>s.mks[i];
	}
	clrscr();
	cout<<"Rno	:"<<s.rno<<endl;
	cout<<"Name	;"<<s.name<<endl;
	for(i=0;i<5;i++)
	{cout<<"Subject  :  "<<i+1<<"	;  "<<s.mks[i]<<endl;}
	getch();
	}

