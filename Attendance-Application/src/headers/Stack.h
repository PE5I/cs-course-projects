// The code in this file was taken from LAB9 for cpts 122
// a skeleton of this code was provided by Andy O'fallon

#pragma once

#include "main.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

template <class T>
class Stack
{
public:
	Stack(int newSize = 0);
	~Stack();

	bool push(T &newItem); 
	bool pop(T &poppedItem);
	T peek(T &item);

	bool isEmpty();

private:
	int mSize; // represents the current number of items in the stack
	int mMaxSize; // must not exceed the max size of our allocated array
	T *mTop; // will point to contigous memory on the heap (an array)
};

template <class T>
Stack<T>::Stack(int newSize)
{
	mSize = newSize; // this can also be used as the index to the top of the stack
	mMaxSize = 100;
	mTop = new T[100]; // allocating an array of 100 items of type T on the heap
}

template <class T>
Stack<T>::~Stack()
{
	delete[] mTop; // this is how we free up an array on the heap in C++
}

// Places the newItem at the top of the stack
template <class T>
bool Stack<T>::push(T &newItem)
{
	bool success = false;

	if(mSize == mMaxSize) {
		cout << "Not enough space!" << endl;
	} else {
		int i=0;
		for(i=0; i<mSize; i++);
		mTop[mSize] = newItem;
		mSize++;
		success = true;
	}
	
	return success;
}

// In this implementation you will apply defensive design. You must check to 
// see if the stack is empty or not before you pop. Places the popped item in 
// the parameter referred to as "poppedItem". Returns true if the item was popped; false
// otherwise.
template <class T>
bool Stack<T>::pop(T &poppedItem)
{
	bool success = false; 
	if(mSize != 0) {
		poppedItem = mTop[mSize];
		mSize--;
		success = true;
	}

	return success;
}

// In this implementation you will apply defensive design. You must check to 
// see if the stack is empty or not before you peek. Places the item at the top of the
// stack in the parameter referred to as "item". Returns true if there
// is an item at the top; false otherwise.
template <class T>
T Stack<T>::peek(T &item)
{
	if(isEmpty()) {
		cout << "Empty stack!" << endl;
	} else {
		item = mTop[mSize-1];
	}

	return item; 
}

// Returns true if the stack is empty; false otherwise
template <class T>
bool Stack<T>::isEmpty()
{
	bool empty = false;

	if(mSize == 0) {
		empty = true;
	}
	return empty;
}
