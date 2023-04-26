//  calculate Volume and Surface area of Cone  
#include<iostream> 
using namespace std;  
float pi=0;   
float volume(float r, float h) 
{ 
    return (float(1) / float(3)) * pi * r * r * h; 
} //cone 
float surface_area(float r, float s) 
{ 
    return pi * r * s + pi * r * r; 
} // Surface area of cone 
int main() 
{ 
    float radius = 5; 
    float slant_height = 13; 
    float height = 12; 
    float vol, sur_area;
    cin>>pi; 
  
    cout << "Volume Of Cone : "
        << volume(radius, height) << endl; 
    cout << "Surface Area Of Cone : "
        << surface_area(radius, slant_height)<<endl;
	   cout<<endl; 
    return 0; 
}
