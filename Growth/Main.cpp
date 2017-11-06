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

void PrintStackArrayAddresses(int intArray[]);
void PrintHeapArrayAddresses(float* floatArray);
void SetFloatValues(float* floatArray);
int main(int argc, const char * argv[]) {

	//Define an array of ints
	int intArray[10]{ 1,2,3,4,5,6,7,8,9,10 };
	PrintStackArrayAddresses(intArray);

	//Dynamically allocated an array of 10 floats on the heap
	float* floatPtr{ new float[10] };
	SetFloatValues(floatPtr);
	PrintHeapArrayAddresses(floatPtr);

	delete[] floatPtr;
	floatPtr = nullptr;

	return 0;
}

void PrintStackArrayAddresses(int intArray[]) {
	
	cout << "The stack int array contents and addresses are as follows" << endl;
	cout << "Index \t" << "Element \t" << "Address (Hex)\t" << "Address (Dec)" << endl;
	
	int* decimalAddress{nullptr};
	//Print out the array details
	for (int index = 0; index < 10; index++) {
		cout << index << "\t" << intArray[index] << "\t\t" << &intArray[index] << "\t" << dec << int(&intArray[index]) << endl;
	}
	cout << "\n\nThe stack growth for variables " << endl;

	int a{ 1 }, b{ 2 }, c{ 3 }, d{ 4 };
	cout << "variable \t" << "value \t" << "Address (Hex)\t" << "Address (Dec)" << endl;
	cout << "a" << "\t" << a << "\t\t" << &a << "\t" << dec << int(&a) << endl;
	cout << "b" << "\t" << b << "\t\t" << &b << "\t" << dec << int(&b) << endl;
	cout << "c" << "\t" << c << "\t\t" << &c << "\t" << dec << int(&c) << endl;
	cout << "d" << "\t" << d << "\t\t" << &d << "\t" << dec << int(&d) << endl;
	cout << sizeof(a);
	
}

void SetFloatValues(float* floatArray) {
	float* arrayPtr = floatArray;

	float value{ 0.0 };
	//Print out the array details
	for (int index = 0; index < 10; index++) {
		*arrayPtr = 0.0f;
		*arrayPtr = *arrayPtr + index+1;
		if (index < 9) {
			*arrayPtr = *arrayPtr + (float)(index + 1) / 10;
		}
		else { *arrayPtr = *arrayPtr + (float)(index + 1) / 100; }
		
		arrayPtr++;
	}

}

void PrintHeapArrayAddresses(float* floatArray) {
	float* arrayPtr = floatArray;
	float test{ 2.15f };
	cout << test << endl;

	cout << "\n\nThe heap float array contents and addresses are as follows" << endl;
	cout << "Index \t" << "Element \t" << "Address (Hex)\t" << "Address (Dec)" << endl;

	//Print out the array details
	for (int index = 0; index < 10; index++) {
		cout << index << "\t" << float(*arrayPtr) << "\t\t" << &*arrayPtr << "\t" << dec << int(&*arrayPtr) << endl;
		//cout << index << "\t" << test << "\t\t" << &*arrayPtr << "\t" << dec << int(&*arrayPtr) << endl;
		arrayPtr++;
	}
	


}