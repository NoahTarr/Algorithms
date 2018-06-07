// Here is the file binarytree.cpp

#include <iostream>
#include "LL.h"
#include "binarytree.h"
using namespace std;



binarytree::binarytree()
{
    root = nullptr;
}




binarytree::binarytree(binarytree & copy)
{
    clone_aux(root, copy.root);
    mSize = copy.mSize;
}




binarytree::~binarytree()
{
    clear();
}




binarytree binarytree::operator=(const binarytree& copy)
{
    clone_aux(root, copy.root);
    mSize = copy.mSize;
    return *this;
}




void binarytree::print() const
{
    print_aux(root);
}




void binarytree::insert(const int item)
{
    insert_aux(root, item);
    mSize++;
}




binarytree::size_type binarytree::size() const
{
    return mSize;
}




int binarytree::find(int target, bool& found) const
{
    return find_aux(root, target, found);
}




void binarytree::del(int target, bool& found)
{
    del_aux(root, target, found);
    if (found)
    {
        mSize--;
    }
}




int binarytree::numPrimes() const
{
    int numPrimes = 0;
    numPrimes_aux(root, numPrimes);
    return numPrimes;
}




LL<int> binarytree::toLL()
{
    LL<int> temp;
    toLL_aux(root, temp);
    return temp;
}




void binarytree::clone(const binarytree& copy)
{
    clear_aux(root);
    clone_aux(root, copy.root);
    mSize = copy.mSize;
}




void binarytree::clear()
{
    clear_aux(root);
    root = nullptr;
    mSize = 0;
}





/****************
* Auxilary Functions
****************/

void del_aux(binarytree::treenode*& root,
             int target,
             bool& found)
{

    if (root == nullptr)
    {
        found = false;
    }
    else if (target < root->data)
    {
        del_aux(root->left, target, found);
    }
    else if (target > root->data)
    {
        del_aux(root->right, target, found);
    }
    else if (root->left == nullptr)
    {
        binarytree::treenode* tempptr = root;
        root = root->right;
        delete tempptr;
        found = true;
    }
    else
    {
        int max;
        remove_max(root->left, max);
        root->data = max;
        found = true;
    }
}




void remove_max(binarytree::treenode*& root, int& max)
{
    if (root->right == nullptr)
    {
        max = root->data;
        binarytree::treenode* tempptr = root;
        root = root->left;
        delete tempptr;
    }
    else
    {
        remove_max(root->right, max);
    }
}




int find_aux(binarytree::treenode* root,
             int target,
             bool& found)
{

    if (root == nullptr)
    {
        found = false;
        return 0;
    }
    else if (target == root->data)
    {
        found = true;
        return root->data;
    }
    else if (target < root->data)
    {
        return find_aux(root->left, target, found);
    }
    else
    {
        return find_aux(root->right, target, found);
    }
}




void insert_aux(binarytree::treenode*& root, int item)
{
    if (root == nullptr)
    {
        // root = new treenode(item, nullptr, nullptr);
        root = new binarytree::treenode;
        root->data = item;
        root->left = nullptr;
        root->right = nullptr;
    }
    else if (item <= root->data)
    {
        insert_aux(root->left, item);
    }
    else
    {
        insert_aux(root->right, item);
    }
}




void print_aux(binarytree::treenode* root)
{
    if (root != nullptr)
    {
        print_aux(root->left);
        cout << root->data << " ";
        print_aux(root->right);
    }
}




void numPrimes_aux(binarytree::treenode* root, int& numPrimes)
{
    if (root != nullptr)
    {
        if (isPrime(root->data))
        {
            numPrimes++;
        }
        numPrimes_aux(root->right, numPrimes);
        numPrimes_aux(root->left, numPrimes);
    }
}




bool isPrime(const int target)
{
    int temp = target;
    if (target < 0)
    {
        temp *= -1;
    }
    if (target <= 1)
    {
        return false;
    }
    else if (target <= 3)
    {
        return true;
    }
    else if (target % 2 == 0)
    {
        return false;
    }
    else
    {
        int divisor = 3;
        double temp = static_cast<double>(target);
        int limit = static_cast<int>(sqrt(temp) + 1);

        while (divisor <= limit)
        {
            if (target % divisor == 0)
            {
                return false;
            }
            divisor += 2;
        }
        return true;
    }
}




void toLL_aux(binarytree::treenode *& root, LL<int> & newLL)
{
    if (root != nullptr)
    {
        toLL_aux(root->right, newLL);
        newLL.push_front(root->data);
        toLL_aux(root->left, newLL);
    }
}




binarytree::treenode* clone_aux(binarytree::treenode*& root, const binarytree::treenode* copy)
{
    if (copy != nullptr)
    {
        root = new binarytree::treenode;
        root->data = copy->data;
        root->left = clone_aux(root->left, copy->left);
        root->right = clone_aux(root->right, copy->right);
        return root;
    }
}




void clear_aux(binarytree::treenode *& root)
{
    if (root != nullptr)
    {
        clear_aux(root->left);
        clear_aux(root->right);
        delete root;
    }
}
