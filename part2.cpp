/********************************************************************************************************'
This Program is based on the general crime record keeping
It consits of various fuctions and classes
This is a object oriented based programing in C++ language
This was done in Turbo C++
 ********************************************************************************************************/
#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<fstream>
#include<process.h>
#include<string.h>
#include<stdlib.h>

using namespace std;

class information                       //To input general details
{
	char name[20];
	char address[20];
	char occupation[20];
	unsigned long int phoneno;
	unsigned long int idno;
	int age;
	public:
        unsigned long int licenseno;
        void getdata();
        void putdata();
		void update();
		void del();
		void file();
}d;
void information :: getdata()   
{
	cout<<"\nEnter the details:\n\t";
	cout<<"Enter the name: ";
	cin>>name;
	cout<<"\tEnter the license no: ";
	cin>>licenseno;
	cout<<"\tEnter your occupation: ";
	cin>>occupation;
	cout<<"\tEnter your age: ";
	cin>>age;
	cout<<"\tThe Emirates ID no: ";
	cin>>idno;
	cout<<"\tEnter your phone no: ";
	cin>>phoneno;
}
void information :: putdata()
{
cout<<"\nThe details: \n Name: "<<name<<"\n Emirates ID number: " <<idno<<"\n Phone No.: "<<phoneno<<"\n License No.: " <<licenseno;
}
void information :: update()
{
	int lno;
	fstream fstud("hello.txt",ios::in);
	fstream ftemp("temp.txt",ios::out);	
	cout<<"\nEnter the license number to be updated:";
	cin>>lno;
	while(fstud)
	{
		if(licenseno==lno)
		{
			getdata();
			ftemp.write((char*)&d,sizeof(d));
		}
		else
		ftemp.write((char*)&d,sizeof(d));
	}
	fstud.close();
	ftemp.close();
	remove("hello.txt");
	rename("temp.txt","hello.txt");
	system("pause");
}
void information :: del()
{
	int lno;
	ifstream fstud("hello.txt");
	ofstream ftemp("temp.dat");
	cout<<"\nEnter license number to be deleted:";
	cin>>lno;
	while(fstud.read((char*)&d,sizeof(d)))
	{
		if(d.licenseno!= lno)
		ftemp.write((char*)&d,sizeof(d));
	}
	fstud.close();
	ftemp.close();
	remove("hello.txt");
	rename("temp.txt","hello.txt");
}
void information :: file()      			 //to open the file
{
	int n,i;
	ofstream fout;
	fout.open("hello.txt",ios::out|ios::app);
	if(!fout)
	cout<<"File can't open";
	cout<<"\nEnter the total no of people:";
	cin>>n;
	for(i=0;i<n;i++)
	{
		getdata();
		fout.write((char*)&d,sizeof(d));
	}
	fout.close();
}

class info_parking 			//Class to Add Information an the parking
{
	int blackpoint, total_blackpoint;
	char finename[30];
	unsigned int money, total_money;
	/*
    The Functioning rules on Black points:
    >> 24 black point per year is possible
    >> 24
    >> 24 black point you get thrice(yr) then license taken 
    */
	public:
	unsigned long int licensen;
	void cal()
	{
		total_money = total_money+money;
		total_blackpoint = total_blackpoint+blackpoint;
	}
	void gettogether();
	void getpoints();
	void putpoints();
	void Update();
	void Del();
	void police();
	void searchbylisenceno();
	void newblack();
}p;
void info_parking :: gettogether()
{
	cout<<"Enter the blackpoints:";
	cin>>blackpoint;
	cout<<"Enter the vilolation:";
	cin>>finename;
	cout<<"Enter the amount:";
	cin>>money;
	cal();
}
void info_parking :: getpoints()
{
	int a;
	cout<<"Choose your option: \n1.Black points\n2.Fine payment\n3.Together\nEnter the choice";
	switch(a)
	{
		case 1: cout<<"Enter the total black points: ";
			cin>>blackpoint;
			cal();
			break;
		case 2: cout<<"Enter the violation: ";
			cin>>finename;
			cout<<"Enter the amount for fine payment: ";
			cin>>money;
			cal();
			break;
		case 3: gettogether();
			break;
		default: cout<<"Wrong choice";
			break;
	}
}
void info_parking :: putpoints()
{
	cout<<"\n The Black points: "<<total_blackpoint<<" \n Your violations:" <<finename<<"\n Total fine: AED "<<total_money;
}
void info_parking :: Update()
{
	int lno;
	fstream fstud("police.txt",ios::in);
	fstream ftemp("temp.txt",ios::out);
	cout<<"\nEnter the license number to be updated: ";
	cin>>lno;
	while(fstud.read((char*)&p,sizeof(p)))
	{
		if(licensen==lno)
		{
			gettogether();
			ftemp.write((char*)&p,sizeof(p));
		}
		else
		ftemp.write((char*)&p,sizeof(p));
	}
	fstud.close();
	ftemp.close();
	remove("police.txt");
	rename("temp.txt","police.txt");
	system("pause");
}
void info_parking :: Del()
{
	int lno;
	ifstream fstud("police.txt");
	ofstream ftemp("temp.txt");
	cout<<"\n Enter license number to be deleted: ";
	cin>>lno;
	while(fstud.read((char*)&p,sizeof(p)))
	{
		if(licensen!= lno)
		ftemp.write((char*)&p,sizeof(p));
	}
	fstud.close();
	ftemp.close();
	remove("police.txt");
	rename("temp.txt","police.txt");
}
void info_parking :: police()
{
	int pincode,c;
	cout<<"\nEnter the pincode: ";
	cin>>pincode;
	if(pincode==1234)
	{
		cout<<"\nMenu\n1.Person's details \n2.Black points";
		cout<<"\n3.Delete\n4.Modify\nEnter the choice: ";
		cin>>c;
		switch(c)
		{
			case 1: d.file();
				break;
			case 2: newblack();
				break;
			case 3: cout<<"\nMenu\n1.Delete details\n2.Delete black points\nEnter the choice:";
				cin>>c;
				if(c==1)
					d.del();
				else
					Del();
				break;
			case 4: cout<<"\nMenu\n1.Modify details\n2.Modify black points\nEnter your choice:";
				cin>>c;
				if(c==1)
					d.update();
				else
					Update();
				break;
			default:cout<<"Wrong entry";
				break;
		}
	}
	else
	{
		cout<<"Alert :O ..INTRUDER!!!!!!!!!!!”";
	}
}
void info_parking :: searchbylisenceno()
{
	int found=0;
	unsigned long int lno;
	fstream fstud("hello.txt",ios::in);
	fstream fst("police.txt",ios::in);
	cout<<"\nEnter the license number: ";
	cin>>lno; 
	while(fstud.read((char*)&d,sizeof(d)))
	if(d.licenseno==lno)
	{
		d.putdata();
		found=1;
		break;
	}
	while(fst.read((char*)&p,sizeof(p)))
	if(licensen == lno)
	{
		putpoints();
		found=2;
		break;
	}
	if(found==0)
	cout<<"\nLicense number not found\n";
	fstud.close();
	fst.close();
}
void info_parking :: newblack()
{
	fstream fst("police.txt",ios::out|ios::app);
	int i,n;
	if(!fst)
	cout<<"\nfile can't open";
	system("pause");
	cout<<"\nEnter the total number of entries :";
	cin>>n;
	for(i=0;i>n;++i)
	{
		getpoints();
		fst.write((char*)&p,sizeof(p));
	}
	fst.close();
}

int main()
{
	int z;
	char choice;
	do
	{
        cout<<"Menu\n1. General\n2. Guest\nEnter your choice:";
        cin>>z;
        
        switch(z)
        {
            case 1:p.police();
                break;
            case 2:p.searchbylisenceno();
                break;
            default:cout<<"Sorry Wrong Input";
                break;
        }
        system("pause");
        cout<<"\nDo you want to in main menu continue?(y/n)... \n";
        cin>>choice;
	}while(choice=='y');
	cout<<"\nGood bye";
	return 0;
}

