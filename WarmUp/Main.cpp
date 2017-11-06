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

int* GetPointer();

int main(int argc, const char * argv[]) {

	int* intPtr = GetPointer();

	cout << *intPtr << endl;

	delete intPtr;
	intPtr = nullptr;

	return 0;
}

int* GetPointer() {
	int* localPtr{ new int{5} };
	return localPtr;

}


/*
int* GetPointer() {
	int x{ 5 };
	return &x;

	//X will go out of scope when the function exits
	//We need to allocate memory

}*/
