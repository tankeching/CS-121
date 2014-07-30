#ifndef __Person__
#define __Person__

#include <iostream>
#include <string>
using namespace std;

class Person{
public:
	Person();
	Person(const string& name, const string& address);
	Person(const Person& pOther);

	string name() const;
	void name(const string& name);
	
	string address() const;
	void address(const string& address);

	bool operator==(const Person& pother) const;
	bool operator!=(const Person& pother) const;
	friend ostream& operator<<(ostream& os, const Person& p);

private:
	string _name;
	string _address;
};

#endif