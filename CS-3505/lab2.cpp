#include<iostream>
using std::cout;
using std::endl;

class Cat{

    private:
        int lives{13};

public:
    Cat(int l) : lives(l){

    }

    void loseLives(){
        lives--;
    }

    void reportLives(){
        cout << lives << endl;
    }

    Cat& operator+=(int newlives){
        lives = newlives + lives;
        return *this;
    }

};

int main(){
    Cat myCat(9);
    myCat.reportLives();
    myCat.loseLives();
    myCat.reportLives();
    myCat += 1;
    myCat.reportLives();
    (myCat += 3) += 2;
    myCat.reportLives();
    
}