//Question No.1 : Implement following Stack class using arrays
// Mustafa Aru - 30716006


//#include "pch.h"
#include <iostream>
#define SIZE 10

using namespace std;

class Stack {
private:
	int arr[SIZE];
	int top;

public:
	//constructor
	Stack()
	{
		top  =  -1;
	}

	bool isEmpty();
	bool isFull();
	int size();
	void peek();
	void pop();
	void push(int);

	void someOperations();
};



void Stack::push(int x) {
	if (!isFull())
	{
		top++;
		arr[top] = x;
	}
	else
	{
		cout << "The Stack is Full!" << endl;
	}
}

void Stack::pop() {
	if (!isEmpty())
	{
		cout << arr[top] << " Removed" << endl;
		top--;
	}
	else
	{
		cout << "The Stack is Underflow!" << endl;
	}
}

void Stack::peek() {  //Show the last element
	if (!isEmpty())
	{
		cout << "The last element is: " << arr[top] << endl;
	}
	else
	{
		cout << "The stack is empty!" << endl;
	}
}

bool Stack::isEmpty() {
	return top == -1;
}

bool Stack::isFull() {
	return top == SIZE - 1; //Arr[5] is empty because started on 0
}

int Stack::size() {
	return top + 1;
}

void Stack::someOperations() {
	push(10);
	push(20);
	push(30);
	push(40);
	push(50);
	push(60);
	push(70);
	push(80);
	push(90);
	push(100);
	push(110); //It full now so cant push
	pop(); //Remove 100
	peek(); //Showing 90
}

int main() {
	Stack s1;
	s1.someOperations(); // I write in function
	cout << "Your size is: " << s1.size() << endl;
}



