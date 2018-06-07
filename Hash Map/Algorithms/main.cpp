#include <iostream>
#include <algorithm>
#include "Hash.h"

using namespace std;

int binarySearch(int searchThis[], int findThis, int size);

int main()
{
    Hash hashTable(10);

    hashTable.addItem("Noah", 20);
    hashTable.addItem("Chris", 42);
    hashTable.addItem("Niki", 12);

    hashTable.dumpText();
    
    cout << endl << endl;
    hashTable.removeItem("Noah", 20);
    hashTable.removeItem("Niki", 12);
    hashTable.removeItem("Chris", 42);
    hashTable.addItem("Chris", 42);

    hashTable.dumpText();


    system("PAUSE");
    return 0;
}