#ifndef __DblLinkedList__DblLinkedList__
#define __DblLinkedList__DblLinkedList__

#include <iostream>
using namespace std;

template <typename T> class DblLinkedList;
template <typename T> std::ostream& operator<<(ostream&, DblLinkedList<T> const&);

template<typename T>
class DblLinkedList {
public:
	DblLinkedList();
	DblLinkedList(DblLinkedList<T> const& other);
	DblLinkedList<T>& operator=(DblLinkedList<T> const& other);
	~DblLinkedList();

	struct Node{
		Node(T val) : _val(val), _prev(nullptr), _next(nullptr) {}
		T _val;
		Node* _prev;
		Node* _next;
	};

	void push_front(T val);
	void push_back(T val);

	T pop_front();
	T pop_back();

	void insert(T val, Node* before);
	void deleteNode(Node* node);
	bool empty const();
	const Node* front() const;
	const Node* back() const;
	size_t size() const;

	friend ostream operator<<(ostream& os, DblLinkedList<T> const& list);

private:
	void copy(DblLinkedList const& other);
	void deleteRest(Node* from);
private:
	size_t _size;
	Node* _head;
	Node* _tail;
};

	template<typename T>
	DblLinkedList<T>::DblLinkedList(): _size(0), _head(nullptr){}

	template<typename T>
	DblLinkedList<T>::DblLinkedList(const& other) : _head(nullptr){
		copy(other);
	}

	template<typename T>
	DblLinkedList<T>& DblLinkedList<T>::operator=(DblLinkedList<T> const& other){
		if (this != other){ copy(other); }
		return *this;
	}

	template<typename T>
	DblLinkedList<T>::~DblLinkedList(){
		deleteRest(_head);
	}

	template<typename T>
	void DblLinkedList<T>::push_front(T val){
		DblLinkedList<T>::Node* pnew = new Node(val);
		if (_head == nullptr){ _head = pnew; _tail = pnew; _size++; }
		else{
			pnew->_next = _head;
			_head->_prev = pnew;
			_head = pnew;
			_size++;
		}
	}

	template<typename T>
	void DblLinkedList<T>::push_back(T val){
		DblLinkedList<T>::Node* pnew = new Node(val);
		if (_head == nullptr){
			_head = pnew;
			_tail = pnew;
			_size++;
		}
		else{
			DblLinkedList<T>::Node* temp = _head;
			while (temp->next != nullptr){
				temp = temp->next;
			}
			temp->next = pnew;
			_tail = pnew;
			_size++;
		}
	}

	template<typename T>
	T DblLinkedList<T>::pop_front(){
		if (empty()){
			throw std::out_of_range("out of range in LinkedListT<T>::pop_front()");
		}
		else if (_size == 1){
			T result = _head._val;
			delete _head;
			_head = nullptr;
			_tail = nullptr;
			_size--;

			return result;
		}

		else{
			Node* pnew = new Node;
			pnew = _head;
			_head = head->next;
			T result = pnew._val;
			delete pnew;
			_size--;
			return result;
		}
	}
	
	template<typename T>
	T DblLinkedList<T>::pop_back(){
		if (empty()){
			throw std::out_of_range("out of range in LinkedListT<T>::pop_front()");
		}
		else if (_size == 1){
			T result = _head._val;
			delete _head;
			_head = nullptr;
			_tail = nullptr;
			_size--;
			return result;
		}
		else{
			Node* pnew = new Node;
			pnew = _head;
			while (pnew->next != nullptr){
				pnew->_prev = pnew;
				pnew = pnew->next;
			}	
			T result = pnew;
			delete pnew;
			_size--;
			_tail = pnew->_prev;
			return result;
		}
	}

	template<typename T>
	size_t DblLinkedList<T>::size() const{
		return _size;
	}

	template<typename T>
	void DblLinkedList<T>::insert(T val, Node* before){
		DblLinkedList<T>Node *p = _head, *pPrev = _head;
		while (p->_next != nullptr && p->next != before){
			pPrev = p;
			p = p->next;
		}

		if (p->_next == nullptr){ return; }

		p = new Node(val);
		pPrev->_next = p; p->_prev = pPrev;
		p->_next = before; before->_prev = p;
		_size++;
	}

	template<typename T>
	void DblLinkedList<T>::deleteNode(Node* node){
		DblLinkedList<T>::Node* pnew = _head; Node* pprev = _head;
		while (pnew->_next != nullptr && pnew->_next != node){
			pprev = pnew;
			pnew = pnew->next;
		}

		if (p->_next == nullptr){ return; }
		pprev->_next = pnew->_next;
		if (pnew->next == nullptr){ _tail = pprev; }
		delete pnew;
		_size--;
	}


#endif