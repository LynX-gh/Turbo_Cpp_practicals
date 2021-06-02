#include<iostream.h>
#include<conio.h>
#include<stdio.h>

class employe{
		int pid;
		char name[20];
		float basic;
	public:
		void getdata(){
			cout<<"Enter Pid";	cin>>pid;
			cout<<"Enter Name";	gets(name);
			cout<<"Enter Basic";	cin>>basic;
		}
		void display();
	};
	void employe :: display(){
		cout<<pid<<'\t'<<name<<'\t'<<basic<<endl;}
	void main(){
		clrscr();
		employe e;
		e.getdata();
		e.display();
		getch();
		}