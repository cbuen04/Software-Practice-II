#include <iostream>
using namespace std;

int main(){
    int* z = new int;
    *z = 1;
    cout << *z << endl; // 1
    int *y = z;
    cout << *y << " " << *z << endl; // 1 1
    *z = *z + 1;
    cout << *y << " " << *z << endl; // 2 2
    int x = *y;
    cout << x << " " << *y << " " << *z << endl; // 2 2 2
    x++;
    cout << x << " " << *y << " " << *z << endl; // 3 2 2
    *y = *y + 1;
    cout << x << " " << *y << " " << *z << endl; // 3 3 3

    delete z;

}