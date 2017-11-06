#include <iostream>
#include <memory>
#include <cassert>
#include <string>

void PlayingWithUniquePointers();

int main(int) {

	std::cout << "Hello\n" << std::endl;

	
	PlayingWithUniquePointers();

	

	return 0;

}

void PlayingWithUniquePointers() {
	std::cout << "Playing with unique pointers\n" << std::endl;
	
	//https://msdn.microsoft.com/en-us/library/hh279676.aspx

	//lets make a unique pointer
	auto uniquePtr1 = std::make_unique<int>(32);
	
	std::cout << "The value (*) of the unique pointer 1 is: " << *uniquePtr1 << std::endl;
	std::cout << "The address (&) of the unique pointer 1 is: " << &uniquePtr1 << std::endl;
	std::cout << "The address of the memory location (&*) the unique pointer 1 points to is : " << &*uniquePtr1 << std::endl;

	//p will now point to nothing
	auto uniquePtr2 = std::move(uniquePtr1);
	std::cout << "Smart pointer uniquePtr2 created and pointing at uniquePtr1: " << std::endl;

	//Test to see if the pointer p is null
	assert(!uniquePtr1 && "Crap the pointer is still valid"); // now uniquePtr1 owns nothing and holds a null pointer


	std::cout << "The value (*) of the unique pointer 2 is: " << *uniquePtr2 << std::endl;
	std::cout << "The address (&) of the unique pointer 2 is: " << &uniquePtr2 << std::endl;
	std::cout << "The address of the memory location (&*) the unique pointer 2 points to is : " << &*uniquePtr2 << std::endl;

	//std::cout << "The value of the unique pointer uniquePtr1 is: " << *uniquePtr1 << std::endl; //this will crash

	
	std::cout << "The address (&) of the unique pointer 1 is: " << &uniquePtr1 << std::endl;
	std::cout << "The address of the memory location (&*) the unique pointer 1 points to is : " << &*uniquePtr1 << std::endl;
	//std::cout << "The value (*) of the unique pointer 1 is: " << *uniquePtr1 << std::endl; //This will crash


};

