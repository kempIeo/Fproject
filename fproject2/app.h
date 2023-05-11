#pragma once
#include"chat.h"

class app
{
private:
	vector<chat> _app;
	vector<user> _user;
public:
	app();
	void start();
	bool chekuser(user a);
	bool chekuser(string log);
	bool chekchat(chat a);
	user getuserbylog(string log);
	void adduser(user _new);
	void addchat(chat _new);
	void sendmassage(user a, massage text);
	void sendmassage(massage text, int numb);
	void printusers();
	void newmember();
	void makechat(user a,massage text);
	void printuserchats(user a);
	void secondoption();
	void sendmassage(user a);
	void chekmasseg();
	~app() { _app.clear(); }
};


