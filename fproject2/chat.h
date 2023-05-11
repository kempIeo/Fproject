#pragma once
#include <iostream>
#include<vector>
#include<algorithm>
#include <string>
#include <Windows.h>

using namespace std;

struct user
{
private:
	string _login;
	string _password;
public:
	user() = default;
	user(string log, string pas) {_login = log, _password = pas;};
	string getlog() const { return _login; };
	string getpassword() const { return _password; }
	bool chekpassvord(string password) const { return _password == password;};
	bool cheklog(string log) const { return log == _login;};
	bool operator ==(user a) { return (a.getlog() == _login)&&(a.getpassword()==_password);}
};

struct massage
{
private:
	user _user;
	string _text;
public:
	massage() = default;
	massage(user user, string text) { _user = user; _text = text; };
	void print() { cout << _user.getlog() << ": " << _text << endl<<endl; };
	user getuser() { return _user; };	
};

class chat
{
private:

	pair<vector<massage> ,vector<user>> _chat;
	
public:
	chat();
	void adduser(user _new);
	void addtext(massage _new);
	void  print();
	bool chekuser(user a);
	void printusers();
	vector<user> getuser() { return _chat.second; };
	bool operator ==(chat a) { return a._chat.second.size() == _chat.second.size(); }
	int getusercount() { return _chat.second.size(); };
	~chat() { _chat.first.clear(); _chat.second.clear(); };
};

