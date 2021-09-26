#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class Student
{
	private:
		int i,j,id,cs,sem[8],num;
		float cgpa,gpa[8];
		string name,no;
		
	public:
		static int total;
		///////////cunstructor///////////
		Student()
		{
			num=0;
			id=0;
			cgpa=0;
			cs=0;
			for(i=0;i<8;i++)
			{
				sem[i] = i+1;
				gpa[i] = 0.0;
			}
			name = "Default";
			no = "090078601";
		}
		/////////////setData////////////////////
		void setData()
		{
			system("cls");
			Student *ptr;
			ptr = this;
			int n;
			cout << "Enter number of Student you want to add : ";
			n = check();
			for(i=0;i<n;i++)
			{
				system("cls");
				
				if(ptr->id == 0)
				{
					ptr->setID();
					ptr->setName();
					ptr->setNo();
					ptr->setCs();
					ptr->setGPA();
					total++;
				}
				else
				{
					i--;
				}
				ptr++;
			}
		}
		void setCs()
		{
			cout << "Enter current semester : ";
			cs = check();
		}
		void setID()
		{
			cout << "Enter ID : ";
			id = check();
		}
		void setGPA()
		{
			cgpa = 0;
			for(j=0;j<cs-1;j++)
			{
				cout << "Enter GPA for " << j+1;
				if(j == 0)
				{
					cout << "st";
				}
				else if(j == 1)
				{
					cout << "nd";
				}
				else if(j == 2)
				{
					cout << "rd";
				}
				else
				{
					cout << "th";
				}
				cout << " semester : ";
				gpa[j] = checkgpa();
				cgpa = cgpa + gpa[j];
			}
			if(cs == 1)
			{
				cgpa = 0;
			}
			else
			{
				cgpa = cgpa / (cs-1);
			}
		}
		void setName()
		{
			cout << "Enter name : ";
			cin.ignore();
			getline(cin,name);
		}
		void setNo()
		{
			cout << "Enter Contact No. : ";
			cin >> no;
		}
		///////////////////Add semester//////////////////
		void add()
		{
			Student *ptr;
			ptr = this;
			for(i=0;i<total;i++)
			{
				if(ptr->id != 0)
				{
					cout << "Enter GPA for " << ptr->id << " : ";
					cin >> ptr->gpa[ptr->cs-1];
					ptr->cs++;
					ptr->cgpa = 0;
					for(j=0;j<ptr->cs-1;j++)
					{
						ptr->cgpa = ptr->cgpa + ptr->gpa[j];
					}
					ptr->cgpa = ptr->cgpa / (ptr->cs-1);
				}
				ptr++;
			}
		}
		//////////////////getData///////////////////////////////
		void getData()
		{
			Student *ptr;
			ptr = this;
			header();
			for(i=0;i<total;i++)
			{
				if(ptr->id!=0)
				{
					getNum();
					ptr->getID();
					ptr->getName();
					ptr->getNo();
					ptr->getCS();
					ptr->getCGPA();				
					ptr->getGPA();
					cout << endl <<  "------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
				}
				ptr++;
			}
		}
		void getNum()
		{
			num++;
			cout << " " << left << setw(5) << num << left << setw(2) << "|";
		}
		void getID()
		{
			cout << left << setw(7) << id << left << setw(2) << "|";
		}
		void getName()
		{
			cout << left << setw(19) << name << left << setw(2) << "|";
		}
			void getNo()
		{
			cout << left << setw(15) << no << left << setw(5) << "|";
		}
		void getCS()
		{
			cout << left << setw(6) << cs << left << setw(2) << "|";
		}
		void getCGPA()
		{
			cout << fixed << setprecision(2)  << left << setw(5) << cgpa << left << setw(2) << "|";
		}
		void getGPA()
		{
			for(j=0;j<cs-1;j++)
			{
				cout << left << setw(7) << gpa[j]<< left << setw(2) << "|";
			}
		}
		////////////Header//////////////
		void header()
		{
			system("cls");
			num = 0;
			cout << "------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
			cout << " " << left << setw(5) << "No." << left << setw(4) << "|";
			cout << left << setw(5) << "ID" << left << setw(9) << "|";
			cout << left << setw(12) << "Name" << left << setw(5) << "|";
			cout << left << setw(12) << "Contact"<< left << setw(2) << "|";
			cout << left << setw(9) << "Semester"<< left << setw(2) << "|";
			cout << left << setw(5) << "CGPA" << left << setw(2) << "|";
			for(i=0;i<8;i++)
			{
				cout << left << setw(0) << "GPA("<<setw(0)<<i+1<<setw(2)<< ")" << left << setw(2) << "|";
			}
			cout << endl <<  "------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
		}
		//////////get single student data//////////
		void get()
		{
			Student *ptr;
			ptr = this;
			getNum();
			ptr->getID();
			ptr->getName();
			ptr->getNo();
			ptr->getCS();
			ptr->getCGPA();				
			ptr->getGPA();
			cout << endl <<  "---------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
		}
		//////////////Search///////////
		void search()
		{
			float Gpa;
			string Name;
			int ser,Id,count=0;
			Student *ptr;
			ptr = this;
			search:
			system("cls");
			cout << "Enter\n1 to Search by GPA\n2 to Search by Name\n3 to Search all who are above 3.5 GPA\n";
			cout << "4 to Search all who are under serious warning (i.e. CGPA below 1.8)\n5 to Search all who are under warning ";
			cout << "(i.e. CGPA below 2.0 and above 1.8)\n6 to Search by ID " << endl;
			cin >> ser;
			if(ser==1)
			{
				cout << "Enter GPA to search : ";
				cin >> Gpa;
			}
			else if (ser==2)
			{
				cout << "Enter name to search : ";
				cin >> Name;
			}
			else if(ser==6)
			{
				cout << "Enter ID to search : ";
				cin >> Id;
			}
			else if (ser < 1 || ser > 6)
			{
				cout << "Wrong choice ! " << endl;
				system("pause");
				goto search;
			}
			header();
			for(j=0;j<total;j++)
			{
				if(ser == 1)
				{
					for(i=0;i<ptr->cs-1;i++)
					{
						if(Gpa == ptr->gpa[i])
						{
							ptr->get();
							count++;
						}
					}
				}
				else if(ser == 2)
				{
					if(Name == ptr->name)
					{
						ptr->get();
						count++;
					}
				}
				else if(ser == 3)
				{
					for(i=0;i<ptr->cs-1;i++)
					{
						if(ptr->gpa[i] > 3.5)
						{
							ptr->get();
							count++;						
						}
					}
				}
				else if(ser == 4)
				{
					for(i=0;i<ptr->cs-1;i++)
					{
						if(ptr->gpa[i] < 1.8)
						{
							ptr->get();
							count++;						
						}
					}
				}
				else if(ser == 5)
				{
					for(i=0;i<ptr->cs-1;i++)
					{
						if(ptr->gpa[i] < 2.0 && ptr->gpa[i] > 1.8)
						{
							ptr->get();
							count++;
						}
					}
				}
				else if(ser == 6)
				{
					if(Id == ptr->id)
					{
						ptr->get();
						count++;
					}
				}
				ptr++;
			}
			if(count == 0)
			{
				cout << "Error 404 ! Not found !";
			}
		}
		////////////////Edit/////////////
		void edit()
		{
			Student *ptr;
			ptr = this;
			int Id,count,ser;
			string Name;
			edit:
			system("cls");
			cout << "Enter 1 to edit by name,2 to edit by ID : " << endl;
			cin >> ser;
			if(ser==1)
			{
				cout << "Enter student name to edit : ";
				cin >> Name;
			}
			else if (ser==2)
			{
				cout << "Enter student ID to edit : ";
				cin >> Id;
			}
			else
			{
				cout << "Wrong choice ! " << endl;
				system("pause");
				goto edit;
			}
			for(i=0;i<total;i++)
			{
				if(Id == ptr->id)
				{
					ptr->setName();
					ptr->setNo();
					ptr->setCs();	
					ptr->setGPA();
					count++;
				}
				else if(Name == ptr->name)
				{
					ptr->setName();
					ptr->setNo();
					ptr->setCs();	
					ptr->setGPA();
					count++;
				}
				ptr++;
			}
			if(count == 0)
			{
				cout << "Student not found ! " << endl;
			}
		}
		//////////////////Append/////////////////////////
		void append()
		{
			Student *ptr;
			ptr = this;
			ofstream Id,Name,Sem,Gpa,Cgpa,No,Cs;
			Id.open("id.txt",fstream::app);
			Name.open("name.txt",fstream::app);
			Sem.open("sem.txt",fstream::app);
			Gpa.open("gpa.txt",fstream::app);
			Cgpa.open("cgpa.txt",fstream::app);
			No.open("no.txt",fstream::app);
			Cs.open("cs.txt",fstream::app);
			for(i=0;i<total;i++)
			{
				if(ptr->id != 0)
				{
					Cs << ptr->cs << endl;
					Id << ptr->id << endl;
					Name << ptr->name << endl;
					for(j=0;j<ptr->cs-1;j++)
					{
						Gpa << ptr->gpa[j] <<"\t";
						Sem << j+1 << "\t";
					}
					Gpa << endl;
					Sem << endl;
					Cgpa << ptr->cgpa << endl;
					No << ptr->no << endl;
				}
				ptr++;
			}
			Id.close();
			Name.close();
			Sem.close();
			Gpa.close();
			Cgpa.close();
			No.close();
			Cs.close();
			cout << "Successfully appended data in txt file ! ";
		}
		/////////////////Save/////////////////////
		void save()
		{
			Student *ptr;
			ptr = this;
			ofstream Id,Name,Sem,Gpa,Cgpa,No,Cs;
			Id.open("id.txt");
			Name.open("name.txt");
			Sem.open("sem.txt");
			Gpa.open("gpa.txt");
			Cgpa.open("cgpa.txt");
			No.open("no.txt");
			Cs.open("cs.txt"); 		//  n
			for(i=0;i<total;i++)
			{
				if(ptr->id != 0)
				{	
					Cs << ptr->cs << endl;
					Id << ptr->id << endl;
					Name << ptr->name << endl;
					for(int j=0;j<ptr->cs-1;j++)
					{
						Gpa << ptr->gpa[j] <<"\t";
						Sem << j+1 << "\t";
					}
					Gpa << endl;
					Sem << endl;
					Cgpa << ptr->cgpa << endl;
					No << ptr->no << endl;
				}
				ptr++;
			}
			Id.close();
			Name.close();
			Sem.close();
			Gpa.close();
			Cgpa.close();
			No.close();
			Cs.close();
			cout << "Successfully saved data in txt file ! ";
		}
		/////////////////load from file/////////////////////////
		void load()
		{
			Student *ptr;
			ptr = this;
			ifstream Id,Name,Sem,Gpa,Cgpa,No,N;
			Id.open("id.txt");
			Name.open("name.txt");
			Sem.open("sem.txt");
			Gpa.open("gpa.txt");
			Cgpa.open("cgpa.txt");
			No.open("no.txt");
			N.open("cs.txt");
			if(Id.is_open())
			{
				while(!Id.eof())
				{
					if(ptr->id == 0)
					{
						Id >> ptr->id;
						if(ptr->id == 0)
						{
							break;
						}
						getline(Name,ptr->name);
						N >> ptr->cs;
						for(i=0;i<ptr->cs-1;i++)
						{
							Gpa >> ptr->gpa[i];
							sem[i] = i+1;
						}
						Cgpa >> ptr->cgpa;
						No >> ptr->no;
						total++;
					}
					ptr++;
				}
			}
			cout << "Successfully loaded data from txt file ! ";
			Id.close();
			Name.close();
			Sem.close();
			Gpa.close();
			Cgpa.close();
			No.close();
			N.close();
		} 
		/////////////////////Detele/////////////////////
		void dell()
		{
			Student *ptr;
			ptr = this;
			ptr->id=0;
			ptr->cgpa=0;
			for(i=0;i<ptr->cs;i++)
			{
				ptr->sem[i] = i+1;
				ptr->gpa[i] = 0.0;
			}
			ptr->cs=0;
			ptr->name = "Delete";
			ptr->no = "090078601";
		}
		void del()
		{
			Student *ptr;
			ptr = this;
			int Id,count,ser;
			string Name;
			edit:
			system("cls");
			cout << "Enter 1 to delete by name,2 to edit by ID : " << endl;
			cin >> ser;
			if(ser==1)
			{
				cout << "Enter student name to delete : ";
				cin >> Name;
			}
			else if (ser==2)
			{
				cout << "Enter student ID to delete : ";
				cin >> Id;
			}
			else
			{
				cout << "Wrong choice ! " << endl;
				system("pause");
				goto edit;
			}
			for(i=0;i<total;i++)
			{
				if(Id == ptr->id)
				{
					ptr->dell();
					cout << "Deleted !" << endl;
					count++;
				}
				else if(Name == ptr->name)
				{
					ptr->dell();
					cout << "Deleted !" << endl;
					count++;
				}
				ptr++;
			}
			if(count == 0)
			{
				cout << "Student not found ! " << endl;
			}
		}
		/////////////////Sort///////////////////////////////////////////////////
		void sort()
		{
			system("cls");
			
			Student *ptr,temp;
			ptr = this;
			int choice;
			cout << "Enter 1 to sort by ID,2 to sort by CGPA : ";
			cin >> choice;
			cout << "Sorry ! this feature will be available on v2.0" << endl;
			/*
			if(choice == 1)
			{
				for(i=0;i<total;i++)
				{
					for(j=0;j<total;j++)
					{
						if((ptr+i)->id > (ptr+j)->id)
						{
							temp = *(ptr+i);
							*(ptr+i) = *(ptr+j);
							*(ptr+j) = temp;
							cout << "Exchanged !" << endl;
						}
					}
				}
			}
			else if (choice == 2)
			{
				for(i=0;i<total;i++)
				{
					for(j=0;j<total;j++)
					{
						if((ptr+i)->cgpa < (ptr+j)->cgpa)
						{
							temp = *(ptr+i);
							*(ptr+i) = *(ptr+j);
							*(ptr+j) = temp;
							cout << "Exchanged !" << endl;
						}
					}
				}
			}
			else
			{
				cout << "Wrong choice ! Enter again ! ";
				system("pause");
				sort();
			}
			cout << "Sorted ! ";
			*/
		}
		/////////////////////check if id is ZERO/////////////////////////////////
		int checkid()
		{
			if(id == 0)
			{
				return 0;
			}
			else
			{
				return 1;
			}
		}
		/////////////////////////////Input validation check////////////////////////////////
		int check()
		{
			int a;
			while(!(cin >> a) || a < 0)
			{
			    cout << "Enter again ! ";
			    cin >> a;
			}
			return a;
		}
		float checkgpa()
		{
			float a;
			while(!(cin >> a) || a < 0.0 || a > 4.0)
			{
			    cout << "Enter again ! ";
			    cin >> a;
			}
			return a;
		}
};
int Student::total = 0;
void au()
{
	cout << "\t\t           _        _    _       _                    _ _         " << endl;
	cout << "\t\t     /\\   (_)      | |  | |     (_)                  (_) |        " << endl;
	cout << "\t\t    /  \\   _ _ __  | |  | |_ __  ___   _____ _ __ ___ _| |_ _   _ " << endl;
	cout << "\t\t   / /\\ \\ | | '__| | |  | | '_ \\| \\ \\ / / _ \\ '__/ __| | __| | | |" << endl;
	cout << "\t\t  / ____ \\| | |    | |__| | | | | |\\ V /  __/ |  \\__ \\ | |_| |_| |" << endl;
	cout << "\t\t /_/    \\_\\_|_|     \\____/|_| |_|_| \\_/ \\___|_|  |___/_|\\__|\\__, |" << endl;
	cout << "\t\t                                                             __/ |" << endl;
	cout << "\t\t                                                            |___/ " << endl;
	cout << endl << "\t\t    Welcome to Air University Students Managment System v1.0" << endl;
	cout <<         "\t\t    ________________________________________________________" << endl;
}
string encrypt (string a)
{
	for(int i=0;i<a.length();i++)
	{
		a.at(i) = a.at(i) + i - 64;
	}
	return a;
}
string decrypt (string a)
{
	for(int i=0;i<a.length();i++)
	{
		a.at(i) = a.at(i) - i + 64;
	}
	return a;
}
