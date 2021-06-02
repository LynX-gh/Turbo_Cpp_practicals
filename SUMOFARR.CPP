#include<iostream.h>
#include<conio.h>
#include<stdio.h>
void main(){
	clrscr();
	int a[2][5],i,j,sum;
	for(i=0;i<2;i++)
		for(j=0;j<5;j++)
		{	cout<<"Enter value of row "<<i+1<<" and column "<<j+1<<" = ";
			cin>>a[i][j];
		}
	cout<<endl;
	for(i=0,sum=0;i<2;i++)
	{	for(j=0;j<5;j++)
		{	cout<<a[i][j]<<'\t';
			sum+=a[i][j];
		}
		cout<<"\t\t sum = "<<sum;
		cout<<endl;
	}
	cout<<endl<<endl<<"Transpose of the series is"<<endl;
	for(j=0,sum=0;j<5;j++)
	{	for(i=0;i<2;i++)
		{	cout<<a[i][j]<<'\t';
			sum+=a[i][j];
		}
		cout<<"\t\t sum = "<<sum;
		cout<<endl;
	}
	getch();
	}
