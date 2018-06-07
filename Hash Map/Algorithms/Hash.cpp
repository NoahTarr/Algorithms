#include <iostream>
#include "Hash.h"
#include <locale>
#include <algorithm>

Hash::Hash()
{
    hashCapacity = 10;
    hashMap = new node*[hashCapacity];
}

Hash::Hash(int size)
{
    this->hashCapacity = size;
    hashMap = new node*[hashCapacity];
    for (int i = 0; i < size; ++i)
    {
        node* newNode = new node;
        hashMap[i] = newNode;
    }
}

int Hash::indexItem(std::string name) const
{
    std::transform(name.begin(), name.end(), name.begin(), ::tolower);
    name[0] = toupper(name[0]);
    int index = 0;
    for (int i = 0; i < name.size(); ++i)
    {
        index += static_cast<int>(name[i]);
    }
    return index % hashCapacity;
}

void Hash::addItem(std::string name, int age) const
{
    int key = indexItem(name);
    node* newNode = new node(name, age);
    if (hashMap[key]->name.empty())
    {
        hashMap[key] = newNode;
    }
    else
    {
        node* crntNode = hashMap[key];
        while (crntNode->next != nullptr)
        {
            crntNode = crntNode->next;
        }
        crntNode->next = newNode;
    }
}

bool Hash::removeItem(const std::string& name, const int age) const
{
    std::string nameToCheck = name;
    std::transform(nameToCheck.begin(), nameToCheck.end(), nameToCheck.begin(), ::tolower);
    nameToCheck[0] = toupper(nameToCheck[0]);
    int key = indexItem(nameToCheck);
    node* crntNode = hashMap[key];
    node* prevNode = crntNode;

    while (crntNode->name != nameToCheck || crntNode->age != age)
    {
        prevNode = crntNode;
        crntNode = crntNode->next;
        if (!crntNode)
        {
            return false;
        }
    }

    if (crntNode->name != nameToCheck || crntNode->age != age) //Node with given nameToCheck and age doesnt exist
    {
        return false;
    }

    if (crntNode == prevNode)
    {
        if (!crntNode->next)   //Only 1 node in list
        {
            hashMap[key] = new node;
        }
        else   //First node in list
        {
            hashMap[key] = crntNode->next;   
        }
        delete(crntNode);
    }
    else if (!crntNode->next)   //Last node in list
    {
        prevNode->next = nullptr;
        delete(crntNode);
    }
    else if (crntNode->next) //Node in middle of list
    {
        prevNode->next = crntNode->next;
        delete(crntNode);
    }
    return true;
}

void Hash::dumpText() const
{
    for (int i = 0; i < hashCapacity; i++)
    {
        node* crntNode = this->hashMap[i];
        while (crntNode)
        {
            if (crntNode->age != -1)
            {
                std::cout << "Name: " << crntNode->name << ", Age: " << crntNode->age << ", Key: " << i << std::endl;
            }
            crntNode = crntNode->next;
        }
    }
    
}