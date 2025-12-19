//*****************************************************************************************************
//
//		File:					Stock.cpp
//
//		Author:					Haylee Tischler
//
//		This program contains the definitions for the member functions of the Stock.
//	
//		Other files required: 
//			1.	Stock.h
//			
//*****************************************************************************************************

#include "Stock.h"
#include <iostream>
#include <iomanip>

//*****************************************************************************************************

Stock:: Stock(const std::string& n, const std::string& s, double p)
{
	this->name = n;
	this->symbol = s;
	this->price = p;
}

//*****************************************************************************************************

Stock:: Stock(const Stock& s)
{
	name = s.name;
	symbol = s.symbol;
	price = s.price;
}

//*****************************************************************************************************

void Stock:: display() const
{
	std:: cout << "Company Name:\t" << name << std:: endl;
	std:: cout << "Stock Symbol:\t" << symbol << std:: endl;
	std:: cout << "Price: \t\t$" << price << std:: endl;
}

//*****************************************************************************************************

std::ostream& operator << (std::ostream& out, const Stock& data)
{
	out << std::left << std::setw(25)<<data.name<< std::left << std::setw(10) << data.symbol  << data.price;
	return out;
}

//*****************************************************************************************************

Stock* Stock:: operator =(const Stock& rhs)
{
	this->name = rhs.name;
	this->symbol = rhs.symbol;
	this->price = rhs.price;
	return this;
}

//*****************************************************************************************************


