#ifndef __Person__Student__
#define __Person__Student__

#include "Person.h"

class Student : public Person{
public:
	Student();
	Student(const Person& pOther, const string& schoolName, const string& major);

	string schoolName() const;
	void schoolName(const string& schoolName);

	string major() const;
	void major(const string& major);

	bool operator==(const Student& other);
	bool operator!=(const Student& other);
	friend ostream& operator<<(ostream& os, const Student& st);
	
private:
	string _schoolName;
	string _major;
};

#endif