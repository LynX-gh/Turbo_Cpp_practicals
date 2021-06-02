#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<math.h>

class Theatre{
	protected :
		int TNo;
		char City[20];
	public :
		void TInsert();
		void Tdisp(TNo)
		{ cout<<City; }
	};

class Movie : public Theatre {
	protected :
		int Mno;
		char MName;
	public :
		int time;
		int date;
		void Minsert();
		void Mdisp(MNo)
		{ cout<<Mname<<Mno<<time<<date; }
	};

class Ticket : public Movie {
		int TiNo
	protected :
		char Buyer;
		int Price;
	public :
		void tbuy(char c,int MNo,int TNo);
		void tdisp(TiNo);
	};
