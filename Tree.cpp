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
            cout << "Deleteing the node containing key " << n->data << endl;
            delete n;
        }
    }
    //CREATE NODE
    node* ariel::Tree::createLeaf(int i){
        node* n = new node;
        n->data = i;
        n->getLeft = NULL;
        n->getRight = NULL;
        return n;
    }
    
//REMOVE
void ariel::Tree::remove(int i){
    remove(i,head);
    total--;
}
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
        cout <<"The tree is empty\n";
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
//INSERT
void ariel::Tree::insert(int i){
    insert(i,head);
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
    if(head != NULL){
        if (n->getLeft != NULL){
            printInOrder(n->getLeft);
        }
        cout << n->data << " ";
        if (n->getRight != NULL){
            printInOrder(n->getRight);
        }
    }
    else{
        cout << "The tree is empty";
    }
}