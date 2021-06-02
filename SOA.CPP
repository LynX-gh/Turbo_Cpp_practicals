#include<iostream.h>
#include<conio.h>
#include<stdio.h>
void main(){
	clrscr();
	int a[2][5],i,j,sum=0;
	for(i=0;i<2;i++)
		for(j=0;j<5;j++)
		{	cout<<"Enter value of row "<<i+1<<" and column "<<j+1<<" = ";
			cin>>a[i][j];
		}
	cout<<endl;
	for(i=0;i<2;i++)
	{	for(j=0;j<5;j++)
		{	cout<<a[i][j]<<'\t';
			sum+=a[i][j];
		}
		cout<<"\t\t sum = "<<sum;
		sum=0;
		cout<<endl;
	}
	for(j=0;j<5;j++)
	{	for(i=0;i<2;i++)
		{	sum+=a[i][j];
		}
		cout<<sum;
		sum=0;
		cout<<"\t";
	}
	getch();
	}
