#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<ctype.h>
void main(){
	clrscr();
	int i,len;
	char str[40],ch[1];
	cout<<"Enter string : "; gets(str);
	for(i=0;i<40;i++)
	{	if(str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O'||str[i]=='U'||str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u')
		{       //str[i]=ch;
			str[i]++;
		}       //ch=str[i];
		else if(isupper(str[i]))
			str[i]= toupper(str[i]);
		else if(islower(str[i]))
			str[i]= tolower(str[i]);
		else
			str[i]=str[i];
	}
	cout<<str<<endl;
	getch();
	}
