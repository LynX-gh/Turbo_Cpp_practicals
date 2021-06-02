#include<iostream.h>
#include<conio.h>
#include<iomanip.h>
#include<stdio.h>
float merechachakibeti(char a);

void main(){
	clrscr;
	char ch;
	gets(ch);
	merechahakibeti(ch);
	getch();
}
float merechachakibeti(char a)
{       int sum=0,total=0,k;
	float value;
	for(int i=20,i>=0,i--)
	{	if((a[i]==A)||(a[i]==)||(a[i]==S))
			 sum+=1;
		else
			sum+=0;
	}
	cout<<sum;
	total=sum;
	while(sum)
	{	k=sum%10;
		total+=k;
		sum=sum/10;
	}
return sum;
}