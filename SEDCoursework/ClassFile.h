#pragma once
#include <string>
#include <iostream>

using namespace std;

enum UserPrivilage
{
	Principal, Moderator, ContentCreator, PremiumUser, BasicUser
};

class User
{
public:
	User();
	User(string username, string password);
	UserPrivilage GetUserType();
	string GetUsername();
	bool Login(string inputPassword);
	void ChangePassword(string oldPassword, string newPassword);
	string ReadContent();

protected:
	string Username;
	string Password;
	UserPrivilage UserType;
};

class Consumer: public User
{
public:
	Consumer();
	Consumer(string username, string password);
};

class PremiumUser: public Consumer
{
public: 
	PremiumUser();
	PremiumUser(string username, string password);
};

class BasicUser : public Consumer
{
public:
	BasicUser();
	BasicUser(string username, string password);
};

class Admin : public User
{
public:
	Admin();
	Admin(string username, string password);

	virtual void CreateContent(string content);
	virtual void EditContent(string content);
	virtual void DeleteContent();
};

class Principal : public Admin
{
public:
	Principal();
	Principal(string username, string password);

	void CreateContent(string content) override;
	void EditContent(string content) override;
	void DeleteContent() override;

	void DeleteUser(string username);
};

class Moderator : public Admin
{
public:
	Moderator();
	Moderator(string username, string password);

	void EditContent(string content) override;
	void DeleteContent() override;
};

class ContentCreator : public Admin
{
public:
	ContentCreator();
	ContentCreator(string username, string password);

	void CreateContent(string content) override;
};

