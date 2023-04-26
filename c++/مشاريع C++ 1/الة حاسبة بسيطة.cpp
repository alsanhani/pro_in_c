#include <iostream>
//#include<windows.h>
using namespace std; 
int main()
{
	float  a,s;
	char n;
	cout<<"Enter the two numbers\n";
	cin>>a>>s;
	cout<<"Enter the  operation\n";
	cin>>n;
	if(n=='+')
	cout<<a<<" + "<<s<<" = "<<a+s;
	else if (n== '-')
	cout<<a<<" - "<<s<<" = "<<a-s;
	else if (n=='*')
	cout<<a<<" * "<<s<<" = "<<a*s;
	else if (n=='/')
	cout<<a<<" / "<<s<<" = "<<a/s;
	return 0;
}


