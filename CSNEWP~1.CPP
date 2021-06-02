#include<conio.h>
#include<fstream.h>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>

class movie
{	private:
		int mid,mcost;
		char mname[25];
	public:
		movie(){};
		void insert()
		{	cout<<"Enter Movie code : ";
			cin>>mid;
			cout<<endl<<"Enter Movie name : ";
			gets(mname);
			cout<<endl<<"Enter Price of Ticket : ";
			cin>>mcost;
		};
		void display()
		{      	cout<<"\nMovie ID : "<<mid<<endl;
			cout<<"Movie name : "<<mname<<endl;
			cout<<"Price : "<<mcost<<endl;
		};
		int getmid()
		{	return mid;
		};
		int getcost(){
			return mcost;
		};
		~movie(){};
	};

int seat();

class ticket:public movie
{       int Tamt,TicketNo,StartNO,Tcost; //Start no - Ticket no. of starting ticket, TicketNo - No of tickets bought, Tcost - Cost of 1 ticket
	float Tno;
	int TotalTicket[]; //TotalTickets ke display mei ek for loop chala dena for(int i=Startno,i<=TicketNo,i++){cout<<"Ticket Numbers is/are :"<<i;}
	public:
		void insert(int a,int b,int c,float d){
			a=Tcost;
			b=TicketNo;
			c=StartNO;
			d=Tno;
			}
		void display();
		int retTno(){
			return Tno;
		}
		void Ticketamt(int a,int b,int c){}; //TicketNo,StartNO,Tcost
};

void admin(){
    while(1){
	clrscr();
	movie m;
	char adch='n';
	int choice;
	cout<<"\n\nHello Admin Welcome \n\nSelect what you would like to do :- \n\t\t1.Create new movie \n\t\t2.Delete existing movie \n\t\t3.View Movie List \n\t\t4.Exit";
	cin>>choice;
	switch(choice){
		case 1:	fstream fout1("Movie.dat",ios::app|ios::binary);
			m.insert();
			system("Pause");
			clrscr();
			cout<<"\nAre you sure you want to add this movie..??\n";
			m.display();
			cin>>adch;
			clrscr();
			if(adch=='y'||adch=='Y')
			{	fout1.write((char*)&m,sizeof(m));
				delay(3);
				cout<<"List succesfully updated....";
				m.display();
			}
			else
				delay(3);
				cout<<"Stopped Succsfully";
			system("Pause");
			fout1.close();
			break;
		case 2: clrscr();
			int mn;
			ifstream fin2("Movie.dat",ios::in||ios::binary);
			ofstream fout2("temp.dat",ios::out||ios::binary);
			cout<<"Enter Movie No. to delete : "<<endl;
			cin>>mn;
			while(!fin2.eof())
			{	fin2.read((char*)&m,sizeof(m));
				if(m.getmid()==mn)
				{       delay(1);
					cout<<"Are you sure you want to delete this movie??"<<endl;
					cin>>adch;
					{	if(adch=='n'||adch=='N')
						{	fout2.write((char*)&m,sizeof(m));}
					}
				}
				else fout2.write((char*)&m,sizeof(m));
			}
			fin2.close();
			fout2.close();
			remove("Movie.dat");
			rename("temp.dat","Movie.dat");
			cout<<"Movie Deleted";
			system("Pause");
			break;
		case 3: clrscr();
			ifstream fin3("Movie.dat",ios::in||ios::binary);
			fin3.seekg(0);
			while(!(fin3.eof()))
			{	fin3.read((char*)&m,sizeof(m));
				m.display();
			}
			fin3.close();
			system("Pause");
			break;
		case 4: exit(0);
			break;
		default: cout<<"Wrong choice selected please enter correct choice";
			 cin.clear();
			 getch();
	};
    };
}

void user(){
   while(1){
	clrscr();
	int choice;
	cout<<"Welcome to LL Cinema \n\nWhat would you lke to do?? \n\n\t1.View Current Movies\n\n\t2.Book Ticket\n\n\t3.View Booking\n\n\t4.Cancel Booking\n\n\t5.Exit"<<endl;
	cin>>choice;
	ticket t;
	movie m;
	char adch='n';
	switch(choice){
		case 1: clrscr();
			ifstream fin1("Movie.dat",ios::in||ios::binary);
			fin1.seekg(0);
			while(!(fin1.eof()))
			{	fin1.read((char*)&m,sizeof(m));
				m.display();
			}
			fin1.close();
			system("Pause");
			break;
		case 2: cout<<"Enter the Movie No :"<<endl;
			int mn=0;
			cin>>mn;
			ifstream fin2("Movie.dat",ios::in||ios::binary);
			while(!fin2.eof())
			{	fin2.read((char*)&m,sizeof(m));
				if(m.getmid()==mn)
				{       delay(1);
					cout<<"Are you sure you want to watch  this movie??"<<endl;
					m.display();
					cin>>adch;
					{	if(adch=='y'||adch=='Y');
						else
							mn=0;
					}
				}
			}
			if(mn!=0)
			{	int StartNO;
				StartNO=seat();
				if(StartNO==0)
				{	cout<<"No seat selected"<<endl;
					getch();
				}
				else
				{	cout<<"Enter the no. of seats to buy:"<<endl;
					int TicketNo;
					cin>>TicketNo;
					randomize();
					int s,n,o,p,q,r,cost;
					random(s);
					random(n);
					random(o);
					random(p);
					random(q);
					random(r);
					float tno=s+(n*10)+(o*100)+(p*1000)+(q*10000)+(r*100000);
					cost=m.getcost();
					t.insert(cost,TicketNo,StartNO,tno);
					ofstream fout2("Ticket.dat",ios::app|ios::binary);
					fout2.write((char*)&t,sizeof(t));
					delay(3);
					clrscr();
					cout<<"Thank You for Purchase of Ticket :\n\n Please save this Ticket No for future reference"<<endl;
					t.display();
					system("Pause");
					fin2.close();
					fout2.close();
				}
			}
			break;
		case 3: clrscr();
			float tno3;
			ifstream fin3("Ticket.dat",ios::in||ios::binary);
			cout<<"Enter Ticket No. to view: "<<endl;
			cin>>tno3;
			while(!fin3.eof())
			{	fin3.read((char*)&t,sizeof(t));
				if(tno3==t.retTno())
				{       delay(1);
					cout<<"Ticket Found"<<endl;
					t.display();
				}
				else
					cout<<"Invalid Ticket No. Please enter correct value:"<<endl;
					cin.ignore();
					getch();
			}
			fin3.close();
			system("Pause");
			break;
		case 4: clrscr();
			float tno4;
			ifstream fin4("Ticket.dat",ios::in||ios::binary);
			ofstream fout4("temp.dat",ios::out||ios::binary);
			cout<<"Enter Ticket No. to delete : "<<endl;
			cin>>tno4;
			while(!fin4.eof())
			{	fin4.read((char*)&m,sizeof(m));
				if(tno4==t.retTno())
				{       delay(1);
					cout<<"Are you sure you want to delete this movie??"<<endl;
					cin>>adch;
					{	if(adch=='n'||adch=='N')
						{	fout4.write((char*)&m,sizeof(m));}
					}
				}
				else fout4.write((char*)&m,sizeof(m));
			}
			fin4.close();
			fout4.close();
			remove("Ticket.dat");
			rename("temp.dat","Ticket.dat");
			cout<<"TIcket Deleted";
			system("Pause");
			break;
		case 5: exit(0);
			break;
		default: cout<<"Wrong choice selected please enter correct choice";
			 cin.clear();
			 getch();
		};
	};
}


int seat(){
	clrscr();
	cout<<"Note Down The Seat Number And Press Any Key...";
	system("Pause");
	clrscr();
	cout<<"| EXIT |";
	cout<<"| EXIT |";
	cout<<"       SCREEN        ";
	cout<<"|___________________|";
	cout<<"____________________";
	cout<<"|1|2|3|4|5|6|7|8|9| ";
	cout<<"____________________";
	cout<<"___________________";
	cout<<"|10|11|12|13|14|15|16|17|18 |";
	cout<<"___________________";
	cout<<"___________________";
	cout<<"|19|20|21|23|24|25|26|27|28 |";
	cout<<"___________________";
	cout<<"___________________";
	cout<<"|29|30|31|32|33|34|35|36|37 |";
	cout<<"___________________";
	cout<<"__________________";
	cout<<"|38|39|40|41|42|43|44|45|46 |";
	cout<<"__________________";
	getch();
	clrscr();
	cout<<"Enter the Seat No:"<<endl;
	int r;
	cin>>r;
	if(r=='0')
	{
		 cout<<"No Seats Selected!!!";
		 getch();
		 return r;
	}
	else
		return r;
}

void pass(){
		int i=0;
		char pass[15]="pass",user[15]="user",pword[15],uname[15],ch;
		clrscr();
		cout<<"Enter Username : ";
		cin>>uname;
		cout<<endl<<"Enter Password : ";
		while(1)
		{	ch=getch();
			if(ch==13)
				break;
			cout<<"*";
			pword[i]=ch;
			i++;
		}
		pword[i]='\0';
		if (uname=="user" && pword=="pass")
			admin();
		else
			cout<<"\n\nNever Welcome";
		getch();
	}
void main(){
	while(1){
		cout<<"\n\n Welcome to LL Cinema"<<endl;
		cout<<"\n\n Choose 1. User Menu \n\n 2. Admin Menu \n\n 3.Exit";
		int mench;
		cin>>mench;
		switch(mench){
			case 1: user();
				break;
			case 2: pass();
				break;
			case 3: exit(0);
				break;
			default: cout<<"Please enter a valid choice : "<<endl;
				 cin.ignore();
				 system("Pause");
			};
	};
}
