#include<conio.h>
#include<iostream.h>
#include<iomanip.h>
#include<process.h>
#include<stdio.h>
#include<time.h>
int m=1;
char a[9]={49,50,51,52,53,54,55,56,57};
char player[2][20];
void board();	//function to display the game board
void game(int i);	//fucntion to a take the entries of player
int result(int i);	//function to check if any player has won
void main(){
	do{
	clrscr();
	cout<<"Enter the name of Player 1  : "<<endl;
	gets(player[0]);
	cout<<"Enter the name of Player 2  : "<<endl;
	gets(player[1]);
	clrscr();
	cout<<"\n\n\n\n================================================================================\n\t\t\t\t TIC-TAC-TOE"<<endl;
	cout<<"\n\t\t What Do You Want To PLay??? \n\n \t\t\t 1.PvP\n\t\t\t 2.PvE\n\t\t\t 3.Exit\n\n\t\t Enter Your preferred choice : ";
	int gtype,i;	//gtype = the menu operating variable
	cin>>gtype;
	switch(gtype)
	{	case 1:	cout<<"\n\n\t\t\t\tYou selected PvP"<<endl;
			cout<<"================================================================================";
			getch();
			for(i=0;i<9;i++)
			{       board();
				game(i);
				if(i>3)
				{	result(i);
					if(result(i)==0)
						break;
				}
			}
			break;
		case 2:	cout<<"\n\n\t\t\t\tYou selected PvE"<<endl;
			cout<<"================================================================================";
			clrscr();
			cout<<"\n\n\n\n================================================================================\n\t\t\t PVE - Select Your difficulty Level"<<endl;
			cout<<"\n\n \t\t\t 1.Easy\n\t\t\t 2.Medium\n\t\t\t 3.Impossible\n\n\t\t Enter Your preferred choice : ";
			cin>>gtype;
			for(i=0;i<9;i+=2)
			{       board();
				game(i);
				if(i>3)
				{	result(i);
					if(result(i)==0)
						break;
				}
				comp(i,gtype);
				if(i>3)
				{	result(i);
					if(result(i)==0)
						break;
				}
			}
		case 3:	m=0;
			cout<<"\n\n\t\t\t\tThank You for Playing";
			break;
		default:cout<<"\t\t\t\tEnter a corect choice";
			getch();
	}
	}while(m>0);
	}
void board(){
	clrscr();
	cout<<"\n\n\n\t\t\t\t||\t\t||";
	cout<<"\n\t\t\t"<<a[0]<<"\t||\t"<<a[1]<<"\t||\t"<<a[2];
	cout<<"\n\t\t\t\t||\t\t||";
	cout<<"\n\t\t==================================================";
	cout<<"\n\t\t\t\t||\t\t||";
	cout<<"\n\t\t\t"<<a[3]<<"\t||\t"<<a[4]<<"\t||\t"<<a[5];
	cout<<"\n\t\t\t\t||\t\t||";
	cout<<"\n\t\t==================================================";
	cout<<"\n\t\t\t\t||\t\t||";
	cout<<"\n\t\t\t"<<a[6]<<"\t||\t"<<a[7]<<"\t||\t"<<a[8];
	cout<<"\n\t\t\t\t||\t\t||";
	}

void game(int i)
	{       int choice,flag=0;	//choice= the space selected by the user on the board
		cout<<"\n\n\n\t\t "<<player[i%2]<<" enter your choice : ";
		again:cin>>choice;
		for(int j=0;j<9;j++)
		{	if((choice+48)==a[j])
			{	if((i%2+1)==1)
				{	a[j]='X';}
				else if((i%2+1)==2)
				{	a[j]='O';}
				flag=0;
				break;
			}
			else
				flag=1;
		}
		if(flag==1)
		{	cout<<"\nEnter a valid choice"<<endl;
			goto again;
		}
		getch();
	}

int result(int i){
	int result=1;
	if((a[0]==a[1])&&(a[1]==a[2]))
		result=0;
	else if((a[3]==a[4])&&(a[4]==a[5]))
		result=0;
	else if((a[6]==a[7])&&(a[7]==a[8]))
		result=0;
	else if((a[0]==a[3])&&(a[3]==a[6]))
		result=0;
	else if((a[1]==a[4])&&(a[4]==a[7]))
		result=0;
	else if((a[2]==a[5])&&(a[5]==a[8]))
		result=0;
	else if((a[0]==a[4])&&(a[4]==a[8]))
		result=0;
	else if((a[2]==a[4])&&(a[4]==a[6]))
		result=0;
	else
		result=1;

	if(result==0)
	{       clrscr();
		board();
		cout<<"\n\n\t\tPLAYER "<<i%2+1<<" HAS WON THE GAME :-)"<<endl;
		getch();
	}
	else if(i==8)
	{       clrscr();
		board();
		cout<<"\n\n\t\tThe game is draw :-("<<endl;
		getch();
	}
	return result;
	}











