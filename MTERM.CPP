#include<fstream.h>
#include<conio.h>

void main(){
	clrscr();
	ifstream fin;
	fin.open("vowel.txt",ios::binary|ios::in);
	char ch[10],cha[100];
	int wrd=0,a;
	ofstream fout;
	fout.open("vowel.txt",ios::binary|ios::out);
	while(1)
	{	cout<<"Enter the contents of the file :";
		cin.getline(cha,100);
		fout<<cha;
		break;
	}
	fin.seekg(0);
	while(1)
	{	fin>>ch;
		if(fin.eof()){break;}
		for(int i=0;i<10;i++)
		{	if(ch[i]==' ')
				a=i;
		}
		cout<<ch<<" ";
		if(a==3)
		{	wrd++;	}
	}
	cout<<"Number of 3 letter words are : "<<wrd;
	fin.close();
	fout.close();
	getch();
	}
