#include<conio.h>
#include<iostream.h>
#include<stdio.h>

struct lib{
	int id;
	char name[20],auth[20];
	float cost;
	};
lib s[4];

void getdata(){
	for(int i=0;i<4;i++)
	{	clrscr();
		cout<<"Enter the id for the book :";
		cin>>s[i].id;
		cout<<"Enter the name of the book :";
		gets(s[i].name);
		cout<<"Enter the name of the author :";
		gets(s[i].auth);
		cout<<"Enter the cost of the book :";
		cin>>s[i].cost;
	}}

void display(){
	for(int i=0;i<4;i++){
	cout<<"Id	:"<<s[i].id<<endl;
	cout<<"Name	:"<<s[i].name<<endl;
	cout<<"Auth	:"<<s[i].auth<<endl;
	cout<<"Cost	:"<<s[i].cost<<endl;
	cout<<"\n\n";
	}}


void main(){
	clrscr();
	getdata();
	display();
	getch();
	}
