/*
   File: main.cpp
   Description: program stores arbitrarily large integers by keeping their digits in a vector<int>. 
            Also allows for the addition, subtraction, and multiplication of these numbers.
   Created: Friday March 20, 2020 
   Author: Tim Chester
   Email: chestertt@student.vvc.edu
*/

#include <iostream>
#include "biginteger.h"

int main()
{
    //any numbers can be input (as long as the first is larger than the second), but these are the test values
    BigInteger a("97878594769475876213"), b("18493658776543987"); //They also have a different number of digits. 

    std::cout << "The two BigIntegers are   a:   " << a << "   and b:   " << b << std::endl
        << "The sum of these numbers is:   " << a + b << std::endl
        << "The difference of these numbers is:   " << a - b << std::endl
        << "The product of these numbers is:   " << a * b << std::endl;

    return 0;
}