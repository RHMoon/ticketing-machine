// SID/Name 	: 16916079 / Efi R. Shagira
//				  16916216 / I Komang Suvarmana Wisuta
//				  16916348 / Naufal Muhammad Farras
// File name 	: Ticketing_Machine.cpp
// Date 		: 4 November 2016, 16 November 2016, 24 November 2016, 27 November 2016(latest update)
// Description 	: Making progam to simulate ticket machine 

#include <iostream>
#include <fstream>
using namespace std;

void menu(char x);
void destination(string x);
int payment(int x);
//void exch(int x);
void bcode(int x);
void pause(string opt);
void timeDis(int x);

int show,i,j=0,temp=0,n,a,b,t,s;
int A[50];
int jCount,mCount,sCount,yCount;
string city;
string M[6][4];

int main() {
	ifstream ins; // set variable for input stream
	string answer;
	string city;
	char p;
	int C[4],c=0;
	
	ins.open("count.dat");
	
	while (!ins.eof()) {
		ins >> C[c];
		c++;
	}
	ins.close();
	
	jCount=C[0];
	mCount=C[1];
	sCount=C[2];
	yCount=C[3];
	i=0;
	show=1;
	
	while(show==1){
		ins.open("count.dat");
		int C[4],c=0;
		while (!ins.eof()) {
			ins >> C[c];
			c++;
		}
		ins.close();
		
		jCount=C[0];
		mCount=C[1];
		sCount=C[2];
		yCount=C[3];
		
		cout << "WELCOME TO KAI" << endl << endl;// prints
		cout << "Kereta Api ITB" << endl << endl << endl;// prints
		cout << "0. Cancel" << endl << endl;// prints
		cout << "1. Get ticket" << endl << endl;// prints
		cout << "2. Check in" << endl << endl;// prints
		cout << "3. Get schedule" << endl << endl;// prints
		cout << "Please enter the service number ";// prints
		
		cin >> p;
		menu(p);
		
		ofstream myfile("count.dat"); //deklarasi variable myfile
		if (myfile.is_open()){
			C[0]=jCount;
			C[1]=mCount;
			C[2]=sCount;
			C[3]=yCount;
			for (int r=0;r<4;r++){
				myfile << C[r]<<endl;
			}

			myfile.close(); //penting! Menandakan file telah selesai diproses
		}	
		else {
			cout << "File can't be opened'";break;	
		}
		
	}
	
}

void menu(char x){
	char n;
	ifstream ins;
	void bcheck(),fList();
	
	//inputing schedule from 'schedule.dat'
	ins.open("schedule.dat");
	
	while (!ins.eof()) {
		for(i=0;i<6;i++){
			for(j=0;j<4;j++){
				ins >> M[i][j];	
			}
		}
	}
	ins.close();
	
	switch(x){
			case '0' : system("CLS");show = 0; cout<< endl << "Thank you for using our service."<<endl; pause(" "); break;
			case '1' : system ("CLS");cout <<endl<< "You have selected service "<< x <<endl;
			 cout << "Choose you destination"<<endl<<endl;
			 cout << "0. Cancel" << endl << endl;
			 cout << "1. Jakarta" << endl << endl;
			 cout << "2. Malang" << endl << endl;
			 cout << "3. Surabaya" << endl << endl;
			 cout << "4. Yogyakarta" << endl << endl;
			 l:cout << "Please enter your destination number"<< endl << endl;
			 cin >> n;
			 switch(n){
			 		case '0' :system("CLS");
			 			break;
			 		case '1' : city = "Jakarta"; destination(city);
			 			break;
			 		case '2' : city ="Malang"; destination(city);
			 			break;
			 		case '3' : city = "Surabaya"; destination(city);
			 			break;
					case '4' : city = "Yogyakarta"; destination(city);
						break;
			 		default : cout <<"\nWrong input! Please try again!\n\n"; goto l;
		     }
			 break;
			case '2' : system ("CLS");cout <<endl<< "You have selected service "<< x <<endl;
					   bcheck();
			 break;
			case '3' : system ("CLS");cout <<endl<< "You have selected service "<< x <<endl;
				cout << endl << "		  D E P A R T U R E 	S C H E D U L E"<<endl<<endl;
				for(i=0;i<6;i++){
					
					for(j=0;j<4;j++){
						if(j==0||j==1||j==2||j==3){
							cout<<"	";
							
							if (j==2){
								cout<< "	";
								if (M[i][j]=="-"){
									cout <<"  ";
								}
							}
							if (j==3){
								cout<<"  ";
								if (M[i][j]=="-"){
									cout <<"  ";
								}
							}
							if(i!=0){
								cout<<" ";
								if(j==1){
									cout << "	";
									if (M[i][j]=="-"){
										cout <<"  ";
									}
								}
								if(j==3){
									cout<<"	    ";
									if (M[i][j]=="-"){
										cout <<"  ";
									}
								}
				
							}
						}
						cout<<M[i][j]<<" ";
					}
					cout <<endl<<endl;
				}pause(" ");system ("CLS");break;
			case 'l':system ("CLS");cout << "You entered admin mode"<<endl;
				cout <<endl<< "Log (Latest)"<<endl;
				while(b!=0){
					for (i=0;i<temp;i++){
						cout<<endl<<A[i];cout<< "	A["<<i<<"]"<<endl;
						if(i==temp-1){
							goto f;
						}
					}
				}
				cout <<endl<<endl<<"        	  	"<< "[E	M	P	T	Y]"<<endl<<endl;
				f:cout << "\nstatus:	temp = "<<temp;
				cout << " a = "<<a;
				cout << " b = "<<b;
				cout << " Jakarta = "<<jCount;
				cout << " Malang = "<<mCount;
				cout << " Surabaya = "<<sCount;
				cout << " Yogyakarta = "<<yCount<<endl;
				cout << "\n\nfor more detailed log you can see the list on Full List with pressing 'f' on \nmain menu.";
				pause(" ");system ("CLS");break;
			case 'r': system("CLS");char confrm;cout <<endl<< "Do you want to reset? <y/n> ";
				a:cin >> confrm;
				while(confrm != 'n'&& confrm != 'N'&& confrm !='y' && confrm !='Y'){
					cout << endl << "You put wrong key! Please try again!"<<endl;
					goto a;
				}
				if (confrm == 'y'|| confrm =='Y'){
					int C[4];
					ofstream myfile("count.dat"); //deklarasi variable myfile
					if (myfile.is_open()){
						C[0]=0;
						C[1]=0;
						C[2]=0;
						C[3]=0;
						for (int r=0;r<4;r++){
							myfile << C[r]<<endl;
						}
						myfile.close(); //penting! Menandakan file telah selesai diproses
						jCount=C[0];
						mCount=C[1];
						sCount=C[2];
						yCount=C[3];
						a=0;
						b=0;
						cout << "\nCounter has been reset"<<endl;
					}	
					else {
						cout << "File can't be opened'";break;	
					}
					ofstream enlist("log.dat"); //deklarasi variable enlist
					if (enlist.is_open()){
						enlist << "BookingCode"<<"\t  City"<<"\t\tTime"<<endl;
						enlist.close(); //penting! Menandakan file telah selesai diproses
						cout << "\nLog has been reset";
					}	
					else {
						cout << "File can't be opened'";break;	
					}
					for (i=0;i<temp;i++){
						A[i]='\0';
					}
					temp=0;
					pause(" ");system("CLS");
					
				}
				else if (confrm == 'n'||confrm == 'N')
				{
					cout << endl;break;
				}break;
			case 'f': system("CLS");fList();break;
	
			default: system ("CLS");cout <<"Wrong input! Please try again!"<<endl; break;
			
	}
}

void destination(string x){
	char confrm;
	int f,l;
	void timeDis(int x, int *p);
	
	system ("CLS");cout << endl << "You have selected " << x << endl << endl;
	if (x=="Jakarta"){
		f=0;
		timeDis(f,&l);
	}
	if(x=="Malang"){
		f=1;
		timeDis(f,&l);
	}
	if(x=="Surabaya"){
		f=2;
		timeDis(f,&l);
	}
	if(x=="Yogyakarta"){
		f=3;
		timeDis(f,&l);
	}
	r:cout<<"Please enter the time departure: ";
	int c; cin >> c;
	while(c>l||c<=0){
		cout << endl << "You put wrong key! Please try again!"<<endl<<endl;
		goto r;
	}
	cout << "Please enter the number of seat: ";
	cin >> n; cout << endl << "You have to pay " << payment(n) << endl;
	
	a:
	cout << endl << "Are you sure? <y/n> " ;
	cin >> confrm;
	while(confrm != 'n'&& confrm != 'N'&& confrm !='y' && confrm !='Y'){
		cout << endl << "You put wrong key! Please try again!"<<endl;
		goto a;
	}
	if (confrm == 'y'|| confrm =='Y')
	{
	
		int d;
		
		system ("CLS");cout << "Your destination " << city << endl << endl << 
		"Time Departure : ";for (i=1;i<6;i++){
			if (city=="Jakarta"){
				d=0;
			}
			if (city=="Malang"){
				d=1;
			}
			if (city=="Surabaya"){
				d=2;
			}
			if (city=="Yogyakarta"){
				d=3;
			}
			if(c==i){
				cout << M[i][d];
				t=i;
				s=d;
			}
		}
		
		cout<<"\nTotal seat: " << n << endl << 
		"\nYour Booking code"<< endl;
		bcode(n);
		//exch(n);
		pause("tk");
		system ("CLS");
	}
	
	else if (confrm == 'n'||confrm == 'N')
	{
		cout << "\nThank you for using our service" << endl;
		pause(" ");
		system ("CLS");
	}			  	
}

int payment(int x){
	int p;
	if (city=="Jakarta"){
		p=x*100000;
	}
	else if (city=="Malang"){
		p=x*175000;
	}
	else if (city=="Surabaya"){
		p=x*200000;
	}
	else if (city=="Yogyakarta"){
		p=x*225000;
	}
	return p;
}

void bcode(int x){
	fstream me("log.dat",fstream::app);
	//ifstream ime("log.dat");
	
	b = temp;
	a=temp+x;
	if (city=="Jakarta"){
		for (i=temp;i<a;i++){
			A[b]=jCount+14416000;
			b++;
			temp++;
			jCount++;
		}
	}
	else if (city=="Malang"){
		j=44416000;
		for (i=temp;i<a;i++){
			A[b]=mCount+j;
			b++;
			temp++;
			mCount++;
		}
	}
	else if (city=="Surabaya"){
		j=40016000;
		for (i=temp;i<a;i++){
			A[b]=sCount+j;
			b++;
			temp++;
			sCount++;
		}
	}
	else if (city=="Yogyakarta"){
		j=11316000;
		for (i=temp;i<a;i++){
			A[b]=yCount+j;
			b++;
			temp++;
			yCount++;
		}
	}
	for (i=temp-x;i<a;i++){
		cout<<endl<<A[i];cout<<endl;
	}
	
	if(me.is_open()){
		for (int r=temp-x;r<a;r++){
			me<<endl<<A[r];
			if (city=="Jakarta"){
				me<< "\t "<<city<<"\t"<<M[t][s]<<endl;
			}
			if (city=="Malang"){
				me<< "\t  "<<city<<"\t"<<M[t][s]<<endl;
			}
			if (city=="Surabaya"){
				me<< "\t "<<city<<"\t"<<M[t][s]<<endl;
			}
			if (city=="Yogyakarta"){
				me<< "\t"<<city<<"\t"<<M[t][s]<<endl;
			}
			
		}
		me.close();
	}
	else{
		cout << "File can't be opened'";
	}
	
}
void bcheck(){
	ifstream book;
	string C[100][3],p;
	int c=0,g=0;
	book.open("log.dat");
	
	while (!book.eof()) {
		while(g<3){
			book >> C[c][g];
			g++;	
		}
		g=0;c++;
	}
	
	book.close();
	
	cout << "Please enter your booking code " << endl << endl;
	cin>>p;
	
	for (i=0;i<c;i++){
		if(p == C[i][0]){
			cout << endl << "You have check in with booking code "<<p;
			break;
		}
		else{
			if (i==c-1){
				pause("nlist");
				break;
			}
		}
	}
	cout<< endl << endl ; pause(" "); system("CLS");
}
void timeDis(int x, int *p){//display time schedule option when buying ticket
	int r=0;
	int g=0;
	cout<<"TIME SCHEDULE:"<<endl<<endl;
	
	for (i=1;i<6;i++){
		q:if (M[i][x]=="-"){
			
			if(i+1==6){
				goto r;
			}
			i++;
			goto q;
		}
		g++;
		cout <<" "<< g<<". "<< M[i][x]<<endl<<endl;
	}r:cout<<endl;
	*p=g;
}

void fList(){//to show full list of log from file
	ifstream ins; 
	string C[100][3];
	int c=0,g=0;
	
	ins.open("log.dat");
	
	while (!ins.eof()) {
		a:ins >> C[c][g];
		g++;
		if (g==2){
			ins >>C[c][g];
			g=0;c++;
			goto a;
		}
	}
	
	ins.close();
	cout << "\nFull List Log\n\n\n";
	for (i=0;i<c;i++){
		for(j=0;j<3;j++){
			if(C[1][0]=="\0"){
				cout<<"List still empty"<<endl;
				goto d;
			}
			if(i==0){
				if(j==1){
					cout<<"\t";
				}
				if (j==2){
					cout<<"\t";
				}
			}
			if(j==0||j==1||j==2){
				cout<<"	";
							
				if (j==2){
					cout<< "\t";
				}
				if(i!=0){
					cout<<" ";
					if (C[i][1]=="Malang"){
						if(j==2){
							cout << "\t ";
						}
					}
					if(j==1){
						if (C[i][1]=="Malang"){
							cout<<"\t";
						}
						if (C[i][1]=="Yogyakarta"){
							cout << "     ";
							
						}
						if(C[i][1]=="Surabaya"){
							cout << "      ";
						}
						if (C[i][1]=="Jakarta"){
							cout << "\t";
							
						}
						cout << "";
					}
				}
			}
			cout<<C[i][j]<<" ";
		}	
		cout << endl<<endl;
	}
	
	d:pause(" ");system("CLS");
}

void pause(string opt){//in exchage of system("PAUSE")
    if(opt=="tk"){
     cout << "\nPlease take your tickets . . . ";
     cin.get();
     cin.get();
     cout<<endl;
	}
	 if(opt=="nlist"){
     cout <<"\nYour booking code is not on the list! Please try again!";
     cout << "\n\nPress any key to continue . . .";
     cin.get();
     cin.get();
	}
	//
	if(opt==" "){
	 cout << "\n\nPress any key to continue . . .";
     cin.get();
     cin.get();
     cout<<endl;
	}
}
