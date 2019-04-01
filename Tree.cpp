/*  got helped from: https://www.youtube.com/channel/UCcDGsN3JxMavDkM9INRLGFA
    explaning insertion,removal,deconstruction...etc of binary tree in C++.
	very short deletion funcation https://www.geeksforgeeks.org/binary-search-tree-set-2-delete/
*/
#include <iostream>
#include "Tree.hpp"
#include <cstdlib>
    using namespace std;
    //Constrcutor
    ariel::Tree::Tree(){
        total = 0;
        head = NULL;
    }
    //Deconstructor
    ariel::Tree::~Tree(){
       removeSubtree(head);
    }
    void ariel::Tree::removeSubtree(node* n){
        if(n != NULL){
            if(n->getLeft != NULL){
                removeSubtree(n->getLeft);
            }
            if(n->getRight != NULL){
                removeSubtree(n->getRight);
            }
            cout << "Deleteing the node containing data " << n->data << endl;
            delete n;
        }
    }
    //CREATE NODE
    node* ariel::Tree::createLeaf(int i){
        node* n = new node;
        n->data = i;
        n->getLeft = NULL;
        n->getRight = NULL;
		cout << "Added to binary cotaining data " << n->data << endl;
        return n;
    }
    
//REMOVE
void ariel::Tree::remove(int i){
	if (!contains(i))
		throw "not found";
	if (head == NULL)
		throw "cannot remove from empty Tree";
	head = remove(i, head);
		total--;
}
node* ariel::Tree::remove(int i, node* n)
{
	// Base case 
	if (n == NULL)
		return n;

	// Recursive calls for ancestors of 
	// node to be deleted 
	if (n->data > i) {
		n->getLeft = remove(i, n->getLeft);
		return n;
	}
	else if (n->data < i) {
		n->getRight = remove(i,n->getRight);
		return n;
	}

	// We reach here when root is the node 
	// to be deleted. 

	// If one of the children is empty 
	if (n->getLeft == NULL) {
		node* temp = n->getRight;
		delete n;
		return temp;
	}
	else if (n->getRight == NULL) {
		node* temp = n->getLeft;
		delete n;
		return temp;
	}

	// If both children exist 
	else {

		node* succParent = n->getRight;

		// Find successor 
		node *succ = n->getRight;
		while (succ->getLeft != NULL) {
			succParent = succ;
			succ = succ->getLeft;
		}

		// Delete successor.  Since successor 
		// is always left child of its parent 
		// we can safely make successor's right 
		// right child as left of its parent. 
		succParent->getLeft = succ->getRight;

		// Copy Successor Data to root 
		n->data = succ->data;

		// Delete Successor and return root 
		delete succ;
		return n;
	}
}
//INSERT
void ariel::Tree::insert(int i){
		insert(i, head);
		total++;
}
void ariel::Tree::insert(int i, node* n){
    if(head == NULL){
        head = createLeaf(i);
    }
    else if(i < n->data){
        if (n->getLeft != NULL){
          insert(i,n->getLeft);  
        }else{
            n->getLeft = createLeaf(i);
        }
        
    }
    else if(i > n->data){
        if (n->getRight != NULL){
          insert(i,n->getRight);  
        }else{
            n->getRight = createLeaf(i);
        }
        
    }
    else
    {
        throw "The data has already been added to the tree\n";
    }
}
//CONTAINS
bool ariel::Tree::contains(int i){
    return contains(i,head);
}
bool ariel::Tree::contains(int i,node* n){
    if (n==NULL){
        return false;//failed
    }
    if(n->data==i){
        return true;
    }
    if(n->getLeft != NULL){
        if(n->data > i)
            return contains(i,n->getLeft);
    }
    if(n->getRight != NULL){
        if(n->data < i)
            return contains(i,n->getRight);
    }
    return false;//failed
}
//RIGHT
int ariel::Tree::right(int i){
	if (!contains(i))
		throw "does not exist";
    return right(i,head);
}
int ariel::Tree::right(int i,node* n){
    if (n==NULL){
        throw "empty tree";//error
    }
    if(n->data == i){
        if (n->getRight != NULL)
             return n->getRight->data;
            throw "Doesn't have a right child";//error
    }
    if(n->getLeft != NULL){
        if(n->data > i)
            return +right(i,n->getLeft);
    }
    if(n->getRight != NULL){
        if(n->data < i)
            return +right(i,n->getRight);
    }
    return 0;
}
//LEFT
int ariel::Tree::left(int i){
	if (!contains(i))
		throw "does not exist";
    return left(i,head);
}
int ariel::Tree::left(int i,node* n){
    if (n==NULL){
        throw "empty tree";//error
    }
    if (n->data == i){
        if(n->getLeft != NULL)
            return n->getLeft->data;
        throw "Doesn't have a left child";//error;
    }
    if(n->getLeft != NULL){
        if(n->data > i)
            return +left(i,n->getLeft);
    }
    if(n->getRight != NULL){
        if(n->data < i)
            return +left(i,n->getRight);
    }
    return 0;
}
//PARENT
int ariel::Tree::parent(int i){
	if (!contains(i))
		throw "does not exist";
    return parent(i,head);
}
int ariel::Tree::parent(int i,node* n){
    if (n==NULL || n->data == i){
        throw "Doesn't have a parent";
    }
    if(n->getLeft != NULL){
        if (n->getLeft->data == i)
            return n->data;
        if(n->data > i)
            return +parent(i,n->getLeft);
    }
    if(n->getRight != NULL){
        if (n->getRight->data == i)
            return n->data;
        if(n->data < i)
            return +parent(i,n->getRight);
    }
    return 0;
}
//PRINT
void ariel::Tree::print(){
    printInOrder(head);
    cout << endl;
}
void ariel::Tree::printInOrder(node* n){
	if (n == NULL)
		return;
    printInOrder(n->getLeft);
    cout << n->data << " ";
    printInOrder(n->getRight);
}