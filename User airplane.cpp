#include<iostream.h>
#include<process.h>
void status()
{
		int count=0;
		/*for(int i=0; i<no_of_planes; i++)
		{
				if(<airplane_constructor>[i].booked==1)
				{
					cout<<"\n"<<"No."<<count + 1;
					cout<<"\n"<<"-----------------------------------------------------------------------------------";
					cout<<"\n"<< <airplane_constructor>[i].airline_name << "\t" << <airplane_constructor>[i].filght_number;
					cout<<"\n"<<"-----------------------------------------------------------------------------------";
					cout<<"\n"<<"Departs at:"<< <airplane_constructor>[i].departure<<"\t"<<"Arrives at: << <airplane_constructor>[i].arrival;
					cout<<"\n"<<"cost per seat :<< <airplane_constructor>[i].cost;
					count++;
				}
			}*/

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
		/*<airplane_constructor>[pos].booked=1;*/
}
void confirmation(int f_no, int pos)
{
	 /*cout<<"enter no. of seats :"
    int seats;
    cin>>seats;
	 cout<<"Price payable :"<< <airplane_constructor>[pos].cost * seats;
    cout<<"\n"<<"press any key to continue to payment page";
		getch();
	 pay(pos);*/
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
	 /*for(int i=0; i<no_of_planes; i++)
	 {
		  if(strcmpi(src,<airplane_constructor>[i].src)==0 && strcmpi(des,<airplane_constructor>[i].des)==0)
		  {
        cout<<"\n"<<"No."<<count + 1;
				cout<<"\n"<<"-----------------------------------------------------------------------------------";
				cout<<"\n"<< <airplane_constructor>[i].airline_name << "\t" << <airplane_constructor>[i].filght_number;
				cout<<"\n"<<"-----------------------------------------------------------------------------------";
				cout<<"\n"<<"Departs at:"<< <airplane_constructor>[i].departure<<"\t"<<"Arrives at: << <airplane_constructor>[i].arrival;
				cout<<"\n"<<"cost per seat :<< <airplane_constructor>[i].cost;
        count++;
		  }
    }
	 cout<<"enter serial no of flight to book";
	 int b;
	 cin>>b;
    int f_no=<airplane_constructor>[b-1].filght_no;
	 confirmation(f_no, (b-1));*/
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
