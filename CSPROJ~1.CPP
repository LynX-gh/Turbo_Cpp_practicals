#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<dos.h>
#include<fstream.h>


void mainmenu();
void crfile();
void pass();
void disp();
void owner();
void user();
void seat(char r);
void tq();
void bill(char r,char row1[1],char col1[1],char cl);
int u;


class Movie
 {
  private:
   char movnam[20];
   char movlang[10];
   char cast[20];
  public:
   char movid[8];
   void input();
   void output();
   void retmona()
    {
     puts(movnam);
    }
 }ob1[10];

void Movie::input()
 {
  clrscr();
  cout<<"Owners Page...";
  cout<<"Enter Details Of Movie";
  cout<<"Movie ID:";
  gets(movid);
  cout<<"Movie Name:";
  gets(movnam);
  cout<<"Movie Language:";
  gets(movlang);
  cout<<"Cast:";
  gets(cast);
 }

void Movie::output()
 {
  clrscr();
  cout<<"Users Page...";
  cout<<"Details Of Movie";
  cout<<"Movie ID:";
  cout<<movid;
  cout<<"Movie Name:";
  cout<<movnam;
  cout<<"Movie Language:";
  cout<<movlang;
  cout<<"Cast:";
  cout<<cast;
 }

void crfile()
 {
  ofstream f;
  char ch;
  f.open("MOVIE.txt",ios::out);
  int u=0;
  sleep(3);
  do
   {
    ob1[u].input();
    f.write((char*)&ob1[u],sizeof(ob1[u]));
    clrscr();
    cout<<"Do You Want To Continue??? \ny/(any other key)";
    cin>>ch;
    u++;
   }while(ch=='y'||ch=='Y');
   f.close();
 }

void disp()
{
  ifstream f;
  f.open("MOVIE.txt",ios::in);
  f.seekg(0);
  u=0;
  char ch;
  do
   {
    f.read((char*)&ob1[u],sizeof(ob1[u]));
    ob1[u].output();
    cout<<"Press 'y' To View Details Of Next Film";
    cin>>ch;
    u++;
   }while(ch=='y'||ch=='Y');
  f.close();
}

void pass(){
	l:
	  clrscr();
	  char pass[100],p[1];
	  cout<<"\n\tOWNER'S PAGE...";
	  cout<<"\n\n\t\tEnter Password...";
	  cout<<"\n\n\t\tPress 'Esc' To Go Back To Main Menu...";
	  char c;
	  int e;
	  for(int t=0,y=250;t++;y+=10)
	   {
	    cin>>c;
	    e=c;
	    if(e==13)
	     {
	      goto ll;
	     }
	    if(e==27)
	     {
	      exit(1);
	     }
	    pass[t]=c;
	    cout<<"*";
	   }
	  ll:
	  for(t=0;t<9;t++)
	   {
	    p[t]=pass[t];
	   }
	  if(strcmp(p,"admin123")==0)
	   {
	    cout<<"Login Successful...";
	    sleep(2);
	    owner();
	   }
	  else
	   {
	    cout<<"Login Aborted... Incorrect Password...";
	    sleep(3);
	    goto l;
		   }
	 }

class pvr
 {
  private:
   int i,j,k,a,c;
  public:
   void intro();
   void menu();
   void name();
 };
 void pvr::intro()
  {
   clrscr();
   for(k=1;k<=90;k++)
    {
    clrscr();
    cout<<"WELCOME TO";
    }
    cout<<"*****************";
    cout<<" FIVE STAR MOVIES ";
    cout<<"*****************";
  }
  void pvr::name()
   {
    clrscr();
    cout<<"PROJECT BY :-)";
    cout<<"********************";
    cout<<"***Lauda and Lasan***";
    sleep(3);
   }
 void pvr::menu()
  {
   clrscr();
    cout<<"WELCOME";
    sleep(1);
    cout<<"Hit Any Key To Continue...";
    getch();
   }

void mainmenu()
 {
  y:
  int n;
  clrscr();
  char h[1];
  cout<<"MAIN MENU...";
  cout<<"1.OWNER'S PAGE";
  cout<<"2.USERS'S PAGE";
  cout<<"3.EXIT";
  gets(h);
  if(strcmp(h,"1")==0)
   {
    pass();
   }
  else if(strcmp(h,"2")==0)
   {
    user();
   }
  else if(strcmp(h,"3")==0)
   {
    exit(1);
   }
  else
   {
    goto y;
   }
 }

void owner()
 {
  pvr p;
  crfile();
  t:
  clrscr();
  cout<<"Press 'Esc' To Return To Main Menu";
  char a;
  int u;
  a=getch();
  u=a;
  if(u==27)
   {
    mainmenu();
   }
  else
   {
    goto t;
   }
 }
void user()
 {
  int e;
  char q[1],m[1];
  clrscr();
  cout<<"USER'S PAGE...";
  cout<<"View Different Movies By Using 'y' Key...";
  cout<<"Note Down The Movie Id Of The Movie That You";
  cout<<"Wish To Watch...";
  cout<<"Press 'Esc' Go To Main Menu...";
  sleep(5);
  clrscr();
  disp();
  sleep(2);
  cout<<"Enter Id Of Desired Movie...";
  gets(q);
  clrscr();
  ifstream ff;
  ff.open("MOVIE.txt",ios::in);
  ff.seekg(0);
  int ch;
  for(int t=0;t<u;t++)
   {
    ff.read((char*)&ob1[u],sizeof(ob1[u]));
    if(strcmp(q,ob1[t].movid)==0)
     {
      cout<<"Details Of ";
      ob1[t].retmona();
      ob1[u].output();
      cout<<"Hit 'Enter' To Proceed To Seat Selection...";
      ch=getch();
     }
   }
  ff.close();
  if(ch==13)
   {
    char q;
    char a[100],b[2];
    clrscr();
    cout<<"Enter Number Of Seats...";
    q=getch();
    seat(q);
   }
  else
   {
    exit(1);
   }
 }

void seat(char r)
 {
  clrscr();
  cout<<"Note Down The Seat Number And Press Any Key...";
  sleep(3);
  clrscr();
  cout<<"| EXIT |";
  cout<<"| EXIT |";
  cout<<"       SCREEN        ";
  cout<<"|___________________|";
  cout<<"____________________";
  cout<<"|A1|A2|A3|A4|A5|A6|A7|A8|A9| ";
  cout<<"____________________";
  cout<<"___________________";
  cout<<"|B1|B2|B3|B4|B5|B6|B7|B8|B9 |";
  cout<<"___________________";
  cout<<"___________________";
  cout<<"|C1|C2|C3|C4|C5|C6|C7|C8|C9 |";
  cout<<"___________________";
  cout<<"___________________";
  cout<<"|D1|D2|D3|D4|D5|D6|D7|D8|D9 |";
  cout<<"___________________";
  cout<<"__________________";
  cout<<"|E1|E2|E3|E4|E5|E6|E7|E8|E9 |";
  cout<<"__________________";
  getch();
  char row1[1],col1[1],row2[1],col2[1],row3[1],col3[ 1],row4[1],col4[1],row5[1],col5[1],cl;
  clrscr();
  if(r=='0')
   {
    cout<<"No Seats Available!!!";
    getch();
    exit(1);
   }
  if(r=='1')
   {
    cout<<"Select Row(A-E):->";
    gets(row1);
    cout<<"Select Column(1-9):>";
    gets(col1);
    cout<<"Gold Class(g) or Platinum Class(p)";
    cl=getch();
    bill(r,row1,col1,cl);
   }
 }

void bill(char r,char row1[1],char col1[1],char cl)
 {
  clrscr();
  int rs;
  cout<<"-----FIVE STAR MOVIES----";
  cout<<"         ---BILL---         ";
  cout<<"Number Of Seats: ";
  printf("%d",(r-48));
  cout<<"Seat Numbers: ";
  cout<<row1;
  cout<<col1;
  cout<<"Cost Per Ticket...";
  if(cl=='g')
   {
    rs=(r-48)*300;
    cout<<" Rs.300";
    cout<<"Net Bill Amount...";
    printf("%d",rs);
   }
  if(cl=='p')
   {
    rs=(r-48)*500;
    cout<<"Rs.500";
    cout<<"Net Bill Amount...";
    printf("%d",rs);
   }
  cout<<"----------------------";
  getchar();
  tq();
 }

void tq()
 {
  clrscr();
  cout<<"THANK";
  cout<<"YOU...";
  getch();
  exit(1);
 }

void main(){
	pvr p;
	Movie m;
	p.intro();
	p.menu();
	p.name();
	mainmenu();
	tq();
	getch();
}
