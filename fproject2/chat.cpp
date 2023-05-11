#include "chat.h"

chat::chat()
{
	
}

void chat::adduser(user _new)
{
	for (auto elem1 : _chat.second)
	{
		if (elem1 == _new) return;
	}
	_chat.second.push_back(_new);
}

void chat::addtext(massage _new)
{
	_chat.first.push_back(_new);
	adduser(_new.getuser());
}

void chat::print()
{
	for (auto elem1 : _chat.first)
	{
		elem1.print();
	}
}

bool chat::chekuser(user a)
{
	for (auto elem1 : _chat.second)
	{
		if (elem1 == a) return 1;
	}
	return 0;
}

void chat::printusers()
{
	for (auto elem : _chat.second)
	{
		cout << elem.getlog() << " ";
	}
	cout << endl;
}

