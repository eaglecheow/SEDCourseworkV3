#include "stdafx.h"
#include "ClassFile.h"

User::User()
{
	Username = "UserDefault";
	Password = "000000";
	UserType = UserPrivilage::BasicUser;
}

User::User(string username, string password)
{
	Username = username;
	Password = password;
	UserType = UserPrivilage::BasicUser;
}

string User::GetUsername()
{
	return Username;
}

UserPrivilage User::GetUserType()
{
	return UserType;
}

bool User::Login(string inputPassword)
{
	return (inputPassword == Password);
}

void User::ChangePassword(string oldPassword, string newPassword)
{
	if (oldPassword == this->Password)
	{
		this->Password = newPassword;
		cout << "Password changed successfully." << endl;
	}
	else
	{
		cout << "Password incorrect. Password change fail." << endl;
	}
}

string User::ReadContent()
{
	switch (UserType)
	{
	case UserPrivilage::BasicUser:
		return "Basic contents for Basic User";
		break;
	case UserPrivilage::PremiumUser:
		return "Premium contents for Premium User";
		break;
	case UserPrivilage::ContentCreator:
	case UserPrivilage::Moderator:
	case UserPrivilage::Principal:
		return "Admin can access all contents";
		break;
	default:
		return "Default String";
		break;
	}
}

Consumer::Consumer() : User()
{
	//Empty
}

Consumer::Consumer(string username, string password) : User(username, password)
{
	//Empty
}

BasicUser::BasicUser() : Consumer()
{
	//Empty
}

BasicUser::BasicUser(string username, string password) : Consumer(username, password)
{
	//Empty
}

PremiumUser::PremiumUser() : Consumer()
{
	UserType = UserPrivilage::PremiumUser;
}

PremiumUser::PremiumUser(string username, string password) : Consumer(username, password)
{
	UserType = UserPrivilage::PremiumUser;
}

Admin::Admin() : User()
{
	UserType = UserPrivilage::ContentCreator;
}

Admin::Admin(string username, string password) : User(username, password)
{
	UserType = UserPrivilage::ContentCreator;
}

void Admin::CreateContent(string content)
{
	cout << "You have no access to this function" << endl;
}

void Admin::EditContent(string content)
{
	cout << "You have no access to this function" << endl;
}

void Admin::DeleteContent()
{
	cout << "You have no access to this function" << endl;
}

Principal::Principal() : Admin()
{
	UserType = UserPrivilage::Principal;
}

Principal::Principal(string username, string password) : Admin(username, password)
{
	UserType = UserPrivilage::Principal;
}

void Principal::CreateContent(string content)
{
	cout << "Content created : " << content << endl;
}

void Principal::EditContent(string content)
{
	cout << "Content edited : " << content << endl;
}

void Principal::DeleteContent()
{
	cout << "Content deleted" << endl;
}

void Principal::DeleteUser(string username)
{
	//Delete user
}

Moderator::Moderator() : Admin()
{
	UserType = UserPrivilage::Moderator;
}

Moderator::Moderator(string username, string password) : Admin(username, password)
{
	UserType = UserPrivilage::Moderator;
}

void Moderator::EditContent(string content)
{
	cout << "Content edited : " << content << endl;
}

void Moderator::DeleteContent()
{
	cout << "Content deleted" << endl;
}

ContentCreator::ContentCreator() : Admin()
{
	//Empty
}

ContentCreator::ContentCreator(string username, string password) : Admin(username, password)
{
	//Empty
}

void ContentCreator::CreateContent(string content)
{
	cout << "Content created : " << content << endl;
}