/* Mustafa Aru - 30716006
Question No.1 : Implement insertion, selection and bubble sort to sort a singly linked list*/
#include <iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
};

class SList{
	private:
		Node *head;
		
	public:
		SList(){
			head = NULL;
			count = 0;
		}
		Node* CreateNode(int val);
		int count; //Number of elements
		bool IsEmpty();// check if SList is empty
		void InsertLast(int);// inserts at last position from SList
		void RemoveLast(); // removes last element from SList
		void Display(); // show all data in SList
		void Selection_Sort();
		void Bubble_Sort();
		void Insertion_Short();
};

Node* SList::CreateNode(int val){
	Node *newNode = new Node;
	newNode->data = val;
	newNode->next = NULL;
	return newNode;
}

bool SList::IsEmpty(){
		return head==NULL;
}

void SList::InsertLast(int val){
	if(!IsEmpty()) //If there are some nodes 
	{
		
		Node *temp = head; // Head is temp also. Purpose: Not lossing head
		while(temp->next != NULL)
		{
			temp = temp->next; //Finding last!
		}
		
			Node *temp2 = CreateNode(val); //Connecting after find last element
			temp->next = temp2;
	}	
	else //Not node
	{
		head = CreateNode(val);
	}
	count++; //Elements of list
}

void SList::RemoveLast(){
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
	count--; // Elements of list
}

void SList::Display(){
	if(!IsEmpty())
	{
		Node *temp = head;
		while(temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		} //End of while
	}
	else
	{
		cout << "List is empty!" <<endl;
	}
	cout << endl;
}

void SList::Bubble_Sort(){	
	for(int i=0 ; i< count-1 ; i++){ //iteration
		Node *temp = head; //Temp is head AGAIN IN ITERATION!
		while(temp->next != NULL){ //searching all elemets
			if(temp->data > temp->next->data){
				int spare = temp->data; //Swapping
				temp->data = temp->next->data;
				temp->next->data = spare;
			}
			temp = temp->next;
		}
	} //End of for
}

void SList::Insertion_Short(){
	Node *temp2 = head->next;
	for(int i=0 ; i<count-1 ; i++){
		Node *temp1 = head; //temp is head
		while(temp1 != temp2){
			if(temp1->data > temp2->data){
				int spare = temp1->data;
				temp1->data = temp2->data;
				temp2->data = spare;
			}
			temp1 = temp1->next;
		} //end of while
		temp2 = temp2->next;
	}//end of for	
}

void SList::Selection_Sort(){
	Node *temp = head; //temp is head
	
	for(int i = 0 ; i<count-1 ; i++){
		Node *search = temp->next;
		Node *min = temp; //index of min index - beggining is default
		
		while(search!= NULL){
			if(min->data > search->data){ //Swapping
				int spare = min->data;
				min->data = search->data;
				search->data = spare; 
			}
			search = search->next;
		} //end of while
		min = min->next;
		temp = temp->next;
	}
}

int main(){
	SList L1;
	L1.InsertLast(6);
	L1.InsertLast(5);
	L1.InsertLast(8);
	L1.InsertLast(9);
	L1.InsertLast(3);
	L1.InsertLast(2);
	L1.InsertLast(40);
	L1.RemoveLast(); //Deleting 40


	cout << "Normal List: ";
	L1.Display();
	
	cout << "Bubble Sorting: ";
	L1.Bubble_Sort(); //Sorting
	L1.Display();
	
	cout << "Insertion Sorting: ";
	L1.Insertion_Short();
	L1.Display();

	cout << "Section Sorting: ";
	L1.Selection_Sort();
	L1.Display();
	
	return 0;
}
