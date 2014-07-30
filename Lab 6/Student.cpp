#include "Person.h"
#include "Student.h"

Student::Student() : Student(Person(), "no School Name", "no major"){}
Student::Student(const Person& p, const string& schoolName, const string& major) : Person(p), _schoolName(schoolName), _major(major){}

string Student::schoolName() const{ return _schoolName; }
void Student::schoolName(const string& schoolName){ _schoolName = schoolName; }

string Student::major() const{ return _major; }
void Student::major(const string& major){ _major = major; }

ostream& operator<<(ostream& os, const Student& st){
	return os << "Student[ " << dynamic_cast<const Person&>(st) << st._schoolName << ";"
		<< st._major << "]";
}

bool Student::operator==(const Student& other){
	return dynamic_cast<const Person&>(*this) == dynamic_cast<const Person&>(other) && _schoolName == other._schoolName
		&& _major == other._major;
}

