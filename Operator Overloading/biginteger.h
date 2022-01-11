/*
   File: biginteger.h
   Description: header file for BigInteger class.
   Created: Friday March 20, 2020
   Author: Tim Chester
   Email: chestertt@student.vvc.edu
*/

#ifndef BIGINTERGER_H
#define BIGINTERGER_H

#include<vector>
#include<string>
#include<iostream>

class BigInteger
{
private:
	std::vector<int> digits;

public:
	BigInteger();
	/**
	constructor takes a string of integers and converts them to an array of integers with single digits
	@param string of integers
	*/
	BigInteger(std::string); 


	std::string get_digits() const; //@return returns digits as a string
	/**
	returns indexed variables of a BigInteger object
	@param takes an integer for the index of the array
	@return returns the indexed variable
	*/
	int get_a_digit(int index) const; 

	int get_size() const; //@return returns the size of the array in a BigInteger object

	void insert(int in); //@param integer to insert into the beginning of the array in a BigInteger
	void set_size(int length); //@param sets the size of the array in BigInteger
	void set_place(int place); //@param sets the place for multiplication

	/**
	the following functions are operator overloads for the BigInteger object
	*/
	BigInteger operator+(BigInteger& x);
	BigInteger operator-(BigInteger& x);
	BigInteger operator*(BigInteger& x);

	void zero_be_gone(); //removes leading zeroes

	friend std::ostream& operator<<(std::ostream& out, const BigInteger& x); //output operator overload for BigInteger
};

#endif