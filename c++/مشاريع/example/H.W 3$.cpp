#include<iostream>
using namespace std;
int main()
{
int a[6],x,i,j,d=5,k;
for(i=0; i<=5;i++)
{cout<<"enter a["<<i<<"]=";
cin>>a[i]; }
cout<<"enter number for delete it: ";
cin>>x;
k=0;
for(i=0; i<=5;i++)
if(x==a[i])
{k=k+1;
for(j=i; j<=5;j++)
a[j]=a[j+1];
d=d-1;}
if(k==0)
cout<<"not found"<<endl;
for(i=0;i<=d;i++)
cout<<a[i]<<" ";
}
