/*
	Structure file for Airline Reservation System
	Date: 08/12/2017
	Author: @Ayush Agrawal
*/


struct Date{

	int day,
		 month,
		 year;

};

struct Aircraft{

	char name[20];
	int rows,
		 cols,
		 aislepos;

};

struct Airline{

	char name[20],
		  pwd[20];

};

struct Flight{

	char num[6],
		  al[20],
		  src[4],
		  dst[4];

	int price,
		 booked,
		 etdh,				//etd hour
		 etah;            //eta hour

	Date etd,
		  eta;
	//Aircraft aircraft;
};

struct User{

	char name[20],
		  pwd[20];
	int  type; 			//0 - airline, 1 - user

};


//----------------------------------------------------------------------------//


/*
	Functions for AIRS Flights
	Date: 19/12/2017
	Author: @Ayush
*/

#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip.h>

Flight flight[100];
int n = 0; 											//number of flights

void add_flight(){

	clrscr();

	//enter airline
	cout << "Enter Airline:";
	gets(flight[n].al);

	//input flight time
	cout << "\nEnter Date of Departure: (DD MM YYYY): " << endl;
	cin >> flight[n].etd.day >> flight[n].etd.month >> flight[n].etd.year;

	cout << "\nEnter Estimated time of Departure (24 hour):" << endl;
	cin >> flight[n].etdh;

	cout << "\n\nEnter Date of Departure: (DD MM YYYY): " << endl;
	cin >> flight[n].eta.day >> flight[n].eta.month >> flight[n].eta.year;

	cout << "\nEnter Estimated time of Departure (24 hour):" << endl;
	cin >> flight[n].etah;

	//generates flight number (eg AI250 etc)
	char fno[5];
	for (int i = 0; i < 2; i++)
		fno[i] = flight[n].al[i];

	for (; i < 5; i++)
		fno[i] = random(10);

	//input destination and source
	cout << "\n\nEnter Source Airport: " << endl;
	gets(flight[n].src);

	cout << "\nEnter Destination Airport: " << endl;
	gets(flight[n].dst);

	n++;

	//continue
	cout << "\n\nEnter any key to continue";
	getch();
}

void del_flight(){

	//display_flights();

	cout << "Enter sl no of flight to be deleted";
	int pos;

	cin >> pos;
	pos--;

	for (int i = pos - 1; i <= n; i++)
		flight[i] = flight[i+1];
}


//----------------------------------------------------------------------------//


void disp_search(int day, int hour, int year, int f_class, int pmin, int pmax){


}

/*
void search_flight(){

	clrscr();

	//Enter flight details
	int f_class, pmin = 0, pmax = 100000;
	Date date;
	char filt, src[4], dst[4];

	cout << "\nEnter date of flight (DD MM YYYY):" << endl;
	cin >> date.day >> date.month >> date.year;

	cout << "\nEnter flight source: " << endl;
	cin >> src;

	cout << "\nEnter flight destination: " << endl;
	cin >> dst;

	cout << "\nEnter class (Business: 1, Economy: 2): " << endl;
	cin >> f_class;

	cout << "\n\nEnter any key to continue: ";
	getch();

	clrscr();

	cout << setw(5) << "F No" << setw(10) << "Airline" << setw(10) << "Source";

	for (int i = 0; i <= n; i++){
		if (strcmp(src,flight[i].src) && strcmp(dst, flight[i].dst) && date == flight[i].etd && flight[i].price >= pmin && flight[i].price <=pmax);
			disp_search(i);
	}
}
*/

//----------------------------------------------------------------------------//

#include<process.h>
#include<string.h>
void status()
{
		int count=0;
		for(int i=0; i<n; i++)
		{
				if(flight[i].booked==1)
				{
					cout<<"\n"<<"No."<<count + 1;
					cout<<"\n"<<"-----------------------------------------------------------------------------------";
					cout<<"\n"<< flight[i].al << "\t" << flight[i].num;
					cout<<"\n"<<"-----------------------------------------------------------------------------------";
					cout<<"\n"<<"Departs at:"<< flight[i].etdh<<"\t"<<"Arrives at: "<< flight[i].etah;
					cout<<"\n"<<"cost per seat "<< flight[i].price;
					count++;
				}
			}

}
void pay(int cost)
{
		cout<<"enter card no. :";
		long int card_no;
		cin>>card_no;
		cout<<"\nenter CVV";
		int CVV;
		cin>>CVV;
		cout<<"proccessing payment...";
		flight[cost].booked=1;
}
void confirmation(char f_no[6], int pos)
{
	 cout<<"enter no. of seats :";
	 int seats;
	 cin>>seats;
	 cout<<"Price payable :"<< flight[pos].price * seats;
	 cout<<"\n"<<"press any key to continue to payment page";
		getch();
	 pay(pos);
}
void search()
{
	 cout<<"enter source airport code :";
	 char src[4];
	 cin>>src;
	 cout<<"enter destination airport code :";
	 char des[4];
	 cin>>des;
	int count=0;
	 for(int i=0; i<n; i++)
	 {
		  if(strcmpi(src,flight[i].src)==0 && strcmpi(des,flight[i].dst)==0)
		  {
		  cout<<"\n"<<"No."<<count + 1;
				cout<<"\n"<<"-----------------------------------------------------------------------------------";
				cout<<"\n"<< flight[i].al << "\t" << flight[i].num;
				cout<<"\n"<<"-----------------------------------------------------------------------------------";
				cout<<"\n"<<"Departs at:"<< flight[i].etdh<<"\t"<<"Arrives at: "<< flight[i].etah;
				cout<<"\n"<<"cost per seat : "<< flight[i].price;
		  count++;
		  }
	 }
	 cout<<"enter serial no of flight to book";
	 int b;
	 cin>>b;
	 char f_no[6];
	 strcpy(f_no, flight[b-1].num);
	 confirmation(f_no, (b-1));

}


void main()
{
	 int x=1;
	 do{
		 cout<<"1: Search for flights\n2: view current booking\n3: exit";
		 int ch;
		 cin>>ch;
		 switch(ch){
			 case 1:search();
					  break;
			 case 2:status();
					  break;
			 case 3:cout<<"Thank you for using our services!!";
					  exit(0);
		 }
	 }while(x);
}

int main ()
{
	 string userName;
	 string userPassword;
	 int loginAttempt = 0;

	 while (loginAttempt < 5)
	 {
		  cout << "Please enter your user name: ";
		  cin >> userName;
		  cout << "Please enter your user password: ";
		  cin >> userPassword;

		  if (userName == "pavan" && userPassword == "pavbyk")
		  {
				cout << "Welcome Pavan!\n";
				break;
		  }
		  else if (userName == "ayush" && userPassword == "ayush")
		  {
				cout << "Welcome Ayush!\n";
				break;
		  }
		  else if (userName == "rajat" && userPassword == "rajat")
		  {
				cout << "Welcome Rajat!\n";
				break;
		  }
		  else if (userName == "Lufthansa" && userPassword == "la0987")
		  {
				cout << "Welcome Lufthansa admin!\n";
				break;
		  }
		 else
		  {
				cout << "Invalid login attempt. Please try again.\n" << '\n';
				loginAttempt++;
		  }
	 }
	 if (loginAttempt == 5)
	 {
				cout << "Too many login attempts! The program will now terminate.";
				return 0;
	 }

	 cout << "Have a good day!!\n";
}
