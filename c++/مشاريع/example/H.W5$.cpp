#include<iostream> 
using namespace std;
main()
{
int a[3][3],c[3][3];
int n1=0,i,j;
for(i=0;i<3;i++)
for(j=0;j<3;j++)
{cout<<"Enter a["<<i<<"]["<<j<<"]= ";
cin>>a[i][j]; }
for(i=0;i<3;i++)
for(j=0;j<3;j++)
if(a[i][j]%2==0){
n1++;
c[n1][n1]=a[i][j];}
for(i=1;i<=n1;i++)
for(j=1;i<=n1;j++)
cout<<c[i][j]<<"\t";

}
//add
