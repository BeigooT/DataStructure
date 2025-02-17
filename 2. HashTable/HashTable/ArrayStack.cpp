#include "ArrayStack.h"
stack::stack()
{
	top = -1;
	for (int i = 0; i<100; i++)
	{
		array[i] = 0;
	}
}

void stack::push(int x)
{
	if (!this->isFull())
	{
		top++;
		array[top] = x;
	}

}

void stack::pop()
{
	if (!this->isEmpty())
	{
		top--;
	}
}

bool stack::isEmpty() const
{
	return top == -1;
}

bool stack::isFull() const
{
	return top == 99;
}

void stack::print() const
{
	for (int i = 0; i < top + 1; i++)
	{
		cout << this->array[i] << " ";
	}
}

