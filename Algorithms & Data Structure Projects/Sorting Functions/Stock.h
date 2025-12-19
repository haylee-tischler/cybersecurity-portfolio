//*****************************************************************************************************
//
//		File:					Stock.h
//
//		Student:				Haylee Tischler
//
//		Assignment:				11
//
//		Course Name:			Data Structures I
//
//		Course Number:			COSC 3100-01
//
//		Due:					April 22, 2024
//
//
//		This program is a Stock class
//	
//		Other files required: 
//			1.	none
//			
//*****************************************************************************************************

#ifndef STOCK_H
#define STOCK_H

//*****************************************************************************************************

#include <string>

//*****************************************************************************************************

class Stock
{
private: 
	std::string name;
	std::string symbol;
	double price;

public:
	Stock(const std::string& n = "", const std::string& s = "", double p = 0);
	Stock(const Stock& s);
	void display() const;
	std::string getName() const;
	std::string getSymbol() const;
	double getPrice() const;
	bool operator==(const Stock& rhs) const;
	bool operator!=(const Stock& rhs) const;
	bool operator <(const Stock& rhs) const;
	bool operator >(const Stock& rhs) const;
	Stock * operator =(const Stock& rhs);
	friend std::ostream& operator << (std::ostream& out, const Stock& data);
};

//*****************************************************************************************************


inline
std::string Stock:: getName() const
{
	return name;
}

//*****************************************************************************************************

inline
std::string Stock::getSymbol() const
{
	return symbol;
}

//*****************************************************************************************************

inline
double Stock::getPrice() const
{
	return price;
}

//*****************************************************************************************************

inline
bool Stock:: operator ==(const Stock& rhs) const
{
	return (this->symbol == rhs.symbol);
}

//*****************************************************************************************************

inline
bool Stock:: operator !=(const Stock& rhs) const
{
	return!(*this == rhs);
}

//*****************************************************************************************************

inline
bool Stock:: operator <(const Stock & rhs) const
{
	return(this->symbol < rhs.symbol);
}

//*****************************************************************************************************

inline
bool Stock:: operator >(const Stock& rhs) const
{
	return(this->symbol > rhs.symbol);
}

//*****************************************************************************************************
#endif