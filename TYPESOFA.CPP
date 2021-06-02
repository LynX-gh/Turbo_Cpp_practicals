#include<iostream.h>
#include<conio.h>
#include<stdio.h>

void main(){
	clrscr();
	char ch;
	cout<<"Enter Charachter:    ";
	ch=getchar();
	if ((ch>='A' && ch<='Z') || (ch>='a' && ch<='z') )
		if (ch>='A' && ch<='Z')
			cout<<"Upper Case Alphabet"<<endl;
		else
			cout<<"Lower case Alphabet"<<endl;
	else if (ch>='0' && ch<='9')
		cout<<"NUmber....."<<endl;
	else if (ch==' ')
		cout<<"Space   "<<endl;
	else
		cout<<"Special Charachter.....";
	getch();
	}