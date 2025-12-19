//*****************************************************************************************************
//
//		File:					assignment11Driver.cpp
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
//		This program is a driver for different sorting functions
//	
//		Other files required: 
//			1.	SortedaList.h
//			2.  Stock.h
//			
//*****************************************************************************************************

#include "SortedList.h"
#include "Stock.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//*****************************************************************************************************

int main()
{
	SortedList<Stock> stocks(10);
	ifstream stockFile("Stock.txt");
	string symbol,
		   name;
	double price;

	while (getline(stockFile, name, '\n'))
	{
		stockFile >> symbol;
		stockFile >> price;
		stockFile.ignore();
		Stock temp(name, symbol, price);
		stocks.insert(temp);
	}
	stockFile.close();
	cout << "Original List:" << endl << endl << endl;
	stocks.display();

	stocks.randomize();
	stocks.display();

	stocks.quickSortA();
	cout << endl << endl << "quickSortA:" << endl;
	stocks.display();
	stocks.randomize();
	
	cout << endl << endl << "Randomized:" << endl;
	stocks.display();

	stocks.quickSortD();
	cout << endl << endl << "quickSortD:"<<endl;
	stocks.display();
	stocks.randomize();

	cout << endl << endl << "selectionSortA"<<endl ;
	stocks.selectionSortA();
	stocks.display();
	stocks.randomize();

	cout << endl << endl << "selectionSortD"<<endl;
	stocks.selectionSortD();
	stocks.display();
	stocks.randomize();

	cout << endl << endl << "heapSortA" << endl;
	stocks.heapSortA();
	stocks.display();
	stocks.randomize();

	cout << endl << endl << "heapSortD" << endl;
	stocks.heapSortD();
	stocks.display();
	stocks.randomize();

	return 0;
}

//*****************************************************************************************************

/*

Original List:


Apple                    AAPL      234.2
Advanced Micro Devices   AMD       84.51
Intel                    INTC      60.78
Motorola Inc.            MOT       17.49
Microsoft Corp.          MSFT      28.11
NVIDIA                   NVDA      548.58
Sony                     SNE       105.81
Tesla                    TSLA      564.33
XApple                   XAAPL     221.73
XNVIDIA                  XNVDA     648.58
haylee                   HT        756.32
mj                       MJJ       2726.03
anika                    ANK       345.22
madelynne                MAD       123.29
gavin                    GAV       285.94
NVIDIA                   NVDA      548.58
XApple                   XAAPL     221.73
gavin                    GAV       285.94
XNVIDIA                  XNVDA     648.58
Intel                    INTC      60.78
mj                       MJJ       2726.03
haylee                   HT        756.32
madelynne                MAD       123.29
Tesla                    TSLA      564.33
Advanced Micro Devices   AMD       84.51
Motorola Inc.            MOT       17.49
Microsoft Corp.          MSFT      28.11
Sony                     SNE       105.81
Apple                    AAPL      234.2
anika                    ANK       345.22


quickSortA:
Apple                    AAPL      234.2
Advanced Micro Devices   AMD       84.51
anika                    ANK       345.22
gavin                    GAV       285.94
haylee                   HT        756.32
Intel                    INTC      60.78
madelynne                MAD       123.29
mj                       MJJ       2726.03
Motorola Inc.            MOT       17.49
Microsoft Corp.          MSFT      28.11
NVIDIA                   NVDA      548.58
Sony                     SNE       105.81
Tesla                    TSLA      564.33
XApple                   XAAPL     221.73
XNVIDIA                  XNVDA     648.58


Randomized:
Intel                    INTC      60.78
Motorola Inc.            MOT       17.49
XNVIDIA                  XNVDA     648.58
Microsoft Corp.          MSFT      28.11
anika                    ANK       345.22
Sony                     SNE       105.81
NVIDIA                   NVDA      548.58
XApple                   XAAPL     221.73
mj                       MJJ       2726.03
Advanced Micro Devices   AMD       84.51
gavin                    GAV       285.94
haylee                   HT        756.32
madelynne                MAD       123.29
Apple                    AAPL      234.2
Tesla                    TSLA      564.33


quickSortD:
XNVIDIA                  XNVDA     648.58
XApple                   XAAPL     221.73
Tesla                    TSLA      564.33
Sony                     SNE       105.81
NVIDIA                   NVDA      548.58
Microsoft Corp.          MSFT      28.11
Motorola Inc.            MOT       17.49
mj                       MJJ       2726.03
madelynne                MAD       123.29
Intel                    INTC      60.78
haylee                   HT        756.32
gavin                    GAV       285.94
anika                    ANK       345.22
Advanced Micro Devices   AMD       84.51
Apple                    AAPL      234.2


selectionSortA
Apple                    AAPL      234.2
Advanced Micro Devices   AMD       84.51
anika                    ANK       345.22
gavin                    GAV       285.94
haylee                   HT        756.32
Intel                    INTC      60.78
madelynne                MAD       123.29
mj                       MJJ       2726.03
Motorola Inc.            MOT       17.49
Microsoft Corp.          MSFT      28.11
NVIDIA                   NVDA      548.58
Sony                     SNE       105.81
Tesla                    TSLA      564.33
XApple                   XAAPL     221.73
XNVIDIA                  XNVDA     648.58


selectionSortD
XNVIDIA                  XNVDA     648.58
XApple                   XAAPL     221.73
Tesla                    TSLA      564.33
Sony                     SNE       105.81
NVIDIA                   NVDA      548.58
Microsoft Corp.          MSFT      28.11
Motorola Inc.            MOT       17.49
mj                       MJJ       2726.03
madelynne                MAD       123.29
Intel                    INTC      60.78
haylee                   HT        756.32
gavin                    GAV       285.94
anika                    ANK       345.22
Advanced Micro Devices   AMD       84.51
Apple                    AAPL      234.2


heapSortA
Apple                    AAPL      234.2
Advanced Micro Devices   AMD       84.51
anika                    ANK       345.22
gavin                    GAV       285.94
haylee                   HT        756.32
Intel                    INTC      60.78
madelynne                MAD       123.29
mj                       MJJ       2726.03
Motorola Inc.            MOT       17.49
Microsoft Corp.          MSFT      28.11
NVIDIA                   NVDA      548.58
Sony                     SNE       105.81
Tesla                    TSLA      564.33
XApple                   XAAPL     221.73
XNVIDIA                  XNVDA     648.58


heapSortD
XNVIDIA                  XNVDA     648.58
XApple                   XAAPL     221.73
mj                       MJJ       2726.03
Intel                    INTC      60.78
haylee                   HT        756.32
Tesla                    TSLA      564.33
Sony                     SNE       105.81
Microsoft Corp.          MSFT      28.11
anika                    ANK       345.22
gavin                    GAV       285.94
NVIDIA                   NVDA      548.58
madelynne                MAD       123.29
Motorola Inc.            MOT       17.49
Advanced Micro Devices   AMD       84.51
Apple                    AAPL      234.2

*/