#include<iostream.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>

	void main(){
		clrscr();
		int no,guess,ul,ll,a=0,temp=0;
		ul=100;
		ll=0;
		randomize();
		no=random(100);
		do{
		clrscr();
		cout<<"\nEnter your guess of number between : "<<ul<<" and  : "<<ll<<endl;
		cin>>guess;
		if(guess==no)
		{	cout<<"It is the correct guess  : "<<guess;
			a=5;
			temp=1;
			getch();
		}
		else if(guess>no)
		{	cout<<"\nThe guess is greater than the number";
			ul=guess;
			a++;
			cout<<"\nTries left = "<<5-a<<endl;
			getch();
		}
		else if(guess<no)
		{	cout<<"\nThe guess is lesser than the number";
			ll=guess;
			a++;
			cout<<"\nTries left = "<<5-a<<endl;
			getch();
		}
		else
		{	cout<<"\nEnter a valid number";
			a++;
			cout<<"\nTries left = "<<5-a<<endl;
			getch();
		}
		}while(a<5);
		if(temp==0)
			cout<<"\nThe correct number was : "<<no;
		else
			cout<<"\nCongratulations"<<endl;
		getch();
		}