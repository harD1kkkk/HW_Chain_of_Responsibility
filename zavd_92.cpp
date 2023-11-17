// zavd_92.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
using namespace std;

class Handler {
protected:
	Handler* next;

public:
	void setHandler(Handler* next) {
		this->next = next;
	}

	Handler() : next(nullptr) {}

	Handler(Handler* next) : next(next) {}

	virtual void process(string username, string password) = 0;
};


class UsernameHandler : public Handler {
public:
	UsernameHandler() : Handler() {}

	UsernameHandler(Handler* next) : Handler(next) {}

	void process(string username, string password) override {
		if (username.length() >= 5 && username.length() <= 20) {
			cout << "Username is valid. UsernameHandler" << endl;
		}
		else {
			cout << "Username is invalid. UsernameHandler" << endl;
			return;
		}

		if (next == nullptr) {
			cout << "End. No result. UsernameHandler" << endl;
			return;
		}
		next->process(username, password);
	}
};

class PasswordHandler : public Handler {
public:
	PasswordHandler() : Handler() {}

	PasswordHandler(Handler* next) : Handler(next) {}

	void process(string username, string password) override {
		if (password.length() >= 8 && password.length() <= 30) {
			cout << "Password is valid. PasswordHandler" << endl;
		}
		else {
			cout << "Password is invalid. PasswordHandler" << endl;
			return;
		}

		if (next == nullptr) {
			cout << "End. No result. PasswordHandler" << endl;
			return;
		}
		next->process(username, password);
	}
};

class RegistrationHandler : public Handler {
public:
	RegistrationHandler() : Handler() {}

	RegistrationHandler(Handler* next) : Handler(next) {}

	void process(string username, string password) override {
		cout << "Registration successful. RegistrationHandler" << endl;
	}
};



int main()
{
	Handler* first = new UsernameHandler();
	Handler* second = new PasswordHandler();
	Handler* third = new RegistrationHandler();

	first->setHandler(second);
	second->setHandler(third);

	first->process("validuser", "validpassword123");

	cout << endl;

	first->process("user", "pass");
}