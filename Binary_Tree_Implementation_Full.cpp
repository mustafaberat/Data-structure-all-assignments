
//#include "pch.h"
#include <iostream>
using namespace std;

struct Node
{
        int data;
        Node* left;
        Node* right;
};

class Tree
{
public:
        //Member functions
        Tree();
        bool IsEmpty();
        Node* CreateNode(int);
        void Insert(int);
        Node* Delete(Node*, int);
        void Print_PreOrder(Node*);
        void Print_InOrder(Node*);
        void Print_PostOrder(Node*);
        void Print_LevelOrder(Node*);
        int Height(Node*);
        void PrintLevel(Node*, int); //root and level -index
        void Search(int);
        Node* FindMax(Node*);
        Node* FindMin(Node*);
        Node* Parent(int);

        //Data Members
        Node *root;
};

Tree::Tree()
{
        root = NULL;
}

bool Tree::IsEmpty() {
        return root == NULL;
}

Node* Tree::CreateNode(int element) {
        Node* temp = new Node; //Creating the new node
        temp->data = element; //Giving the element on node
        temp->left = NULL; //Left is null (default)
        temp->right = NULL;//Right is null (default)
        return temp; //Returning the address of node
}

Node* Tree::FindMax(Node*r) {
        while (r->right != NULL) //While no right element
        {
               r = r->right; //Look one more right
        }
        return r;
}

Node* Tree::FindMin(Node*temp) {
        while (temp->left != NULL) //While no node left
        {
               temp = temp->left; //Look one more left
        }
        return temp;
}

void Tree::Search(int element) {
        Node *temp = root; //Root to temp
        bool found = false; //Default- Not found
        while (temp != NULL)
        {
               if (element == temp->data)
               {
                       found = true; //Found!
                       break; //Jump to out of while
               }

               else
               {
                       if (element < temp->data)
                       {
                               temp = temp->left;
                       }
                       else
                       {
                               temp = temp->right;
                       }
               }//End of else
        }//End of while

        if (found)
        {
               cout << element << " is found in tree!" << endl;
        }
        else
        {
               cout << element << " could not found in tree!" << endl;
        }
}

Node* Tree::Parent(int element) {
        cout << element << " 's parent is: ";
        Node *temp = root; //Attend root to temp
        Node *parent = NULL; //Default - parent is null
        bool found = false;

        while (temp != NULL)
        {
               if (element == temp->data)
               {
                       found = true;
                       break; //Out of while
               }//End of if
               else
               {
                       parent = temp; /*Temp and parent is the same now because we will jump with temp and parent must be back to temp */
                       if (element < temp->data)
                       {
                               temp = temp->left;
                       }
                       else
                       {
                               temp = temp->right;
                       }
               }//End of else
        }//End of while

        /* If element is not found or is root then set parent to null to indicate no parent*/

        if (!found)
        {
               parent = NULL;
        }

        cout << parent << endl;
        return parent;
}

void Tree::Insert(int element) {
        cout << element << " is added in tree!" << endl;
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

Node* Tree::Delete(Node* root, int data) {
        cout << data << " is deleted in tree!" << endl;
        if (root == NULL)
        {
               return NULL;
        }//End of if
        else if (data < root->data)
        {
               root->left = Delete(root->left, data); //Recursive function
        }//End of elseif
        else if (data > root->data)
        {
               root->right = Delete(root->right, data); //Recursive function
        } //End of elseif

        //If found delete element
        else
        {
               //No child
               if (root->left == NULL && root->right == NULL)
               {
                       delete root;
                       root = NULL;
               }
               //One child
               else if (root->left == NULL)
               {
                       Node *temp = root;
                       root = root->right;//Copy to right to root inself
                       delete temp;
               }
               else if (root->right == NULL)
               {
                       Node *temp = root;
                       root = root->left;
                       delete temp;
               }
               //Two children
               else
               {
                       //We need to chose one of them: 

                       //1-Find max of left subtree
                       Node *temp = FindMax(root->left);
                       root->data = temp->data;
                       root->left = Delete(root->left, temp->data);

                       //2-Find min of right subtree
                       /*temp = FindMin(root->right);
                       root->data = temp->data;
                       root->right = Delete(root->right, temp->data);*/
               }
        }
        return root;
}

void Tree::Print_PreOrder(Node* temp) {
        if (temp == NULL)
        {
			return;
        }
        cout << temp->data << " ";
        Print_PreOrder(temp->left);
        Print_PreOrder(temp->right);
}

void Tree::Print_InOrder(Node* temp) {
        if (temp == NULL)
        {
               return;
        }
        Print_InOrder(temp->left);
        cout << temp->data << " ";
        Print_InOrder(temp->right);
}

void Tree::Print_PostOrder(Node* temp) {
        if (temp == NULL)
        {
               return;
        }
        Print_PostOrder(temp->left);
        Print_PostOrder(temp->right);
        cout << temp->data << " ";
}

void Tree::Print_LevelOrder(Node* temp) {
        int h = Height(temp);
        for (int i = 0; i <= h; i++) {
               PrintLevel(temp, i);
               cout << endl;
        }
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

void Tree::PrintLevel(Node* temp, int level) {
        if (root == NULL)
               return;
        if (level == 1)
        	cout << temp->data << " ";
        else if (level > 1) {
               PrintLevel(temp->left, level - 1);
               PrintLevel(temp->right, level - 1);
        }
}

int main()
{
        Tree T1;
        T1.Insert(20);
        T1.Insert(40);
        T1.Insert(10);
        T1.Insert(15);
        T1.Insert(8);
        T1.Insert(42);
        T1.Insert(35);
        cout << endl;
        Node *temp = T1.root;
        T1.Print_PreOrder(temp);
//        cout << "The maximum element of tree: " << T1.FindMax(temp) << endl;
//        cout << "The minimum element of tree: " << T1.FindMin(temp) << endl;

}

