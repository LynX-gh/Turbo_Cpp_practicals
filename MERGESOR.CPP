#include<iostream.h>
#include<conio.h>

void mergesort(int a[],int m,int b[], int n, int c[])
{	int i=0,j=n-1,k=0
	while(i<m && j>=0)
	{	if(a[i]<b[j])
			c[k++]=a[i++];
		else
			c[k++]=b[j--];
	}
	while(i<m)
	{	c[k++]=a[i++];
int main(){
	clrscr();

	getch();
	return 0;


	}