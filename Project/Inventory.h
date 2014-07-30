#ifndef __ZorkProject__Inventory__
#define __ZorkProject__Inventory__

#include <iostream>
#include <unordered_map>
using namespace std;

#include "Item.h"

template<typename T>
class Inventory;

template<typename T>
ostream& operator<<(ostream& os, Inventory<T> const& inventory);

template <typename T>
class Inventory{
public:
	Inventory();

private:
	Inventory(Inventory const& other);
	Inventory<T>& operator=(Inventory<T> const& other);

public:
	virtual ~Inventory();

	T find(string const& name);
	void add(T object);
	void remove(string name);
	size_t size() const;

	string objects() const;
	friend ostream& operator<< <T> (ostream& os, Inventory const& inventory);

private:
	unordered_map<string, T> _objects;
};

template<typename T>
Inventory<T>::Inventory() {}

template<typename T>
Inventory<T>::Inventory(Inventory<T> const& other){
	_objects.clear();

	_objects = other._objects;
	other._objects.clear();
}

template <typename T>
Inventory<T>::~Inventory(){
	for (typename unordered_map<string, T>::iterator it = _objects.begin(); it != _objects.end(); it++)
	{
		delete it->second;
	}
}

template <typename T>
void Inventory<T>::add(T go){
	if (go == nullptr){
		cout << "Warning: ignoring attempt to add null item to Inventory." << endl;
		return;
	}
	_objects[go->name()] = go;
}

template <typename T>
void Inventory<T>::remove(string name){
	typename unordered_map<string, T>::iterator it = _objects.find(name);
	if (it != _objects.end()){ _objects.erase(it); }
}

template <typename T>
T Inventory<T>::find(string const& name){
	typename unordered_map<string, T>::const_iterator cit = _objects.find(name);
	if (cit == _objects.end()){
		cout << "warning! could not find " << name << endl;
		
	}

	return (cit != _objects.end() ? cit->second : nullptr);
}

template <typename T>
size_t Inventory<T>::size() const { return _objects.size(); }

template <typename T>
string Inventory<T>::objects() const{
	string objects;
	for (typename unordered_map<string, T>::const_iterator cit = _objects.begin(); cit != _objects.end(); cit++){
		objects += cit->first + "	";
	}
	return objects;
}

template <typename T>
ostream& operator<<(ostream& os, Inventory<T> const& inventory){
	return os << "Inventory[" << inventory.objects() << "]";
}

#endif

