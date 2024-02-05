#include "Dog.h"

#include <iostream>
using namespace std;


int add_one(int x)
{
    
    return x+1;
}

void print_bear()
{
    cout << "bear" << endl;
}
void prints(string x)
{
  
    cout << x << endl;
    
}
void printi(int x)
{
  
    cout << x << endl;
}
int multiply(int k)
{
    return k*10;
}

int main()
{
    Dog ;    

    Dog carl(20);
    
    // cout << carl.x << endl;
    // cout << sex.x << endl;

    int var = 5;
    var = add_one(var);
    cout << var << endl;
    cout << add_one(9059782) << endl;
    prints("Hello");
    int num = 1242;
    num = multiply(num);
    printi(num);


    print_bear();

    return 0;
}   