
#include <iostream>
#include <string>
#include <sstream>
#include "stack.h"

using namespace std;

double evaluateRPN(string expression)
{

    Stack stack;
    stringstream ss(expression);
    string line;
    
    while (ss >> line)
    {
        //for this if statment i used chat GPT to tell me how to tell if the input is a number of its a symbol and to set it to a double to be added together properly/
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


int main(int argc, char *argv[])
{
    string inputline;
    cout << "Enter String to Parse: ";
    getline(cin,inputline);
    cout << "The answer is: "<< evaluateRPN(inputline )<< endl;
    return 0;
}
