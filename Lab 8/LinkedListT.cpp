#include <string>
#include "LinkedListT.h"

template <typename T>
LinkedListT<T>::LinkedListT() : _size(0), _head(nullptr){}

template<typename T>
LinkedListT<T>::LinkedListT(LinkedListT<T> const& other) : _head(nullptr)
{ copy(other); }

template<typename T>
LinkedListT<T>& LinkedListT<T>::operator=(LinkedListT<T> const& other){
	if (this != &other){ copy(other); }
	return *this;
}

template <typename T>
LinkedListT<T>::~LinkedListT() { deleteRest(_head); }

template <typename T>
void LinkedListT<T>::push_front(T val){
	LinkedListT<T>::Node* p = new Node(val);
	p->_next = _head;
	_head = p;
	_size++;
}

template <typename T>
void LinkedListT<T>::push_back(T val){
	LinkedListT<T>::Node* p = new Node(val);
	/*if(_head == nullptr){
		_head = p;
		_size++;
	}

	else{
		LinkedListT<T>::Node* temp = _head;
		//while(temp != nullptr){
			temp->next = _head;
		//}

		_size++;

	}*/
}

template<typename T>
 T LinkedListT<T>::pop_front(){
	if (empty()){
		throw std::out_of_range("out of range in LinkedListT<T>::pop_front()");
	}

	else if(_size == 1){
		T result = _head._val;
		delete _head;
		_head = nullptr;
		_size--;

		return result;
	}

	else{
		 Node* p = new Node;
		 p = _head;
		 _head = head->_next;
		 T result = p._val;
		 delete p;
		 _size--;
		 return result;
	}



} 

template <typename T>
 T LinkedListT<T>::pop_back(){
	if (empty()){
		throw std::out_of_range("out of range in LinkedListT<T>::pop_back()");
	}

	if(_size == 1){
		delete _head;
		_head = nullptr;
		_size--;
	}
	else{
		p = _head;
		pPrev = _head;
		while(p->_next != nullptr){
			pPrev = p;
			p = p->_next;
		}

		_size--;
		delete p;
		pPrev->_next = nullptr;
	}
		

	return result;
} 

template <typename T>
void LinkedListT<T>::insert(T val, Node* before){
	new Node* x = new Node* val; //missing code
	new Node* y = new Node* before;

} 

template <typename T>
void LinkedListT<T>::deleteNode(Node* node){
	LinkedListT<T>::Node *p = _head, *pPrev = _head;
	while (p->next != nullptr && p->_next != node){
		pPrev = p;
		p = p->_next;
	}

	if (p->_next == nullptr){ return; } // node not found
	pPrev->_next = p->_next;
	delete p;
	_size--;
}

template <typename T>
bool LinkedListT<T>::empty() const{ return _head == nullptr; }

template <typename T>
void LinkedListT<T>::copy(LinkedListT const& other){
	deleteRest(_head);
	if (other._head == nullptr){ _head = nullptr; return; }
	_head = new Node(other._head->_val);
	LinkedListT<T>::Node *p = _head, *pPrev = _head, *q = other._head;
	while (q->next != nullptr){
		//missing code
	}
	p->_next = nullptr;
}


template <typename T>
void LinkedListT<T>::deleteRest(Node* from){
	LinkedListT<T>::Node *p = _head, *pPrev = _head, *pNext=_head;

	//missing code
}


template <typename T>
const typename LinkedListT<T>::Node* LinkedListT<T>::front() const{ return _head; }

template <typename T>
const typename LinkedListT<T>::Node* LinkedListT<T>::back() const{
	LinkedListT<T>::Node* p = _head;
	//missing code
} 

template <typename T>
std::ostream& operator<<(std::ostream& os, LinkedListT<T> const* list){
	os << "LinkedListT<T>{";
	if (list.empty()){ return os << "(empty)]" << std::endl; }
	return os << "]";
}

 int main(){
	LinkedListT<int> iList;
	iList.push_back(1);
	iList.push_back(2);
	iList.push_back(3);
	iList.push_back(4);
	cout << "iList is: " << iList << endl;

	iList.push_back(5);
	iList.push_back(6);
	iList.push_back(7);
	cout << "and now iList is: " << iList << endl << endl;

	LinkedListT<double> dblList;
	dblList.push_back(1.23);
	dblList.push_back(3.45);
	dblList.push_back(6.78);
	cout << "dblList is: " << dblList << endl << endl;

	LinkedListT<string> strList;
	strList.push_back("four");
	strList.push_back("score");
	strList.push_back("and");
	strList.push_back("seven");
	strList.push_back("years");
	strList.push_back("ago");
	cout << "strList is: " << strList << endl << endl;

	strList.push_front("our");
	strList.push_front("fathers");
	strList.push_front("brought");
	strList.push_front("forth");
	strList.push_front("on");
	strList.push_front("this");
	strList.push_front("continent");
	cout << "and now strList is: " << strList << endl << endl;

	return 0;
}



