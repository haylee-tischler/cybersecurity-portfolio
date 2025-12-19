//*****************************************************************************************************
//
//		File:					SortedList.h
//
//		Author:					Haylee Tischler
//
//		This a class with different sorting functions
//	
//		Other files required: 
//			1.	none
//			
//*****************************************************************************************************

#ifndef SORTEDLIST_H
#define SORTEDLIST_H
 
//*****************************************************************************************************

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <random>

//*****************************************************************************************************

template<typename T>
class SortedList
{
private:
	T* list;
	int size;
	int numValues;
	int minIndex(int index);
	int maxIndex(int index);
	void selectionSortA(int index);
	void selectionSortD(int index);
	int partitionA(T arr[], int low, int high);
	int partitionD(T arr[], int low, int high);
	void heapifyA(T arr[], int n, int root);
	void heapifyD(T arr[], int n, int root);
	void quickSortA(T arr[], int low, int high);
	void quickSortD(T arr[], int low, int high);
	void heapSortA(T arr[], int n);
	void heapSortD(T arr[], int n);
public:
	SortedList(int s);
	~SortedList();
	void insert(const T& item);
	void randomize();
	void selectionSortA();
	void selectionSortD();
	void quickSortA();
	void quickSortD();
	void heapSortA();
	void heapSortD();
	void display() const;
};

//*****************************************************************************************************

template<typename T>
SortedList<T> ::SortedList(int s)
{
	list = new T[s];
	size = s;
	numValues = 0;
}

//*****************************************************************************************************

template<typename T>
SortedList<T> ::~SortedList()
{
	delete[] list;
	size = 0;
	numValues = 0;
}

//*****************************************************************************************************

template<typename T>
void SortedList<T> ::insert(const T& item)
{
	if (numValues == size)
	{
		size += 10;
		T* newList = new T[size];
		for (int i = 0; i < numValues; i++)
		{
			newList[i] = list[i];
		}

		list = newList;

		size += 10;
	}

	list[numValues] = item;
	numValues++;
}

//*****************************************************************************************************

template <typename T>
void SortedList<T> ::randomize()
{
	std::srand(unsigned(std::time(0)));
	std::random_shuffle(&list[0], &list[numValues]);
}

//*****************************************************************************************************

template<typename T>
void SortedList<T> ::selectionSortA() //public
{
	selectionSortA(0);
}

//*****************************************************************************************************

template<typename T>
void SortedList<T> ::selectionSortD()
{
	selectionSortD(0);
}

//*****************************************************************************************************

template<typename T>
void SortedList<T> ::quickSortA()
{
	quickSortA(list, 0, numValues - 1);
}

//*****************************************************************************************************

template<typename T>
void SortedList<T> ::quickSortD() 
{
	quickSortD(list, 0, numValues - 1);
}

//*****************************************************************************************************

template<typename T>
void SortedList<T>:: heapSortA()
{
	heapSortA(list,numValues);
}

//*****************************************************************************************************

template<typename T>
void SortedList<T>::heapSortD()
{
	heapSortD(list,numValues);
}

//*****************************************************************************************************

template<typename T>
void SortedList<T> ::display() const
{

	for (int i = 0; i < numValues; i++)
	{
		std::cout << list[i] << std::endl;
	}
}
//*****************************************************************************************************

template<typename T>
int SortedList<T> ::minIndex(int index)
{
	if (index == numValues - 1)
	{
		return index;
	}
	int k = minIndex(index + 1);

	return(list[index] < list[k] ? index : k);
}

//*****************************************************************************************************

template<typename T>
int SortedList<T> ::maxIndex(int index)
{
	if (index == numValues - 1)
	{
		return index;
	}
	int k = maxIndex(index + 1);

	return(list[index] > list[k] ? index : k);
}
//*****************************************************************************************************

template<typename T>
void SortedList<T> ::selectionSortA(int index) 
{
	int min;
	if (index == numValues)
	{
		return;
	}
	min = minIndex(index);

	if (list[min] < list[index])
	{
		std::swap(list[min], list[index]);
	}

	selectionSortA(index + 1);

}

//*****************************************************************************************************

template<typename T>
void SortedList<T> ::selectionSortD(int index)
{
	int max;
	if (index == numValues)
	{
		return;
	}
	max = maxIndex(index);

	if (list[max] > list[index])
	{
		std::swap(list[max], list[index]);
	}

	selectionSortD(index + 1);
}

//*****************************************************************************************************

template <typename T>
int SortedList<T> ::partitionA(T arr[], int low, int high)
{
	T pivot = arr[(low + high) / 2];
	std::swap(arr[low], arr[(low + high) / 2]);
	int smallIndex = low;
	int index;

	for (int i = low + 1; i <= high; ++i)
	{
		index = i;
		if (pivot > arr[index])
		{
			++smallIndex;
			std::swap(arr[smallIndex], arr[index]);
		}
	}

	std::swap(arr[low], arr[smallIndex]);
	return smallIndex;
}

//*****************************************************************************************************

template <typename T>
int SortedList<T> ::partitionD(T arr[], int low, int high)
{
	T pivot = arr[(low + high) / 2];
	std::swap(arr[low], arr[(low + high) / 2]);
	int smallIndex = low;
	int index;

	for (int i = low + 1; i <= high; ++i)
	{
		index = i;
		if (pivot < arr[index])
		{
			++smallIndex;
			std::swap(arr[smallIndex], arr[index]);
		}
	}

	std::swap(arr[low], arr[smallIndex]);
	return smallIndex;
}

//*****************************************************************************************************

template<typename T> 
void SortedList<T> ::heapifyA(T arr[], int n, int root)
{
	int largest = root; 
	int l = 2 * root + 1; 
	int r = 2 * root + 2; 
	// If left child is larger than root
	if ((l < n) && (arr[l] > arr[largest])) 
	{
		largest = l;
	}
	// If right child is larger than largest so far
	if ((r < n) && (arr[r] > arr[largest])) 
	{
		largest = r;
	}
	// If largest is not root
	if (largest != root) 
	{
		//swap root and largest
		std::swap(arr[root], arr[largest]);
		// Recursively heapify the sub-tree
		heapifyA(arr, n, largest);
	}
}

//*****************************************************************************************************

template<typename T>
void SortedList<T> :: heapifyD(T arr[], int n, int root)
{
	int smallest = root;
	int l = 2 * root + 1;
	int r = 2 * root + 2;
	// If left child is larger than root
	if ((l < n) && (arr[l] < arr[smallest]))
	{
		smallest = l;
	}
	// If right child is larger than largest so far
	if ((r < n) && (arr[r] < arr[smallest]))
	{
		smallest = r;
	}
	// If largest is not root
	if (smallest != root)
	{
		//swap root and largest
		std::swap(arr[root], arr[smallest]);
		// Recursively heapify the sub-tree
		heapifyA(arr, n, smallest);
	}
}

//*****************************************************************************************************

template<typename T>
void SortedList<T> ::quickSortA(T arr[], int low, int high)
{
	if (low < high) {
		int pivotLoc = partitionA(arr, low, high);
		quickSortA(arr, low, pivotLoc - 1);
		quickSortA(arr, pivotLoc + 1, high);
	}
}

//*****************************************************************************************************

template<typename T>
void SortedList<T> ::quickSortD(T arr[], int low, int high)
{
	if (low < high)
	{
		int pivotLoc = partitionD(arr, low, high);
		quickSortD(arr, low, pivotLoc - 1);
		quickSortD(arr, pivotLoc + 1, high);
	}
}

//*****************************************************************************************************

template<typename T>
void SortedList<T> :: heapSortA(T arr[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--) 
	{ 
		heapifyA(arr, n, i);
	}
	for (int i = n - 1; i >= 0; i--) 
	{ 
		std::swap(arr[0], arr[i]); 
		heapifyA(arr, i, 0); 
	}

}

//*****************************************************************************************************

template <typename T>
void SortedList<T> :: heapSortD(T arr[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		heapifyD(arr, n, i);
	}
	for (int i = n - 1; i >= 0; i--)
	{ 
		std::swap(arr[0], arr[i]); 
		heapifyD(arr, i, 0); 
	}
}

//*****************************************************************************************************

#endif // !SORTEDLIST_H




