/*
			Airline Reservation System
			Date: 08/12/2017
			Author: @Ayush Agrawal, @Rajat Agarwal,@Pavan Bykampadi
		*/

		int main();
		void admin();
		struct Date{

			int day,
				 month,
				 year;

		};

		struct Flight{

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


		struct User {

			char name[20],
				  pwd[20];

			int booked[10],
				 bcount,
				 type;  					//0 - user, 1 - airline

		} user[10];


		/*
			Hardcoded values
		*/

		/*
			Functions for AIRS Flights
			Date: 19/12/2017
			Author: @Ayush Agrawal, @Rajat Agarwal
		*/

		#include <iostream.h>
		#include <stdio.h>
		#include <stdlib.h>
		#include <iomanip.h>
		#include <conio.h>

		Flight flight[100];
		int n = 0, upos = 0; 											//number of flights, user logged in

		void password(char pass[]){

			cout<<"\nPlease enter your user password: ";
			for(int i=0;i<20;i++)
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
						cout<<"\n\n"<<"--------------------------------------------------------------------------------";
						cout<<"\n\n"<< flight[i].al << "\t" << flight[i].num;
						cout<<"\n\n"<<"--------------------------------------------------------------------------------";
						cout<<"\n\n"<<"Departs at:"<< flight[i].etdh<<"\t"<<"Arrives at: "<< flight[i].etah;
						cout<<"\n\n"<<"cost per seat "<< flight[i].price;


				}
		}

		void add_flight(){

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
			char fno[5];
			int i;
			for (i = 0; i < 2; i++)
				fno[i] = flight[n].al[i];

			for (; i < 5; i++)
				fno[i] = rand( ) % 10;


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

		void del_flight(){

			display_flights();

			cout<<"\nEnter sl no of flight to be deleted";
			int pos;

			cin >> pos;


			for (int i = pos - 1; i <= n; i++)
				flight[i] = flight[i+1];
			n--;
		}

		#include<process.h>
		#include<string.h>

		void status()
		{
				int count=0, bcount;

				bcount = user[upos].bcount;

				for(int i=0; i<n; i++)
				{
					for(int j = 0; j < bcount; j++){
						if(user[upos].booked[j] == i)
						{
							cout<<"\n\n"<<"No."<<count + 1;
							cout<<"\n\n"<<"-----------------------------------------------------------------------------------";
							cout<<"\n\n"<< flight[i].al << "\t" << flight[i].num;
							cout<<"\n\n"<<"-----------------------------------------------------------------------------------";
							cout<<"\n\n"<<"Departs at:"<< flight[i].etdh<<"\t"<<"Arrives at: "<< flight[i].etah;
							cout<<"\n\n"<<"cost per seat "<< flight[i].price;
							count++;
						}
					}
				}

		}
		void pay(int pos)
		{
			int bcount, CVV;
			cout<<"\nenter card no. :";
			double card_no[16];

			for(int j = 0; j < 16; j++)
				cin >> card_no[j];

			cout<<"\n\nenter CVV :";

			cin >> CVV;
			cout<<"\nproccessing payment...";
			for (double i = 0; i < 100000000; i++) {}
			bcount = user[upos].bcount;

			user[upos].booked[bcount] = pos;
			bcount++;


		}

		void confirmation(char f_no[6], int pos)
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

			 int count=0;
			 for(int i=0; i<n; i++)
			 {
				  if(strcmpi(src,flight[i].src)==0 && strcmpi(des,flight[i].dst)==0)
				  {
						cout<<"\n\n"<<"No."<<count + 1;
						cout<<"\n\n"<<"-----------------------------------------------------------------------------------";
						cout<<"\n\n"<< flight[i].al << "\t" << flight[i].num;
						cout<<"\n\n"<<"-----------------------------------------------------------------------------------";
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
				 char f_no[6];
				 strcpy(f_no, flight[b-1].num);
				 confirmation(f_no, (b-1));
			 }
			 else
			 {
				 cout<<"\nSorry!No flights match your request";
			 }

		}


		void userf()
		{

			 int x=1;
			 do{
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
			 do{
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
