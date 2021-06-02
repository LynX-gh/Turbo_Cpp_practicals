#include<iostream.h>
#include<conio.h>

void main() { clrscr();
	char a[];
	cin>>a;
	char *ptr=a;
	for(*ptr;*ptr!='\0';*ptr++)
		cout<<ptr<<endl;
	getch();
	}
