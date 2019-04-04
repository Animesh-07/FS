/*Write a C++ program to read two lists of names and then match the
names in the two lists using Co sequential Match() operation
and display the contents of all the lists.*/
#include<iostream>
#include<cstdlib>
#include<fstream>
#include<cstring>
using namespace std;

void sortnames(char names[][100],int n)
{
     for(int i=0;i<n-1;i++)
     {
        for(int j=i+1;j<n;j++)
        {

           if(strcasecmp(names[i],names[j])>0)
           {
               swap(names[i],names[j]);
           }
        }
     }
}

int main()
{
    fstream f1,f2,fout;
    char list4[100][100],list5[100][100],list6[100][100];
    int m,n;
    cout<<"\n      CO-SEQUENTIAL MATCH  \n";
    cout<<"\n Enter the number of names for list1:\n";
    cin>>m;
    cout<<"\n Enter the names:\n";
    for(int i=0;i<m;i++)
    cin>>list4[i];
    cout<<"\n Enter the number of names for list2:\n";
    cin>>n;
    cout<<"\n Enter the names:\n";
    for(int i=0;i<n;i++)
    cin>>list5[i];
    cout<<"\n The sorted contents of list1:\n";
    sortnames(list4,m);
    f1.open("data4.txt",ios::out);
    for(int i=0;i<m;i++)
    {
      cout<<list4[i]<<endl;
      f1<<list4[i]<<endl;
    }
    f1.close();
    cout<<"\n The sorted contents of list2:\n";
    sortnames(list5,n);
    f2.open("data5.txt",ios::out);
    for(int i=0;i<n;i++)
    {
      cout<<list5[i]<<endl;
      f2<<list5[i]<<endl;
    }
    f2.close();
    f1.open("data4.txt",ios::in);
    f2.open("data5.txt",ios::in);
    int i=0;
    int j=0;
     fout.open("output.txt",ios::out);
    cout<<"\nElements common to both files are\n";
    while(i<m&&j<n)
    {
        if(strcmp(list4[i],list5[j])==0)
        {
            fout<<list4[i];
            cout<<list4[i]<<"\n";
            fout<<'\n';
            i++;
            j++;
        }
        else if(strcmp(list4[i],list5[j])<0)
            i++;
        else
            j++;
    }
    getchar();

    return 0;
}
