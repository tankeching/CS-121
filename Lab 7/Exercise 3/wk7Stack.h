#ifndef __Stack__Class__
#define __Stack__Class__

#include <iostream>
using namespace std;
#include <stdexcept>

class Stack{
public:
	Stack(int max = 100);
	Stack(const Stack& other);
	Stack& operator=(const Stack& other);
	~Stack();

	int size() const;
	int max() const;

	int top() const;
	void pop();
	void push(int val);
	bool empty() const;

	bool operator==(const Stack& other) const;
	bool operator!=(const Stack& other) const;
	friend ostream& operator<<(ostream& os, const Stack& st);

private:
	void copy(const Stack& other);

private:
	int _top;
	int _max;
	int* _data;
};

#endif