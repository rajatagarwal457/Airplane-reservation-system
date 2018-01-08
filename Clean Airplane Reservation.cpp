/*
			Airline Reservation System
			Date: 08/12/2017
			Author: @Ayush Agrawal, @Rajat Agarwal
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
				 booked,
				 etdh,				//etd hour
				 etah;            //eta hour

			Date etd,
				  eta;
			//Aircraft aircraft;
		};



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
		int n = 0; 											//number of flights


		void display_flights()
		{
			for(int i=0; i<n; i++)
			{

						cout<<"\n\n"<<"No."<<i + 1;
						cout<<"\n\n"<<"-----------------------------------------------------------------------------------";
						cout<<"\n\n"<< flight[i].al << "\t" << flight[i].num;
						cout<<"\n\n"<<"-----------------------------------------------------------------------------------";
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

			cout<<"\n\n\nEnter Date of Arrival: (DD MM YYYY): " << endl;
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
			cout<<"\n\n\nEnter Source Airport: " << endl;
			cin>>flight[n].src;

			cout<<"\n\nEnter Destination Airport: " << endl;
			cin>>flight[n].dst;

			cout<<"enter cost per seat :";
			cin>>flight[n].price;

			n++;

			//continue
			cout<<"\n\n\nEnter any key to continue";
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
				int count=0;
				for(int i=0; i<n; i++)
				{
						if(flight[i].booked==1)
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
		void pay(int pos)
		{
				cout<<"\nenter card no. :";
				double card_no;
				cin>>card_no;
				cout<<"\n\nenter CVV";
				int CVV;
				cin >> CVV;
				cout<<"\nproccessing payment...";
				for (double i = 0; i < 100000000; i++) {}
				flight[pos].booked=1;
		}
		void confirmation(char f_no[6], int pos)
		{
			 cout<<"\nenter no. of seats :";
			 int seats;
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
			 char userData[20][20];
			 char passData[20][20];
			 char airlineData[20][20];
			 char airlinePassData[20][5];
			 strcpy(userData[0], "rajat");
			 strcpy(passData[0], "rajat");
			 strcpy(userData[1], "ayush");
			 strcpy(passData[1], "ayush");
			 strcpy(airlineData[0], "airline");
			 strcpy(airlinePassData[0], "abcd");
			 char userName[20];
			 char userPassword[20];
			 int loginAttempt = 0;
			 int i;

			 while (loginAttempt < 5)
			 {
				  cout<<"\nPlease enter your user name: ";
				  cin >> userName;
				  cout<<"\nPlease enter your user password: ";
				  cin >> userPassword;
					for(i=0; i<5; i++)
					{

						if(strcmp(userName, userData[i])==0 && strcmp(userPassword, passData[i])==0)
							{
								userf();
								loginAttempt=0;
								i=0;
								break;
							}
					}

					for(i=0; i<5; i++)
					{
						if(strcmp(userName, airlineData[i])==0 && strcmp(userPassword, airlinePassData[i])==0)
								{
									admin();
								  loginAttempt=0;
									i=0;
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
