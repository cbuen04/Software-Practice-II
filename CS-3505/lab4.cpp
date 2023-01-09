// #include <iostream>

// int main(){

//     int vals[] = {1, 2, 3};

//     std::cout<< vals[3] << std::endl;

//     int* hVals = new int[3];
//     hVals[3] = 19;

//     std::cout<< hVals[3] << std::endl;

// }

#include <iostream>

int* getIntPtr();

int main() {
  int* val = new int(4);
  int* same_mem = val;

 // std::cout << val << " " << same_mem << std::endl;
    int* ptr = getIntPtr();
    std::cout << ptr << " " << *ptr << std::endl;

  delete val;
  //delete same_mem;

}

// int* getIntPtr() {
//     int number = 5;
//     return &number;
// }

int* getIntPtr() {
    int number = 5;
    int* ptr = &number;
    return ptr;
}