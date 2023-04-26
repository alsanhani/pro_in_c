#include<iostream>
using namespace std;
main()
{
int a[3][3]={{5,6,2},{8,7,4},{1,3,9}};
int i,j,sum=0;
for(i=0;i<3;i++)
for(j=0;j<3;j++)
{if(i!=j && i>j)
a[i][j]=0;
cout<<a[i][j];
}
}

//the secend is 0
