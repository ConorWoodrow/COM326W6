/*
* Main.cpp
*
* Version information
* Author: Dr. Shane Wilson
* Date:30/09/2017
* Description: Vector Memory management
*
* Copyright notice
*/

#pragma once 

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <random>
#include <iterator>


using namespace std;
float GenerateRandomNumber();
void PopulateVector(vector <int> &v, int size);
void RemoveRepeating(vector<int> &vec1, vector<int> &vec2);

int main(int argc, const char * argv[]) {

	vector<int> v1{};
	vector<int> v2{};

	//Print out the size and capacity of the vectors
	cout << "V1 size is: " << v1.size() << endl;
	cout << "V2 size is: " << v2.size() << endl;
	cout << "V1 capacity is: " << v1.capacity() << endl;
	cout << "V2 capacity is: " << v2.capacity() << endl;

	//Populate the vectors
	PopulateVector(v1, 100);
	PopulateVector(v2, 100);
	//Sort the vectors
	std::sort(v1.begin(), v1.end());
	std::sort(v2.begin(), v2.end());

	//Print out the size and capacity of the vectors
	cout << "V1 size is: " << v1.size() << endl;
	cout << "V2 size is: " << v2.size() << endl;
	cout << "V1 capacity is: " << v1.capacity() << endl;
	cout << "V2 capacity is: " << v2.capacity() << endl;

	//Shrink the vectors back down to 100 elements
	v1.shrink_to_fit();
	v2.shrink_to_fit();
	
	
	//Print out the size and capacity of the vectors
	cout << "V1 size is: " << v1.size() << endl;
	cout << "V2 size is: " << v2.size() << endl;
	cout << "V1 capacity is: " << v1.capacity() << endl;
	cout << "V2 capacity is: " << v2.capacity() << endl;

	RemoveRepeating(v1, v2);

	
	return 0;
}

void PopulateVector(vector <int> &v, int size) {
	for (int index = 0; index < size; index++) {
		v.push_back(GenerateRandomNumber());

	}


}


float GenerateRandomNumber() {

	/* Some of you asked how this works. You really need to read the documentation for the deep dive explanation.
	* If you want to know what is happening here I have added some comments
	* This will become clearer when we talk about classes and objects in week 3
	*/


	//Taken from: http://en.cppreference.com/w/cpp/numeric/random/uniform_real_distribution
	//Define an instance (aka an object) of the random_device Class and call the object rd
	std::random_device rd; //The random number device. Will be used to obtain a seed for the random number engine
						   //Call the constructor of the object rd and use the RD engine to create a mersenne_twister_engine
						   //The mersenne_twister_engine is based on the Mersenne twister algorithm
	std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
							//Create a new distribution object with min and max values. So the range the random number should fall between
	std::uniform_real_distribution<> dis(0, 1000);

	//Generate the randome number passing in the mersenne_twister_engine generator
	int outcome = dis(gen);
	//std::cout << " outcome " << outcome;

	return outcome;
}


void RemoveRepeating(vector<int> &vec1, vector<int> &vec2) {
	std::vector<int> res; // Will contain the symmetric difference
	std::set_symmetric_difference(vec1.begin(), vec1.end(),
		vec2.begin(), vec2.end(),
		std::back_inserter(res));

	// Use set difference from <algorithm> to get the elements in vec 2 that do not appear in vec 1
	vector<int> difference;
	set_difference(vec2.begin(), vec2.end(),
		vec1.begin(), vec1.end(),
		std::inserter(difference, difference.begin()));

	//Erase all elements in vec2
	vec2.clear();
	//Copy elements from difference into vec2
	vec2 = difference;
	

}