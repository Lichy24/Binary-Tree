/*  got helped from: https://www.youtube.com/channel/UCcDGsN3JxMavDkM9INRLGFA
    explaning insertion,removal,deconstruction...etc of binary tree in C++.
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
	cout << "delete used for " << i << endl;
	if (!contains(i))
		throw "not found";
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
/*
void ariel::Tree::remove(int i,node* n){
    if(head != NULL){
        if(head->data == i){
            removeRoot();
        }
        else{
            if(i < n->data && n->getLeft != NULL){
                if(n->getLeft->data == i){
                    removeMatch(n,n->getLeft,true);
                    
                }else{
                    remove(i,n->getLeft);
                }
            }
        else if(i > n->data && n->getRight != NULL){
                if(n->getRight->data == i){
                    removeMatch(n,n->getRight,false);
                }else{
                    remove(i,n->getRight);
                }
            }
        else{
            throw "The data was not found in the tree\n";
        }
        }
    }else{
        throw "The tree is empty\n";
    }
}
void ariel::Tree::removeRoot(){
    if (head != NULL){
        node* delPtr = head;
        int rootdata = head->data;
        int smallestInRightSubTree;
        if(head->getLeft == NULL && head->getRight == NULL){
            head = NULL;
            delete delPtr;
        }
        else if(head->getLeft == NULL && head->getRight != NULL){
            head = head->getRight;
            delPtr->getRight = NULL;
            delete delPtr;
            cout << "The root node with data "<< rootdata << " was deleted. " << "The new root contains data "<< head->data << endl;
        }
        else if(head->getLeft != NULL && head->getRight == NULL){
            head = head->getLeft;
            delPtr->getLeft = NULL;
            delete delPtr;
            cout << "The root node with data "<< rootdata << " was deleted. " << "The new root contains data "<< head->data << endl;
        }
    else
    {
        smallestInRightSubTree = findSmallest(head->getRight);
        remove(smallestInRightSubTree, head);
        head->data = smallestInRightSubTree;
        cout << "The root data containing " << rootdata << " was overwritten with data " << head->data << endl;
    }
    }
    else{
        throw "Can remove root the tree is empty\n";
    }
}
void ariel::Tree::removeMatch(node* n,node* match,bool left){
    if(head != NULL){
        node* delPtr;
        int matchData = match->data;
        int smallestInRightSubTree;
        
        if(match->getLeft == NULL && match->getRight == NULL){
            delPtr = match;
            if(left == true){
                n->getLeft = NULL;
            }
            else{
                n->getRight = NULL;
            }
            delete delPtr;
            cout << "The node containing data " << matchData << " was removed\n";
        }
        else if(match->getLeft == NULL && match->getRight != NULL){
            if (left == true){
                n->getLeft = match->getRight;
            }else{
                n->getRight = match->getRight;
            }
            match->getRight = NULL;
            delPtr = match;
            delete delPtr;
            cout << "The node containing data " << matchData << " was removed\n";
        }
        else if(match->getLeft != NULL && match->getRight == NULL){
            if (left == true){
                n->getLeft = match->getLeft;
            }else{
                n->getRight = match->getLeft;
            }
            match->getLeft = NULL;
            delPtr = match;
            delete delPtr;
            cout << "The node containing data " << matchData << " was removed\n";
        }
        else{
            smallestInRightSubTree = findSmallest(match->getRight);
            remove(smallestInRightSubTree,match);
            match->data = smallestInRightSubTree;
        }
    }
}
*/
//INSERT
void ariel::Tree::insert(int i){
	cout << "used insert for " << i << endl;
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
        throw "The key has already been added to the tree\n";
    }
}
//FIND
int ariel::Tree::findSmallest(){
    return findSmallest(head);
}
int ariel::Tree::findSmallest(node* n){
    if(head == NULL){
        throw "Failed to find smallest number";//ERROR
    }
    if(n->getLeft != NULL){
        return findSmallest(n->getLeft);
    }else{
        return n->data;
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
	cout << "used right for " << i << endl;
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
	cout << "used left for " << i << endl;
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
	cout << "used parent for " << i << endl;
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
    cout << "printing tree..." << endl;
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
