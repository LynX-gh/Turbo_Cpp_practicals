#include<iostream.h>
#include<conio.h>

void num(int x[]){
	for (int i=5;i>0;i--)
		cout<<x[i]<<" ";
	}

int main(){
	clrscr();
	int x[5]={1,2,3,4,5};
	int *p = x;
	int i;
	for (i=0;i<2;i++){
		int temp = *(p+i);
		*(p+i) = *(p+4-i);
		*(p+4-i) = temp;
	}
	for (i=0;i<5;i++)
		cout<<x[i]<<" ";
	cout<<endl;
	num(x);
	cout<<endl;
	cout<<x[5];
	getch();
	return 0;
}