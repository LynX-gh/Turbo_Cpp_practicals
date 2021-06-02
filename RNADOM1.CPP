#include<conio.h>
#include<iostream.h>
#include<stdlib.h>

void main(){
	clrscr();
	char city[][15]={"Vapi","Surat","Rajkot","Anand","Baroda"};
	int turn=10,trik;
	for(int count=1;count<4;count++)
	{	randomize();
		trik=random(count);
		cout<<turn-trik<<city[trik]<<"\t\t";
	}
	getch();
	}