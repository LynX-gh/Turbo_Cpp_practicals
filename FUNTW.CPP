#include<iostream.h>
#include<conio.h>
//Example of type with parameter
float avg(float, float, float);
void main(){
	clrscr();
	float s1,s2,s3,ans;
	cout<<"Enter any 3 sub marks";
	cin>>s1>>s2>>s3;
	ans=avg(s1,s2,s3);
	cout<<"\n Average Percent :"<<ans;
	getch();
	}
float avg(float a,float b,float c)
{	float d=(a+b+c)/3;
	cout<<"Total of three sub marks is : "<<a+b+c<<endl;
	return d;
}
