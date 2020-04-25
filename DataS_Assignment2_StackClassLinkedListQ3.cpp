/* Question No. 3. Implement following Stack class methods for linked
list implementation of Stack. */
// Mustafa Aru - 30716006


//#include "pch.h"
#include <iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
};


class Stack
{
private:
	Node *top;
	int count;
	int max_size;
	
public:
	Stack() 
	{ 
		top = NULL;
		count = 0;
	}
	
	bool isEmpty();// check if stack is empty
	void push(int);// add new element in first position of stack
	void set_size(int); //max size defined here
	void pop();// remove first element
	void peek();// Show first element
	void display(); // show all data in stack
	void displayCount(); // show number of elements in stack
};

void Stack::set_size(int maxsize){
	max_size = maxsize;
}

bool Stack::isEmpty(){
	return top == NULL;
}

void Stack::push(int val){
	if(count<max_size){
		if(isEmpty())
		{ //No any elements
		Node *temp = new Node;
		temp->data = val;
		temp->next = NULL;
		top = temp;
		count++;
		cout << temp->data << " Added!" << endl;
		}
	
		else
		{ // We have at least one Node on it
			//Adding one nodes and changing pointer address
			Node *temp = new Node;
			temp->data = val;
			temp->next = top; //Added the first on position
			top = temp; //copy address of temp to top
			count++;		
			cout << temp->data << " Added!" << endl;
		}
		
	}
	else{ //FULL SIZE
		cout << "The Stack is maximum size! You have to pop one of them." << endl;
	}
}

void Stack::pop(){
	if(isEmpty()){
		cout << "The Stack is already empty! You can not delete." << endl;
	}
	else{ //Not empty
		Node *temp = top;
		top = top->next;
		cout << "Removed: " << temp->data <<endl;
		delete temp;
		count--;
	}
}

void Stack::display(){
	if(!isEmpty()){
		Node *temp = top; // Copy address top to temp
		
		for(int i=1 ; i<=count ; i++){ //Looking all of them
			cout << i << ". Element: " <<  temp->data << endl;
			temp = temp->next; //Going next Node
		}
	}
	else{ //Empty
		cout << "The Stack is empty! -Display function" << endl;
	}
}

void Stack::displayCount(){
	cout << "The Elements in Stack: " << count << endl;
}

void Stack::peek(){
	cout << "The First Element: " << top->data << endl;
}

int main() {
	cout << "Enter the max size: ";
	int maxsize;
	cin>>maxsize;
	
	Stack S1;
	S1.set_size(maxsize);
	S1.push(5); //Added
	S1.push(3); //Added
	S1.push(2); //Added
	S1.push(8); //Added
	S1.push(9); //Added
	S1.push(11); //Can not add because MAX SIZE
	S1.pop(); //Delete 9 one
	S1.displayCount(); // deleted one so 4
	S1.peek(); // Last one is: 8
	S1.display(); //All displayed!
}



