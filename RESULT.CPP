
#include<iostream.h>
#include<conio.h>

void main() {
	clrscr();
	float p,c,m,cs,eng,tot,per;
	cout<<"Enter marks obtained in the order p,c,m,cs,eng";
	cin>>p>>c>>m>>cs>>eng;
	tot=p+c+m+cs+eng;
	per=tot/5;
	clrscr();
		cout<<"--------------------------------------------------------------------------------"<<endl;
		cout<<"\t\t\t Report Card of Tutions  "<<endl;
		cout<<"--------------------------------------------------------------------------------"<<endl;
		cout<<"\t\t\t Physics:\t\t" <<p<<endl;
		cout<<"\t\t\t Chemistry:\t\t" <<c<<endl;
		cout<<"\t\t\t Math:\t\t\t"<<m<<endl;
		cout<<"\t\t\t Comp. Sci.:\t\t"<<cs<<endl;
		cout<<"\t\t\t English:\t\t"<<eng<<endl;
		cout<<"\n\n--------------------------------------------------------------------------------"<<endl;
		cout<<"\t\w\t Total   :"<<tot<< "\n\t\t Total Percentage  : "<<per<<endl;
	getch();
	}
