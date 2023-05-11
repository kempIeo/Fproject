#include "app.h"
using namespace std;


bool goodlog(string log)
{
	int size = log.size();
	if (size < 3 || size > 20) return false;

	for (int i = 0; i < size; i++)
	{
		if (log[i] == ' ') return false;
	}
	return true;
}

bool goodpassvord(string passvord)
{
	int size = passvord.size();
	if (size < 6 || size > 20) return false;

	for (int i = 0; i < size; i++)
	{
		if (passvord[i] == ' ') return false;
	}
	return true;
}

void app::start()
{
	int option;
	bool flag = true;
	do {
		do {
			system("cls");
			cout << "1) �������� ������������\n\n" <<
				"2) �������� �� ����� ������������\n\n" <<
				"3) ����������� ��� ���� ������������\n\n" <<
				"4) �����\n\n";
			cin >> option;
		} while (option < 1 || option>4);

		switch (option)
		{
		case 1: {
			newmember();
			break;
		};
		case 2: {
			secondoption();
			break;
		};
		case 3: {
			chekmasseg();
			break;
		};
		case 4:
		{
			flag = false;
			break;
		};
		}
	} while (flag);
	return;
}

app::app()
{
}

bool app::chekchat(chat a)
{
	for (auto elem : _app)
	{
		if (elem == a) return true;
	}
	return false;
}

bool app::chekuser(user a)
{
	for (auto elem : _user)
	{
		if (elem==a) return true;
	}
	return false;
}

bool app::chekuser(string log)
{
	for (auto elem : _user)
	{
		if (elem.getlog() == log) return true;
	}
	return false;
}

void app::adduser(user _new)
{
	if (chekuser(_new)) return;
	_user.push_back(_new);
}

void app::addchat(chat _new)
{
	if (chekchat(_new));
	_app.push_back(_new);
}

void app::sendmassage(user a, massage text)
{
	if (a.getlog() == "") return;
	chat temp;
	temp.addtext(text);
	temp.adduser(a);
	for (auto elem : _app)
	{
		if (elem == temp) 
		{
			elem.addtext(text); 
			return;
		}
	}
	_app.push_back(temp);
}

void app::sendmassage(massage text, int i)
{
	int j = 1;
	for (auto elem : _app)
	{
		if (elem.chekuser(text.getuser())) j++;
		if (j == i) { elem.addtext(text); return; }
	}
}

user app::getuserbylog(string log)
{
	for (auto elem : _user)
	{
		if (elem.getlog() == log) return elem;
	}
	user temp(nullptr, nullptr);
	return temp;
}

void app::printusers()
{
	for (auto elem : _user)
	{
		cout << elem.getlog() << "\n\n";
	}
}

void app::newmember()
{
	system("cls");
	string log;
	string passvord;
	bool flag = true;
	getline(cin, log);
	//
	//
	cout << "������� �����(�� 3-� �� 20-� �������� ��� ��������)\n";
	do
	{
		getline(cin, log);
		if (goodlog(log))
		{
			flag = false;
		}
		else
		{
			cout << "����� �� �����, ���������� ������\n";
		}
	} while (flag);
	//
	//
    flag = true;
	system("cls");
	//
	//
	cout << "������� ������ (�� 6-� �� 20-� �������� ��� ��������)\n";
	do
	{
		getline(cin, passvord);
		if (goodpassvord(passvord))
		{
			flag = false;
		}
		else
		{
			cout << "������ �� �����, ���������� ������\n";
		}
	} while (flag);
	//
	//
	user New(log, passvord);
	adduser(New);
}

void app::makechat(user a, massage text)
{
	bool flag;
	chat NEW;
	NEW.addtext(text);
	system("cls");
	printusers();
	do {
		string log;
		cout << "������� ����� ������������ �������� ������ ��������\n\n";
		getline(cin, log);
		NEW.adduser(getuserbylog(log));
		cout << "��� ��������?(1,0)\n";
		cin >> flag;
	} while (flag);
	addchat(NEW);
}

void app::printuserchats(user a)
{
	int i = 1;
	for (auto elem : _app)
	{
		if (elem.chekuser(a)) { cout << i++ << ")"; elem.printusers(); }
	}
}

void app::sendmassage(user a)
{
	string log;
    system("cls");
	string text;
	printusers();
	cout << "������� ����������\n";
	getline(cin, log); 
	system("cls");
	cout << "������� ���������\n";
	getline(cin, text);
	massage temp2(a, text);
	sendmassage(getuserbylog(log),temp2);
	return;
}

void app::chekmasseg()
{
	system("cls");
	printusers();
	//
	//
	bool flag = true;
	string log;
	string passvord;
	getline(cin, log);
	//
	//
	cout << "������� �����\n";
	do
	{
		getline(cin, log);
		if (chekuser(log))
		{
			flag = false;
		}
		else
		{
			cout << "��� ������ ������������\n";
		}
	} while (flag);
	//
	//
	flag = true;
	system("cls");
	//
	//
	cout << "������� ������ \n";
	do
	{
		getline(cin, passvord);
		user temp(log, passvord);
		if (chekuser(temp))
		{
			system("cls");
			int i = 1;
			for (auto elem : _app)
			{
				if (elem.chekuser(temp)) {
					
					cout << i << "-�� ���:";
					elem.printusers();
					i++;
					elem.print();
				}
			} 
			bool back;
			do { cout << "�������� � ����(1,0)\n"; cin >> back; } while (!back);
			if (back) return;
			
		}
		else
		{
			cout << "������ �� �����, ���������� ������\n";
		}
		//
	} while (flag);


}

void app::secondoption()
{

	system("cls");
	cout << "�������� ������������\n";
	printusers();
	//
	//
	bool flag = true;
	string log;
	string passvord;
	getline(cin, log);
	//
	//
	cout << "������� �����\n";
	do
	{
		getline(cin, log);
		if (chekuser(log))
		{
			flag = false;
		}
		else
		{
			cout << "��� ������ ������������\n";
		}
	} while (flag);
	//
	//
	flag = true;
	system("cls");
	//
	//
	do
	{
		cout << "������� ������ \n";
		getline(cin, passvord);
		user temp(log, passvord);
		if (chekuser(temp))
		{
			bool chat;
			system("cls");
			cout << "�������� � ���(1) ��� ������ ���������(0)\n";
			cin >> chat;
			if (!chat)
			{
				sendmassage(temp);
				return;
			}
			else
			{
				bool NEW;
				printuserchats(temp);
				cout << "������� ����� ���?\n";
				cin >> NEW;
				if (!NEW) 
				{
					int i;
					cout << "������� ����� ����\n";
					cin >> i;
					system("cls");
					string text;
					cout << "������� ���������\n";
					getline(cin, text);
					massage temp2(temp, text);
					sendmassage( temp2,i);
				}
				else
				{
					system("cls");
					string text;
					cout << "������� ���������\n";
					getline(cin, text);
					getline(cin, text);
					massage temp2(temp, text);
					makechat(temp,temp2);
					return;
				}
			}
		}
		cout << "������ �� ������\n";
	} while (1);
}
