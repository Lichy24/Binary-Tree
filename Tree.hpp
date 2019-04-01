#ifndef TREE_HEADER
#define TREE_HEADER

struct node{
    int data;
    node* getLeft;
    node* getRight;
};
namespace ariel{
class Tree{
    public:
    Tree();
    ~Tree();
    node* createLeaf(int i);
    void insert(int i);
    void remove(int i);
    int size(){
        return total;
    }
    bool contains(int i);
    int root(){
        return head->data;
    }
    int parent(int i);
    int left(int i);
    int right(int i);
    void print();

    private:
    int total;
    node* head;
    void printInOrder(node* n);
    void insert(int i, node* n);
    node* remove(int i,node* n);
    int parent(int i,node* n);
    int left(int i,node* n);
    int right(int i,node* n);
    bool contains(int i,node* n);
    void removeRoot();
    void removeMatch(node* n,node* match,bool left);
    int findSmallest();
    int findSmallest(node* n);
    void removeSubtree(node* n);
    
};
};
#endif