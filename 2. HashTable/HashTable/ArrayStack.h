#pragma once

#include "ArrayStack.h"
#include <iostream>
using namespace std;

class stack
{
private:
	int array[100];
	int top;
public:
	stack();
	void push(int x);
	void pop();
	bool isEmpty()const;
	bool isFull() const;
	void print()const;
};

