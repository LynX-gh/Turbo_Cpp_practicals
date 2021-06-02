#include<iostream.h>
#include<conio.h>

void main(){
	clrscr();
	int sales[3][4],total[3],qtotal[3];
	for(int i=0,j=0;i<3;i++)
	{       j=0;
		total[i]=0;
		for(;j<4;j++)
		{	cout<<"Enter the sales for employee "<<i+1<<" of quarter"<<j+1<<" = ";
			cin>>sales[i][j];
			cout<<endl;
			total[i]+=sales[i][j];
		}
	}
	for(j=0;j<4;j++)
	{       i=0;
		qtotal[j]=0;
		for(;i<3;i++)
		{	qtotal[j]+=sales[i][j];
		}
	}
		clrscr();
	cout<<"The sales of the salesperson are"<<endl;
	cout<<"SNo.\t|Qtr 1|\t\t|Qtr 2|\t\t|Qtr 3|\t\t|Qtr 4|\t\t|Total|\n"<<endl;
	for(i=0,j=0;i<3;i++)
	{	j=0;
		cout<<i<<'\t';
		for(;j<4;j++)
		{	cout<<"  "<<sales[i][j]<<"\t\t";
		}
		cout<<total[i]<<endl;
		cout<<endl;
	}
	cout<<"\nTotal\t";
	for(i=0;i<4;i++)
		cout<<"  "<<qtotal[i]<<"\t\t";
	cout<<total[1]+total[2]+total[0];
	getch();
	}
