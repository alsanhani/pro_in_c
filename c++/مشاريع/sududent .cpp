#include <iostream>
#include <fstream>
#include <conio.h>
#include  <string>
#include <windows.h>
using namespace std;
//HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // For use of SetConsoleTextAttribute()
const char FILE_PATH[] = "DataFile.txt";
const char path2file[] = "roq2.txt";
// --------------------------------- write to file -----------------------------
void write(char s[]){
	ofstream o(path2file, ios::out);
	o << s;
	o.close();
}
void write(char name[], char add[])
{
	ofstream j(path2file, ios::app);
	j << name << "\n" << add;
	j.close();
	/*ofstream fout;
	fout.open("out.txt");
	char str[300] = "Time is a great teacher but
	unfortunately it kills all its pupils. Berlioz";
	//Write string to the file.
	fout << str;
	fout.close();*/
}
//------------------------------ read any line from file-----------------------
string read(int line){
	string pathfile;//= "D:\\myfiles\\files\\student.txt";
	cout << "enter the name of file :";
	cin >> pathfile;
	ifstream r(path2file, ios::in);
	char x[255];
	int u = 0;
	while (r.getline(x, 255)){
		if (u >= line){ break; }
		u++;
	}
	if (line>u){ cout << ".........\n"; }
	r.close();
	return x;
};
//------------------------------- count the lines in file ---------------------------
int count(){
	ifstream r(path2file, ios::in);
	int i = 0;
	char x[255];
	while (r.getline(x, 255)){
		i++;
	}
	return i;
}
//----------------------count number of lines----------------------------
void count_num_line(){
	ifstream fin;
	fin.open("DataFile.txt");
	int count = 0;
	char str[80];
	while (!fin.eof())
	{
		fin.getline(str, 80);
		count++;
	}
	cout << "Number of lines in file are " << count; fin.close();

}
//----------------------------------- count number of words-----------------------
void count_num_word(){
	ifstream fin;
	fin.open("DataFile.txt");
	int count = 0;
	char word[30];
	while (!fin.eof())
	{
		fin >> word;
		count++;
	}
	cout << "Number of words in file are " << count;
	fin.close();
}

//------------------------- count_num_char------------------------------------------
void count_num_char(){
	ifstream fin;
	fin.open("DataFile.txt");
	int count = 0;
	char ch;
	while (!fin.eof())
	{
		fin.get(ch);
		cout << ch;
		count++;
	}
	cout << "Number of characters in file are " << count;
	fin.close();
}

// ----------------------------------- read all letters in file -------------------------
void read_all_data()
{
	char a;
	ifstream roq(path2file, ios::in);
	while (!roq.eof())
	{
		roq >> a;
		cout << a;
	}
}
//---------------------- search from file -------------------------------------------
void search()
{
	string key, line;
	int offset;
	bool check = false;
	//ifstream roq(path2file, ios::in);
	ifstream roq_search;
	roq_search.open("roq2.txt");
	cout << "enter the name you want to search :" << endl;
	cin >> key;
	if (roq_search.is_open())//---> else-->if(roq_search.fail())
	{
		while (!roq_search.eof())
		{
			getline(roq_search, line);
			if ((offset = line.find(key, 0)) != string::npos){
				cout << "the word has been founded  : " << key << endl;
				check = true;
			}
		}
		if (check != true)
			cout << "the word has not found  : " << endl;

		roq_search.close();
	}
	else
		cout << "could not open file " << endl;


}

//-------------------------search for last name in text file, then output the whole line in the console.
void searchFile()
{
	ifstream dataIn;
	dataIn.open("DataFile.txt");

	string temp;
	string line;
	string word;

	cout << "Search by last name: ";
	cin >> word;

	if (dataIn.is_open())
	{
		while (getline(dataIn, temp))
		{
			line.append(temp);
			//string::npos is a constant (probably -1) representing a non-position. 
			//It's returned by method find when the pattern was not found.
			if (line.find(word) != string::npos)
			{

				cout << "\nUser found!" << endl;
				cout << "User credentials below: " << endl;
				cout << temp << endl;
				cout << endl;
				break;
			}
		}
		dataIn.close();
	}


}
void delete_student()
{
	fstream stud;
	fstream temp;
	stud.open("student.txt", ios::in);
	temp.open("temp.txt", ios::out);
	char name[25];
	char age[25];
	char phone[25];
	char a[25];
	cin.ignore();
	cout << " \n\t enter the phone number to delete record : ";
	cin.getline(a, 25);
	while (!stud.eof())
	{
		stud.getline(name, 25, '|');
		stud.getline(phone, 25, '|');
		stud.getline(age, 25);
		if (strcmp(phone, a) == 0)
		{
			continue;
		}
		else
		{
			temp << name << '|' << phone << '|' << age << '\n';
		}
	}
	temp.close();
	stud.close();
	stud.open("student.txt", ios::out);
	temp.open("temp.txt", ios::in);
	while (!temp.eof())
	{
		temp.getline(name, 25, '|');
		temp.getline(phone, 25, '|');
		temp.getline(age, 25);
		stud << name << '|' << phone << '|' << age << '\n';
	}
	temp.close();
	stud.close();
	remove("temp.txt");
	cout << "\n done !!! \n";
}
void update_student()
{
	fstream stud;
	fstream temp;

	stud.open("student.txt", ios::in);
	temp.open("temp.txt", ios::out);
	char name[25];
	char age[25];
	char phone[25];
	char a[25];
	cin.ignore();
	cout << " \n\t enter the phone number to update record : ";
	cin.getline(a, 25);
	while (!stud.eof())
	{
		stud.getline(name, 25, '|');
		stud.getline(phone, 25, '|');
		stud.getline(age, 25);
		if (strcmp(phone, a) == 0)
		{

			cout << " \n\tenter new value of record  \n ";
			cout << " \n name : ";
			cin.getline(name, 25);
			cout << " \n phone : ";
			cin.getline(phone, 25);
			cout << " \n age : ";
			cin.getline(age, 25);
			temp << name << '|' << phone << '|' << age << '\n';
		}
		else
		{
			temp << name << '|' << phone << '|' << age << '\n';
		}


	}
	temp.close();
	stud.close();

	stud.open("student.txt", ios::out);
	temp.open("temp.txt", ios::in);
	while (!temp.eof())
	{
		temp.getline(name, 25, '|');
		temp.getline(phone, 25, '|');
		temp.getline(age, 25);
		stud << name << '|' << phone << '|' << age << '\n';
	}
	temp.close();
	stud.close();
	remove("temp.txt");
	cout << "\n done !!! \n";
}
void display_all()
{
	char name[25];
	char age[25];
	char phone[25];

	fstream stud;
	stud.open("student.txt", ios::in);

	cout << " \n\t name \t phone \t age \n";
	while (!stud.eof())
	{
		stud.getline(name, 25, '|');
		stud.getline(phone, 25, '|');
		stud.getline(age, 25);
		cout << "\n \t " << name << "\t" << phone << "\t" << age << endl;

	}
}
void search_student()
{

	fstream stud;
	stud.open("student.txt", ios::in);
	char name[25];
	char age[25];
	char phone[25];
	char a[25];
	cout << " \n enter the phone to search about it : ";
	cin.ignore();
	cin.getline(a, 25);
	bool x = false;
	cout << " \n\t name \t phone \t age \n";
	while (!stud.eof())
	{
		stud.getline(name, 25, '|');
		stud.getline(phone, 25, '|');
		stud.getline(age, 25);
		if (strcmp(phone, a) == 0)
		{
			cout << "\n \t " << name << "\t" << phone << "\t" << age << endl;
			x = true;
			break;
		}

	}
	if (x == false)
	{
		cout << " \n not found !!!!\n";
	}
	stud.close();
}
void  insert_student()
{

	char name[25];
	char age[25];
	char phone[25];
	fstream stud;
	stud.open("student.txt", ios::app);
	cin.ignore();
	cout << " \n name : ";
	cin.getline(name, 25);
	cout << " \n phone : ";
	cin.getline(phone, 25);
	cout << " \n age : ";
	cin.getline(age, 25);
	stud << name << '|' << phone << '|' << age << '\n';

	cout << "done !";
	stud.close();
}

int main()
{
	bool flag = true;



	while (flag)
	{
		system("cls");
		//system("COLOR  04");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED |
			FOREGROUND_GREEN |
			FOREGROUND_INTENSITY |
			BACKGROUND_BLUE
			);
		cout << "\t\t\t-------------------------------------------------------------------------";
		cout << "\n\n\t\t\t\t\t\tPlease Enter Your Choice (1-11): ";
		cout << "\n\n\t\t\t-------------------------------------------------------------------------";
		//getch();
		//system("COLOR 08");
		cout << "\n\n\t1.CREATE Customer RECORD";
		cout << "\n\n\t2.SEARCH Customer RECORD ";
		cout << "\n\n\t3.DISPLAY ALL CustomerRECORDS";
		cout << "\n\n\t4.MODIFY  Customer RECORD";
		cout << "\n\n\t5.DELETE  Customer RECORD";
		cout << "\n\n\t6. Read whole content of file";
		cout << "\n\n\t7. Read any line in  file";
		cout << "\n\n\t8.count number of character in file";
		cout << "\n\n\t9.count number of lines";
		cout << "\n\n\t10.count number of words";
		cout << "\n\n\t11. EXIT";
		cout << "\n\n\t-------------------------------------------------------------------------\n\n";

		int ch;
		cout << "\t choose any Opreation : ";
		cin >> ch;
		system("cls");
		switch (ch)
		{

		case 1:
			insert_student();
			break;
		case 2:
			search_student();
			break;
		case 3:
			display_all();
			break;
		case 4:
			update_student();

			break;
		case 5:
			delete_student();
			break;
		case 6:
			read_all_data();
			break;
		case 7:
			cout << read(4) << endl;
			break;
		case 8:
			count_num_char();
			break;
		case 9:
			count_num_line();
			break;
		case 10:
			count_num_word();
			break;
		case 11:
			exit(0);
			break;
		default:
			cout << " \n choose right number \n";
		}
		cout << " if you continue to use program press ' y ' \n ";
		char f;
		cin >> f;
		if (f != 'y')
		{
			flag = false;
		}
	}
	return 0;
	system("pause");
}




