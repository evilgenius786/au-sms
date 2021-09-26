#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include "header.h"
using namespace std;

int main()
{
	system("color 0a");
	int i,c=0,attempt = 3,max = 10,auth = 0;
	string uname,pass,a,b;
	string str;
	ifstream Uname,Pass;
	ofstream u,p;
	Student *ptr,*temp;
	ptr = new Student [max];
	temp = ptr;
	au();
	ifstream ufile("u.txt"),pfile("p.txt");
	if(!ufile.good() || !pfile.good())
	{
		ufile.close();
		pfile.close();
		string admin = "admin";
		u.open("u.txt");
		p.open("p.txt");
		admin = encrypt(admin);
		u << admin;
		p << admin;
		u.close();
		p.close();
	}
	Uname.open("u.txt");
	Pass.open("p.txt");
	Uname >> a;
	Pass >> b;
	a = decrypt(a);
	b = decrypt(b);
	Uname.close();
	Pass.close();
	do
	{
		ptr = temp;
		while(auth == 0)
		{
			char ch;
			pass = "";
			if(attempt == 3)
			{
				cout << "Default username password is admin : admin" << endl;
			}
			cout << "Enter Username : ";
			cin >> uname;
			cout << "Enter Password : ";
			ch = _getch();
			while(ch != 13)
			{
		      pass.push_back(ch);
		      cout << '*';
		      ch = _getch();
			}
			cout << endl;
			if(uname == a && pass == b)
			{
				cout << "Login successful ! ";
				cout << "\nLoading =";
				for(int i=0;i<30;i++)
				{
			        cout << "-" ;
			        Sleep(100);
			    }
			    cout << "\nSuccessfully loaded ! " << endl;
				auth++;
				system("pause");
				system("cls");
			}
			else
			{
				if(attempt == 0)
				{
					goto end;
				}
				cout << "Invalid username or password ! " << attempt << " attempts left ! " << endl;
				attempt--;
			}
		}
		system("cls");
		au();
		cout << "Enter\n1 to add student\n2 to show current student\n3 to search student\n4 to edit student";
		cout << "\n5 to save to file\n6 to load from file\n7 to delete a student\n8 to append current data with previous data\n9 to sort data\n10 to add a semester\n11 to update username and password" << "\n0 to exit !" << endl;
		cin >> c;
		if(c==1)
		{
			ptr->setData();
		}
		else if (c == 2)
		{
			ptr->getData();
		}
		else if(c==3)
		{
			ptr->search();
		}
		else if(c==4)
		{
			ptr->edit();
		}
		else if(c==5)
		{
			ptr->save();
		}
		else if( c == 6 )
		{
			ptr->load();
		}
		else if ( c== 7)
		{
			ptr->del();
		}
		else if(c == 8)
		{
			ptr->append();
		}
		else if(c == 9)
		{
			ptr->sort();
		}
		else if (c == 10)
		{
			ptr->add();
		}
		else if (c == 11)
		{
			string cu,cp;
			auth = 0;
			while(auth == 0)
			{
				char ch;
				cout << "Enter current username : ";
				cin >> uname;
				cout << "Enter current password : ";
				cin >> pass;
				ch = _getch();
				pass = "";
				while(ch != 13)
				{
			      pass.push_back(ch);
			      cout << '*';
			      ch = _getch();
				}
				if(uname == a && pass == b)
				{
					cout << "Enter new username : ";
					cin >> uname;
					cout << "Enter new password : ";
					ch = _getch();
					pass = "";
					while(ch != 13)
					{
				      pass.push_back(ch);
				      cout << '*';
				      ch = _getch();
					}
					u.open("u.txt");
					p.open("p.txt");
					uname = encrypt(uname);
					pass = encrypt(pass);
					u << uname;
					p << pass;
					u.close();
					p.close();
					auth++;
					cout << "Username and password updated ! ";
				}
				else
				{
					if(attempt == 0)
					{
						goto end;
					}
					cout << "Invalid username or password ! " << attempt << " attempts left ! " << endl;
					attempt--;
				}
			}
		}
		system("pause");
		system("cls");
	}
	while(c != 0);
	if(c == 0)
	{
		abc:
		cout << "Do you want to save data ? \nEnter\n1 to save data\n2 to append current data with previous one\n0 to exit without saving !";
		cin >> c;
		if(c == 1)
		{
			ptr->save();
		}
		else if(c == 2)
		{
			ptr->append();
		}
		else if(c == 0)
		{
			system("cls");
			cout << "Thanks for using our software ! Bye !" << endl;
		}
		else
		{
			cout << "Enter Again ! ";
			system("pause");
			goto abc;
		}
	}
	end:
		if(attempt == 0)
		{
			cout << "Login Failed ! Exiting ";
		}
}
