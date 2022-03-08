/*
@Lab: Lab 5 Binary Search Trees
@Author: Casey Merritt, Revanth Cherukuri
@Purpose: this is just a implementation of the currency class
*/

//#include "pch.h"//Needed for vis studio comment out if not on vis
#include "currency.h"
#include <iostream>
#include <fstream>
#include <string>

currency::currency() {
	Whole = 0;
	Part = 0;
}

currency::~currency() {

}

int currency::getWhole() {
	return Whole;
}

int currency::getPart() {
	return Part;
}

void currency::setWhole(int x) {
	Whole = x;
}

void currency::setPart(int x) {
	Part = x;
}

std::string currency::getNoteName() {
	std::string x = "None tbh";//big oof
	return x;
}

std::string currency::getCoinName() {
	std::string x = "None tbh";//big oof again
	return x;
}

currency currency::operator+(const currency& x) {
	currency temp;
	temp.Whole = x.Whole + this->Whole;
	temp.Part = x.Part + this->Part;
	if (temp.Part > 99) {
		temp.Whole = temp.Whole + (temp.Part / 100);
		temp.Part = temp.Part % (100 * (temp.Part / 100));
	}
	return temp;
}

currency currency::operator-(const currency& x) {
	currency temp;
	temp.Whole = this->Whole - x.Whole;
	temp.Part = this->Part - x.Part;
	while (temp.Part < 0 && temp.Whole > 0) {
		temp.Whole = temp.Whole - 1;
		temp.Part = 100 + temp.Part;
	}
	/*
	//used to keep values consistent below zero
	//not utilized since we are not allowing values below zero
	//wrote this before realizing that rip haha
	while (temp.Whole <= 0 && temp.Part < -99) {
		temp.Whole = temp.Whole - 1;
		temp.Part = 100 + temp.Part;
	}
	*/
	if (temp.Whole <= 0 && temp.Part < 0) {
		temp.Whole = 0;
		temp.Part = 0;
		std::cout << "Cannot go below zero, account balance set to zero" << std::endl;
	}
	return temp;
}

bool currency::operator>(const currency& x) {
	int a = ((this->Whole * 100) + this->Part);
	int b = ((x.Whole * 100) + x.Part);
	if (a > b) {
		return true;
	}
	else {
		return false;
	}
}

bool currency::operator<(const currency& x) {
	int a = ((this->Whole * 100) + this->Part);
	int b = ((x.Whole * 100) + x.Part);
	if (a < b) {
		return true;
	}
	else {
		return false;
	}
}

bool operator==(currency x, currency y) {
	double k = 0;
	double j = 0;
	j = y.Whole + (y.Part / 100);
	k = x.Whole + (x.Part / 100);

	if (j == k) {
		return true;
	}
	else {
		return false;
	}
}

void currency::operator=(currency x) {
	this->Whole = x.Whole;
	this->Part = x.Part;
}

//currency one
std::ostream& operator<<(std::ostream& out, currency& x) {
	//out << x.getNoteName() << " " << x.Whole << " " << x.Part << " " << x.getCoinName() << std::endl;
	out << "$" << x.Whole << "." << x.Part;//altered the output a bit from lab1a so it looks better with this output style
	return out;
}

std::ostream& operator<<(std::ostream& out, Dollar& x) {
	//out << x.noteName << " " << x.Whole << " " << x.Part << " " << x.coinName;
	if (x.Part < 10) {
		out << "$" << x.Whole << "." << "0" << x.Part;//altered the output a bit from lab1a so it looks better with this output style
	}
	else {
		out << "$" << x.Whole << "." << x.Part;//altered the output a bit from lab1a so it looks better with this output style
	}
	return out;
}

//currency one
currency* operator>>(std::istream& in, currency* x) {
	std::string note, coin;
	int w, p;
	bool test = false;
	while (test == false) {//checking for valid formats here
		in >> note >> w >> p >> coin;
		if (note == "Dollar" || note == "dollar" || note == "Pound" || note == "pound" || note == "Rupee" || note == "rupee" || note == "Yen" || note == "yen" || note == "Real" || note == "real") {
			if ((w >= 0 || w <= 0) && (p >= 0 || p <= 0)) {
				test = true;
			}
		}
		else {
			std::cout << "Invalid Format Please Try Again: " << std::endl;
		}
	}
	if (note == "Dollar" || note == "dollar") {
		x->setWhole(w);
		x->setPart(p);
		//x = new Dollar(w, p);
	}
	else if (note == "Pound" || note == "pound") {//not needed for this lab
		//x = new Pound(w, p);
	}
	else if (note == "Rupee" || note == "rupee") {//not needed for this lab
		//x = new Rupee(w, p);
	}
	else if (note == "Real" || note == "real") {//not needed for this lab
		//x = new Real(w, p);
	}
	else if (note == "Yen" || note == "yen") {//not needed for this lab
		//x = new Yen(w, p);
	}
	return x;
}

currency* operator>>(std::ifstream& in, currency* x) {
	std::string note, coin;
	int w, p;
	bool test = false;
	in >> note >> w >> p >> coin;
	if (note == "Dollar" || note == "dollar" || note == "Pound" || note == "pound" || note == "Rupee" || note == "rupee" || note == "Yen" || note == "yen" || note == "Real" || note == "real") {
		if ((w >= 0 || w <= 0) && (p >= 0 || p <= 0)) {
			x->setWhole(w);
			x->setPart(p);
		}
	}
	else {
		std::cout << std::endl;
		std::cout << "Invalid Format Please Try Again Detected Skipping That Line!" << std::endl;
		std::cout << std::endl;
	}
	return x;
}

std::istream& operator>>(std::istream& in, Dollar& x) {
	//need to add non correct input checker later
	//currently this isn't being used so not a big deal
	std::string nN;
	std::string cN;
	in >> nN >> x.Whole >> x.Part >> cN;
	//in >> x.Whole >> x.Part;
	x.setNoteName(nN);
	x.setCoinName(cN);
	return in;
}

Dollar::Dollar() {
	noteName = "Dollar";
	coinName = "cent";
}

Dollar::Dollar(int x, int y) {
	noteName = "Dollar";
	coinName = "cent";
	Whole = x;
	Part = y;
}

std::string Dollar::getNoteName() {
	return noteName;
}

std::string Dollar::getCoinName() {
	return coinName;
}

void Dollar::setNoteName(std::string x) {
	noteName = x;
}

void Dollar::setCoinName(std::string x) {
	coinName = x;
}
