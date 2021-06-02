#include<iostream.h>
#include<conio.h>
#include<stdio.h>
void main(){
	clrscr();
	int i,len;
	char str[40];
	cout<<"Enter string : "; gets(str);
	for(i=0;i<40;i++)
	{	if(str[i]=='\ ')
			str[i]='-';
	}
	cout<<str<<endl;
	getch();
	}
