#include<conio.h>
#include<iostream.h>

class student{
	private:
		int rno;
	public:
		void get_no(int a){
			rno=a;	}
		void put_no(void){
			cout<<"Roll No : "<<rno<<endl;
		};
class test : public student{
		private:
			float s1,s2;
		public:
			float get_s1{ return s1;}
			float get_s2{ return s2;}
			void get_marks(float x, float y){ x=get_s1(); y=get_s2();}
			void put_marks(void){
				cout<<"Marks Obtained : "<<endl;
				<<"Subject 1 : "<<s1<<endl;
				<<"Subject 2 ; "<<s2<<endl;
			}
		};
class sports{
	private:
		float scores;
	public:
		float get_score(float s)
		{	s=