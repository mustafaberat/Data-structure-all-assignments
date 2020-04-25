/*Mustafa Aru - 30716006
Question No.1
a) Write a program that draws a binary tree.
b) Write a program that draws a general tree.
c) Write a program that can input and display a person’s family tree.
Question 2.
Implement all the functions as discussed in the class. Also add following function to the Tree
class.
a) Write a function to print Sum and Product of minimum and maximum element of a
Binary Search Tree
b) Write a function to display the sum of all nodes in a binary search tree
c) Write a function to count and display even and odd numbers in a binary search tree.
d) Write a function to count and display the number of external nodes in a tree.
e) Write a function to count and display the number of internal nodes in a tree.
f) Write a function to check if number occurs more than one time in the whole tree.
g) Print all even nodes using preorder traversal
h) Print all odd nodes using postorder traversal
*/

//#include "pch.h"
#include <iostream>
#include <cstring>
using namespace std;

struct Node
{
        int data;
        string Name;
        Node* left;
        Node* right;
};

class Tree
{
public:
        //Member functions
        Tree();
        Node* CreateNode(int);
        void Insert(int);
        int Height(Node*);
        Node* FindMax(Node*);
        Node* FindMin(Node*);
        
        //Homework 1-2 Functions
        void Print_Horizontal(Node*,int);
        void Print_HorizontalForPerson(Node*,int);
        void Sum_Max_Min(Node*);
        void Sum_All(Node*);
        void Even_Odd(Node*);
        void Print_Even(Node*);
        void Print_Odd(Node*);
		void Find_External(Node*);
        void Find_Internal(Node*);
        Node* CreatePerson(string);
        void CheckDuplicated(Node*);
        
        //Data Members
        Node *root;
        int count_even;
        int count_odd;
        int count_external;
        int count_internal;
};

Tree::Tree()
{
        root = NULL;
        count_even = 0;
        count_odd = 0;
        count_external = 0;
        count_internal = 0;
}

Node* Tree::CreateNode(int element) {
        Node* temp = new Node; //Creating the new node
        temp->data = element; //Giving the element on node
        temp->left = NULL; //Left is null (default)
        temp->right = NULL;//Right is null (default)
        return temp; //Returning the address of node
}

Node* Tree::CreatePerson(string name){
		Node* temp = new Node; //Creating the new node
        temp->Name = name; //Giving the element on node
        temp->left = NULL; //Left is null (default)
        temp->right = NULL;//Right is null (default)
        return temp; //Returning the address of node
}

Node* Tree::FindMax(Node* temp) {
        while (temp->right != NULL) //While no right element
        {
               temp = temp->right; //Look one more right
        }
        return temp;
}

Node* Tree::FindMin(Node*temp) {
        while (temp->left != NULL) //While no node left
        {
               temp = temp->left; //Look one more left
        }
        return temp;
}

void Tree::Insert(int element) {
        if (root == NULL) //If no root in tree
        {
               root = CreateNode(element); //Creating a node that r,l null
        }

        else
        {
               Node *temp = root; //Attend root to temp
               Node *parent = NULL; /*Parent is null for default - Parent must back to temp!*/

               while (temp != NULL)
               {
                       parent = temp; //Parent and temp the same now- we will jump with temp

                       /*if element smaller than data go to left - if not go to right*/
                       temp = element < temp->data ? temp->left : temp->right;

               } //End of while

               temp = CreateNode(element); //Creating the temp node
               if (element < parent->data) //If smaller
               {
                       parent->left = temp; //Merge left
               }
               else
               {
                       parent->right = temp; //Merge right
               }

        }//End of else
}

int Tree::Height(Node *temp) {
        if (temp == NULL)
               return 0;

        else {
               int lheight = Height(temp->left);
               int rheight = Height(temp->right);

               //Use larger one
               if (lheight > rheight)
                       return lheight + 1;
               else
                       return rheight + 1;
        }
}

void Tree::Sum_Max_Min(Node* temp){
		Node* max_pointer = temp; //Initial pointer for search
        Node* min_pointer = temp; //Initial pointers
        
		while (max_pointer->right != NULL) //While no right  no left element
        {
            max_pointer = max_pointer->right; //Look one more right
        }
        
        while(min_pointer->left != NULL)
		{
        	min_pointer = min_pointer->left; //Look one more left
		}
        cout << "Sum of max and min: "<< min_pointer->data + max_pointer->data << endl;
        cout << "Production of max and min: "<< min_pointer->data * max_pointer->data << endl;
}

void Tree::Sum_All(Node* temp){
		Node* search_left = temp; //Initial pointer for search
        Node* search_right = temp; //Initial pointers
        int total_all = 0;
        total_all += search_right->data;
        total_all += search_left->data;
        
		while (search_right->right != NULL) //While no right  no left element
        {
            search_right = search_right->right; //Look one more right
        	total_all += search_right->data;
		}
        
        while(search_left->left != NULL)
		{
        	search_left = search_left->left; //Look one more left
        	total_all += search_left->data;
		}
        cout << "Sum of all numbers:  "<< total_all << endl;
        
}

void Tree::Even_Odd(Node *temp){ //Function give the count of even and odd and also display 
/*Count and display even and odd numbers in a binary search tree.*/
   
	 if (temp == NULL){
		return;
	 }
        
        if(temp->data %2 == 0){
        	cout << "Even Node: " << temp->data <<endl;
        	count_even++;
		}
		else if(temp->data %2 != 0){
			cout << "Odd Node: " << temp->data <<endl;
        	count_odd++;	
		}
		
        Even_Odd(temp->left);
        Even_Odd(temp->right);  	
  	
    	    
   
    
} //End of Even_Odd

void Tree::Print_Even(Node* temp){
	//Using preorder
	
	 if (temp == NULL){
		return;
	 }
        
        if(temp->data %2 == 0){
        	cout << "Even Node: " << temp->data <<endl;
		}
		
        Print_Even(temp->left);
        Print_Even(temp->right);  	
}

void Tree::Print_Odd(Node* temp){
	//Using post order
	
	 if (temp == NULL){
		return;
	 }
        
        Print_Odd(temp->left);
        Print_Odd(temp->right);  
			
        if(temp->data %2 != 0){
        	cout << "Odd Node: " << temp->data <<endl;
		}
}

void Tree::Find_External(Node* temp){
    /* Count and display the number of external nodes in a tree. */
    //External Node: No child
    
   if (temp == NULL) 
        return; 
  
    if(temp->right == NULL && temp->left == NULL){ //It means: No child
            count_external++;
            cout<< "External node: " << temp->data << endl;
        }
        
    /* then recur on left sutree */
    Find_External(temp->left);  
  
    /* now recur on right subtree */
    Find_External(temp->right); 
}

void Tree::Find_Internal(Node* temp){
    /* Count and display the number of internal nodes in a tree. */
    //Internal Node: Have one or two childer
    
   if (temp == NULL) 
        return; 
  
    if(temp->right != NULL || temp->left != NULL){ //It means: one child or two children
            count_internal++;
            cout<< "Internal node: " << temp->data << endl;
        }
        
    /* then recur on left sutree */
    Find_Internal(temp->left);  
  
    /* now recur on right subtree */
    Find_Internal(temp->right); 
}

void Tree::Print_Horizontal(Node* temp,int space) {
	// Base case 
	if (temp == NULL)
		return;

	// Increase distance between levels 
	space += Height(temp);

	// Process right child first 
	Print_Horizontal(temp->right, space);


	cout << endl;
	for (int i = Height(temp); i < space; i++)
		cout << "   ";
	cout << temp->data << endl << endl ;

	// Process left child 
	Print_Horizontal(temp->left, space);
	}

void Tree::Print_HorizontalForPerson(Node* temp,int space) {
	// Base case 
	if (temp == NULL)
		return;

	// Increase distance between levels 
	space += Height(temp);

	// Process right child first 
	Print_HorizontalForPerson(temp->right, space);


	cout << endl;
	for (int i = Height(temp); i < space; i++)
		cout << "\t";
	cout << temp->Name << endl << endl ;

	// Process left child 
	Print_HorizontalForPerson(temp->left, space);
	}

void Tree::CheckDuplicated(Node* temp) 
{ 

    // If tree is empty or external node, there are no duplicates.  
    if (temp->right == NULL && temp->left == NULL) 
       return; 
  	
    // If current node's data is already present. 
    if (temp->data == temp->right->data || temp->data == temp->left->data) 
    {
    	cout << "Duplicate data found!" << endl; 
		return;
	}
        
    // Recursively check in left and right subtrees. 
	CheckDuplicated(temp->right); 
    CheckDuplicated(temp->left);
} 

int main(){
		cout << "---------------------" <<endl;
		cout << "Binary Search Tree" <<endl;
		cout << "---------------------" <<endl;
        Tree T1; //Creating Object
         
        //interstion
        T1.Insert(20);
        T1.Insert(40);
        T1.Insert(10);
        T1.Insert(15);
        T1.Insert(8);
        T1.Insert(42);
        T1.Insert(35);
        //T1.Insert(35); //For looking duplicate funtion

		T1.Print_Horizontal(T1.root,0);//Drawing the binary search tree
		cout << endl;
        
		T1.Sum_Max_Min(T1.root); //Sum of max and min
		cout << endl;
		
        T1.Sum_All(T1.root); //Sum of all nodes
		cout << endl;
		
		T1.Even_Odd(T1.root); //Write odd and even also counter
		//It is recursive funtion so we cant write number of odd numbers inside function!
		cout << "Number of odd numbers: " << T1.count_odd << endl;
   		cout << "Number of even numbers: " << T1.count_even << endl << endl;
   		
		T1.CheckDuplicated(T1.root);	
		
		//Not binary search
		cout << "---------------------" <<endl;
		cout << "Normal Tree" <<endl;
		cout << "---------------------" <<endl;
		Tree T2; 
		//Insertion
		T2.root = T2.CreateNode(50); 
	    T2.root->left = T2.CreateNode(100);
	    T2.root->right = T2.CreateNode(20);
	    T2.root->right->right = T2.CreateNode(90);
	    T2.root->right->left = T2.CreateNode(11);
	    T2.root->left->right = T2.CreateNode(91);
	    T2.root->left->left = T2.CreateNode(17);
	    
	    T2.Print_Horizontal(T2.root,0); //Drawing the normal tree
	    cout << endl;
	    
	    T2.Find_External(T2.root); //Finding external nodes, writing also counter
		cout << "Number of external node: " << T2.count_external << endl << endl;
		
		T2.Find_Internal(T2.root); //Finding internal nodes, writing also counter
		cout << "Number of internal node: " << T2.count_internal << endl << endl;
		
				
		T2.Print_Even(T2.root); //Printing even numbers by preorder algorithm
		cout << endl;
		
		T2.Print_Odd(T2.root); //Printing odd numbers by postorder algorithm
		cout << endl;
		
		
		
		//For family tree
		cout << "---------------------" <<endl;
		cout << "Family Tree" <<endl;
		cout << "---------------------" <<endl;
		Tree T3; 
		
		//Insertion
		T3.root = T3.CreatePerson("Mustafa");
	    T3.root->left = T3.CreatePerson("Ali");
	    T3.root->right = T3.CreatePerson("Aslan");
	    T3.root->right->right = T3.CreatePerson("Osman");
	    T3.root->right->left = T3.CreatePerson("Emre");
	    T3.root->left->left = T3.CreatePerson("Oya");
	    T3.root->left->right = T3.CreatePerson("Ipek");
	    
	    cout << endl<<endl;
	    T3.Print_HorizontalForPerson(T3.root,0);
	    
	    return 0;
}

