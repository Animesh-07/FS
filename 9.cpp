/*Write a C++ program to implement simple index on secondary key for a file of student objects. Implement add (), search (),
delete () using the index.*/
#include<iostream>
#include<string.h>
#include<fstream>
#include<stdlib.h>
using namespace std;
int n=0,index1=0;
class student
{
public:
    char name[20],usn[20],branch[5];
    int sem;
    void insert(fstream &f1,fstream &f2)
    {
        cout<<"\nEnter Name: ";
        cin>>name;
        cout<<"Enter USN: ";
        cin>>usn;
        cout<<"Enter Sem: ";
        cin>>sem;
        cout<<"Enter Branch: ";
        cin>>branch;
        write(f1,f2);
    }
    void write(fstream &f1,fstream &f2)
    {
        f1<<++index1<<"\t"<<name<<"\n";
        f2<<name<<"\t"<<usn<<"\t"<<sem<<"\t"<<branch<<"\n";
    }
    void display(fstream &f2)
    {
        f2>>name>>usn>>sem>>branch;
        cout<<"------------------------------------------\n";
        cout<<name<<"\t"<<usn<<"\t"<<sem<<"\t"<<branch<<"\n";
        cout<<"------------------------------------------\n";
    }
    void search(fstream &f1,fstream &f2,char key[20])
    {
        int i,x,record=0;
        for(i=1; i<=n; i++)
        {
            f2>>name>>usn>>sem>>branch;
            f1>>x>>name;
            if(strcmp(name,key)==0)
            {
                record++;
                cout<<"Record "<<x<<" found & Details are\n";
                cout<<"Name="<<name<<"\n"<<"USN="<<usn<<"\n";
                cout<<"Sem="<<sem<<"\n"<<"Branch="<<branch<<"\n\n";
            }
        }
        if(record==0)
            cout<<"Record not found\n";
    }
    int remove(fstream &f1,fstream &f2,char key[20])
    {
        char usn1[20];
        int i,x,record=0;
        cout<<"Enter the usn to delete : ";
        cin>>usn1;
        for(i=1; i<=n;i++)
        {
             f2>>name>>usn>>sem>>branch;
            f1>>x>>name;
            if(strcmp(name,key)==0)
            {

                if(strcmp(usn,usn1)==0)
                {

                    record=1;
                    return i;
                }
            }

        }
    if(record==0){
        cout<<"Record  not found ";
            return 0;
        }
    }
};
int main()
{
    fstream f1,f2;printf("\n2:Delete_id");
    student s[20],p;
    int ch,k=0,i;
    f1.open("index.txt",ios::trunc);
    f2.open("record.txt",ios::trunc);
    f1.close();
    f2.close();
    for(;;)
    {
    cout<<"\n\nEnter\n1.Insert \n2.Display\n3.Search \n4.Delete\n5.Exit\n";
    cin>>ch;
    switch(ch)
    {
        case 1:
            f1.open("index.txt",ios::out);
            f2.open("record.txt",ios::out);
            cout<<"Enter no. of students: ";
            cin>>k;
            n=n+k;
            for(int i=1; i<=k; i++)
                s[i].insert(f1,f2);
            f1.close();
            f2.close();
            break;
        case 2:
            f2.open("index1.txt",ios::in);
            for(i=1; i<=n; i++)
                s[i].display(f2);
            f2.close();
            break;
        case 3:
            char name[20];
            cout<<"Enter name to search: ";
            cin>>name;
            f1.open("index.txt",ios::in);
            f2.open("record.txt",ios::in);
            int j;
            p.search(f1,f2,name);
            f1.close();
            f2.close();
            break;
        case 4:
            char name1[20];
            char usn1[20];
            f1.open("index.txt",ios::in);
            f2.open("record.txt",ios::in);
            cout<<"Enter name to delete: ";
            cin>>name1;
            j=p.remove(f1,f2,name1);
            if(j!=0)
            {
                for(i=j; i<n; i++)
                    s[i]=s[i+1];
                cout<<"Deletion successfull\n";
            }
            n--;
            index1--;
            f1.close();
            f2.close();
            f1.open("index.txt",ios::trunc|ios::out);
            f2.open("record.txt",ios::trunc|ios::out);
            index1=0;
            for(i=1; i<=n; i++)
                s[i].write(f1,f2);
            f1.close();
            f2.close();
            break;
        case 5: exit(0);
        default:
            cout<<"Invalid Option";}}
}
