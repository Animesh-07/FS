/*Write a c++ program to read  2 lists of names and merge the names of 2 lists ,ito a single list by performing co-sequential merge operation.*/
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
           if(strcmp(names[i],names[j])>0)
           {
              swap(names[i],names[j]);
           }
        }
     }
}

int main()
{
    fstream f1,f2,fout;
    char list1[100][100],list2[100][100],list3[100][100];
    int m,n;
    cout<<"\n Enter the number of names for list1:\n";
    cin>>m;
    cout<<"\n Enter the names:\n";
    for(int i=0;i<m;i++)
        cin>>list1[i];
    cout<<"\n Enter the number of names for list2:\n";
    cin>>n;
    cout<<"\n Enter the names:\n";
    for(int i=0;i<n;i++)
        cin>>list2[i];
    cout<<"\n The sorted contents of list1:\n";
    sortnames(list1,m);
    f1.open("list1.txt",ios::out);
    for(int i=0;i<m;i++)
    {
      cout<<list1[i]<<endl;
      f1<<list1[i]<<endl;
    }
    f1.close();
    cout<<"\n The sorted contents of list2:\n";
    sortnames(list2,n);
    f2.open("list2.txt",ios::out);
    for(int i=0;i<n;i++)
    {
      cout<<list2[i]<<endl;
      f2<<list2[i]<<endl;
    }
    f2.close();
    f1.open("list1.txt",ios::in);
    f2.open("list2.txt",ios::in);
    string name;
    fout.open("output.txt",ios::out);
    int i=0,j=0;
    cout<<"\nElements after merging both files are\n";
    while(i<m && j<n)
    {
        if(strcmp(list1[i],list2[j])==0)
        {
            fout<<list1[i];
            cout<<list1[i]<<"\n";
            cout<<'\n';
            i++;
            j++;
        }
        else if(strcmp(list1[i],list2[j])<0)
        {
            fout<<list1[i];
            cout<<list1[i];
            cout<<'\n';
            i++;
        }
        else
        {
            fout<<list2[j];
            cout<<list2[j];
            cout<<'\n';
            j++;
        }
    }
   if(i==m && j<n)  // to print the elements after ending of one file
    {
        while(j<n)
        {
            fout<<list2[j];
            cout<<list2[j];
            j++;
        }
    }
    if(i<m && j==n)
    {
        while(i<m)
        {
            fout<<list1[i];
            cout<<list1[i];
            i++;
        }
    }
    return 0;
}
