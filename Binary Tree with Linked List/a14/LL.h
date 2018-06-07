//  This is the file LL.h

#ifndef LL_h
#define LL_h

#include <cstdio>

template <class T>
class LL
{
public:
    typedef size_t size_type;
    typedef T value_type;

private:
    struct node
    {
        value_type data;
        node* next;
    };
    node* list;


public:
    class iterator
    {
    public:
        iterator(node* initial = nullptr)
        {
            current = initial;
        }

        value_type& operator*() const
        {
            return current->data;
        }

        iterator& operator++()
        {
            current = current->next;
            return *this;
        }

        iterator operator++(int)
        {
            iterator original(current);
            current = current->next;
            return original;
        }

        bool operator==(iterator other) const
        {
            return current == other.current;
        }

        bool operator !=(iterator other) const
        {
            return current != other.current;
        }

        const node* link() const
        {
            return current;
        }

        node*& link()
        {
            return current;
        }

    private:
        node* current;
    };


    class const_iterator
    {
    public:
        const_iterator(const node* initial = nullptr)
        {
            current = initial;
        }

        const value_type& operator*() const
        {
            return current->data;
        }

        const_iterator& operator++()
        {
            current = current->next;
            return *this;
        }

        const_iterator operator++(int)
        {
            const_iterator original(current);
            current = current->next;
            return original;
        }

        bool operator==(const const_iterator other) const
        {
            return current == other.current;
        }

        bool operator !=(const const_iterator other) const
        {
            return current != other.current;
        }

        const node* link() const
        {
            return current;
        }

        node*& link()
        {
            return current;
        }
    private:
        const node* current;
    };  // end of iterator class declarations.  LL class continues below.

    iterator begin()
    {
        return iterator(list);
    }

    iterator end()
    {
        return iterator();
    }

    const_iterator begin() const
    {
        return const_iterator(list);
    }

    const_iterator end() const
    {
        return const_iterator();
    }

    class Empty_List_Error
    {
    };
    LL();
    LL(const LL& copyMe);
    LL operator=(const LL& right);
    ~LL();
    bool empty() const;
    size_type size() const;
    void clone(const LL& copyMe);
    void clear();
    void pop_front();
    void push_front(const value_type& item);
    value_type& front();
    const value_type& front() const;
    void insert_after(iterator& position, const value_type& insertMe);
    void delete_after(iterator& position);
};


#include "LL.cpp"
#endif