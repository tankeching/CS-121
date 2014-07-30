#include "Person.h"
#include "Student.h"

int main(){
	Person p("John Smith", "321 Wilson st.");
	Person q("John Smith", "123 Wilson st.");

	Student st1(p, "CSUF", "CS");
	Student st2(q, "CSUF", "EE");

	cout << "p is: " << p << endl;
	cout << "q is: " << q << endl;

	cout << "p == q?" << (p == q) << endl;

	cout << "st1 is: " << st1 << endl;
	cout << "st2 is: " << st2 << endl;

	cout << "st1 == st2?" << (st1 == st2) << endl;

	return 0;
}