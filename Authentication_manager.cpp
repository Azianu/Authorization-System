#include<iostream>
#include<iomanip>
#include<string>
#include<cstring>
#include<fstream>
#include<ctime>

using namespace std;

void sign_up();
void login();


struct users
{
	string user_name;
	string password;
};

time_t timetoday;
string active_user;

int main()
{
	system("CLS");
	char choice_access, choice;

	cout << endl << endl;
	cout << setw(65) << "|" << setw(35) << setfill('-') << "-" << "|" << setfill(' ') << endl;
	cout << setw(65) << "|" << "\t\tMENU   \t " << setw(13) << " | " << endl;
	cout << setw(65) << "|" << setw(35) << setfill('-') << "-" << "|" << setfill(' ') << endl;
	cout << setw(65) << "|" << setw(37) << " | " << endl;
	cout << setw(65) << "|" << "\tLogin\t\t1" << setw(13) << " | " << endl;
	cout << setw(65) << "|" << "\tSign Up\t\t2" << setw(13) << " | " << endl;
	cout << setw(65) << "|" << "\tLogout\t\t3" << setw(13) << " | " << endl;
	cout << setw(65) << "|" << "\tEXIT\t\t4" << setw(13) << " | " << endl;
	cout << setw(65) << "|" << setw(35) << setfill('-') << "-" << "|" << setfill(' ') << endl;
again:
	cout << endl << setw(84) << "Enter your choice: ";
	cin >> choice_access;

	switch (choice_access)
	{
	case '1':
	{
				login();
				break;
	}
	case '2':
	{
				sign_up();
				break;
	}
	case '3':
	{
				cout << "Are you sure you want to logout?(Y/N)";
				cin >> choice;
				if (choice == 'Y' || choice == 'y')
				{
					active_user = " ";
					system("CLS");
					cout << "\n\n\n\n\n" << setw(90) << "Logged out\n\n";
					cout << setw(103) << "Press any key to go the main screen.";
					cin.get(); cin.get();
					main();
				}
				else
					main();
				break;
	}

	case '4':
	{
				cout << "Are you sure you want to Exit?(Y/N)";
				cin >> choice;
				if (choice == 'Y' || choice == 'y')
				{
					system("CLS");
					cout << "\n\n\n\n\n";
					cout << setw(100) << "Thank you for using this software." << endl;
					cout << setw(93) << "Hope to see you again" << endl;
					cout << setw(96) << "Have a nice day\n\n\n\n\n";
					exit(0);
				}
				else
				{
					system("CLS");
					main();
				}
				break;
	}
	default:
	{
			   cout << "Invalid choice.\n Try again.\n";
			   goto again;
	}
	}

	cout << endl;
	system("pause");
	return 0;
}




void login()
{
	system("CLS");
	string user, pass, user_f, pass_f;
	char choice;
	//Login header
	cout << setw(65) << "|" << setw(35) << setfill('-') << "-" << "|" << setfill(' ') << endl;
	cout << setw(65) << "|" << "\t\tLOGIN \t " << setw(13) << " | " << endl;
	cout << setw(65) << "|" << setw(35) << setfill('-') << "-" << "|" << setfill(' ') << endl;
	//Inputting username and password from user
	cout << setw(85) << "Username:";
	cin >> user;
	cout << setw(85) << "Password:";
	cin >> pass;

	//Checking if account exists in "users.txt" file
	fstream file;
	file.open("users.txt", ios::in);
	if (!file)
	{
		cout << "No Account exists. Create account first.";
		cin.ignore(); cin.ignore();
		sign_up();
	}

	else
	{
		while (!file.eof())
		{
			getline(file, user_f);
			getline(file, pass_f);
			//checking if username and password are correct
			if ((user == user_f) && (pass == pass_f))
			{
				active_user = user_f;
				file.close();
				cout << endl << endl << setw(93) << "Access granted." << endl;
				cout << setw(102) << "Press any key to go the main menu.";
				cin.get(); cin.get();
				main();
			}
			else;
		}
	}
	file.close();
	//If account does not exists then sending to the sign_up() function
	cout << endl << endl << setw(93) << "Invalid credentials." << endl;
	cout << "Do you want to create a account?(Y/N)";
	cin >> choice;
	if (choice == 'Y' || choice == 'y')
		sign_up();
	else
		main();
}

void sign_up()
{
	system("CLS");
	
	users user_account;
	fstream file;
	file.open("users.txt", ios::out | ios::app);


	cout << setw(65) << "|" << setw(35) << setfill('-') << "-" << "|" << setfill(' ') << endl;
	cout << setw(65) << "|" << "\t\tSign Up\t " << setw(13) << " | " << endl;
	cout << setw(65) << "|" << setw(35) << setfill('-') << "-" << "|" << setfill(' ') << endl;

	cout << setw(85) << "Username:";
	cin.ignore();
	getline(cin, user_account.user_name);
	cout << setw(85) << "Password:";
	getline(cin, user_account.password);

	file << user_account.user_name << endl;
	file << user_account.password << endl;
	file.close();
	cout << endl << endl << setw(93) << "Account created." << endl;
	cout << setw(100) << "Press any key to go to Login.";
	cin.ignore();
	login();
}

