#ifndef __LinkedListT__LinkedListT__
#define __LinkedListT__LinkedListT__

#include <iostream>
using namespace std;

template <typename T> class LinkedListT;
template <typename T> std::ostream& operator<<(std::ostream&, LinkedListT<T> const&);

template <typename T>
class LinkedListT {
public:
	LinkedListT();
	LinkedListT(LinkedListT<T> const& other);
	LinkedListT<T>& operator=(LinkedListT<T> const& other);
	~LinkedListT();

	struct Node{
		Node(T val) : _val(val), _next(nullptr){}
		T		_val;
		Node* _next;
	};

	void push_front(T val);
	void push_back(T val);

	T pop_front();
	T pop_back();

	void insert(T val, Node* before);
	void deleteNode(Node* node);
	bool empty() const;

	const Node* front() const;
	const Node* back() const;

	friend ostream& operator<< <T>(ostream& os, LinkedListT<T> const& list);

private:
	void copy(LinkedListT const& other);
	void deleteRest(Node* from);
	Node* back();

private:
	size_t _size;
	Node* _head;
};

#endif