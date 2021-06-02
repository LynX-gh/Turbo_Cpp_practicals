#include<conio.h>
#include<iostream.h>
#include<process.h>
struct emp{
	char name[20];
	int no;
	float obal,cbal;
	};
	emp e[3];

void getdata(){
	for(int i=0;i<3;i++)
	{       clrscr();
		cout<<"Enter the name of the account holder : "<<endl;
		cin>>e[i].name;
		cout<<"Enter the account no. : "<<endl;
		cin>>e[i].no;
		cout<<"Enter the opening balance : "<<endl;
		cin>>e[i].obal;
		e[i].cbal=e[i].obal;
	}
	}
void display(){
	clrscr();
	cout<<"Enter the number of the account to display"<<endl;
	float acc;
	cin>>acc;
	for(int flag,i=0;i<3;i++)
	{	if(acc==e[i].no)
		{	cout<<"\n Name : "<<e[i].name<<"\n Account no :"<<e[i].no<<"\n Opening Balance : "<<e[i].obal<<"\n Closing Balance : "<<e[i].cbal<<endl;
			flag=1;
			break;
		}
		else if(acc==0)
		{	for(int i=0;i<3;i++)
			{
				cout<<" Account of person : "<<i+1;
				cout<<"\n Name :\t"<<e[i].name<<"\n Account no :\t"<<e[i].no<<"\n Opening Balance :\t"<<e[i].obal<<"\n Closing Balance :\t"<<e[i].cbal<<endl;
			}
			flag=1;
			break;
		}
	}
	if(flag==1)
		cout<<" ";
	else
		cout<<"Enter the correct account no.";
	getch();
	}

void deposit(){
	clrscr();
	cout<<"Enter the number of the account to deposit money";
	int acc;
	float mon;
	cin>>acc;
	for(int flag,i=0;i<3;i++)
	{	if(acc==e[i].no)
		{	cout<<"Enter the amount of money to be deposited in the account : "<<endl;
			cin>>mon;
			e[i].cbal=e[i].obal+mon;
			flag=1;
			cout<<"\n New balance is : "<<e[i].cbal;
			break;
		}
	}
	if(flag==1)
		cout<<" ";
	else
		cout<<"Enter the correct account no.";
	getch();
	}
void withdraw(){
	clrscr();
	cout<<"Enter the number of the account to withdraw money";
	int acc;
	float mon;
	cin>>acc;
	for(int flag,i=0;i<3;i++)
	{	if(acc==e[i].no)
		{	cout<<"Enter the amount of money to be withdrawn from the account : "<<endl;
			cin>>mon;
			e[i].cbal=e[i].obal-mon;
			cout<<"\n New balance is : "<<e[i].cbal;
			flag=1;
			break;
		}
	}
	if(flag==1)
		cout<<" ";
	else
		cout<<"Enter the correct account no.";
	getch();
	}
void main(){
	clrscr();
	getdata();
	clrscr();
	int choice,a=6;
	for(;a>5&&a<50;a++)
	{       clrscr();
		cout<<"What do you want to do???\n1.Display\n2.Withdraw\n3.Deposit\n4.Exit"<<endl;
		cin>>choice;
		switch(choice)
		{	case 1: display(); break;
			case 2: withdraw(); break;
			case 3: deposit(); break;
			case 4: cout<<"\n\n\n\n\t\tThank You...."; a=4; break;
			default : cout<<"Enter a correct choice"; break;
		}
	}
	getch();
}