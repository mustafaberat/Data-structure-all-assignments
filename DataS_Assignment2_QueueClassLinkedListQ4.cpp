/* Question No. 4 Implement following Queue class methods for linked
list implementation of Queue. */
// Mustafa Aru - 30716006


//#include "pch.h"
#include <iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
};

class Queue{
private:
	//Data Members
	Node *front;
	Node *rear;
	int count;
	int max_size;
	
public:
	Queue() //Constructure
	{
		front = NULL;
		rear = NULL;
		count = 0;
	}
	
	//Member Functions
	//----------------
	bool isEmpty();// check if Queue is empty
	void enqueue(int);// add new element in last position of Queue
	void dequeue();// remove first element
	void peek();// Show last and first element
	void display(); // show all data in Queue
	void set_max_size(int);
	void displayCount(); // show number of elements in Queue
};

void Queue::set_max_size(int maxsize){
	max_size = maxsize;
}

bool Queue::isEmpty(){
	return front == NULL;
}

void Queue::enqueue(int val){
	if(count<max_size){ 
		Node *temp = new Node;
		temp->data = val;
		temp->next = NULL;
		
		if(isEmpty()){ //No Node
			front = rear = temp; //All in one
		}
		else{ //More Nodes
			rear->next = temp;
			rear = temp;
		}
		count++; //Number of elements
		cout << temp->data << " Added!" <<endl;
	}
	else{ //MAX SIZE
		cout << "The Queue is full. Please dequeue one of the objects." << endl;
	}
}

void Queue::dequeue(){
	if(!isEmpty()){
		cout << "Deleted: " << front->data << endl;
		
		if(rear == front){ //Only one Node
			rear = front = NULL;
		}
		else{ //More than one Nodes
			Node *temp = front;
			front = front->next; //Front goint next
			delete temp;
		}
		count--; //Elements of objects	
	}
	
	else{ //Empty
		cout << "There is no any Nodes. You can not delete!" << endl;
	}
}

void Queue::display(){
	if(!isEmpty()){ //Not empty
		Node *temp = front;
		for(int i=1 ; i<=count ; i++){
			cout << i << " Element: " << temp->data << endl;
			temp = temp->next;
		}
	}
	else{ //Empty
		cout << "The Queue is Empty! Can not be displayed!" << endl;
		return;
	}
}

void Queue::displayCount(){
	cout << "The number of elements: " << count <<endl;
}

void Queue::peek(){
	cout << "First element: " << front->data << endl;
	cout << "The last element: " << rear->data << endl; 
}

int main() {
	cout << "Enter the max size: ";
	int maxsize;
	cin>>maxsize;
	
	Queue Q1;
	Q1.set_max_size(maxsize);
	Q1.dequeue(); //CANT DELETE - NO NODES
	
	Q1.enqueue(10);
	Q1.enqueue(20);
	Q1.enqueue(30);
	Q1.enqueue(40);
	Q1.enqueue(50);
	Q1.enqueue(60); //FULL SIZE
	Q1.displayCount(); //MAX So 5
	
	Q1.peek(); //First 10 Last 50
	
	cout << "\n\n";
	Q1.display();
	cout << "\n\n";
	
	Q1.dequeue(); //Deleting first one
	Q1.dequeue(); //Delete second one

	cout << "\n\n";
	Q1.display();

}


