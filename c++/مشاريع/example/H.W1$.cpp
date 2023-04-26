#include<iostream>
using namespace std;
int main()
{
int a[3][3],i,j,s=0;
for(i=0;i<3;i++)
for(j=0;j<3;j++)
{cout<<"Enter a["<<i<<"]["<<j<<"]= ";
cin>>a[i][j]; }
int x=a[2][2];
for(i=0;i<=1;i++)
{for(j=0;j<=1;j++)
if(a[i][j]%x==0)
s+=a[i][j];}
cout<<"\n sum numbers= " << s;

}
// \
