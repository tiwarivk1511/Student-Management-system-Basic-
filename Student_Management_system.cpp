#include"student.h"
#include "addStudent.cpp"
#include "listStudent.cpp"
#include "editStd.cpp"
#include "delStd.cpp"
#include "search.cpp"
#include "sortStudent.cpp"

string usr,pas,u,p,sp,su;
void login();
void regstr();
void forgot();
int mod()
{
	int ch;

	cout<<"======================= Options =============================\n";
	cout<<"1.Login Account \n2.Register Yourself\n3.Forgot credential\n";
	cout<<"=============================================================\n";
	cout<<"Enter your choice:";
	cin>>ch;
	switch(ch)
	{
		case 1:
			login();
			break;
		case 2:
			regstr();
			break;
		case 3:
			forgot();
			break;
		default:
			cout<<"Sorry, wrong choice selected."<<endl;
	}
	cout<<endl;
	int x;
	cout<<"Enter non-integer to continue:";
	cin>>x;
	if(x)
	{
		mod();
	}
	else
	{
		return 0;
	}
}

void enter()
{
   system("cls");
    system("color 2");
	 cout<<"=============================================================";
     cout<<"\nTime: "__TIME__<<"\t\t                 Date: "<<__DATE__;
     cout<<"\n===============================================================\n\n";
     cout<<"           Welcome to Student Management System              \n";
	 cout<<"=============================================================\n";
     cout<<"\n===================== Log In / Sign UP ====================\n\n";
        mod();
}

void feature()
{
	cout<<"Time: "__TIME__<<"\t\t Date: "<<__DATE__;
	cout<<"\n\n=======================================================\n";
	cout <<"\t\t\tWelcome "<<usr<< endl;
	cout<<"\n=========================================================\n\n";
    cout << "1.Add Student !" << endl;
    cout << "2.view Student !" << endl;
    cout << "3.edit Student !" << endl;
    cout << "4.delete Student !" << endl;
    cout<<"5.Search Student data !"<<endl;
    cout<<"6.Sort Student data !"<<endl;
    cout << "7.Exit !" << endl;

    do
    {
        int choice;
        cout << "Enter ur choice :";
        cin >> choice;
        switch (choice)
        {
        case  1 :
            addStudent();
            break;
        case  2 :
            listStudent();
            break;
        case  3 :
            editStu();
            break;
        case  4 :
            delStu();
            break;
        case  5 :
            SearchStu();
            break;
        case  6 :
            sortStudents();
            break;
        case  7 :
            exit(0);
            break;
        default:
            cout <<"Please enter a valid choice !!";
            break;
        }
    } while (1);
}

int main()
{
	enter();
}

void regstr()
{
	int t=0;
	char a;
	system("cls");
	cout<<"=========================================================\n";
	cout<<"                      Register Yourself                  \n";
	cout<<"==========================================================\n\n";
	cout<<"Enter username:";
	cin>>usr;
	ofstream write("data\\username.dat",ios::app); // username file created which of append type 
	ifstream read("data\\username.dat");
	while(read>>u>>p)
	{
		if(u==usr)
		{
			t=1;
			break;
		}
	}
	if(t==1)
	{
		cout<<"Username is already taken."<<endl;
		cout<<"enter y = yes   n= no"<<endl;
		cout<<"Do you want to login [y/n] : ";
		cin>>a;
		if(a=='y')
		{
			system("cls");
			login();
		}
		else if(a == 'n')
		{
			system("cls");
			enter();
		}
	}
	else
	{
		cout<<"Enter password:";
		cin>>pas;
		write<<usr<<" "<<pas<<endl;
		cout<<"Registration is successfull."<<endl;
		system("cls");
		feature();
	}
	write.close();
}
void login()
{

	int t=0;
	cout<<"=========================================================\n";
	cout<<"                        Login Yourself                  \n";
	cout<<"==========================================================\n\n";
  
	cout<<"Enter the username: ";
	cin>>usr;
	cout<<"Enter the password: ";
	cin>>pas;
	ifstream read("data\\username.dat"); //ifstream uses here for reading the file
	while(read>>u>>p) // while loop uses here for reading the file till end and in each iteration registered username and password store in u and p respectively
	{
		if(u==usr && p==pas)
		{
			t=1;
		}
	}
	read.close();
	if(t==1)
	{
		cout<<"========================================================\n";
		cout<<"                 Login successfull"<<endl;
		cout<<"========================================================\n\n";
		system("cls");
		feature();
	}
	else
	{
		cout<<"Login failed."<<endl;
		mod();

	}
}

void forgot()
{
	int ch;
	system("cls");
	cout<<"=========================================================\n";
	cout<<"                        Forget Account                  \n";
	cout<<"==========================================================\n\n";
	cout<<"1.Search your account by username\n2.Search Your account by password\n3.Mainmenu\n4.Enter your choice:";
	cin>>ch;
	switch(ch)
	{
		case 1:
			{
				int t=0;
				cout<<"Enter your remembered username:";
				cin>>su;
				ifstream read("data\\username.dat");
				while(read>>u>>p)
				{
					if(su==u)
					{
						t=1;
						break;
					}
				}
				read.close();
				if(t==1)
				{
					cout<<"Congrats! account found\nPassword is: "<<p<<endl;
				}
				else
				{
					cout<<"Sorry, account not found"<<endl;
				}
				break;
			}
		case 2:
			{
				int t=0;
				cout<<"Enter your remembered password:";
				cin>>sp;
				ifstream read("data\\username.dat");
				while(read>>u>>p)
				{
					if(sp==p)
					{
						t=1;
						break;
					}
				}
				read.close();
				if(t==1)
				{
					cout<<"Congrats! account found\nUsername is: "<<u<<endl;
				}
				else
				{
					cout<<"Sorry, account not found"<<endl;
				}
				break;
			}
	    case 3:
		    {
		    	cout<<endl;
		    	mod();
		    	break;
			}
		default:
			{
				cout<<"Wrong choice selected.press a key to try again!"<<endl;
				forgot();
			}
			
	}
}
