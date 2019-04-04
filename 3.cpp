/*Write a C++ program to read and write student objects with variable-length records and the fields delimited by “|” and records delimited by “#”. Implement modify(), display( ) and search( ) methods by performing pack and unpack operations*/
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<fstream>
using namespace std;
class student
{
    char name[25],usn[11],sem[3],dept[20],buf[39];
   public:
    void pack();
    void unpack();
    void display();
    void search();
    void read();
    void modify();
};
void student :: pack()
{
    strcpy(buf,usn);
    strcat(buf,"|");
    strcat(buf,name);
    strcat(buf,"|");
    strcat(buf,dept);
    strcat(buf,"|");
    strcat(buf,sem);
    strcat(buf,"#");
    strcat(buf,"\n");//donot forget to put \n
}
void student :: unpack()
{
    strcpy(usn,strtok(buf,"|"));
    strcpy(name,strtok(NULL,"|"));
    strcpy(dept,strtok(NULL,"|"));
    strcpy(sem,strtok(NULL,"#"));
}
void student :: read()
{
    cout<<"Enter the USN: ";
    cin>>usn;
    cout<<"Enter the NAME : ";
    cin>>name;
    cout<<"Enter the DEPT : ";
    cin>>dept;
    cout<<"Enter the  SEM : ";
    cin>>sem;
    pack();
    ofstream fout;
	fout.open("3rd.txt",ios::app);
	fout<<buf;
	fout.close();
	cout<<"\n Student Record Added \n";

}
void student :: display()
{
    ifstream fin;
    fin.open("3rd.txt");
    while(!fin.eof())
    {
        fin>>buf;

        if(fin.fail()) break;

        unpack();
        cout<<"\n-------------------------------------\n";
        cout<<"\nUSN : "<<usn<<"\nNAME : "<<name<<"\nDEPT : "<<dept<<"\nSEM : "<<sem<<endl;
        cout<<"\n-------------------------------------\n";
    }
    fin.close();
}
void student :: search()
{
    ifstream fin;
    fin.open("3rd.txt");
    char key[30];
    cout<<"Enter the key : ";
    cin>>key;
    int found = 0;
    while(!fin.eof())
    {
        fin>>buf;
        if(fin.fail()) break;
        unpack();
        if(strcmp(usn,key)==0)
        {
            cout<<"\nStudent Found : "<<"\nUSN : "<<usn<<"\nNAME : "<<name<<"\nDEPT : "<<dept<<"\nSEM : "<<sem<<endl;

            found = 1;
        }
    }
    if(found==0)
    cout<<"Student Not found!!\n";
    fin.close();
    return;
}
void student :: modify()
{
    fstream f;
    f.open("3rd.txt",ios::in|ios::out);
    char key[30];
    cout<<"Enter the key : ";
    cin>>key;
    int size;
    while(!f.eof())
    {
        f>>buf;
        if(f.fail()) break;
        size = strlen(buf);// make sure this size variable must be above unpack()

        unpack();

        if(strcmp(usn,key)==0)
        {
            cout<<"\nStudent Found \nEnter the new Name :";
            cin>>name;
            cout<<"Enter the new DEPT :";
            cin>>dept;
            cout<<"Enter the new Sem :";
            cin>>sem;

            f.seekp((int)f.tellg()-(size+1),ios::beg);
            pack();
            f<<buf;
            f.close();
            return;
        }
    }
    cout<<"Student Not found \n";
    f.close();
}
int main(void)
{
    student s;
    int choice;
    while(1)
    {
        cout<<"\n 1.insert\n  2.Search\n 3.Modify\n 4.Display\n 5.exit\n";
        cout<<"Enter choice for Variable Length\n";
        cin>>choice;
         switch(choice)
        {
           case 1:  s.read();
                    break;
           case 2:  s.search();
                    break;
           case 3:  s.modify();
                    break;
           case 4:  s.display();
                    break;
            case 5: exit(0);
          default: cout<<"invalid\n";
       }
    }
    return 0;
}
