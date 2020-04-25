//Implement following doubly linked list class’s method
// Mustafa Aru - 30716006

#include <iostream>
#include <unistd.h> //For sleep to check infinity loops !sleep function
#include <conio.h>
using namespace std;

struct Node{
	int data;
	Node *next;
	Node *prev;
};

class DList{
	public:
		Node *head;
		DList(){
		head = NULL;
		}
		
		Node* CreateNode(int val);
		bool IsEmpty();// check if DList is empty
		void InsertLast(int);// inserts at last position from DList
		void InsertFirst(int);// inserts at first position from DList
		void InsertAtIndex(int, int);//insert data at a specific position from DList
		void RemoveLast(); // removes last element from DList
		void RemoveFirst(); // remove first element from DList
		void RemoveAtIndex(int);// remove at some position
		void Display(); // show all data in DList
		void DisplayReverse ();
		int CountItems();// count the number of elements in DList
		void Find(int);// search for an element in the DList
		void ChangeList ();
		void FindSum();
		int CheckDuplicate(int);
		void Square();
		void CountEvenAndOdd();
};

Node* DList::CreateNode(int val){
	Node *newNode = new Node;
	newNode->data = val;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}

bool DList::IsEmpty(){
		return head==NULL;
}

void DList::InsertFirst(int val){
	if(!IsEmpty())
	{
		Node *newNode = CreateNode(val);
		head->prev = newNode;
		newNode->next = head;
		head = newNode;
	}
	
	else
	{
		head = CreateNode(val);
	}
}

void DList::InsertLast(int val){
	if(!IsEmpty())
	{
		
		Node *temp = head; // Head is temp also. Purpose: Not lossing head
		while(temp->next!=NULL)
		{
			temp = temp->next; //Finding last!
		}
		
			Node *newNode = CreateNode(val); //Connecting after find last element
			newNode->prev = temp;
			temp->next = newNode;
	}	
	else
	{
		head = CreateNode(val);
	}
}

void DList::InsertAtIndex(int val, int index){
		int count_items = CountItems();
		int counter = 1;
		
	if(index>=count_items)
	{
		InsertLast(val);
	}
	
	else
	{
		if(index<=1)
		{
			InsertFirst(val);
		}
		else
		{
			Node *newNode = CreateNode(val);
			Node *temp = head;	
			while(counter<index)
			{
				temp = temp->next; //Finding until index
				counter++; //Simple counter
			} //End of while
			
			newNode->prev = temp;
			newNode->next = temp->next;
			temp->next->prev = newNode;
			temp->next = newNode;	
			
		}
	}	
}

void DList::RemoveLast(){
	if(IsEmpty()){
		cout << "You do not already have any nodes" << endl;
	}
	else
	{
		if(head->next ==NULL){ //Only one node
			head = NULL;
		}
		else
		{
			Node *temp = head;
			
			while(temp->next->next !=NULL)
			{
				temp=temp->next;//Finding last
			} //End of while
			temp->next = NULL;
		
		} //End of else
	}
}

void DList::RemoveFirst(){
	if(IsEmpty()){
		cout << "You do not already have any nodes" << endl;
	}
	else{
		if(head->next == NULL){ //Only one Node
			head = NULL;
		}
		else{
			Node *temp = head;
			head = head->next;
			delete temp;
		}
	}
}

void DList::RemoveAtIndex(int index){
	if(IsEmpty()){
		cout << "You do not already have any nodes" << endl;
	}
	
	else{
		if(head->next == NULL){ //Only one Node
			head = NULL; //Delete that one Node
		}
		else{
			int count_items = CountItems();

			if(index>=count_items){ //If index is 99
				RemoveLast();
			}
			else if(index<=1){ // If index -5 or 1
				RemoveFirst();
			}
			else{ //Others
				int counter = 1; //Simple counter not elements counter
				
				Node *temp = head;	
				while(counter<index-1) //Coming that index -1  because stay 1 step back to delete
				{
					temp = temp->next; //Finding until index
					counter++; //Simple counter
				} //End of while
				
				//We are in before Node for newNode and temp
				
				Node *newNode = temp->next;
				temp->next = newNode->next;
				temp->next->prev = temp;
				newNode->next->prev = temp;
				
				delete newNode;
			}
		}
	}
}

void DList::Display(){
	if(!IsEmpty())
	{
		int counter = 1;
		Node *temp = head;
		while(temp != NULL)
		{
			cout << counter << ". Element is: " << temp->data <<endl;
			counter++;
			temp = temp->next;
		} //End of while
	}
	else
	{
		cout << "List is empty!" <<endl;
	}
}

void DList::DisplayReverse(){
	
	if(!IsEmpty())
	{
		int count_items = CountItems();
		int simple_counter = count_items;
		Node *temp = head;
		cout<<"Reverse Display: ";
		
		while(temp->next != NULL)
		{
			temp=temp->next; //Finding last
		} //End of while

		while(simple_counter > 0)	{		
			cout << temp->data << " - ";
			simple_counter--;
			temp = temp->prev;
		} //End of while
	}
	else
	{
		cout << "List is empty!" <<endl;
	}
}

void DList::Find(int val){
	if(IsEmpty()){
		cout << "Your list is empty!" << endl;
	}
	else{
		Node *temp = head;
		int simple_counter = 0;
		while(temp->next != NULL){
			if(temp->data == val){ //Found!
				simple_counter++;
			}
			temp = temp->next; //Search for all
		}
		
		if(simple_counter>0){
			cout << endl << val <<" is found in your list" << endl;
		}
		else if(simple_counter>=0){
			cout << val <<" could not find in your list" << endl;
		}
	}
}

void DList::FindSum(){
	if(IsEmpty()){
		cout << "Your list is empty!" << endl;
	}
	else{
		Node *temp = head;
		int total_data = 0;
		int simple_counter = CountItems();
		while(simple_counter > 0){
			total_data += temp->data;
			temp = temp->next; //Search for all
			simple_counter--;
		}
		cout << "Total Data Numbers is: "<< total_data << endl;
	}
}

int DList::CheckDuplicate(int val){
	if(IsEmpty()){
		cout << "Your list is empty!" << endl;
	}
	else{
		Node *temp = head;
		int found = 0;
		int simple_counter = CountItems();
		while(simple_counter > 0){ // Search all
			if(temp->data == val){
				found++;
			}
			temp = temp->next; //Going next
			simple_counter--;
		}
		//cout << "Found: " <<found<<endl;
		return found;	
	}
}

void DList::CountEvenAndOdd(){
	if(IsEmpty()){
		cout << "Your list is empty!" << endl;
	}
	else{
		Node *temp = head;
		int odd_numbers = 0;
		int even_numbers = 0;
		int simple_counter = CountItems(); //How many numbers
		
		while(simple_counter > 0){
			if(temp->data % 2 == 0){
				even_numbers++;
			}
			else if(temp->data % 2 == 1){
				odd_numbers++;
			}
			else if(temp->data % 2 != 0 || temp->data % 2 != 1){
				cout<< "Your number is not integer" <<endl;
			}
			temp = temp->next; //Search for all
			simple_counter--;
		}
		cout << "Odd: "<< odd_numbers << endl;
		cout << "Even: " <<even_numbers <<endl;
	}
}

int DList::CountItems(){
	Node *temp = head;
	int count_items = 0;
	
	while(temp != NULL){
		count_items++;
		temp = temp->next;
	}
	
	return count_items;
}

void DList::Square(){
	if(IsEmpty()){
		cout << "The list is empty!" << endl;
	}
	
	else{
		cout << "-----------"<<endl;
		cout << "Square Function" <<endl;
		int simple_no;
		int simple_counter = CountItems();
		Node *temp = head;
		while (simple_counter>0){
			temp->data = (temp->data) * (temp->data);
			simple_counter--;
			temp = temp->next;
		}
	} //End of else
}

void DList::ChangeList(){
	if(IsEmpty()){
		cout << "The list is empty!" << endl;
	}
	else{
		cout << "------" <<endl;
		cout << "If head-data is bigger than last-data change them:" <<endl;
		Node *temp = head; //Temp will be next one to compare!
		
		while(temp->next != NULL){
			temp = temp->next;
		} //End of while
		
		
		if(head->data > temp->data){ //First is bigger than last value of node
			int spare_no = head->data;
			head->data = temp->data;
			temp->data = spare_no; //Change them
		}
	}
}

int main(){
	Node N1;
	DList D1;
	D1.InsertLast(10);
	D1.InsertLast(20);
	D1.InsertLast(30);
	D1.InsertFirst(5);
	D1.InsertFirst(80);
	D1.InsertFirst(2);
	D1.InsertAtIndex(8,2);
	D1.InsertAtIndex(25,5);
	D1.RemoveLast(); //30 is removed
	D1.RemoveFirst(); //2 is removed
	D1.InsertAtIndex(35,90); //Big index
	D1.RemoveAtIndex(3); //Removing 10
	D1.Display();
	D1.DisplayReverse();
	D1.Find(10);
	D1.Find(32);
	D1.FindSum();
	D1.CheckDuplicate(5); // How many time 5 seen
	D1.CountEvenAndOdd(); //Even and odd numbers
	D1.ChangeList(); //If head-data is bigger than last-data change them
	D1.Display(); //Show again changed!
	D1.Square();
	D1.Display();
	getch();
}
