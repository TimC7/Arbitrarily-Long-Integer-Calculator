/*
   File: biginteger.cpp
   Description: implementation of BigInteger class
   Created: Friday March 20, 2020
   Author: Tim Chester
   Email: chestertt@student.vvc.edu
*/

#include "biginteger.h"

BigInteger::BigInteger()
{

}
BigInteger::BigInteger(std::string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		int digit = str.at(i) - '0';
		digits.push_back(digit);
	}
}

std::string BigInteger::get_digits() const
{
	std::string str = "";
	for (int i = 0; i < digits.size(); i++)
	{
		str += std::to_string(digits[i]);
	}
	return str;
}

int BigInteger::get_a_digit(int index) const
{
	return digits[index];
}

int BigInteger::get_size() const
{
	return digits.size();
}

void BigInteger::insert(int in)
{
	digits.insert(digits.begin(), in); 
}

void BigInteger::set_size(int size)
{
	digits.clear();
	int i = 0;
		while (i < size)
		{
			digits.push_back(0);
			i++;
		}
	
}

//similar to set_size except it does not have ".clear()" 
void BigInteger::set_place(int place)
{
	int i = 0;
	while (i < place)
	{
		digits.push_back(0);
		i++;
	}
}

BigInteger BigInteger::operator+(BigInteger& x)
{
	//set length equal to each other with leading zeroes in the smaller one
	if (digits.size() > x.get_size())
	{
		while (digits.size() != x.get_size())
		{
			x.insert(0);
		}
	}

	if (digits.size() < x.get_size())
	{
		while (digits.size() != x.get_size())
		{
			digits.insert(digits.begin(), 0);
		}
	}

	BigInteger sum("");
	sum.set_size(digits.size());

	int carry = 0;

	for (int i = digits.size() - 1; i >= 0; i--)
	{
		sum.digits[i] = x.get_a_digit(i) + digits[i];
		sum.digits[i] += carry;
		carry = 0;
		
		if (i != 0 && sum.digits[i] >= 10) //splits the digit and carries the 1 for the addition of the next indexed variables
		{
			sum.digits[i] -= 10;
			carry++;
		}
		if (i == 0) //loop to deal with splitting and saving the final digits on the leftmost side
		{
			int last = 0;

			last = sum.digits[i] / 10;
			sum.digits[i] %= 10;
			
			sum.insert(last);
		}
	}
	sum.zero_be_gone();
	return sum;
}

/*
left side argument must be larger than right side argument. To fix, compare BigIntergers to find the one with higher value, make that one the left argument
then subtract, and, if the right argument was originally the higher number of the two, then add a negative sign to the front of the difference
*/
BigInteger BigInteger::operator-(BigInteger& x)
{
	if (digits.size() > x.get_size())
	{
		while (digits.size() != x.get_size())
		{
			x.insert(0);
		}
	}

	if (digits.size() < x.get_size())
	{
		while (digits.size() != x.get_size())
		{
			digits.insert(digits.begin(), 0);
		}
	}

	BigInteger difference("");
	difference.set_size(digits.size());
	
	int carry = 0;
	for (int i = digits.size() - 1; i >= 0; i--)
	{
		if (digits[i] < x.get_a_digit(i))
		{
			digits[i] += 10;
			carry++;
		}
		if (i != 0)
		{
			digits[i-1] -= carry;
		}
		difference.digits[i] = digits[i] - x.get_a_digit(i);
		carry = 0;
	}

	difference.zero_be_gone();
	return difference;
}


BigInteger BigInteger::operator*(BigInteger& x)
{
	BigInteger product(""), buffer("");
	

	if (digits.size() > x.get_size())
	{
		while (digits.size() != x.get_size())
		{
			x.insert(0);
		}
	}

	if (digits.size() < x.get_size())
	{
		while (digits.size() != x.get_size())
		{
			digits.insert(digits.begin(), 0);
		}
	}

	int place = 0, carry = 0;

	for (int i = digits.size() - 1; i >= 0; i--)
	{
		buffer.set_size(digits.size());

		for (int j = digits.size() - 1; j >= 0; j--)
		{
			
			buffer.digits[j] = (x.get_a_digit(i) * digits[j]) + carry;
			
			carry = 0;

			if (buffer.digits[j] >= 10 && j != 0)
			{
				carry = buffer.digits[j] / 10;
				
				buffer.digits[j] %= 10;
			}
			if (j == 0) 
			{	
					int last = 0;

					last = buffer.digits[j] / 10;
					buffer.digits[j] %= 10;

					buffer.insert(last);
					if (place > 0)
					{
						buffer.set_place(place);
					}
			}
		}
		place++;

		product = product + buffer;
	}
	product.zero_be_gone();
	return product;
}

void BigInteger::zero_be_gone()
{
	int i = 0;
	while (digits[i] == 0)
	{
		digits.erase(digits.begin() + i);
	}
}

std::ostream& operator<<(std::ostream& out, const BigInteger& x)
{
	out << x.get_digits();
	return out;
}


 