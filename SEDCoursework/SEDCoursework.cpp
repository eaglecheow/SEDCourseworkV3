// SEDCoursework.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ClassFile.h"
#include <iostream>
#include <string>
#include <vector>
#include <tuple>

using namespace std;

vector<User*>userList;

void Menu();
void AccessFeature(User selectedUser);

void CreateUser()
{
	cout << "Create a user... " << endl;
	cout << "Please choose a user type : " << endl;
	cout << "1. Principal" << endl;
	cout << "2. Moderator" << endl;
	cout << "3. Content Creator" << endl;
	cout << "4. Premium User" << endl;
	cout << "5. Basic User" << endl;

	string userInput = "";

	while (userInput != "1" && userInput != "2" && userInput != "3" && userInput != "4" && userInput != "5")
	{
		cout << "Your option : ";
		cin >> userInput;
	}

	int option = stoi(userInput);
	string username = "";
	string password = "";

	cout << "Please enter a username : ";
	cin >> username;

	cout << "Please enter a password : ";
	cin >> password;

	if (option == 1)
	{
		class Principal principal = class Principal(username, password);
		userList.push_back(&principal);
	}
	else if (option == 2)
	{
		class Moderator moderator = class Moderator(username, password);
		userList.push_back(&moderator);
	}
	else if (option == 3)
	{
		class ContentCreator contentCreator = class ContentCreator(username, password);
		userList.push_back(&contentCreator);
	}
	else if (option == 4)
	{
		class PremiumUser premiumUser = class PremiumUser(username, password);
		userList.push_back(&premiumUser);
	}
	else if (option == 5)
	{
		class BasicUser basicUser = class BasicUser(username, password);
		userList.push_back(&basicUser);
	}
	else
	{
		cout << "Create user error" << endl;
	}

	Menu();
}

void ShowUser()
{
	for each (User* user in userList)
	{
		cout << user->GetUsername() << endl;
	}

	Menu();
}

void Login()
{
	string username;
	bool isUsernameFound = false;
	User* selectedUser = &User();
	while (isUsernameFound == false)
	{
		cout << "Please enter your username : ";
		cin >> username;

		for each (User* user in userList)
		{
			if (user->GetUsername() == username)
			{
				selectedUser = user;
				isUsernameFound = true;
				cout << "User found!" << endl;
			}
		}
	}

	string password;
	cout << "Please enter password : ";
	cin >> password;

	if (selectedUser->Login(password))
	{
		cout << "Login Successful!" << endl;
		AccessFeature(*selectedUser);
	}
	else
	{
		cout << "Password Incorrect!";
		Login();
	}
}

void AccessFeature(User selectedUser)
{
	bool quitToMenu = false;

	if (selectedUser.GetUserType() == Principal)
	{
		class Principal principal = class Principal();
	}
	else if (selectedUser.GetUserType() == Moderator)
	{
		class Moderator moderator = class Moderator();
	}
	else if (selectedUser.GetUserType() == ContentCreator)
	{
		class ContentCreator contentCreator = class ContentCreator();
	}
	else if (selectedUser.GetUserType() == PremiumUser)
	{
		class PremiumUser premiumUser = class PremiumUser();
	}
	else if (selectedUser.GetUserType() == BasicUser)
	{
		class BasicUser basicUser = class BasicUser();
	}
	Menu();
}

void Menu()
{
	cout << "Please select a function : " << endl;
	cout << "1. Create User" << endl;
	cout << "2. Show Users" << endl;
	cout << "3. Login" << endl;

	string userInput = "";

	while (userInput != "1" && userInput != "2" && userInput != "3")
	{
		cout << "Your option : ";
		cin >> userInput;
	}

	int option = stoi(userInput);

	if (option == 1)
	{
		CreateUser();
	}
	else if (option == 2)
	{
		ShowUser();
	}
	else if (option == 3)
	{
		Login();
	}
}


int main()
{
	Menu();
}

