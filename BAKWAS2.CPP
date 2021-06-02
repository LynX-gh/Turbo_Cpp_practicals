#include<iostream.h>
#include<conio.h>
#include<iomanip.h>
#include<string.h>
#include<ctype.h>
#include<stdio.h>

void contents(char ch)
{       int dig=0,alp=0,spa=0,oth=0;
	for(int i=0;i<='\0';i++)
	{	if(isdigit(ch[i]))
			dig+=1;
		else if(isalpha(ch[i]))
			alp+=1;
		else if(isspace(ch[i]))
			spa+=1;
		else
			oth+=1;
	}
	cout<<"The number of digits = "<<dig<<"The no of alphabets = "<<alp<<"The no of spaces = "<<spa<<"Special Characters = "<<oth;
	getch();
}
void main(){
	char ch[20];
	cout<<"Enter the string you want to calculate for ; "<<endl;
	gets(ch,20);
	contents(ch);
	getch();
	}