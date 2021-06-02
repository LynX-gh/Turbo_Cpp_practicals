#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dos.h>
#include<iostream>
#include<fstream>
#include<Windows.h>
using namespace std;

void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

class movie
{	private:
		int mid,mcost;
	public:
		char mname[25];
		void insert();
		void display();
		movie (int a,int b,char c[25]);
		int getmid()
		{	return mid;
		};
		int getcost()
		{	return mcost;
		};
};
movie::movie(int a=0,int b=0,char c[25]='\0')
{	mid=a;
	mcost=b;
	strcpy_s(mname,c);
}

void movie::insert()
{	gotoxy(10,10);
	cout<<"Enter Movie code : ";
	cin>>mid;
	gotoxy(10,12);
	cout<<"Enter Movie name : ";
	gets(mname);
	gotoxy(10,14);
	cout<<"Enter Price of Ticket : ";
	cin>>mcost;
}
void movie::display()
{      	cout<<endl<<"Movie ID : "<<mid<<endl;
	cout<<endl<<"Movie Name : "<<mname<<endl;
	cout<<endl<<"Price : "<<mcost<<endl;
	cout<<"_________________________________________________________"<<endl;
}

class ticket
{       private:
		movie m;
	int Tamt,TicketNo,StartNO; //Start no - Ticket no. of starting ticket, TicketNo - No of tickets bought, Tcost - Cost of 1 ticket
	float Tno;
	public:
		void TotalTicket();
		void insert(int b,int c,float d,int m);
		void display();
		int retTno(){
			return Tno;
		}
};

void ticket::insert(int b,int c,float d,int mn)
{	TicketNo=b;
	StartNO=c;
	Tno=d;
	ifstream fin2("Movie.dat",ios::in||ios::binary);
	while(1)
	{	fin2.read((char*)&m,sizeof(m));
		if(m.getmid()==mn)
		{	movie ref(m.getmid(),m.getcost(),m.mname);
			m=ref;
			break;
		}
	}
}

void ticket::display()
{       cout<<"_________________________________________________________"<<endl;		cout<<"\nTicket no : "<<Tno<<endl;
	cout<<"Movie : "<<m.mname<<endl;
	cout<<"No of Tickets : "<<TicketNo<<endl;
	cout<<"Ticket No is/are : ";
	TotalTicket();
	cout<<"\nTotal Cost : "<<TicketNo*m.getcost()<<endl;
	cout<<"_________________________________________________________"<<endl;
}

void ticket::TotalTicket(){
	for(int i=0,j=StartNO;i<TicketNo;i++)
		{	cout<<"|"<<j<<"|";
			j++;
		}
}

int a,b;
int seat();
void admin();
void user();
void pass();

void main()
{       while(1)
	{	clrscr();
		gotoxy(30,5);
		cout<<"Welcome to YMAX Cinemas"<<endl;
		gotoxy(20,10);
		cout<<"1.Admin Menu";
		gotoxy(20,12);
		cout<<"2.User Menu";
		gotoxy(20,14);
		cout<<"3.Exit";
		gotoxy(20,18);
		cout<<"Enter Your Choice...";
		int mench;
		cin>>mench;
		switch(mench){
			case 1: ::a=1;
				pass();
				break;
			case 2: ::b=1;
				user();
				break;
			case 3: exit(0);
				break;
			default: gotoxy(20,18);
				 cout<<"Please Enter a Valid choice... ";
				 cin.ignore(4,'\n');
				 cin.clear();
				 sleep(1.8);
			};
	};
}




void admin(){
    while(a){
	clrscr();
	ticket t;
	movie m;
	char adch='n';
	int choice;
	gotoxy(30,5);
	cout<<"Welcome to YMAX Cinemas [Admin]";
	gotoxy(20,10);
	cout<<"1.Add New Movie";
	gotoxy(20,12);
	cout<<"2.Delete Movie";
	gotoxy(20,14);
	cout<<"3.Display Movies";
	gotoxy(20,16);
	cout<<"4.View All Bookings";
	gotoxy(20,18);
	cout<<"5.Return";
	gotoxy(20,22);
	cout<<"Enter Your Choice...";
	cin>>choice;
	switch(choice){
		case 1: clrscr();
			fstream fout1("Movie.dat",ios::app|ios::binary);
			gotoxy(30,5);
			cout<<"Add New Movie Information";
			m.insert();
			clrscr();
			m.display();
			cout<<"Are you sure you want to add this movie (y/n)...";
			cin>>adch;
			if(adch=='y'||adch=='Y')
			{	fout1.write((char*)&m,sizeof(m));
				delay(3);
				cout<<"\n\nMovie Updated..."<<endl;
			}
			else
			{	delay(3);
				cout<<"\n\nRecord Erased!"<<endl;
				cin.clear();
				cin.ignore(4,'\n');
			}
			system("Pause");
			fout1.close();
			break;
		case 2: clrscr();
			int mn=0,check=0;
			ifstream fin2("Movie.dat",ios::in||ios::binary);
			ofstream fout2("temp.dat",ios::out||ios::binary);
			gotoxy(30,5);
			cout<<"Delete Movie Information";
			gotoxy(20,10);
			cout<<"Enter Movie ID : ";
			cin>>mn;
			cin.clear();
			while(1)
			{      	fin2.read((char*)&m,sizeof(m));
				if(fin2.eof()){break;}
				if(m.getmid()==mn)
				{       system("cls");
					check++;
					delay(1);
					m.display();
					cout<<"Are you sure you want to Delete this Movie?(y/n)...";
					cin>>adch;
					cin.clear();
					{	if(adch=='n'||adch=='N')
						{	fout2.write((char*)&m,sizeof(m));	}
						else
						{	cout<<"\n\nMovie Deleted!"<<endl;
							sleep(1.8);
						}
					}
				}
				else
					fout2.write((char*)&m,sizeof(m));
			}
			if(check==0)
			{	gotoxy(20,14);
				cout<<"Incorrect Movie ID!!"<<endl;
				gotoxy(20,16);
				system("Pause");
			}
			fin2.close();
			fout2.close();
			remove("Movie.dat");
			rename("temp.dat","Movie.dat");
			break;
		case 3: clrscr();
			ifstream fin3("Movie.dat",ios::in||ios::binary);
			fin3.seekg(0);
			cout<<"_________________________________________________________"<<endl;
			while(1)
			{	fin3.read((char*)&m,sizeof(m));
				if(fin3.eof()){break;}
				m.display();
			}
			fin3.close();
			system("Pause");
			break;
		case 4: clrscr();
			ifstream fin4("Ticket.dat",ios::in||ios::binary);
			cout<<"_________________________________________________________"<<endl;
			fin4.seekg(0);
			while(1)
			{	fin4.read((char*)&t,sizeof(t));
				if(fin4.eof()){break;}
				t.display();
			}
			fin4.close();
			system("Pause");
			break;
		case 5: a=0;
			break;
		default: gotoxy(20,22);
			 cout<<"Please Enter a Valid choice...";
			 cin.ignore(4,'\n');
			 cin.clear();
			 sleep(1.8);
	};
    }
}

void user(){
   while(b){
	clrscr();
	int choice;
	gotoxy(30,5);
	cout<<"Welcome to YMAX Cinemas [User]";
	gotoxy(20,10);
	cout<<"1.Display Movies";
	gotoxy(20,12);
	cout<<"2.Book Ticket";
	gotoxy(20,14);
	cout<<"3.View Booking";
	gotoxy(20,16);
	cout<<"4.Cancel Booking";
	gotoxy(20,18);
	cout<<"5.Return";
	gotoxy(20,22);
	cout<<"Enter Your Choice...";
	cin>>choice;
	cin.clear();
	ticket t;
	movie m;
	char adch='n';
	switch(choice){
		case 1: clrscr();
			ifstream fin1("Movie.dat",ios::in||ios::binary);
			fin1.seekg(0);
			cout<<"_________________________________________________________"<<endl;
			while(1)
			{	fin1.read((char*)&m,sizeof(m));
				if(fin1.eof()){break;}
				m.display();
			}
			fin1.close();
			system("Pause");
			break;
		case 2: clrscr();
			gotoxy(35,5);
			cout<<"Book Tickets";
			gotoxy(20,10);
			cout<<"Enter Movie ID :";
			int mn=0;
			cin>>mn;
			cin.clear();
			ifstream fin2("Movie.dat",ios::in||ios::binary);
			ofstream fout2("Ticket.dat",ios::app|ios::binary);
			while(1)
			{	fin2.read((char*)&m,sizeof(m));
				if(m.getmid()==mn)
				{       delay(1);
					system("cls");
					m.display();
					cout<<"Confirm Movie Selected (y/n)...";
					cin>>adch;
					cin.clear();
					{	if(adch=='y'||adch=='Y');
						else
							mn=0;
					}
					break;
				}
				else if(fin2.eof())
				{	mn=0;
					cout<<"\nIncorrect Movie Id"<<endl;
					system("Pause");
					break;
				}
			}
			if(mn!=0)
			{	int StartNO;
				StartNO=seat();
				if(StartNO==0)
				{	cout<<"No Seat Selected!"<<endl;
					getch();
				}
				else
				{	gotoxy(10,11);
					cout<<"Enter no. of Tickets to Buy : ";
					int TicketNo;
					cin>>TicketNo;
					if(StartNO+TicketNo>46)
					{	cout<<"From seat no."<<StartNO<<" You can only purchase "<<47-StartNO<<"seats. \nPlease select a valid number of Seats "<<endl;
						system("pause");
						break;
					}
					randomize();
					int s,n,o,p;
					s=random(10);
					n=random(10);
					o=random(10);
					p=random(10);
					float tno=s+(n*10)+(o*100)+(p*1000);
					t.insert(TicketNo,StartNO,tno,m.getmid());
					fout2.write((char*)&t,sizeof(t));
					delay(3);
					clrscr();
					gotoxy(0,8);
					cout<<"_________________________________________________________"<<endl;
					gotoxy(0,10);
					t.display();
					cout<<"_________________________________________________________"<<endl;
					cout<<"\n\nThank You for Purchase of Ticket...";
					cout<<"\n\nPlease Save this Ticket No for Future Reference\n\n";
					system("Pause");
				}
			}
			fin2.close();
			fout2.close();
			break;
		case 3: clrscr();
			float tno3;
			ifstream fin3("Ticket.dat",ios::in||ios::binary);
			gotoxy(35,5);
			cout<<"View Ticket";
			gotoxy(10,10);
			cout<<"Enter Ticket No. to View : ";
			cin>>tno3;
			cin.clear();
			while(1)
			{	fin3.read((char*)&t,sizeof(t));
				if(fin3.eof())
				{	gotoxy(10,13);
					cout<<"Invalid Ticket No..."<<endl;
					sleep(1.8);
					break;
				}
				if(tno3==t.retTno())
				{       delay(1);
					gotoxy(10,12);
					cout<<"Ticket Found...";
					sleep(1);
					system("cls");
					t.display();
					cout<<endl;
					system("Pause");
					break;
				}
			}
			fin3.close();
			break;
		case 4: clrscr();
			float tno4,check=0;
			ifstream fin4("Ticket.dat",ios::in||ios::binary);
			ofstream fout4("temp.dat",ios::out||ios::binary);
			gotoxy(30,5);
			cout<<"Cancel Your Ticket";
			gotoxy(20,10);
			cout<<"Enter Ticket No. : ";
			cin>>tno4;
			while(1)
			{	fin4.read((char*)&t,sizeof(t));
				if(fin4.eof()){break;}
				if(tno4==t.retTno())
				{       check++;
					delay(1);
					system("cls");
					t.display();
					cout<<"Confirm Cancellation (y/n)...";
					cin>>adch;
					cin.clear();
					{	if(adch=='n'||adch=='N')
						{	fout4.write((char*)&t,sizeof(t));	}
						else
						{	cout<<"\n\nTicket Cancelled!"<<endl;
							system("Pause");
						}
					}
				}
				else
					fout4.write((char*)&t,sizeof(t));
			}
			if(check==0)
			{	gotoxy(20,13);
				cout<<"Incorrect Ticket No... "<<endl;
				sleep(1.8);
			}
			fin4.close();
			fout4.close();
			remove("Ticket.dat");
			rename("temp.dat","Ticket.dat");
			break;
		case 5: b=0;
			break;
		default: gotoxy(20,22);
			 cout<<"Please Enter a Valid choice...";
			 cin.clear();
			 cin.ignore(4,'\n');
			 sleep(1.8);
		};
	};
}


int seat(){
	clrscr();
	cout<<"Note Down The Seat Number And Press Any Key...";
	delay(2);
	system("cls");
	gotoxy(1,25);
	cout<<"| EXIT |";
	gotoxy(71,25);
	cout<<"| EXIT |";
	gotoxy(38,1);
	cout<<"SCREEN";
	gotoxy(20,2);
	cout<<"|________________________________________|";
	gotoxy(28,7);
	cout<<"----------------------------";
	gotoxy(28,8);
	cout<<"|01|02|03|04|05|06|07|08|09|";
	gotoxy(28,9);
	cout<<"----------------------------";
	gotoxy(28,10);
	cout<<"|10|11|12|13|14|15|16|17|18|";
	gotoxy(28,11);
	cout<<"----------------------------";
	gotoxy(28,12);
	cout<<"|19|20|21|23|24|25|26|27|28|";
	gotoxy(28,13);
	cout<<"----------------------------";
	gotoxy(28,14);
	cout<<"|29|30|31|32|33|34|35|36|37|";
	gotoxy(28,15);
	cout<<"----------------------------";
	gotoxy(28,16);
	cout<<"|38|39|40|41|42|43|44|45|46|";
	gotoxy(28,17);
	cout<<"----------------------------";
	getch();
	clrscr();
	gotoxy(10,10);
	cout<<"Enter the Seat No:";
	int r;
	cin>>r;
	if(r<1||r>46)
	{
		 cout<<"No Seats Selected!!!";
		 getch();
		 r=0;
		 return r;
	}
	else
		return r;
}

void pass(){
	clrscr();
	int i,x;
	char ch='/0',password[]="pass",match[20];
	gotoxy(30,5);
	cout<<"Admin Authentication";
	gotoxy(7,12);
	cout<<"Enter Password for Access :";
	for(i=0;i>=0;)
	{	ch=getch();
		if(ch!=8&&ch!=13)
		{	cout<<"*";
			match[i]=ch;
			i++;
		}
		else if(ch==13)
		{	match[i]='\0';
			break;
		}
		else
			break;

	}
	if(strcmp(match,password)==0)
		admin();

	else
	{	gotoxy(7,16);
		cout<<"Access Denied...";
		gotoxy(7,17);
		cout<<"You Entered : ";
		gotoxy(21,17);
		puts(match);
		gotoxy(7,19);
		system("pause");
	}
}