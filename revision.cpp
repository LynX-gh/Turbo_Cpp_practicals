void Encrypt (char *S, int key)
{		char *Temp = S;
		if (key%2==0)
		 {	key--; }
		While (*Temp != ‘\0’)
		{	*Temp += key;
			Temp += key;		}
}
void main(){
		int Key_Set[ ] = {1 ,2, 3};
		char Pvt_Msg[ ]=”Computer2018”;
		for (int C =0; C<2; C++)
		{	Encrypt (Pvt_Msg, Key_Set[C]);
			cout<<”New Encrypted Message after Pass “ <<C + 1<<” is : “ <<Pvt_Msg;
			cout<<endl; }
}
