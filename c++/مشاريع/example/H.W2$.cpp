#include<iostream>
using namespace std;
 int main()
{
int a[20],x,x1,n,i,k=0;
cout<<"enter long matrix";
cin>>n;
for(i=1;i<=n;i++)
{cout<<"enter a["<<i<<"]";
cin>>a[i];}
for(i=1;i<=n;i++)
cout<<a[i]<<" ";
cout<<endl;
cout<<"enter x";
cin>>x;
cout<<"enter element in the matrix";
cin>>x1;
for(i=1;i<=n;i++)
if(x1==a[i])
{a[i]=x;
k=k+1;}
if(k==0)
cout<<"not found"<<endl;
for(i=1;i<=n;i++)
cout<<a[i]<<" ";
}
//change
