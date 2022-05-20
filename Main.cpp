/*
* Name: Joshua Shor
* Student ID: 200968955
* Email: shor002@cougars.csusm.edu
*
Write a C++ program to implement the six sorting algorithms that we learned in this class:
Selection Sort, Bubble Sort, Insertion Sort, Quick Sort, Merge Sort, and Heap Sort. Your program
must be able to read a list of integers (separated by space) from keyboard input and sort them
using any of these six sorting algorithms.
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <ctype.h>

using namespace std;

void printArray(int ary[], int aSize) {

	//cout << "Sorted Array:" << endl;

	for (int i = 0; i < aSize; i++) {
		cout << ary[i] << " ";
		
	}

	cout << endl;
}

void selectionSort(int a[], int len) {

	int low;

	for (int i = 0; i < len; i++) {
		low = i;
		for (int j = i + 1; j < len; j++) {
			if (a[j] < a[low]) {
				low = j;			
			}
		}
		swap(a[i], a[low]);

	}


}

void bubbleSort(int a[], int len) {

	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len - 1; j++) {
			if (a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
			}
		}
	}


}

void insertionSort(int a[], int len) {
	
	for (int i = 0; i < len; i++) {

		
		int j = i;
		int temp = a[j]; //estalish temp var to compare to array

		while (a[j - 1] > temp && j > 0) {
			swap(a[j], a[j - 1]);
			j--;
		}
	}
}


//Quick Sort functions//
int partition(int a[], int p, int r) {

	int pivThisThing = a[r]; //last element of array
	int i = p - 1; 
	int j = p - 1; //p-1 because I'm incrementing it in while loop
	
	//cout << r << endl;
	//cout << pivThisThing << endl;

	while (++j <= r) {
		if (a[j] < pivThisThing) {
			i++; //move the index up one
			swap(a[i], a[j]); //swap if smaller than pivot variable
		}

	}
	swap(a[i+1], a[r]);
	return (i + 1); //return next pivot point
}

void quickSort(int a[], int p, int r){

	int pivoter;

	if (p >= r) {
		return;
	}
	if (p < r) {
		pivoter = partition(a, p, r);

		quickSort(a, p, pivoter - 1); //left side
		quickSort(a, pivoter + 1, r); //right side
	}

}
//Merge Sort functions//
void merge(int a[], int mid, int low, int hi) {

	int i, j, k, *b; //index elements and array
	b = new int[hi]; //make some sub-array
	i = low; k = i; j = mid + 1; //initialize pointers

	//while both subarrays are not empty
	while (i <= mid && j <= hi) {
		if (a[i] <= a[j]) {
			b[k++] = a[i++];
		}
		else b[k++] = a[j++];
	}
	while (i <= mid) {
		b[k++] = a[i++]; //copy any leftover to b
	}
	while (j <= hi) {
		b[k++] = a[j++];
	}
	for (i = low; i < k; i++) { //b can only be k elements, everything else will be empty
		a[i] = b[i];	//copy b back to a
	}
}

void mergeSort(int a[], int lo, int len) {

	if (lo == len)return; //if array has one element
	int mid = (lo + len) / 2; //find midpoint
	mergeSort(a, lo, mid); //left side
	mergeSort(a, mid+1, len); //right side
	merge(a, mid, lo, len); //merge arrays

}

//Heap Sort functions//
class MinHeap {
	int* arr;
	int capacity;
	int size;

public:
	MinHeap(int cap) {
		size = 0;
		capacity = cap;
		arr = new int[capacity];
	}

};

int parent(int i) {
	return (i - 1) / 2;
}

int left(int i) {
	return(2 * i + 1);
}

int right(int i) {
	return (2 * i + 2);
}


void build_heap(int a[], int len) {
	
	int half = (len / 2) - 1;
	int i = 0;
	//for (int i = half; i >= 0; i--) {

	//}
	//heapify(a, len, i);
	//heapify(a, len, i);
}

int heapify(int a[], int len, int i) {
	
	int idx, l, r;

	idx = i;
	l = left(i);
	r = right(i);

	if (l < len && idx < a[idx]) idx = l;
	if (r < len && a[r] < a[idx]) idx = r;
	if (idx != i) {
		swap(a[i], a[idx]);
		
		heapify(a, len, idx);
	}
	return (idx);

}

	
void heapSort(int a[], int len) {
	
	int i, * b;
	
	//MinHeap h(len);
	//h.heapify(a, len);
	//b = new int[len];
	//build_heap(a, len - 1);
	heapify(a, len - 1, 0);
	


}

int main() {

	string nnum;
	int menuChoice, digt, nSize, *arry;
	vector<int> theNumberList;


	// Title for funsies!
	cout << "  __            __              " << endl;
	cout << " (    __/'  _  /__)_   _ _ _ _  " << endl;
	cout << "__)()/ ///)(/ /   / ()(// (///) " << endl;
	cout << "          _/         _/         " << endl;
	cout << endl << endl;
	cout << "Please enter in a set of numbers seperated by a space" << endl;


	
	getline(cin, nnum);
	cout << endl << endl;
	
	//8 29 64 13 q 2 5
	//nnum = "2 66 10 62 25 75 81 h 8 12 6 1 50 94 93 35"; //just to test so I don't have to type something in each time while testing

	//iterate through string to get rid of non-digital non-white space characters
	for (int i = 0; i < nnum.length(); i++) {
		//cout << "Character at Index" << i << " is : " << nnum.at(i) << endl;
		if (nnum[i] != ' ' && !isdigit(nnum[i]))
			nnum[i] = ' ';
	}
	//cout << "you have entered: " << nnum << endl;
	stringstream strm(nnum);


	//function to parse string and turn them into array of numbers goes here
	cout << "you have entered the following numbers: " << endl;
	while (strm >> digt) {
		theNumberList.push_back(digt);

	}

	nSize = theNumberList.size();
	//cout << "The size of this thing is " << nSize << endl;

	//dump contents of vector into array because the assignment demands it (I'd just stick with using a vector, personally)

	arry = new int[nSize];

	for (int i = 0; i < nSize; i++) {
		arry[i] = theNumberList[i];
	}
	cout << endl;
	printArray(arry, nSize);
	cout << endl;
	cout << "Please enter the type of sorting you want to use\n" << endl;
	cout << "Press(1) for selectionSort, Press(2) for bubbleSort,\n";
	cout << "Press(3) for insertionSort, Press(4) for quickSort,\n";
	cout << "Press(5) for mergeSort,     Press(6) for heapSort\n" << endl;
	cin >> menuChoice;
	

	//the Menu
	switch (menuChoice) {
		case 1:
			cout << "you chose selectionSort\n";
			selectionSort(arry, nSize);
			break;

		case 2:
			cout << "you chose bubbleSort\n";
			bubbleSort(arry, nSize);
			break;

		case 3:
			cout << "you chose insertionSort\n";
			insertionSort(arry, nSize);
			break;

		case 4:
			cout << "you chose quickSort\n";
			quickSort(arry, 0 ,nSize-1);
			break;

		case 5:
			cout << "you chose mergeSort\n";
			mergeSort(arry, 0, nSize-1);
			break;

		case 6:
			cout << "you chose heapSort\n";
			heapSort(arry, nSize); 
			break;
		default:
			cout << "you didn't choose anything\n";
	}
	cout << "the sorted array is : \n";
	printArray(arry, nSize);

	return 0;
}