#include<iostream.h>
#include<conio.h>
#include<stdio.h>
void main(){
	clrscr();
	int i,j,len;
	char str[40],ch[1];
	cout<<"Enter string : "; gets(str);
	for(len=0;str[len]!='\0';len++);
	for(i=0,j=len-1;i<40;j--,i++)
	{	str[i]=ch[1];
		ch[1]=str[j];

	}
	cout<<str<<endl;
	getch();
	}
