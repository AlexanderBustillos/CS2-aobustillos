#include "fractions.h"

fractions::Fraction::Fraction(int numerator, int denominator)
{
    //I am making some constructors to be able to access these private variables
    _numerator = numerator;
    _denominator = denominator;
    // This is only for if both numbers are 0 i take in new numbers from the user, this is inherently flawed because if someone wants to add 0/0 and 0/0 then it wont work, i hope nobody does that
    if(_numerator == 0 && _denominator == 0)
    {
    cin >> _numerator;
    cin >> _denominator;
    }
    //if someone wants to divide by zero I cant allow it
    if(_denominator == 0)
    {
        cout << "Denominator cannot be zero"<< endl;
        cin >> _denominator;
    }
}

fractions::Fraction fractions::Fraction::operator+(fractions::Fraction const &frac)
{
    //VERY VERY MESSY, i am making a ton of tmp variavles to have a consistant numbers because i will be altering the numbers and need constants, some of these arnt neccesarry but I like them.
    int dentmp1 = 0;
    int dentmp2 = 0;
    int numtmp1 = 0;
    int numtmp2 = 0;
    int newNumerator = 0;
    int newDenominator = 0;
    int denominator1 = _denominator;
    int numerator1 = _numerator;
    int denominator2 = frac._denominator;
    int numerator2 = frac._numerator;
    // If both denominators are the same then i just need to add the numerators
    if (denominator1 == denominator2)
        {
            newNumerator = numerator1 + numerator2;
            newDenominator = denominator1;
        }
    else //if they arnt the same then i check if they are differnet, this is not needed because if they are not same they have to different
    {
        if( denominator1 != denominator2)
        {
            //where the mess starts
            dentmp1 = denominator1;
            dentmp2 = denominator2;
            numtmp1 = numerator1;
            numtmp2 = numerator2;
            //just multiplying the denominator of the second fraction to the first numerator and denominator and the denominator of the first fractions to the numerator and denominator of the second fraction
            numerator1 = numtmp1 * dentmp2;
            denominator1 = dentmp1 * dentmp2;
            numerator2 = numtmp2 * dentmp1;
            denominator2 = dentmp2 * dentmp1;
        }
        //then i add the numerators together and set the denominator to one of the denominators that i mutiplied, doesnt matter which one 
        newNumerator = numerator1 + numerator2;
        newDenominator = denominator2;
    }
    //I am returning the fractions function inside a functions, and am simplifying the fraction in a form of a fraction, hard to explain
    return frac.simplify(Fraction(newNumerator, newDenominator));
}

fractions::Fraction fractions::Fraction::operator-(fractions::Fraction const &frac)
{
    //everything is the exact same but the multiplication is made better
    int tmp = 0;
    int newNumerator = 0;
    int newDenominator = 0;
    int denominator1 = _denominator;
    int numerator1 = _numerator;
    int denominator2 = frac._denominator;
    int numerator2 = frac._numerator;
    
    if (denominator1 == denominator2)
        {
            newNumerator = numerator1 - numerator2;
            newDenominator = denominator1;
        }
    else 
    {
        if( denominator1 != denominator2)
        {
            // this time there is only 1 tmp and its the only neccesary one
            tmp = denominator1;
            numerator1 = numerator1 * denominator2;
            denominator1 = denominator1 * denominator2;
            numerator2 = numerator2 * tmp;
            denominator2 = numerator2 *tmp;
        }
        newNumerator = numerator1 - numerator2;
    
        newDenominator = denominator1;
    }

    return frac.simplify(Fraction(newNumerator, newDenominator));
    
}

fractions::Fraction fractions::Fraction::operator*(Fraction const &frac)
{
    int newNumerator = 0;
    int newDenominator = 0;
    int denominator1 = _denominator;
    int numerator1 = _numerator;
    int denominator2 = frac._denominator;
    int numerator2 = frac._numerator;
    //just multiplying the numbers together then simplyfing 
    newNumerator = numerator1 * numerator2;
    newDenominator = denominator1 * denominator2;
    return frac.simplify(Fraction(newNumerator, newDenominator));
}

fractions::Fraction fractions::Fraction::operator/(Fraction const &frac)
{
    int newNumerator = 0;
    int newDenominator = 0;
    int denominator1 = _denominator;
    int numerator1 = _numerator;
    int denominator2 = frac._denominator;
    int numerator2 = frac._numerator;
    //this time i am doing copy dot flip, i copy the first fraction, then multply by the flip of the second fraction
    newNumerator = numerator1 * denominator2;
    newDenominator = denominator1 * numerator2;
    return frac.simplify(Fraction(newNumerator, newDenominator));
}

fractions::Fraction fractions::Fraction::simplify(Fraction frac)
{
    //I make the fraction that will be returned
    int newNumerator = 0;
    int newDenominator = 0;;
    //I create a value to store the greatest common divisor 
    int gcd;
    //then i get the greatest common diviser of the inputed fraction
    gcd=frac.gcd(frac._numerator, frac._denominator);
    //now i divide the fractions numerator and denominator by the gcd to get the simplified form
    newNumerator = frac._numerator/gcd;
    newDenominator = frac._denominator/gcd;

    //then i return these new numbers 
    return Fraction(newNumerator, newDenominator);
}
//is this meant to be here? scary 
void fractions::Fraction::simplify()
{
}

int fractions::Fraction::gcd(int a, int b)
{
    //making my variables min to get the smallest number of the 2
    int min =0;
    // i for an index
    int i =0;
    //I did abs because if num a is -10 and num b is 2, -10 is the smaller number but we want to divide by 2 because thats technically the smallest number we want
    int num = abs(a);
    int den = abs(b);
    //if the numerator is less then the denominator then set it as the min, else set the min to the den
    if( num < den)
    {
        min = num;
    }
    else 
    {
        min = den;
    }
    //the index is now set to the smallest number
    i = min;
    //while the index is less then or equal to the minimum, this doesnt matter becasue you want an infinite loop untill you get the gcd
    while(i <= min)
    {
        // cout << "DEBUG2"<<endl;
        if(num%i==0 && den%i==0)
        {
            return i;
        }
        //decriment to keep going
        i--;
    }
    //if for some reason it doesnt find the gcd just return 0 to make the computer happy
    return 0;
}

bool fractions::Fraction::operator==(Fraction const &frac)
{
    //make a flag to change 
    bool flag = false;
    //first i simplify the fractions just in case something like 1/10 and 2/20 is inputted, they mean the same thing but have different numbers
    simplify(Fraction(_numerator,_denominator));
    simplify(Fraction(frac._numerator, frac._denominator));
    //if they are equal then change the flag to true and return the flag
    if(_numerator == frac._numerator && _denominator == frac._denominator)
    {
        flag = true;
    }
    
    return flag;
}

ostream &fractions::operator<<(ostream &os, const Fraction &frac)
{
    //once the number is displayed i check a few things
    // if the numerator and the denominator are both equal to one then that means its 1 and then just output the numerator
    if(frac._numerator == 1 && frac._denominator == 1) 
    {
        os << frac._numerator;

    }
     //if the denominator is equal to one then that means i can just output the numerator
    else if(frac._denominator == 1)
    {
        os << frac._numerator;
    }
    //if the numerator is equal to 0 then i can just output the numerator
    else if (frac._numerator == 0)
    {
        os << frac._numerator;
    }
    //then if none of these apply just output it.
    else
    {
     os << frac._numerator<< "/"<< frac._denominator;
    }
    return os;
}
