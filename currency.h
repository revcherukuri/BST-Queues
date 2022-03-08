#pragma once
/*
@Lab: Lab 5 Binary Search Trees
@Author: Casey Merritt, Revanth Cherukuri
@Purpose: Implementation of the currency class
*/

#pragma once
#include <iostream>
#include <string>

class currency
{
protected:
	int Whole;
	int Part;
public:
	currency();
	~currency();
	/*method gets the value of Whole
	Pre:
	Post:
	Return: returns the variable Whole
	*/
	int getWhole();

	/*method gets the value of Part
	Pre:
	Post:
	Return: returns the variable Part
	*/
	int getPart();

	/*method sets the value of Whole
	Pre:passes value
	Post:sets whole to x
	Return:
	*/
	void setWhole(int x);

	/*method sets the value of part
	Pre:passes value x
	Post:
	Return:
	*/
	void setPart(int x);

	/*method is an overloading function that will return currency note name
	Pre:
	Post:
	Return: Returns the value of currency note from child class
	*/
	virtual std::string getNoteName();

	/*method is an overloading function that will return currency coin name
	Pre:
	Post:
	Return: Returns the value of currency coin from child class
	*/
	virtual std::string getCoinName();

	/*method is an overloading operator allowing for the addition of currency classes
	Pre:passes const currency object by reference
	Post:
	Return: Returns a new currency class with addition included
	*/
	virtual currency operator+(const currency& x);

	/*method is an overloading operator allowing for the subtraction of currency classes
	Pre: passes const currency object by reference
	Post:
	Return: Returns a new currency class with subtraction included
	*/
	virtual currency operator-(const currency& x);

	/*method is an overloading operator allowing for comparison of two currenct objects for >
	Pre: passes const currency object by reference
	Post:
	Return: Returns true/false based on evaluation
	*/
	virtual bool operator>(const currency& x);

	/*method is an overloading operator allowing for comparison of two currenct objects for <
	Pre: passes const currency object by reference
	Post:
	Return: Returns true/false based on evaluation
	*/
	virtual bool operator<(const currency& x);

	/*method is an overloading operator allowing specific output for the currency class
	Pre: passes an out stream object and a currency object
	Post:
	Return: Returns out stream object
	*/
	friend std::ostream& operator<<(std::ostream& out, currency& x);

	/*method is an overloading operator allowing specific input for the currency class
	Pre: passes an in stream object and a currency object
	Post:
	Return: Returns in stream object
	*/
	friend currency* operator>>(std::istream& in, currency* x);

	void operator=(currency x);

	friend bool operator==(currency y, currency x);

	friend currency* operator>>(std::ifstream& in, currency* x);
};

class Dollar : public currency
{
private:
	std::string noteName;
	std::string coinName;
public:
	Dollar();
	Dollar(int, int);
	~Dollar() {}
	/*method gets the value of NoteName
	Pre:
	Post:
	Return: returns the variable NoteName
	*/
	std::string getNoteName();

	/*method gets the value of CoinName
	Pre:
	Post:
	Return: returns the variable CoinName
	*/
	std::string getCoinName();

	/*method sets the value of NoteName to x
	Pre: passes string with value x
	Post:
	Return:
	*/
	void setNoteName(std::string x);

	/*method sets the value of CoinName to x
	Pre: passes string with value x
	Post:
	Return:
	*/
	void setCoinName(std::string x);

	/*method is an overloading operator allowing specific output for the Dollar class
	Pre: passes an out stream object and a Dollar object
	Post:
	Return: Returns out stream object
	*/
	friend std::ostream& operator<<(std::ostream& out, Dollar& x);

	/*method is an overloading operator allowing specific Input for the Dollar class
	Pre: passes an in stream object and a Dollar object
	Post:
	Return: Returns in stream object
	*/
	friend std::istream& operator>>(std::istream& in, Dollar& x);
};