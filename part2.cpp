/********************************************************************************************************'
This Program is based on the general crime record keeping
It consits of various fuctions and classes
This is a object oriented based programing in C++ language
This was done in Turbo C++
 ********************************************************************************************************/
#include <iostream>
#include<conio.h>
#include<stdio.h>
#include<fstream.h>
#include<process.h>
#include<string.h>
#include<stdlib.h>

using namespace std;

void del4police();
void del4details();
void update4police();
void update4details();

class details                       //To enter and input details to file
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
}hi;
void details :: getdata()
{
	cout<<"\nEnter the details:\n\t";
	cout<<"Enter the name:";
	gets(name);
	cout<<"\n\t Enter the license no:";
	cin>>licenseno;
	cout<<"\n\t Enter your occupation:";
	gets(occupation);
	cout<<"\n\t Enter your age:";
	cin>>age;
	cout<<"\t The Emirates ID no:";
	cin>>idno;
	cout<<"\t Enter your phone no:";
	cin>>phoneno;
	system("pause");
}
void details :: putdata()
{
cout<<"\nThe details:\n Name:"<<name<<"\n Emirates ID number:" <<idno<<"\n Phone number :"<<phoneno<<"\n License number:" <<licenseno;
}

class po   			//To Enter the police details
{
	int blackpoint;
	char finename[30];
	unsigned int money;
	unsigned int tmoney;
	int tblackpoint;
	/*24 black point per yr(3month license taken for 1 month)
	  24 black point u get thrice(yr) then license taken */
	public:
	unsigned long int licensen;
	void cal()
	{
		tmoney = tmoney+money;
		tblackpoint = tblackpoint+blackpoint;
	}
	void gettogether();
	void getpoints();
	void putpoints();
}po1;
void po :: gettogether()
{
	cout<<"Enter the blackpoints:";
	cin>>blackpoint;
	cout<<"Enter the vilolation:";
	gets(finename);
	cout<<"Enter the amount:";
	cin>>money;
	cal();
}
void po :: getpoints()
{
	int a;
	cout<<"Choose your option: \n 1.Black points\n 2.Fine payment\n 3.Together\nEnter the choice";
	switch(a)
	{
		case 1: cout<<"Enter the total black points:";
			cin>>blackpoint;
			cal();
			break;
		case 2: cout<<"Enter the violation: ";
			gets(finename);
			cout<<"Enter the amount for fine payment:";
			cin>>money;
			cal();
			break;
		case 3: gettogether();
			break;
		default: cout<<"Wrong choice";
			break;
	}
}
void po :: putpoints()
{
	cout<<"\n The Black points : "<<tblackpoint<<" \n Your violations:" <<finename<<"\n Total fine : AED "<<tmoney;
}

void file()      			 //to open the file
{
	int n,i;
	ofstream fout;
	fout.open("hello.txt",ios::out|ios::app);
	if(!fout)
	cout<<"File can't open";
	system ("pause");
	cout<<"Enter the total no of people:";
	cin>>n;
	for(i=0;i<n;i++)
	{
		hi.getdata();
		fout.write((char*)&hi,sizeof(hi));
	}
	fout.close();
}
void searchbylisenceno()
{
	fstream fstud("hello.txt",ios::in);
	fstream fst("police.txt",ios::in);
	details s1;
	po p1;
	int found=0;
	unsigned long int lno;
	cout<<"\nEnter the license number:";
	cin>>lno;
	while(fstud.read((char*)&s1,sizeof(s1)))
	if(s1.licenseno==lno)
	{
		s1.putdata();
		found=1;
		break;
	}
	while(fst.read((char*)&p1,sizeof(p1)))
	if(p1.licensen == lno)
	{
		p1.putpoints();
		found=2;
		break;
	}
	if(found==0)
	cout<<"\n License number not found";
	fstud.close();
	fst.close();
}
void newblack()
{
	fstream fst("police.txt",ios::out|ios::app);
	po p1;
	int i,n;
	if(!fst)
	cout<<"\nfile can't open";
	system("pause");
	cout<<"\nEnter the total number of entries :";
	cin>>n;
	for(i=0;i>n;++i)
	{
		p1.getpoints();
		fst.write((char*)&p1,sizeof(p1));
	}
	fst.close();
}
void police()
{
	int pincode,c;
	cout<<"\nEnter the pincode:";
	cin>>pincode;
	if(pincode==1234)
	{
		cout<<"\nMenu\n1.Person's details \n2.Black points";
		cout<<"\n3.Delete\n4.Modify\nEnter the choice:";
		cin>>c;
		switch(c)
		{
			case 1: file();
				break;
			case 2: newblack();
				break;
			case 3: cout<<"\nMenu\n1.Delete details\n2.Delete black points\nEnter the choice:";
				cin>>c;
				system("pause");
				if(c==1)
				del4details();
				else
				del4police();
				break;
			case 4: cout<<"\nMenu\n1.Modify details\n2.Modify black points\nEnter your choice:";
				cin>>c;
				system("pause");
				if(c==1)
				update4details();
				else
				update4police();
				break;
			default:cout<<"Wrong entry";
				break;
		}
	}
	else
	{
		cout<<"Alert :O ..INTRUDER!!!!!!!!!!!”";
	}
	system("pause");
}
void del4police()
{
	ifstream fstud("police.txt");
	po p;
	ofstream ftemp("temp.txt");
	int lno;
	cout<<"\n Enter license number to be deleted: ";
	cin>>lno;
	while(fstud.read((char*)&p,sizeof(p)))
	{
		if(p.licensen!= lno)
		ftemp.write((char*)&p,sizeof(p));
	}
	fstud.close();
	ftemp.close();
	remove("police.txt");
	rename("temp.txt","police.txt");
}
void del4details()
{
	ifstream fstud("hello.txt");
	details d;
	ofstream ftemp("temp.dat");
	int lno;
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
void update4police()
{
	fstream fstud("police.txt",ios::in);
	fstream ftemp("temp.txt",ios::out);
	int lno;
	po p;
	cout<<"\nEnter the license number to be updated:";
	cin>>lno;
	while(fstud.read((char*)&p,sizeof(p)))
	{
		if(p.licensen==lno)
		{
			p.gettogether();
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
void update4details()
{
	fstream fstud("hello.txt",ios::in);
	fstream ftemp("temp.txt",ios::out);
	int lno;
	details d;
	cout<<"\nEnter the license number to be updated:";
	cin>>lno;
	while(fstud.read((char*)&d,sizeof(d)))
	{
		if(d.licenseno==lno)
		{
			d.getdata();
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
int main()
{
	int z;
	char choice;
	do
	{
        cout<<"Menu\n 1. General\n2. Guest\nEnter your choice:";
        cin>>z;
        
        switch(z)
        {
            case 1:police();
                break;
            case 2:searchbylisenceno();
                break;
            default:cout<<"Sorry Wrong Input";
                break;
        }
        system("pause");
        cout<<"\ncontinue? (y/n)\n";
        cin>>choice;
	}while(choice=='y');
	cout<<"\nGood bye";
	return 0;
}

/*void main()
{       
    clrscr();
	int q;
	cout<<"********WELCOME TO RCO BASE**********\n";
	system("pause");
	cout<<"\n Record Of Crimes And Offences";
	cout<<"\nMenu\n 1.Crimes\n 2.Public offences\n 3.Complains \n4.Exit";
	cout<<"\n Enter your choice: ";
	cin>>q;
	switch(q)
	{
		case 1: menu1();
			break;
		case 2: menuu();
			break;
		case 3: cout<<"to complain box";
			break;
		case 4: cout<<"GoodBye";
			exit(0);
		default:cout<<"Wrong Choices!!!";
			exit(0);
	}
	getch();
}*/