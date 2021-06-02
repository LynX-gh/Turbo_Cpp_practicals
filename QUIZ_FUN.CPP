#include<iostream.h>
#include<conio.h>
#include<iomanip.h>

int tot=0,a;
void Q1();
void Q2();
void Q3();
void Q4();
void Q5();

void main(){
	clrscr();
	cout<<"The first question is...."<<endl;
	Q1();
	getch();
	cout<<"The Second question is...."<<endl;
	Q2();
	getch();
	cout<<"The Third question is...."<<endl;
	//Q3;
	//getch();
	//cout<<"The Fouth question is...."<<endl;
	//Q4;
	//getch();
	//cout<<"The Fifth question is...."<<endl;
	//Q5;
	//getch();
	cout<<"\n\n\n\t The Total Score is  =  "<<tot;
	getch();
	}

void Q1(){
	clrscr();
	cout<<"Who is the father of the modern computer\n"<<endl;
	cout<<"1. Prince Charles \n 2. John Van Neuman \n 3. Charles Babbage \n 4. Lalit Aditya"<<endl;
	cout<<"Enter the correct choice : ";
	cin>>a;
	if(a==2)
	{	cout<<"The correct answer........ ";
		tot+=10;
	}
	else
	{       cout<<"The wrong answer....";
		tot+=-20;
	}
}
void Q2(){
	clrscr();
	cout<<"Who was the first to make organic compund in a Laboratory\n"<<endl;
	cout<<"1. Wohler \n 2. Haber \n 3. Madam Curie \n 4. Stephen Hawking"<<endl;
	cout<<"Enter the correct choice : ";
	cin>>a;
	if(a==1)
	{	cout<<"The correct answer........ ";
		tot+=10;
	}
	else
	{       cout<<"The wrong answer....";
		tot+=-20;
	}
}