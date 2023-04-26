#include <iostream>
using namespace std; 
int main()
{
	int o , y=2020;
	cout<<"Enter your birthyear\n";
	cin>>o;
    cout<<"your old is "<<y-o<<" years"<<endl;
	if (o<1984)
	cout<<" you are old";
	else if (o>=1985 && o<=2005)
	cout<<" you are  young";
	else if (o >=2006 && o<=2020)
	cout<<" you are child";

	return 0;
}
