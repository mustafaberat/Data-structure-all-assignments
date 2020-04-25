/* Implement a queue using two stacks */
#include <iostream>
#include <stdlib.h> //For malloc function
using namespace std;

// structure of a stack node
struct Node { 
	int data; 
	struct Node* next; 
}; 

void push(struct Node** top_ref, int new_data); 
int pop(struct Node** top_ref); 

// structure of queue that having two stacks
struct queue { 
	struct Node* stack1; 
	struct Node* stack2; 
}; 

void enQueue(struct queue* q, int val) 
{ 
	// &q is referencing the queue address that's why used Node**
	push(&q->stack1, val); 
} 

int deQueue(struct queue* q) 
{ 
	int spare; 

	if (q->stack1 == NULL && q->stack2 == NULL) { //Both stacks empty
		printf("Queue is empty"); 
		getchar(); //Look the number
	} 

	// Move elements from stack1 to stack 2 only if stack2 is empty 
	if (q->stack2 == NULL) {  //Stack2 empty
		while (q->stack1 != NULL) { //Stack1 is not empty 
			spare = pop(&q->stack1);  //Delete stack1 element first and get value on it
			push(&q->stack2, spare); //And add to stack2 what stack1 delted
		} 
	} 

	spare = pop(&q->stack2); //Delete what you add because you made back up in stack2
	return spare; //The number of top value of stack2
} 

void push(struct Node** top_ref, int new_data) 
{ 
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 
	if (new_node == NULL) { 
		printf("Stack overflow \n"); 
		getchar(); //For reading
	} 
	new_node->data = new_data; 
	new_node->next = (*top_ref); //Link old list off new node
	(*top_ref) = new_node; //Move head to point to new node
} 

int pop(struct Node** top_ref) 
{ 
	int res; 
	struct Node* top; //Create a top

	if (*top_ref == NULL) { //Stack is empty
		printf("Stack underflow \n"); 
		getchar(); 
	} 
	else { //Not empty stack
		top = *top_ref; 
		res = top->data; 
		*top_ref = top->next; 
		delete(top); //Deleting value of top_ref so top
		return res; //Number of top value
	} 
} 

int main() { 
	struct queue* q = (struct queue*)malloc(sizeof(struct queue)); 
	q->stack1 = NULL; 
	q->stack2 = NULL; 
	
	int iteration = 0;
	int addnumber; //Which number added
	cout << "Enqueu 0 is exit" <<endl;
	
	do{
		cout << "Enqueue the number: ";
		cin >> addnumber;
		enQueue(q,addnumber);
		iteration++;
	}while(addnumber != 0);
	cout << endl;
	
	// When we dequeu, it delete and writing thats why after for queue would empty
	for(int i = 1 ; i < iteration ; i++){
		cout <<"Number "<<i<< " element: " <<deQueue(q) << endl;
	}
	
	return 0; 
} 

