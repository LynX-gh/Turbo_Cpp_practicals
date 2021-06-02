#include<CONIO.H>
#include<iostream.h>
#include<STDIO.H>
#include<STDLIB.H>
#include<TIME.H>
#include<STRING.H>
int m=1;
char a[9],player[2][20];


void board();	//function to display the game board
void game(int i);	//fucntion to a take the entries of player
int result(int i);	//function to check if any player has won
void reset();	//fucntion to reset tha names and the global char array to default
void comp(int i,int difficulty);	//function to take the turn of computer
void defend();	//fucntion to check if the player is winning and stop them and check if computer will win


void main(){
	do{
	clrscr();
	cout<<"\n\n\n\n================================================================================\n\t\t\t\t TIC-TAC-TOE"<<endl;
	cout<<"\n\t\t What Do You Want To PLay??? \n\n \t\t\t 1.PvP\n\t\t\t 2.PvC \n\t\t\t 3.View Last Game \n\t\t\t 4.Exit\n\n\t\t Enter Your preferred choice : ";
	unsigned int gtype,i;	//gtype = the menu operating variable
	cin>>gtype;
	switch(gtype)
	{	case 1:	cout<<"\n\n\t\t\t\tYou selected PvP"<<endl;
			cout<<"================================================================================";
			getch();
			reset();
			cout<<"Enter the name of Player 2  : "<<endl;
			gets(player[1]);
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
			reset();
			strcpy(player[1],"COMPUTER");
			int difficulty;
			cout<<"\n================================================================================\n\t\t\t PVE - Select Your difficulty Level"<<endl;
			cout<<"\n\n\t\t\t 1.Easy\n\t\t\t 2.Hard\n\n\t\t Enter Your preferred choice : ";
			cin>>difficulty;
			for(i=0;i<9;i++)
			{       board();
				if(i%2==0)
				{	game(i);
					if(i>3)
					{	result(i);
						if(result(i)==0)
							break;
					}
				}
				else
				{	comp(i,difficulty);
					if(i>3)
					{	result(i);
						if(result(i)==0)
							break;
					}
				}
			}
			break;
		case 3:	board();
			getch();
			break;
		case 4:	m=0;
			cout<<"\n\n\t\t\t\tThank You for Playing";
			break;
		default:cout<<"\t\t\t\tEnter a corect choice....Don't use the numpad";
			cin.clear();
			cin.ignore(4,'\n');
			getch();
	}
	}while(m>0);
	}


int de;
void comp(int i,int difficulty){
	int num=0;
	switch(difficulty)
	{      	case 1:	defend();
			break;
		case 2: if(i==0)
			{	if(a[4]=='X')
				{       de=4;
					randomize();
					num=random(4);
					if(num==0)
						a[0]='O';
					else if(num==1)
						a[2]='O';
					else if(num==2)
						a[6]='O';
					else
						a[8]='O';
				}
				else if(a[1]=='X')
				{	a[0]='O';
					de=1;
				}
				else if(a[3]=='X')
				{	a[0]='O';
					de=3;
				}
				else if(a[5]=='X')
				{	a[2]='O';
					de=5;
				}
				else if(a[7]=='X')
				{	a[6]='O';
					de=7;
				}
				else
				{	a[4]='O';
					de=8602;
				}
			}
			else if(i==2)
			{       if(de==4)
				{	if(a[3]==a[4])
						a[5]='O';
					else if(a[4]==a[5])
						a[3]='O';
					else if(a[1]==a[4])
						a[7]='O';
					else if(a[4]==a[7])
						a[1]='O';
					else if(a[0]==a[4])
						a[8]='O';
					else if(a[4]==a[8])
						a[0]='O';
					else if(a[2]==a[4])
						a[6]='O';
					else
						a[2]='O';
				}
				else if(de==1)
				{  	if(a[1]==a[4])
						a[7]='O';
					else if(a[1]==a[7])
						a[4]='O';
					else
					{	for(int j=1;j>0;j++)
						{	randomize();
							num=random(9);
							if(a[num]!='X')
							{	a[num]='O';
								break;
							}
						}
					}
				}
				else if(de==3)
				{      	if(a[3]==a[4])
						a[5]='O';
					else if(a[3]==a[5])
						a[4]='O';
					else
					{	for(int j=1;j>0;j++)
						{	randomize();
							num=random(9);
							if(a[num]!='X')
							{	a[num]='O';
								break;
							}
						}
					}
				}
				else if(de==5)
				{	if(a[5]==a[4])
						a[3]='O';
					else if(a[5]==a[3])
						a[4]='O';
					else
					{	for(int j=1;j>0;j++)
						{	randomize();
							num=random(9);
							if((a[num]!='X')&&(a[num]!='O'))
							{	a[num]='O';
								break;
							}
						}
					}
				}
				else if(de==7)
				{	if(a[7]==a[4])
						a[1]='O';
					else if(a[7]==a[1])
						a[4]='O';
					else
					{	for(int j=1;j>0;j++)
						{	randomize();
							num=random(9);
							if((a[num]!='X')&&(a[num]!='O'))
							{	a[num]='O';
								break;
							}
						}
					}
				}
				else
				{	if(a[0]==a[1])
						a[2]='O';
					else if(a[1]==a[2])
						a[0]='O';
					else if(a[0]==a[2])
						a[1]='O';
					else if(a[2]==a[5])
						a[8]='O';
					else if(a[5]==a[8])
						a[2]='O';
					else if(a[2]==a[8])
						a[5]='O';
					else if(a[6]==a[7])
						a[8]='O';
					else if(a[7]==a[8])
						a[6]='O';
					else if(a[6]==a[8])
						a[7]='O';
					else if(a[0]==a[3])
						a[6]='O';
					else if(a[3]==a[6])
						a[0]='O';
					else if(a[0]==a[6])
						a[3]='O';
					else
					{	for(int j=1;j>0;j++)
						{	randomize();
							num=random(9);
							if((a[num]!='X')&&(a[num]!='O'))
							{	a[num]='O';
								break;
							}
						}
					}
				}
			}
			else
				defend();
		}
	}


void defend(){
	char c='O',d='X';
	for(int i=1;i<2;i++){
	if((a[0]==c)&&(a[1]==c)&&(a[2]!=d))
		a[2]='O';
	else if((a[1]==c)&&(a[2]==c)&&(a[0]!=d))
		a[0]='O';
	else if((a[0]==c)&&(a[2]==c)&&(a[1]!=d))
		a[1]='O';
	else if((a[2]==c)&&(a[5]==c)&&(a[8]!=d))
		a[8]='O';
	else if((a[5]==c)&&(a[8]==c)&&(a[2]!=d))
		a[2]='O';
	else if((a[2]==c)&&(a[8]==c)&&(a[5]!=d))
		a[5]='O';
	else if((a[6]==c)&&(a[7]==c)&&(a[8]!=d))
		a[8]='O';
	else if((a[7]==c)&&(a[8]==c)&&(a[6]!=d))
		a[6]='O';
	else if((a[6]==c)&&(a[8]==c)&&(a[7]!=d))
		a[7]='O';
	else if((a[0]==c)&&(a[3]==c)&&(a[6]!=d))
		a[6]='O';
	else if((a[3]==c)&&(a[6]==c)&&(a[0]!=d))
		a[0]='O';
	else if((a[0]==c)&&(a[6]==c)&&(a[3]!=d))
		a[3]='O';
	else if((a[3]==c)&&(a[4]==c)&&(a[5]!=d))
		a[5]='O';
	else if((a[4]==c)&&(a[5]==c)&&(a[3]!=d))
		a[3]='O';
	else if((a[3]==c)&&(a[5]==c)&&(a[4]!=d))
		a[4]='O';
	else if((a[1]==c)&&(a[4]==c)&&(a[7]!=d))
		a[7]='O';
	else if((a[4]==c)&&(a[7]==c)&&(a[1]!=d))
		a[1]='O';
	else if((a[1]==c)&&(a[7]==c)&&(a[4]!=d))
		a[4]='O';
	else if((a[0]==c)&&(a[4]==c)&&(a[8]!=d))
		a[8]='O';
	else if((a[4]==c)&&(a[8]==c)&&(a[0]!=d))
		a[0]='O';
	else if((a[0]==c)&&(a[8]==c)&&(a[4]!=d))
		a[4]='O';
	else if((a[2]==c)&&(a[4]==c)&&(a[6]!=d))
		a[6]='O';
	else if((a[4]==c)&&(a[6]==c)&&(a[2]!=d))
		a[2]='O';
	else if((a[2]==c)&&(a[6]==c)&&(a[4]!=d))
		a[4]='O';
	else if(c=='X')
	{       int num=0;
		for(float j=1;j>0;j++)
		{	randomize();
			num=random(9);
			if((a[num]!='X')&&(a[num]!='O'))
			{	a[num]='O';
				break;
			}
		}
	}
	else if(c=='O')
	{	c='X';
		d='O';
		i=0;
	}
	}
}



void game(int i)
	{       int choice,flag=0;	//choice= the space selected by the user on the board
		cout<<"\n\n\n\t\t "<<player[i%2]<<" enter your choice : ";
		again:cin>>choice;
		for(int j=0;j<9;j++)
		{	if((choice+48)==a[j])
			{	if((i%2)==0)
				{	a[j]='X';}
				else if((i%2)==1)
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
		cout<<"\n\n\t\t"<<player[i%2]<<" HAS WON THE GAME :-)"<<endl;
		getch();
	}
	else if(i>7)
	{       clrscr();
		board();
		cout<<"\n\n\t\tThe game is draw :-("<<endl;
		getch();
	}
	return result;
	}


void reset(){
	char val='1';
	for(int i=0;i<9;i++)
	{	a[i]=val;
		val++;
	}
	getch();
	clrscr();
	cout<<"Enter the name of Player 1  : "<<endl;
	gets(player[0]);
	}
