/*Write a C++ program to reclaim the free space resulting from the deletion of records using linked lists.*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<fstream>
using namespace std;
class node
{
    public:
    char usn[30];
    char name[30];
    char address[30];
    char branch[30];
    char college[30];
    node *link;
};
class person
{
    public:
    char buffer[100];
    node *first;
    void writeFile();
    void display();
    void Delete();
    void Insert();
    person()
    {
    first=NULL;
    }
};
void person::writeFile()
{
    node *p;
    fstream is;
    is.open("student.txt",ios::out);
    p=first;
    while(p!=NULL)
    {
        strcpy(buffer,p->usn); strcat(buffer,"|");
        strcat(buffer,p->name); strcat(buffer,"|");
        strcat(buffer,p->address); strcat(buffer,"|");
        strcat(buffer,p->branch); strcat(buffer,"|");
        strcat(buffer,p->college); strcat(buffer,"|");
        strcat(buffer,"#");
        is<<buffer;
        p=p->link;
    }
}
void person::display()
{
    node *p;
    if(first==NULL)
    {
        cout<<"\nList is empty";
        return;
    }
    p=first;
    while(p!=NULL)
    {
        cout<<"\nUSN : "<<p->usn;
        cout<<"\nNAME : "<<p->name;
        cout<<"\nADDRESS : "<<p->address;
        cout<<"\nBRANCH : "<<p->branch;
        cout<<"\nCOLLEGE : "<<p->college;
        p=p->link;
    }
}
void person::Insert() //Insert the record at the rear end
{
    node *p,*q;
    p=new node;
    cout<<"Enter Usn"<<endl;
    cin>>p->usn;
    cout<<"Enter Name"<<endl;
    cin>>p->name;
    cout<<"Enter Address"<<endl;
    cin>>p->address;
    cout<<"Enter Branch"<<endl;
    cin>>p->branch;
    cout<<"Enter College"<<endl;
    cin>>p->college;
    p->link=NULL;
    if(first==NULL)
    {
        first=p;
        writeFile();
        display(); //display the record on the screen
        return;
    }
    for(q=first;q->link!=NULL;q=q->link){ ; }
    q->link=p;
    writeFile(); //writing the record to the file
    display(); //display the records to the screen.
}
void person::Delete()
{
    char key[15];
    node *curr,*prev,*del;
    if(first==NULL)
    {
        printf("\nThe list is empty. Deletion is not possible");
        return;
    }
    cout<<"\nEnter the usn to be deleted = ";
    cin>>key;
    if(strcmp(first->usn,key)==0)
    {
        del=first;
        first=first->link;
        delete del;
        cout<<"\nRECORD DELETED ....!!!! \n";
        writeFile();
        cout<<"\n REMAINING RECORDS ARE \n";
        display();
        return;
     }
     prev=NULL;
     curr=first;
     while( ( strcmp(curr->usn,key) != 0 ) && curr!=NULL)
     {
        prev=curr;
        curr=curr->link;
     }
     if(curr==NULL)
     {
        cout<<"\nThe student with usn "<<key<<" is not present";
        return;
     }
     prev->link=curr->link;
     delete curr;
     cout<<"\nRECORD DELETED ....!!!! \n";
     writeFile();
     cout<<"\n REMAINING RECORDS ARE \n";
     display();
}
int main()
{
    int choice;
    person p;
    for(;;)
    {
         printf("\n\n1:Insert_rear");//we can also use cout<<
         printf("\n2:Delete_id");
         printf("\n3:Display");
         printf("\n4:exit");
         printf("\n\nEnter the choice=");
         scanf("%d",&choice);
         switch(choice)
         {
             case 1:p.Insert();
             break;
             case 2:p.Delete();
             break;
             case 3:p.display();
             break;
             case 4:exit(0);
             default:cout<<"\nInvalid option";break;
     }
    }
}
