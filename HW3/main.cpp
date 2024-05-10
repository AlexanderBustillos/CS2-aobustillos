#include <cassert>
#include <iostream>
#include <string>
#include <sstream>
#include "stack.h"
#include <cmath>

using namespace std;

double evaluateRPN(string expression)
{

    Stack stack;
    stringstream ss(expression);
    string line;
    
    while (ss >> line)
    {
        //for this if statment i used chat GPT to tell me how to tell if the input is a number of its a symbol and to set it to a double to be added together properly
        if (isdigit(line[0]) || (line.size() > 1 && line[0] == '-' && isdigit(line[1])))
        {
            double number = stod(line); 
            stack.push(number); 
        }
        else if (line == "+" || line == "-" || line == "*" || line == "/")
        {
            if (stack.size() < 2)
            {
                cout << "Not enough numbers/symbols inputed" << endl;
                return NAN;
            }
            double number2 = stack.pop();
            double number1 = stack.pop();
            double total = 0.0;

            if (line == "+")
            {
                total = number1 + number2;
            }
            else if (line == "-")
            {
                total = number1 - number2;
            }
            else if (line == "*")
            {
                total = number1 * number2;
            }
            else if (line == "/")
            {
                if (number2 == 0)
                {
                    cout << "Error: Division by zero." << endl;
                    return NAN;
                }
                total = number1 / number2;
            }
            stack.push(total);
        }
        else
        {
            cout << "Does not work properley" << endl;
            return NAN;
        }
    }

    return stack.pop();
}
void tests();

int main(int argc, char *argv[])
{
    if(argc >= 2 && (string)argv[1] == "test")
    {
        tests();
        return 0;
    }
    
    
    string inputline;
    cout << "Enter String to Parse: ";
    getline(cin,inputline);
    cout << "The answer is: "<< evaluateRPN(inputline )<< endl;
    return 0;
}
void tests()
    {
    assert(evaluateRPN("3 4 + 5 6 + +") == 18);
    // there is some sort of problem with sotring floats and setting them equal to eachother and im not sure how to fix it
    assert(abs(evaluateRPN("7 5 + 1 42 / +") - 12.0238) <= .00001);
    assert(evaluateRPN("2 5 + 2 - 8 9 + +") == 22);
    assert(evaluateRPN (" 1 2 +")== 3);
    cout << "All tests passed!" << endl;
    }
