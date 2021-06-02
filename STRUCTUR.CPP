#include<iostream.h>
#include<conio.h>
#include<iomanip.h>
#include<string.h>
#include<ctype.h>
#include<stdio.h>

struct stu{
	int rno;
	char name[20];
	float mks[3];
	};
void getdata(stu &s)
{	cout<<"Enter rno, name and marks for 3 subjects : ";
	cin>>s.rno;
	gets(s.name);
	for(int i=0;i<3;i++)
		cin>>s.mks[i];
	clrscr();
}
void display(stu &s)
{	cout<<"Rno : "<<s.rno<<" Name : "<<s.name<<" Phy : "<<s.mks[0]<<"  Maths : "<<s.mks[1]<<" Chem : "<<s.mks[2]<<endl;}

void main(){
	clrscr();
	stu s1,s2;
	getdata(s1);
	getdata(s2);
	display(s1);
	display(s2);
	getch();
	}