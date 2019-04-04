/*Write a C++ program to read and write student objects with fixed-length records and the fields delimited by “|” and records delimited by “#”. Implement modify( ), display() and search( ) methods by performing pack and unpack operations.*/

#include <iostream>
#include<bits/stdc++.h>

using namespace std;

class student
{
    public:
        string Name,USN,Branch,buff,address;
        void search(const char *fname,string usn)
        {
            string data;
            fstream f1;
            f1.open(fname,ios::in);
            if(!f1)
            {    cout<<"Some reading error!"<<endl;    }
            while(!f1.eof())
            {
                unpack(f1);
                if(USN.compare(usn)==0)
                {    cout <<Name<<"\t"<<USN<<"\t"<<Branch<<"\t"<<address<<"\t"<<data<<endl;    }
            }
            f1.close();
        }
        void pack()
        {
            Name.push_back('|');USN.push_back('|');Branch.push_back('|');address.push_back('|');
            buff = Name+USN+Branch+address;
            while(buff.length()<49)
                buff.push_back('#');
            cout<<buff;
        }
        void unpack(fstream &f1)
        {
                string data;
                getline(f1,Name,'|');
                getline(f1,USN,'|');
                getline(f1,Branch,'|');
                getline(f1,address,'|');
                getline(f1,data,'#');
                getline(f1,buff);
        }
        void modify(const char *fname,string usn)
        {
            string data;
            fstream f1;
            bool found = 0;
            f1.open(fname,ios::in|ios::out);
            if(!f1)
            {    cout<<"Some reading error!"<<endl;    return;    }
            while(!f1.eof())
            {
                unpack(f1);
                if(USN.compare(usn)==0)
                {
                    found = 1;
                    int pos = f1.tellg();
                    pos-=1;
                    cout<<pos<<endl;
                    pos -=51;
                    f1.seekg(pos,ios::beg);
                    cout<<"Enter what to modify?\n1.Name\t2.USN\t3.Branch\t4.Address"<<endl;
                    int ch;
                    cin>>ch;
                    switch(ch)
                    {
                        case 1: cout<<"Name:"<<endl;cin>>Name;break;
                        case 2: cout<<"USN :"<<endl; cin >>USN; break;
                        case 3: cout<<"Branch :" <<endl;cin >>Branch; break;
                        case 4: cout <<"Address :" <<endl;cin >> address;break;
                    }
                    pack();
                    data = Name+USN+Branch+address;
                    while(data.length()<49)
                        data.push_back('#');
                    f1<<endl<<data;
                    f1.close();
                    break;
                }
            }
            if(!found)
                cout << "No such record exists!";
        }
        void display(const char *fname)
        {
            fstream f1;string data;
            f1.open(fname,ios::in);
            while(!f1.eof())
            {
                unpack(f1);
                cout <<Name<<"\t"<<USN<<"\t"<<Branch<<"\t"<<address<<endl;
            }
            f1.close();
        }
        void write(const char *fname)
        {
            fstream f1;
            f1.open(fname,ios::out|ios::app);
            f1<<endl<<buff;
            f1.close();
        }
        void readData()
        {
            cout<<"Enter the Name,USN,Branch,address of student"<<endl;
            cin>>Name;cin>>USN;cin>>Branch;cin>>address;
        }
};

int main()
{
    student s1;string usn;
    int choice;
    while(1)
    {
        cout<<"\n1.Write\t2.Search\t3.Modify\t4.Display"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1: s1.readData();
                   s1.pack();
                   s1.write("new.dat");
                   break;
            case 2: cout<<"Enter usn to search"<<endl;
                    cin>>usn;
                    s1.search("new.dat",usn);
                    break;
            case 3: cout<<"Enter the USN"<<endl;
                    cin>>usn;
                    s1.modify("new.dat",usn);
                    break;
            case 4:    s1.display("new.dat");
                    break;
            default: cout<<"Invalid choice"<<endl;
                    exit(0);
        }
    }
}