#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<process.h>
const size=3;
int a=0;
class candidate{
	int rno;
	char name[20];
	float score;
	char remarks[20];
	void assignrem()
	{	if(score>=50)
			strcpy(remarks,"Selected");
		else
			strcpy(remarks,"Not Selected");
	}
	public:
		int getrno(){return rno;}
		void search(int a);
		void enter(){
			cout<<"Enter Registration no : ";
			cin>>rno;
			cin.ignore();
			cout<<"Enter Name : ";
			gets(name);
			cout<<"Enter Score :";
			cin>>score;
			assignrem();
			}
		void display(){
			cout<<"\nRegistration No. : "<<rno<<endl;
			cout<<"\nName             : "<<name<<endl;
			cout<<"\nScore            : "<<score<<endl;
			cout<<"\nRemarks          : "<<remarks<<endl;
		}
	};
void candidate :: search (int n){
	for(int i=0;i<size;i++){
		if (getrno()==n)
		{	cout<<rno<<'\t'<<name<<'\t'<<score<<'\t'<<remarks<<endl;
			break;
		}
		else if(i==(size-1))
			a++;
	}
}

int main(){
	candidate c[size];
	system("cls");
	for(int i=0;i<size;i++){
		c[i].enter();
		}
	for(i=0;i<size;i++){
		c[i].display();
		}
	cout<<"Enter rno to be searcehed for......";
	int r; cin>>r;
	for(i=0;i<size;i++){
		c[i].search(r);
		}
	if(a>2)
		cout<<"Record not found";s
	getch();
	return 0;
	}

