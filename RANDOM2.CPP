#include<conio.h>
#include<stdlib.h>
#include<iostream.h>

void main(){
	clrscr();
	int num;
	num=random(3)+2;
	char text[]="ABCDEFGHIJKLMNOPQRSTUWXYZ";
	clrscr();
	cout<<"\t\tNUM is : "<<num<<endl<<endl;
	for(int i=1;i<=num;i++)
	{	for(int j=num;j<=5;j++)
			cout<<text[j];
		cout<<endl;
	}
	cout<<endl;

	system("pause");
	}