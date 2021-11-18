//
// Created by lmilo on 2021-10-19.
// Luka Milosevic 20170844 18lm40
//

#include <iostream>
#include <string>
#include <algorithm>
#include "fraction_18lm40.h"

using namespace std;
FractionException::FractionException(const string& message) : message(message){}

string& FractionException::what(){
    return message;
}
Fraction::Fraction(int n){//traditional constructor with default 0 and just one numerator as input
    num = n;
    denom = 1;
}

Fraction::Fraction(Fraction const& f){//copy constructor
    num = f.num;
    denom = f.denom;
}

Fraction::Fraction(int n, int d){//constructor with two int input
    int tempNum = n;
    int tempDenom = d;
    if(d < 0 && n > 0){// if d is negative -> set n to negative and d to positve
        tempNum = -n;
        tempDenom = -d;
    }
    else if(d < 0 && n < 0){//if both negative -> set both to positive
        tempNum = abs(n);
        tempDenom = abs(d);
    }
    else if(d == 0){//throwing exception if denominator is zero
        throw FractionException("Invalid Denominator.");
    }
    else{//if both postive -> keep original values
        tempNum  = n;
        tempDenom = d;
    }
    int gcd = __gcd(tempNum, tempDenom);//reducing fraction
    num = tempNum / abs(gcd);
    denom = tempDenom / abs(gcd);
}

int Fraction::numerator()const {//numerator getter function
    return num;
}

int Fraction::denominator()const {//denominator getter function
    return denom;
}

void Fraction::simplify(){//simplify function for fractions if needed
    for(int i = this->num * this->denom; i > 1; i--){//iterate through all possible divisors
        if((numerator() % i) == 0 && (this->denom % i) == 0){// divide by common divisors
            this->num = this->num / i;
            this->denom = this->denom / i;
        }
    }
}
Fraction& Fraction::operator-() {// overloading negating operator with no parameters
    if(this->num < 0 && this->denom > 0){//if num is negative and denom is positve -> negate num
        this->num = this->num * -1;
    }
    else if(this->denom < 0 && this->num > 0){//if both negative absolute value of both
        this->num = abs(this->num);
        this->denom = abs(this->denom);
    }
    else{
        this->num *= -1;//else negate num
    }
    return *this;//return by reference
}
Fraction& Fraction::operator++ (){//overload ++ post increment operator
    this->num += this->denom;
    return *this;
}

Fraction Fraction::operator++(int) {//pre-incrementing using post increment operator
    Fraction temp(*this);
    ++(*this);//pre increment
    return temp;
}

Fraction& Fraction::operator+=(const Fraction& f) {//plus equals overload fraction += fraction
    int tempaDenom = this->denom;
    int tempMulti = this->denom;//temp variable of a denominator to use for multiplication of b
    int tempbDenom = f.denominator();
    int tempaNum = this->num;
    int tempbNum = f.numerator();

    if(this->denom != f.denominator()){// setting denominators to match
        tempaNum *=tempbDenom;
        tempaDenom *= tempbDenom;
        //tempbDenom *= tempMulti;
        tempbNum *= tempMulti;
        tempaNum += tempbNum;
        Fraction temp(tempaNum, tempaDenom);
        temp.simplify();// simplifying temp fraction before returning
        this->num = temp.num;
        this->denom = temp.denom;
        return *this;

    }
    else{
        this->num = tempaNum + tempbNum;
        this->denom = tempaDenom;
        return *this;
    }
}

Fraction& Fraction::operator+=(int i){//plus equals overload fraction += int
    int tempaDenom = this->denom;
    Fraction Temp = (i, tempaDenom);
    Temp += *this;
    *this = Temp;
    return *this;
}


Fraction operator+(const Fraction& a, const Fraction& b) {//2 fraction addition operator overload
    int tempaDenom = a.denominator();
    int tempMulti = a.denominator();
    int tempbDenom = b.denominator();
    int tempaNum = a.numerator();
    int tempbNum = b.numerator();

    if(a.denominator() != b.denominator()){// setting denominators to match
        tempaNum *=tempbDenom;
        tempaDenom *= tempbDenom;
        //tempbDenom *= tempMulti;
        tempbNum *= tempMulti;
        tempaNum += tempbNum;
        Fraction temp(tempaNum, tempaDenom);
        temp.simplify();
        return temp;
    }
    else{
        return Fraction(tempaNum + tempbNum, tempaDenom);
    }

}

Fraction operator+(const int i, const Fraction& f){//overloading int - fraction operator
    int tempDenom;
    int tempNum;
    int iNum = i;
    if (iNum != f.denominator()){
        iNum *= f.denominator();
    }
    tempNum = iNum + f.numerator();
    tempDenom = f.denominator();
    return Fraction(tempNum,tempDenom);
}

Fraction operator+(const Fraction& f, const int i) {//overloading + operator with int parameter Fraction + int
    int tempDenom;
    int tempNum;
    int iNum = i;
    if (iNum != f.denominator()){
        iNum *= f.denominator();
    }
    tempNum = f.numerator() + iNum;
    tempDenom = f.denominator();
    return Fraction(tempNum, tempDenom);
}

Fraction operator-(const Fraction& a, const Fraction& b) {//2 fraction subtraction operator overload
    int tempaDenom = a.denominator();
    int tempMulti = a.denominator();
    int tempbDenom = b.denominator();
    int tempaNum = a.numerator();
    int tempbNum = b.numerator();

    if (a.denominator() != b.denominator()) {// setting denominators to match
        tempaNum *= tempbDenom;
        tempaDenom *= tempbDenom;
        //tempbDenom *= tempMulti;
        tempbNum *= tempMulti;
        tempaNum -= tempbNum;
        Fraction temp(tempaNum, tempaDenom);
        temp.simplify();
        return temp;
    } else {
        return Fraction(tempaNum - tempbNum, tempaDenom);
    }
}

Fraction operator-(const Fraction& f, const int i) {//overloading - operator with int parameter Fraction - int
    int tempDenom;
    int tempNum;
    int iNum = i;
    if (iNum != f.denominator()){
        iNum *= f.denominator();
    }
    tempNum = f.numerator() - iNum;
    tempDenom = f.denominator();
    return Fraction(tempNum, tempDenom);
}

Fraction operator-(const int i, const Fraction& f){//overloading int - fraction operator
    int tempDenom;
    int tempNum;
    int iNum = i;
    if (iNum != f.denominator()){
        iNum *= f.denominator();
    }
    tempNum = iNum - f.numerator();
    tempDenom = f.denominator();
    return Fraction(tempNum,tempDenom);
}

Fraction operator*(const Fraction& a, const Fraction& b) {//multiplication operator overload * fraction * fraction
    int tempDenom;
    int tempNum;
    tempNum = a.numerator() * b.numerator();//multiply numerators and denominators together
    tempDenom = a.denominator() * b.denominator();
    return Fraction(tempNum, tempDenom);
}

Fraction operator/(const Fraction& a, const Fraction& b) {// division operator overload / fraction / fraction
    int tempDenom;
    int tempNum;
    tempNum = a.numerator() * b.denominator();//cross multiply
    tempDenom = a.denominator() * b.numerator();
    return Fraction(tempNum, tempDenom);
}

bool operator== (const Fraction& a, const Fraction& b) {//equals operator overload for Fraction

    return a.numerator() * a.denominator() == a.numerator() * a.denominator();//multiply and equate when cross multiplied

}

bool operator!= (const Fraction& a, const Fraction& b) {//inequality operator overload for Fraction

    return a.numerator() * a.denominator() != b.numerator() * b.denominator();//multiply and equate when cross multiplied

}

ostream& operator<< (ostream& os, const Fraction& f){//output operator overload <<
    os << f.numerator() << '/' << f.denominator();// printing fraction with "/" in between numerator and denominator
    return os;
}

istream& operator>> (istream& is, Fraction& f){//input operator overload >>
    string in;
    is >> in;// setting input stream to a string variable to itterate through
    for(int x = 0; x < in.length(); x ++){// itterating through string input
        if(in[x] == '/'){//if "/" found-> set num and denom to variables on either side
            f.num = stoi(in.substr(0,x));
            f.denom = stoi(in.substr(x+1, in.length()-1));
            return is;
        }
    }
    f.num = stoi(in);//if no bracket take integer input from string using stoi()
    f.denom = 1;
    return is;
}

bool operator> (const Fraction& a, const Fraction& b) {//greater than operator overload for Fraction > Fraction
    return a.numerator() * b.denominator() > a.denominator() * b.numerator();
}

bool operator> (const Fraction& f, const int i) {//greater than operator overload for Fraction > int
    Fraction temp(i,f.denominator());//making temp fraction to utilize original overloaded operator
    return f > temp;
}

bool operator> (const int i, const Fraction& f) {//greater than operator overload for int > Fraction
    Fraction temp(i,f.denominator());//making temp fraction to utilize original overloaded operator
    return temp > f;
}

bool operator>= (const Fraction& a, const Fraction& b) {//greater than-equality operator  overload for Fraction >= Fraction
    return a.numerator() * b.denominator() >= a.denominator() * b.numerator();
}

bool operator< (const Fraction& a, const Fraction& b) {//less than operator overload for Fraction < Fraction
    return a.numerator() * b.denominator() < a.denominator() * b.numerator();
}

bool operator< (const int i, const Fraction& f) {//less than operator overload for int < Fraction
    Fraction temp(i,f.denominator());//making temp fraction to utilize original overloaded operator
    return temp < f;
}

bool operator< (const Fraction& f, const int i) {//less than operator overload for Fraction < int
    Fraction temp(i,f.denominator());//making temp fraction to utilize original overloaded operator
    return f < temp;
}

bool operator<= (const Fraction& a, const Fraction& b) {//less than-equality operator overload for Fraction <= Fraction
    return a.numerator() * b.denominator() <= a.denominator() * b.numerator();
}


