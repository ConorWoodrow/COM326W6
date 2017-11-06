/*
* Main.cpp
*
* Version information
* Author: Dr. Shane Wilson
* Date:30/09/2017
* Description: Memory management
*
* Copyright notice
*/

#pragma once 

#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

int * CreateInts(int num);
void ReadInts(int* array, int num);
int HowMany();
void DisplayInts(int* array, int num);

int main(int argc, const char * argv[]) {

	int howMany = HowMany();
	
	int* iPtr{ nullptr };
	iPtr = CreateInts(howMany);
	ReadInts(iPtr, howMany);
	DisplayInts(iPtr, howMany);
	delete[] iPtr; //array delete
	//Always set a pointer to nullptr after deleting
	iPtr = nullptr;
	
		

	//int* iPtr = new int[5000];
	//*iPtr = 55;

	//delete iPtr;

	return 0;
}

int HowMany() {
	int number{ 0 };
	cout << "How many integers would you like to record? ";
	cin >> number;

	return number;
}

int* CreateInts(int num) {
	int* arrayPtr{ new int[num] };
	return arrayPtr;
}

void ReadInts(int* array, int num) {

	int* arrayPtr = array;

	for (int index = 0; index < num; index++) {
		cout << "\nPlease enter an integer: ";
		cin >> *arrayPtr;
		arrayPtr++;
	}
}

void DisplayInts(int* array, int num) {
	int* arrayPtr = array;
	
	cout << "\nThe value stored in the array heap are: " << endl;
	for (int index = 0; index < num; index++) {
		cout << " " << *arrayPtr;
		arrayPtr++;
	}
}
