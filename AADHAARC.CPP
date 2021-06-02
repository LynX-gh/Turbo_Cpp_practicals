#include<conio.h>
#include<iostream.h>
#include<stdio.h>

struct voter{
	int id,age;
	char name[20],adress[40];
	};
	voter v[5];

void getdata(){
	for(int i=0;i<5;i++)
	{       clrscr();
		cout<<"Enter the age of the candidate : "<<endl;
		cin>>v[i].age;
		if(v[i].age>=18)
		{	cout<<"Enter the name if the cadidte : "<<endl;
			gets(v[i].name);
			cout<<"Enter the adress of the candidate : "<<endl;
			gets(v[i].adress);
			cout<<"Enter the voter id : "<<endl;
			cin>>v[i].id;
		}
		else
		{	cout<<"You are not eligibe for voting";
			i-=1;
		}
	}

void display(){
	for(int i=0;i<5;i++)
	{	cout<<"\n\nVoter card of the person : "<<v[i].name<<" is : "<<endl;
		cout<<"Voter id :\t"<<v[i].id<<endl;
		cout<<"Adress :\t"<<v[i].adress<<endl;
		cout<<"Age :\t"<<v[i].age<<endl;
	}
	}
void search(int a){
	int flag;
	for(int i=0;i<5;i++)
	{	if(v[i].id==a)
		{	cout<<"Voter card of the person : "<<v[i].name<<" is : "<<endl;
			cout<<"Voter id : "<<v[i].id<<endl;
			cout<<"Adress : "<<v[i].adress<<endl;
			cout<<"Age : "<<v[i].age<<endl;
			break;
		}
		else
			flag=1;
	}
	if(flag==1)
		cout<<"Chutiya mat bana bsdk";
	}
void main(){
	clrscr();
	do