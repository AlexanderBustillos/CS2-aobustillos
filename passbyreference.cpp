#include <iostream>

using namespace std;

void getNums(int&,int&);
void addNums(int,int,int&);

int main(int argc,char* argv[])
{
    int number1,number2,result;
    int* ptr1, *ptr2, *ptr3;

    ptr1 = &number1;
    ptr2 = &number2;
    ptr3 = &result;
    getNums(number1,number2);
    addNums(number1,number2, result);
    return 0;
}

void getNums(int& n1,int& n2)
{
    cout << "";
    cin>>n1>>n2;
}

void addNums(int num1, int num2, int& sum)\
{
    num1 + num2 = sum;
}