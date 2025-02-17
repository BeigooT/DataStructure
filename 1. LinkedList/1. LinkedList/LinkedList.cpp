#include "LinkedList.h"

template<typename T>
struct Node
{
	T value;
	Node<T>* next;
};

template<typename T>
class LinkedList
{
private:
	Node<T>* head;
public:
	LinkedList();
	void push_front(T value);
	void push_back(T value);
	void pop_front();
	void pop_back();
	bool is_empty();
};

