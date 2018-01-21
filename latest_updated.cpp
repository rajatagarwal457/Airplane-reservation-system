/*
Airline Reservation System
Date: 08/12/2017
Author: @Ayush Agrawal, @Rajat Agarwal,@Pavan Bykampadi
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <conio.h>
#include <process.h>
#include <string.h>

using namespace std;

int main();
void admin();
struct Date
{

	int day,
	month,
	year;

};

struct Flight
{

	char num[6],
	al[20],
	src[4],
	dst[4];

	int price,
	seats,
	etdh,				//etd hour
	etah;            //eta hour

	Date etd,
	eta;

};


struct User
{

	char name[20],
	pwd[20];

	int booked[10],
	bcount,
	type;  					//0 - user, 1 - airline

} user[10];




/*
Functions for AIRS Flights
Date: 19/12/2017
Author: @Ayush Agrawal, @Rajat Agarwal
*/


Flight flight[100];

int n = 4, upos = 0,i,bcount; 											//number of flights, user logged in

void password(char pass[])
{

	cout<<"\nPlease enter your user password: ";
	for(i=0;i<20;i++)
	{
		pass[i]=getch();

		if(pass[i] !=8) {
			cout<<"*";

			if(pass[i]=='\r')
			break;
		}
		else if(pass[i]==8 && i > 0)
		{
			i-=2;
			cout<<"\b\b";
		}
	}
	pass[i]='\0';
}



void display_flights()
{
	for(int i=0; i<n; i++)
	{

		cout<<"\n\n"<<"No."<< (i + 1);
		cout<<"\n\n"<<"-----------------------------------------------------------------------------";
		cout<<"\n\n"<< flight[i].al << "\t" << flight[i].num;
		cout<<"\n\n"<<"-----------------------------------------------------------------------------";
		cout<<"\n\n"<<"Departure Date: "<<flight[i].etd.day<<" "<<flight[i].etd.month<<" "<<flight[i].etd.year;
		cout<<"\n\n"<<"Arrival Date:   "<<flight[i].eta.day<<" "<<flight[i].eta.month<<" "<<flight[i].eta.year;
		cout<<"\n\n"<<"Departs at:"<< flight[i].etdh<<"\t"<<"Arrives at: "<< flight[i].etah;
		cout<<"\n\n"<<"cost per seat "<< flight[i].price;


	}
}

void add_flight()
{

	//enter airline
	cout<<"\nEnter Airline:";
	cin>>flight[n].al;

	//input flight time
	cout<<"\n\nEnter Date of Departure: (DD MM YYYY): " << endl;
	cin >> flight[n].etd.day >> flight[n].etd.month >> flight[n].etd.year;

	cout<<"\n\nEnter Estimated time of Departure (24 hour):" << endl;
	cin >> flight[n].etdh;

	cout<<"\nEnter Date of Arrival: (DD MM YYYY): " << endl;
	cin >> flight[n].eta.day >> flight[n].eta.month >> flight[n].eta.year;

	cout<<"\n\nEnter Estimated time of Arrival (24 hour):" << endl;
	cin >> flight[n].etah;

	//generates flight number (eg AI250 etc)
	char fno[6];
	int i;

	for (i = 0; i < 2; i++)
	fno[i] = flight[n].al[i];

	for (; i < 5; i++)
	fno[i] = rand() % 10 + 49;

	fno[6]='\0';

	strcpy(flight[n].num, fno);


	//input destination and source
	cout<<"\nEnter Source Airport: " << endl;
	cin>>flight[n].src;

	cout<<"\n\nEnter Destination Airport: " << endl;
	cin>>flight[n].dst;

	cout<<"\nenter cost per seat :";
	cin>>flight[n].price;

	n++;

	//continue
	cout<<"\nEnter any key to continue";
	getch();

}

void del_flight()
{

	display_flights();

	cout<<"\nEnter sl no of flight to be deleted :";
	int pos;

	cin >> pos;


	for (int i = pos - 1; i <= n; i++)
	flight[i] = flight[i+1];
	n--;
}


void status()
{
	int count=0,a[10],x=0;

	bcount = user[upos].bcount;

	for(int i=0; i<n; i++)
	{
		for(int j = 0; j <= bcount; j++)
		{
			if(user[upos].booked[j] == i)
			{
				a[x]=i;
				x++;
				cout<<"\n\n"<<"No."<<count + 1;
				cout<<"\n\n"<<"-----------------------------------------------------------------------------------";
				cout<<"\n\n"<< flight[i].al << "\t" << flight[i].num;
				cout<<"\n\n"<<"-----------------------------------------------------------------------------------";
				cout<<"\n\n"<<"Departure Date: "<<flight[i].etd.day<<" "<<flight[i].etd.month<<" "<<flight[i].etd.year;
				cout<<"\n\n"<<"Arrival Date:   "<<flight[i].eta.day<<" "<<flight[i].eta.month<<" "<<flight[i].eta.year;
				cout<<"\n\n"<<"Departs at:"<< flight[i].etdh<<"\t"<<"Arrives at: "<< flight[i].etah;
				cout<<"\n\n"<<"cost per seat "<< flight[i].price;
				count++;
			}
		}
	}
	cout<<"\nPress R to return to main menu\nPress C to cancel a booking :";
	char ch;
	cin>>ch;
	if(ch=='C' || ch=='c')
	{
		cout<<"\nenter serial number of flight to cancel :";
		int cpos;
		cin>>cpos;
		cout<<"\nCancel flight from "<<flight[a[cpos-1]].src<<" to "<<flight[a[cpos-1]].dst<<"?\nPress C to confirm :";
		char conf;
		cin>>conf;
		if(conf=='C' || conf=='c')
		{
			user[upos].booked[a[cpos-1]] = -1;
			user[upos].bcount--;
			bcount--;
		}
	}
}
void pay(int pos)
{
	int CVV;
	cout<<"\nenter card no. :";
	double card_no;

	//for(int j = 0; j < 16; j++)
	cin >> card_no;

	cout<<"\n\nenter CVV :";

	cin >> CVV;
	cout<<"\nproccessing payment...";
	for (double i = 0; i < 100000000; i++) {}
	bcount = user[upos].bcount;

	user[upos].booked[bcount] = pos;
	user[upos].bcount++;
	bcount++;


}

void confirmation(int pos)
{
	int seats;

	cout<<"\nenter no. of seats :";
	cin>>seats;

	cout<<"\nPrice payable :"<< flight[pos].price * seats;

	cout<<"\n\n"<<"press any key to continue to payment page";
	getch();
	pay(pos);
}

void search()
{
	cout<<"\nenter source airport code :";
	char src[4];
	cin>>src;
	cout<<"\nenter destination airport code :";
	char des[4];
	cin>>des;

	int day, month, year;
	cout<<"\nenter date of departure : (DD MM YYYY) :";
	cin>>day>>month>>year;

	int count=0, a[10],x=0;
	for(int i=0; i<n; i++)
	{

		if(strcmpi(src,flight[i].src)==0 && strcmpi(des,flight[i].dst)==0 && flight[i].etd.day==day && flight[i].etd.month==month && flight[i].etd.year==year)
		{
			a[x]=i;
			x++;
			cout<<"\n\n"<<"No."<<count + 1;
			cout<<"\n\n"<<"-----------------------------------------------------------------------------------";
			cout<<"\n\n"<< flight[i].al << "\t" << flight[i].num;
			cout<<"\n\n"<<"-----------------------------------------------------------------------------------";
			cout<<"\n\n"<<"Departure Date: "<<flight[i].etd.day<<" "<<flight[i].etd.month<<" "<<flight[i].etd.year;
			cout<<"\n\n"<<"Arrival Date:   "<<flight[i].eta.day<<" "<<flight[i].eta.month<<" "<<flight[i].eta.year;
			cout<<"\n\n"<<"Departs at:"<< flight[i].etdh<<"\t"<<"Arrives at: "<< flight[i].etah;
			cout<<"\n\n"<<"cost per seat : "<< flight[i].price;
			count++;
		}
	}
	if(count !=0)
	{
		cout<<"\nenter serial no of flight to book :";
		int b;
		cin>>b;


		confirmation(a[b-1]);
	}
	else
	{
		cout<<"\nSorry!No flights match your request";
	}

}


void userf()
{

	int x=1;
	::bcount=user[upos].bcount;
	do
	{
		cout<<"\n1: Search for flights\n2: View current booking\n3: Exit";
		cout<<"\n\noption: ";
		int ch;
		cin>>ch;
		switch(ch){
			case 1:search();
			break;
			case 2:status();
			break;
			case 3:cout<<"\nThank you for using our services!!";
			x=0;
			break;
		}
	}while(x);
}
void admin()
{
	int x=1;
	do
	{
		cout<<"\n1. Add flight\n2. Delete flight\n3. Exit";
		cout<<"\n\nOption :";
		int ch;
		cin>>ch;
		switch(ch)
		{
			case 1:add_flight();
			break;
			case 2:del_flight();
			break;
			case 3:x=0;
			break;

		}
	}while(x);
}

int main()
{
	//Hardcoded values

	//Users
	strcpy(user[0].name, "ayush");
	strcpy(user[1].name, "rajat");
	strcpy(user[2].name, "pavan");
	strcpy(user[3].name, "airline");

	strcpy(user[0].pwd, "ayush");
	strcpy(user[1].pwd, "rajat");
	strcpy(user[2].pwd, "pavan");
	strcpy(user[3].pwd, "airline");

	user[0].bcount = 0;
	user[1].bcount = 0;
	user[2].bcount = 0;
	user[3].bcount = 0;

	user[0].type = 0;
	user[1].type = 0;
	user[2].type = 0;
	user[3].type = 1;

	//Flights
	flight[0].price=20000;
	flight[0].seats=150;
	flight[0].etdh=1200;
	flight[0].etah=1400;
	flight[0].etd.day=6;
	flight[0].etd.month=9;
	flight[0].etd.year=2018;

	flight[1].price=25000;
	flight[1].seats=150;
	flight[1].etdh=1100;
	flight[1].etah=1500;
	flight[1].etd.day=6;
	flight[1].etd.month=9;
	flight[1].etd.year=2018;

	flight[2].price=27000;
	flight[2].seats=150;
	flight[2].etdh=1000;
	flight[2].etah=1400;
	flight[2].etd.day=8;
	flight[2].etd.month=10;
	flight[2].etd.year=2018;

	flight[3].price=30000;
	flight[3].seats=180;
	flight[3].etdh=2000;
	flight[3].etah=2350;
	flight[3].etd.day=6;
	flight[3].etd.month=9;
	flight[3].etd.year=2018;

	strcpy(flight[0].al,"Emirates");
	strcpy(flight[0].src,"blr");
	strcpy(flight[0].dst,"dxb");
	strcpy(flight[0].num,"em469");

	strcpy(flight[1].al,"Emirates");
	strcpy(flight[1].src,"dxb");
	strcpy(flight[1].dst,"gnv");
	strcpy(flight[1].num,"em369");

	strcpy(flight[2].al,"Air France");
	strcpy(flight[2].src,"blr");
	strcpy(flight[2].dst,"cdg");
	strcpy(flight[2].num,"ai489");

	strcpy(flight[3].al,"Ethihad");
	strcpy(flight[3].src,"blr");
	strcpy(flight[3].dst,"dbx");
	strcpy(flight[3].num,"et420");

	char userName[20];
	char pass[20];
	int loginAttempt = 0;
	int i,c=0;

	while (loginAttempt < 5)
	{
		cout<<"\nPlease enter your user name: ";
		cin >> userName;

		password(pass);

		for(i=0; i<10; i++)
		{
			if(strcmp(userName, user[i].name)==0 && strcmp(pass, user[i].pwd)==0)
			{
				if (user[i].type == 0)
				userf();
				else
				admin();

				loginAttempt=0;
				upos = i;

				break;
			}
		}
	}
	if (loginAttempt == 5)
	{
		cout<<"\nToo many login attempts! The program will now terminate.";

	}

	cout<<"\nHave a good day!!\n";
	return 0;
}
