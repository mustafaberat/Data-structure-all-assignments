


//Question No. 2 Implement following queue class using arrays
// Mustafa Aru - 30716006

#define SIZE 10
//#include "pch.h"
#include <iostream>

using namespace std;

class Queue{
	private:
		int arr[SIZE];
		int front;
		int rear;
		int count;
		
	public:
		//constructor
		Queue()
		{
			count = 0;
			front = 0;
			rear = -1;
		}
		
		bool isEmpty();
		bool isFull();
		int size();
		void dequeue();
		void enqueue(int val);
		void peek();
		
		void someOperations();
};



void Queue::enqueue(int val){
	if(!isFull())
	{
		count++;
		rear = (rear+1)%SIZE;
		arr[rear] = val;
	}
	else
	{
		cout << "The Stack is Full!"<<endl;
	}
}

void Queue::dequeue(){
	if(!isEmpty())
	{
		cout << arr[rear] << " Removed" << endl;
		front = (front+1)%SIZE;
		count--;
	}
	else
	{
		cout << "The Stack is Empty!" << endl;
	}
}

void Queue::peek(){
	if(!isEmpty())
	{
		cout << "The last element is: " << arr[rear] << endl;
	}
	else
	{
		cout << "The stack is empty!" << endl;
	}
}

bool Queue::isEmpty(){
	return count==0;
}

bool Queue::isFull(){
	return count==SIZE; //Arr[10] must be full because started at 0 index
}

int Queue::size(){
//	cout << "Size : " <<count <<endl;
	return count;
}

void Queue::someOperations(){
	dequeue(); //Must be said that: You list is empty!
	enqueue(1); //Include the first
	enqueue(2); // Include the second
	enqueue(3); 
	dequeue(); //Deleting the last one [3]
	enqueue(4); 
	enqueue(5); 
	enqueue(6); 
	enqueue(7);
	enqueue(8); 
	enqueue(9); 
	enqueue(10); 
	enqueue(11);
	enqueue(12); // Not possible to add ' It must give overflow message!
	peek(); //Showing last element  
	cout << "The size is: " << size() << endl; // Returning the size
}

int main(){	
	Queue q1; //Object of Queue Class
	q1.someOperations(); // I write some operations in a function to make main function most clear
}
