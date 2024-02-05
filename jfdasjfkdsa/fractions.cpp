#include <iostream>

using namespace std;

class Fraction {
    private:
    int _numerator;
    int _denominator;
    public:
    Fraction();
    ~Fraction();

    //setters
    void setNumerator(int);
    void setDenominator(int);
};

int main(int argc, char* argv[])
{
    Fraction frac1;
    Fraction frac2;

    return 0;

}

Fraction::Fraction()
{
_numerator = 0;
_denominator = 1;
}
Fraction::~Fraction()
{

}

// void setNumerator(int);
// {
//     _numerator = numerator;
// }
// void setDenominator(int);
// {
//     while (denominator == 0)
//     {
//         cout << "The denominator must not equal zero"
//     }
// }