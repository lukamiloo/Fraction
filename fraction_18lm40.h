//
// Created by lmilo on 2021-10-19.
// Luka Milosevic 20170844 18lm40
//

#ifndef ASSIGNMENT2_FRACTION_18LM40_H
#define ASSIGNMENT2_FRACTION_18LM40_H
#include "fraction_18lm40.h"

using namespace std;

class Fraction {
public:
    int numerator() const;//numerator getter function
    int denominator() const;//denominator getter function
    void simplify();//simplify function for fractions if needed
    //constructors
    Fraction(int n = 0);//traditional constructor with default 0 and just one numerator as input
    Fraction(int n, int d);//constructor with two int input
    Fraction(Fraction const& f);//copy constructor
    //member operator overloads
    Fraction& operator-();
    Fraction& operator++();//post increment operator ++ overloadFraction& operator+= (Fraction const& f);//Fraction + int operator overload
    Fraction operator++(int);//overload ++ pre increment operator
    Fraction& operator+= (int i);//plus equals overload fraction += int
    Fraction& operator+= (const Fraction& f);//plus equals overload fraction += fraction

private:
    int num, denom;//instance variables

    friend ostream& operator<<(ostream& os, const Fraction& f);//output operator overload <<
    friend istream& operator>>(istream& is, Fraction& f);//input operator overload >>
};
//non member operator overloads
Fraction operator/ (const Fraction& a, const Fraction& b);// division operator overload /
Fraction operator* (const Fraction& a, const Fraction& b);//multiplication operator overload *
Fraction operator- (const int i, const Fraction& f);//subtraction operator overload int - fraction
Fraction operator- (const Fraction& f, const int i);//subtraction operator overload fraction - int
Fraction operator- (const Fraction& a, const Fraction& b);//subtraction operator overload fraction - fraction
Fraction operator+ (const Fraction& a, const Fraction& b);//2 fraction addition operator overload
Fraction operator+ (const int i, const Fraction& f);// fraction addition operator overload int + fraction
Fraction operator+ (const Fraction& f, const int i);// fraction addition operator overload fraction + int

bool operator== (const Fraction& a, const Fraction& b);//equals operator overload for Fraction
bool operator!= (const Fraction& a, const Fraction& b);//inequality operator overload for Fraction
bool operator> (const Fraction& a, const Fraction& b);//greater than operator overload for Fraction > Fraction
bool operator> (const Fraction& f, const int i);//greater than operator overload for Fraction > int
bool operator> (const int i, const Fraction& f);//greater than operator overload for int > Fraction
bool operator>= (const Fraction& a, const Fraction& b);//greater than-equality operator  overload for Fraction >= Fraction
bool operator< (const Fraction& a, const Fraction& b);//less than operator overload for Fraction < Fraction
bool operator< (const int i, const Fraction& f);//less than operator overload for int < Fraction
bool operator< (const Fraction& f, const int i);//less than operator overload for Fraction < int
bool operator<= (const Fraction& a, const Fraction& b);//less than-equality operator overload for Fraction <= Fraction

class FractionException{//fraction exception for invalid denominators(zero)
public:
    FractionException(const string& message);//constructor
    string& what();//exc what function
private:
    string message;//message variable
};
#endif //ASSIGNMENT2_FRACTION_18LM40_H
