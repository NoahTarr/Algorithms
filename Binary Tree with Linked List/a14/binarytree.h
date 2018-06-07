// Here is the file binarytree.h

#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <cstdlib>	// for size_t
#include "LL.h"

class binarytree
{

public:
    typedef std::size_t size_type;
    binarytree();
    binarytree(binarytree & copy);
    ~binarytree();
    binarytree operator=(const binarytree& copy);
    void insert(const int item);
    void print() const;
    size_type size() const;
    int find(int target, bool& found) const;
    void del(int target, bool& found);
    int numPrimes() const;
    LL<int> toLL();
    void clone(const binarytree& copy);
    void clear();

private:
    struct treenode
    {
        int data;
        treenode* left;
        treenode* right;
    };

    treenode* root;
    int mSize = 0;
    friend void insert_aux(treenode*& root, int item);
    friend void print_aux(treenode* root);
    friend int find_aux(treenode* root, int target, bool& found);
    friend void del_aux(treenode*& root, int target, bool& found);
    friend void remove_max(treenode*& root, int& max);
    friend void numPrimes_aux(treenode* root, int& numPrimes);
    friend bool isPrime(const int target);
    friend void toLL_aux(treenode*& root, LL<int> & newLL);
    friend treenode* clone_aux(treenode*& root, const treenode* copy);
    friend void clear_aux(treenode*& root);
};
#endif
