/********************************************************************************************************'
This Program is based on the general crime record keeping
It consits of various fuctions and classes
This is a object oriented based programing in C++ language
This was done in Turbo C++
 ********************************************************************************************************/
#include<iostream.h>
#include<stdio.h>
#include<fstream.h>
#include<string.h>
#include<stdlib.h>

//#include<conio.h>
//#include<process.h>

using namespace std;

void del4police();
void del4details();
void update4police();
void update4details();

class crim_rec
{
    char name[20],gender,fathr_name[20],addrs[25],offense[20],blood[5],dob[9];
    int crim_code, reward;
    void disp();
    public:
        void get();
        void wtf();
        void rff();
        void search();
        void del();
        void mod();
}c;
void crim_rec::get()
{
    puts("\nEnter name of criminal:");
    gets(name);
    puts("\nGender (M/F):");
    cin>>gender;
    puts("\nEnter Date of Birth:");
    gets(dob);
    puts("\nEnter blood group (Ap/An/Bp/Bn/ABp/ABn/Op/On):");
    gets(blood);
    puts("\nEnter father's name:");
    gets(fathr_name);
    puts("\nEnter address:");
    gets(addrs);
    puts("\nEnter crime commited:");
    gets(offense);
    puts("\nEnter reward on criminal:");
    cin>>reward;
}
void crim_rec::disp()
{
    cout<<"The record of criminal:\n";
    cout<<"\nName of criminal: "<<name;
    cout<<"\nGender: "<<gender;
    cout<<"\nDOB: "<<dob;
    cout<<"\nBlood Group: "<<blood;
    cout<<"\nFather's name: "<<fathr_name;
    cout<<"\nAddress: "<<addrs;
    cout<<"\nCrime: "<<offense;
    cout<<"\nReward: "<<reward;
}
void crim_rec::wtf()
{
    ofstream ofile;
    ofile.open("CBI", ios::app);
    get();
    ofile.write((char*)&c, sizeof(c));
    ofile.close();
}
void crim_rec::rff()
{
    ifstream ifile;
    ifile.open("CBI");
    ifile.seekg(0, ios::beg);
    ifile.read((char*)&c, sizeof(c));
    while(ifile)
    {
        disp();
        ifile.read ((char*)&c, sizeof(c));
    }
    ifile.close();
}
void crim_rec::search()
{
    char m[20];
    ifstream ifile("CBI");
    puts("Enter name of criminal which has to be searched");
    gets(m);
    ifile.seekg (0, ios::beg);
    ifile.read((char*)&c, sizeof(c));
    while(ifile)
    {
        if (strcmpi(m, name)==0)
            disp();
        ifile.read((char*)&c, sizeof(c));
    }
    ifile.close();
}
void crim_rec::del()
{
    char b[20];
    ifstream ifile;
    ifile.open("CBI", ios::app);
    ofstream ofile;
    ofile.open("new", ios::app);
    puts("Enter the name of the criminal whose records you want to del");
    gets(b);
    ifile.seekg (0, ios::beg);
    ifile.read((char*)&c, sizeof(c));
    while(ifile)
    {
        if (strcmpi(b, name))
            ofile.write((char*)&c, sizeof(c));
        ifile.read((char*)&c, sizeof(c));
    }
    ifile.close();
    ofile.close();
    remove ("CBI");
    rename("new", "CBI");
}
void crim_rec::mod()
{
    char d[20];
    int p;
    puts("\nEnter name of criminal whose record you want to modify\n");
    gets(d);
    fstream f;
    f.open("CBI", ios::in|ios::out);
    f.seekg(0, ios::beg);
    f.read((char*)&c, sizeof(c));
    int a;
    while(! f.eof())
    {
        if (!strcmpi(d, name))
        {
            puts("\nPress 1 to change name\nPress 2 to change sex\nPress 3 to change date of birth\nPress 4 to change blood group\nPress 5 to change father's name\nPress 6 to change address\nPress 7 to change crime committed\nPress 8 to change reward on criminal\n");
            cin>>p;
            switch(p)
            {
                case 1: gets(name);
                        break;
                case 2: cin>>gender;
                        break;
                case 3: gets(dob);
                        break;
                case 4: gets(blood);
                        break;
                case 5: gets(fathr_name);
                        break;
                case 6: gets(addrs)
                        break;
                case 7: gets(offense);
                        break;
                case 8: cout<<"\nEnter the Reward:";
                        cin>>reward;
                        break;
            }
            f.seekg(sizeof(c), ios::beg);
            f.write((char*)&c, sizeof(c));
        }
        f.read((char*)&c, sizeof(c));
        a=f.tellg();
    }
    f.close();
}
void menu1()
{
    int ch;
    char choice;
    do
    {
        cout<<"\t Central Bureau of Investigation";
        cout<<"\n--------------------------------------------";
        cout<<"\n\n *  1. View criminal details                 *";
        cout<<"\n\n *  2. Add new criminal details               *";
        cout<<"\n\n *  3. Search a criminal record              *";
        cout<<"\n\n *  4. Delete a criminal record              *";
        cout<<"\n\n *  5. Modify a criminal record              *";
        cout<<"\n--------------------------------------------- ";
        cout<<"\n\n Enter your choice: ";
        cin>>ch;
        
        
        switch(ch)
        {
            case 1: c.rff();
                    break;
            case 2: c.wtf();
                    break;
            case 3: c.search();
                    break;
            case 4: c.del();
                    break;
            case 5: c.mod();
                    break;
            default:
            {
                cout<<"\nerror!";
            }break;
        }
        cout<<"\ncontinue? (y/n)\n";
        cin>>choice;
    }while(choice=='y');
    cout<<"\nGood bye";
    getch();
}

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
		cout<<"\nMenu\n1.Person's details\n2.Black points";
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
		cout<<"Alert :O ..INTRUDER!!!";
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
void menuu()
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
	getch();
}

void main()
{       
    system("CLS");
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
}
