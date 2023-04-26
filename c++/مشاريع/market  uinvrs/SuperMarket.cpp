#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

struct product{
	int id;
	string name;
	int barcode;
	float price;
	float percent;
	float tax;
}
pro[3];

void main_menu();
void add();
void delet();
void sort();
void display();

int main()
{
	system("color 90");
	main_menu();
	
	return 0;
}

void main_menu(){
	char op;
	
	cout << "\n\n\t|--------------------<< WELCOME to AnasMarket >>------------------------|\n\t|\t\t\t\t\t\t\t\t\t|\n\t|\t\t\t\t\t\t\t\t\t|\n";
	cout << "\t|\t   1. Add Products to the Supermarket. \t\t\t\t|\n\t|\t\t\t\t\t\t\t\t\t|\n";
	cout << "\t|\t   2. Display All the Products in the Supermarket.  \t\t|\n\t|\t\t\t\t\t\t\t\t\t|\n";
	cout << "\t|\t   3. Delete Products from the Supermarket.  \t\t\t|\n\t|\t\t\t\t\t\t\t\t\t|\n";
	cout << "\t|\t   4. EXIT.  \t\t\t\t\t\t\t|\n\t|\t\t\t\t\t\t\t\t\t|\n";
	cout << "\t|-----------------------------------------------------------------------|\n\n";
	cout << "\t Please, enter the number of the operation you want ( 1 - 4 ): ";
	cin >> op;
	cout << "\n\n";
	
	system("cls");
	
	switch(op){
		case '1': add();
			break;
		case '2': display();
			break;
		case '3': delet();
			break;
		case '4': exit(0);
			break;
		default: main_menu();
	}
}

//-----------this function is for adding new products-----------------//
void add(){
	ofstream Market;
	bool isDone = false;
	int i = 0;
	char a;
	do{
		Market.open("SuperMarket.txt", ios::app);
		cout << "\n\n\t--------------------------------------------------------------";
		cout << "\n\t|\n\t|\t Enter the ID of porduct number " << i+1 <<" :       ";
		cin >> pro[i].id;
		Market << "\t\t" << pro[i].id << "\t";
		cout << "\t|\n\t|\t Enter the Name of porduct number " << i+1 <<" :     ";
		cin >> pro[i].name;
		Market << pro[i].name << "\t";
		cout << "\t|\n\t|\t Enter the Barcode of porduct number " << i+1 <<" :  ";
		cin >> pro[i].barcode;
		Market << pro[i].barcode << "\t";
		cout << "\t|\n\t|\t Enter the Price of porduct number " << i+1 <<" :    $";
		cin >> pro[i].price;
		Market << pro[i].price << "\t";
		cout << "\t|\n\t|\t Enter the percent of Tax for porduct number " << i+1 <<" :  %";
		cin >> pro[i].percent;
		pro[i].tax = pro[i].price * ( pro[i].percent / 100 );
		Market << pro[i].tax << "\n\t--------------------------------------------------------------------\n";
		Market.close();
		cout << "\n\t--------------------------------------------------------------\n";
		
		cout << "\n\t The Product number " << i+1 << " has been added SUCCESSFULLY !\a\n" << endl;
		cout << "\t If you want to add another Product, press Y\n";
		cout << "\t If you want to return to the main menu, press any key\n\n\t\t";
		cin >> a;
		cout << "\n\n";
		
		switch (a){
			case 'y':
				{
				isDone = true;
				i++;
				system("cls");
				}
				break;
			case 'Y':
				{
				isDone = true;
				i++;
				system("cls");
				}
				break;
			default:
				system("cls");//clear screen command (DOS cmd)
				main_menu();
				break;
		}
	} while ( isDone );
}


//-----------this function is for displaying the all products-----------------//
void display(){
	ifstream Market;
	char ch;
	
	cout << "\n\n\t|---------------<< Display All AnasMarket's Products >>-----------------|\n\t|\t\t\t\t\t\t\t\t\t|\n\t|\t\t\t\t\t\t\t\t\t|\n";
	cout << "\t|\t   1. Ordered. \t\t\t\t\t\t\t|\n\t|\t\t\t\t\t\t\t\t\t|\n";
	cout << "\t|\t   2. Unordered. \t\t\t\t\t\t|\n\t|\t\t\t\t\t\t\t\t\t|\n";
	cout << "\t|\t   3. Return to Main Menu.  \t\t\t\t\t|\n\t|\t\t\t\t\t\t\t\t\t|\n";
	cout << "\t|-----------------------------------------------------------------------|\n\n";
	cout << "\t Please, enter the number of the operation you want ( 1 - 3 ): ";
	cin >> ch;
	cout << "\n\n";
	
	system("cls");
	
	switch(ch){
		case '1': sort();
			break;
		case '2':
		{
			cout << "\n\n\nProduct: \tID \tName \t\tBarcode \tPrice \tTax \n";
			cout << "----------------------------------------------------------------------------\n  ";
			
			Market.open("SuperMarket.txt");
			cout << Market.rdbuf(); //It returns a pointer to the internal filebuf object.declaration 
			Market.close();
			
			cout << "\n\n\t\t\t";
			system("pause");
			system("cls");//clears the screen
			main_menu();
		};
			break;
		case '3': system("cls");
			main_menu();
			break;
		default: system("cls");
			display();
			break;
	}
	
}


//-----------this function is for deleting products-----------------//
void delet(){
	fstream replace; // in & out

	int dlt;
	char a;
	
	in:
	cout << "\n\n\t Please, enter the ID of the product you want to delete : ";
	cin >> dlt;
	if (dlt == pro[0].id){
		pro[0].id = 0;
		pro[0].name = "\t\t";
		pro[0].barcode = 0;
		pro[0].price = 0;
		pro[0].tax = 0;
		
		replace.open("temp.txt",ios::app);
		for(int t = 0; t < 3; t++){
			replace << "\t\t" << pro[t].id << "\t";
			replace << pro[t].name << "\t";
			replace << pro[t].barcode << "\t";
			replace << pro[t].price << "\t";
			replace << pro[t].tax << "\n\t--------------------------------------------------------------------\n";
		}
		replace.close();
		remove("SuperMarket.txt");
		rename("temp.txt" , "SuperMarket.txt");
		
		cout << "\n\tThe product has been deleted SUCCESSFULLY!" << endl;
		cout << "\t If you want to delete another Product, press Y\n";
		cout << "\t If you want to return to the main menu, press any key\n\n\t\t";
		cin >> a;
		cout << "\n\n";
	
		switch (a){
			case 'y': goto in;
				break;
			case 'Y': goto in;
				break;
			default:
				system("cls");
				main_menu();
				break;
		}
	}
	else if (dlt == pro[1].id){
		pro[1].id = 0;
		pro[1].name = "\t\t";
		pro[1].barcode = 0;
		pro[1].price = 0;
		pro[1].tax = 0;
		
		replace.open("temp.txt",ios::app);
		for(int t = 0; t < 3; t++){
			replace << "\t\t" << pro[t].id << "\t";
			replace << pro[t].name << "\t";
			replace << pro[t].barcode << "\t";
			replace << pro[t].price << "\t";
			replace << pro[t].tax << "\n\t--------------------------------------------------------------------\n";
		}
		replace.close();
		remove("SuperMarket.txt");
		rename("temp.txt" , "SuperMarket.txt");
		
		cout << "\n\tThe product has been deleted SUCCESSFULLY!" << endl;
		cout << "\t If you want to delete another Product, press Y\n";
		cout << "\t If you want to return to the main menu, press any key\n\n\t\t";
		cin >> a;
		cout << "\n\n";
	
		switch (a){
			case 'y': goto in;
				break;
			case 'Y': goto in;
				break;
			default:
				system("cls");
				main_menu();
				break;
		}
	}
	else if (dlt == pro[2].id){
		pro[2].id = 0;
		pro[2].name = "\t\t";
		pro[2].barcode = 0;
		pro[2].price = 0;
		pro[2].tax = 0;
		
		replace.open("temp.txt",ios::app);
		for(int t = 0; t < 3; t++){
			replace << "\t\t" << pro[t].id << "\t";
			replace << pro[t].name << "\t";
			replace << pro[t].barcode << "\t";
			replace << pro[t].price << "\t";
			replace << pro[t].tax << "\n\t--------------------------------------------------------------------\n";
		}
		replace.close();
		remove("SuperMarket.txt");
		rename("temp.txt" , "SuperMarket.txt");
		
		cout << "\n\tThe product has been deleted SUCCESSFULLY!" << endl;
		cout << "\t If you want to delete another Product, press Y\n";
		cout << "\t If you want to return to the main menu, press any key\n\n\t\t";
		cin >> a;
		cout << "\n\n";
	
		switch (a){
			case 'y': goto in;
				break;
			case 'Y': goto in;
				break;
			default:
				system("cls");
				main_menu();
				break;
		}
	}
	else{
		cout << "\n\t The ID you entered is not found, try again\t";
		system("pause");
		system("cls");
		main_menu();
	}
}

//-----------this function is for organizing and sorting the products by their ID number-----------------//
void sort(){
	fstream replace;
	
	int temp1, temp3;
	string temp2;
	float temp4, temp5;
	
	for(int n = 0; n < 3; n++){
		for(int m = n+1; m < 3; m++){
			if( pro[n].id > pro[m].id ){
			//----------to sort the IDs--------//
				temp1 = pro[n].id;
				pro[n].id = pro[m].id;
				pro[m].id = temp1;
			
			//----------to sort the Names--------//	
				temp2 = pro[n].name;
				pro[n].name = pro[m].name;
				pro[m].name = temp2;
			
			//----------to sort the Barcodes--------//	
				temp3 = pro[n].barcode;
				pro[n].barcode = pro[m].barcode;
				pro[m].barcode = temp3;
			
			//----------to sort the Prices--------//	
				temp4 = pro[n].price;
				pro[n].price = pro[m].price;
				pro[m].price = temp4;
			
			//----------to sort the Taxes--------//	
				temp5 = pro[n].tax;
				pro[n].tax = pro[m].tax;
				pro[m].tax = temp5;
			}
		}
	}
			cout << "\n\n\nProduct: \tID \tName \t\tBarcode \tPrice \tTax \n";
			cout << "----------------------------------------------------------------------------\n  ";
			
			replace.open("temp.txt",ios::app);
			for(int t = 0; t < 3; t++){
				replace << "\t\t" << pro[t].id << "\t";
				replace << pro[t].name << "\t";
				replace << pro[t].barcode << "\t";
				replace << pro[t].price << "\t";
					replace << pro[t].tax << "\n\t--------------------------------------------------------------------\n";
			}
			replace.close();
			remove("SuperMarket.txt"); //It deletes___ <cstdio>
			rename("temp.txt" , "SuperMarket.txt");
			
			replace.open("SuperMarket.txt");
			cout << replace.rdbuf();
			replace.close();
			
			cout << "\n\n\t\t\t";
			system("pause");
			system("cls");
			main_menu();
}
