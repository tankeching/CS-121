#include "wk7Stack.h"

Stack::Stack(int max) : _top(0), _max(max), _data(new int[_max]){}
Stack::Stack(const Stack& other) : _data(nullptr){
	copy(other);
}
Stack& Stack::operator=(const Stack& other){
	if (this != &other) { copy(other); }
	return *this;
}

void Stack::copy(const Stack& other){
	_top = other._top;
	_max = other._max;
	if (_data != nullptr){ delete[] _data; }

	_data = new int[other._max];
	memcpy(_data, other._data, _top * sizeof(int));
}

Stack::~Stack() {
	if (_data != nullptr) { delete[] _data; }
}

int Stack::top() const {
	if (empty()) { throw std::underflow_error("in Stack::top()"); }
	return _data[_top - 1];
}

int Stack::max() const { return _max; }

void Stack::pop(){
	if (empty()){ throw std::underflow_error("in Stack::pop()"); }
	int temp = _data[_top--];
}

void Stack::push(int val){
	if (_top > _max - 2){ throw std::overflow_error("in Stack::push(int)"); }
	_data[_top++] = val;
}

bool Stack::empty() const { return _top == 0; }

bool Stack::operator==(const Stack& other) const{
	return _top == other._top &&
		_max == other._max &&
		((_data == nullptr && other._data == nullptr) || memcmp(_data, other._data, _top));

}

bool Stack::operator!=(const Stack& other) const { return !(*this == other); }

ostream& operator<<(ostream& os, const Stack& st){
	os << "Stack[";
	if (st.empty()){ os << "empty"; }
	else{
		Stack temp = st;
		while (!temp.empty()) {
			os << temp.top();
			temp.pop();
			if (!temp.empty()) { os << " "; }
		}
	}
	return os << "]";
}
