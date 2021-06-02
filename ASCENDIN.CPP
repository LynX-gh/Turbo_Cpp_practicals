#include<iostream.h>
#include<conio.h>

void main(){
	clrscr();
	long a[10],temp,i,j;
	cout<<"Enter any 10 numbers";
	for(i=0;i<10;i++)
		cin>>a[i];
	for(i=0;i<9;i++)
		{	for(j=i;j<10;j++)
			if(a[i]>a[j])
			{	a[j]=temp;
				a[i]=a[j];
				temp=a[i];
			}
	}
	cout<<"The aray in ascending order is";
	for(i=0;i<10;i++)
		cout<<a[i]<<"\n"
		;
	getch();
	}
