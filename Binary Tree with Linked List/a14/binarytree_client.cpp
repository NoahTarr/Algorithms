#include <iostream>
#include "binarytree.h"
#include "LL.h"

using namespace std;

int main()
{
    binarytree t;
    binarytree x;
    for (size_t i = 0; i < 20; i++)
    {
        t.insert(rand()% 50 + 1);
    }

    t.print();
    cout << endl << "Before Clear: " << endl;
    x = t;
    cout << endl << "After Clone: " << endl;
    x.print();
    cout << endl;
    x.clear();
    cout << endl;
    cout << endl << "After Clone: " << endl;
    x.print();
    cout << endl;
    x = t;
    x.print();
    cout << endl;
    x.clone(t);
    x.print();
    x.clear();
    cout << endl;
    x.clone(t);
    x.print();
    cout << endl;
    t.print();
    cout << endl;
    cout << endl;
    cout << "t size: " << t.size() << endl;
    cout << "x size: " << x.size();
    cout << endl;


    


    system("PAUSE");
    return 0;
}