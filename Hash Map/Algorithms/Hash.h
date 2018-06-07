#pragma once
#ifndef HASH_H
#define HASH_H
#include <string>
#include <algorithm>

class Hash
{
private:
    struct node
    {
        std::string name;
        int age;
        node* next;

        node(std::string name = "", int age = -1, node* next = nullptr)
        {
            std::transform(name.begin(), name.end(), name.begin(), ::tolower);
            name[0] = toupper(name[0]);
            this->name = name;
            this->age = age;
            this->next = next;
        }
    };
    node** hashMap;
    int hashCapacity;

    int indexItem(std::string name) const;

public:
    Hash();
    Hash(int size);
    void addItem(std::string name, int age) const;
    bool removeItem(const std::string& name, const int age) const;
    void dumpText() const;

    
};

#endif