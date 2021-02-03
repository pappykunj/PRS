#include <iostream>
#include<conio.h>
#include<stdio.h>
#include<fstream>
#include<process.h>
#include<string.h>
#include<stdlib.h>

using namespace std;

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
    puts("\nEnter blood group (Ap/An/Bp/Bn/ABp/ABn/Op/On): ");
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
        if (strcmp(m, name)==0)
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
    puts("Enter the name of the criminal whose records you want to deleted: ");
    gets(b);
    ifile.seekg (0, ios::beg);
    ifile.read((char*)&c, sizeof(c));
    while(ifile)
    {
        if (strcmp(b, name))
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
    puts("\nEnter name of criminal whose record you want to modify: ");
    gets(d);
    fstream f;
    f.open("CBI", ios::in|ios::out);
    f.seekg(0, ios::beg);
    f.read((char*)&c, sizeof(c));
    int a;
    while(! f.eof())
    {
        if (!strcmp(d, name))
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
                case 6: gets(addrs);
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
int main()
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
    return 0;
}
