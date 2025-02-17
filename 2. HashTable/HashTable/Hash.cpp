#include <string>
#include <list>
#include <iostream>
using namespace std;

class HashTable
{
private:
	static const int hashGroups = 10;	//static: it belongs to the class, not the object
	list<pair<int,int>> table[hashGroups];	//pair<type, type> A; A.first = ..., A.second = ...

public:
	bool isEmpty() const;
	int hashFunction(int key) const;
	void insertItem(int key, int value);
	void removeItem(int key);
	int retrieve(int key);

};

bool HashTable::isEmpty() const	//go over all the linked lists. if all are empty, then is empty.
{
	for (int i = 0; i < hashGroups; i++)
	{
		if (!table[i].empty()) {
			return false;	//if there is even a single element in one of the table
		}
	}
	return true;
}

int HashTable::hashFunction(int key) const
{
	return key % hashGroups;
}

void HashTable::insertItem(int key, int value)
{
	//if key already exists: replace the value
	//if not: push front.
	int index = this->hashFunction(key);
	for (auto& p : table[index]) //iterator. 
	{
		if (p.first == key)
		{
			p.second = value;
			return;
		} 
	}
	pair<int, int> newPair{ key,value };
	table[index].push_front(newPair);
	
}

void HashTable::removeItem(int key)
{
	int index = this->hashFunction(key);
	for (auto it = table[index].begin(); it!=table[index].end(); it++)
	{
		if (it->first == key)
		{
			table[index].erase(it);
			return;
		}
	}
}

int HashTable::retrieve(int key)
{
	int index = hashFunction(key);
	//cout << "RETRIEVE INDEX: " << endl;
	for (auto p : table[index])
	{
		if (p.first == key)
		{
			return p.second;
		}
	}
	cout << "KEY UNFOUND" << endl;
	return -1;
}



