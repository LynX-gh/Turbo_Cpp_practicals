#include<fstream.h>
#include<stdio.h>
#include<conio.h>

class client{
		int cid;
		char name[20], phone[10];
	public:
		void getdata();
		void display();
	};
void client::getdata(){
	cout<<"Enter cid, name and phone of client : ";
	cin>>cid; gets(name); cin>>phone;
}
void client :: display(){
	cout<<cid<<'\t'<<name<<'\t'<<phone<<endl;
}
void main(){
	clrscr();
	fstream finout;client c;
	finout.open("Client.dat",ios::in|ios::out|ios::binary|ios::app);
	char ch='y';
	while(ch=='y'){
		c.getdata();
		finout.write((char *)&c,sizeof(c));
		cout<<"Want to continue??";
		cin>>ch;
	}
	int Ioc=finout.tellg()/sizeof(c);
	cout<<Ioc<<endl;
	finout.close();
	getch();

	}