#include <iostream>
#include <memory>
#include <cassert>
#include <string>

void PlayingWithSmartPointers();

int main(int) {

	PlayingWithSmartPointers();

	return 0;

}

void PlayingWithSmartPointers() {
	std::cout << "Playing with smart pointers\n" << std::endl;
	//https://msdn.microsoft.com/en-us/library/hh279669.aspx


	std::cout << "Creating a shared pointer A which points at an empty string\n" << std::endl;
	std::shared_ptr<std::string> sharedPointerA = std::make_shared<std::string>();

	std::cout << "What is your name? : ";
	std::cin >> *sharedPointerA;

	std::cout << "The & address of shared pointer A is: " << &sharedPointerA << std::endl;
	std::cout << "The &* address of shared pointer A is: " << &*sharedPointerA << std::endl;
	std::cout << "The * value of the thing the shared pointer A points to is: " << *sharedPointerA << std::endl;
	std::cout << "The count of shared pointer is: " << sharedPointerA.use_count() << std::endl;

	std::cout << "Creating a shared pointer B which points at nullptr\n" << std::endl;
	std::shared_ptr<std::string> sharedPointerB(nullptr);

	sharedPointerB = sharedPointerA;

	std::cout << "The & address of shared pointer B is: " << &sharedPointerB << std::endl;
	std::cout << "The &* address of shared pointer B is: " << &*sharedPointerB << std::endl;
	std::cout << "The * value of the thing the shared pointer B points to is: " << *sharedPointerB << std::endl;
	std::cout << "The count of shared pointer A is: " << sharedPointerA.use_count() << std::endl;
	std::cout << "The count of shared pointer B is: " << sharedPointerB.use_count() << std::endl;


	std::cout << "Creating a smart pointer C which points at nullptr\n" << std::endl;
	std::shared_ptr<std::string> sharedPointerC(nullptr);

	sharedPointerC = sharedPointerA;

	std::cout << "The & address of shared pointer C is: " << &sharedPointerC << std::endl;
	std::cout << "The &* address of shared pointer C is: " << &*sharedPointerC << std::endl;
	std::cout << "The * value of the thing the shared pointer C points to is: " << *sharedPointerC << std::endl;
	std::cout << "The count of shared pointer A is: " << sharedPointerA.use_count() << std::endl;
	std::cout << "The count of shared pointer B is: " << sharedPointerB.use_count() << std::endl;
	std::cout << "The count of shared pointer C is: " << sharedPointerC.use_count() << std::endl;
	

	sharedPointerA = nullptr;

	std::cout << "The & address of shared pointer B is: " << &sharedPointerB << std::endl;
	std::cout << "The &* address of shared pointer B is: " << &*sharedPointerB << std::endl;
	std::cout << "The * value of the thing the shared pointer B points to is: " << *sharedPointerB << std::endl;
	std::cout << "The count of shared pointer B is: " << sharedPointerB.use_count() << std::endl;

	std::cout << "The & address of shared pointer C is: " << &sharedPointerC << std::endl;
	std::cout << "The &* address of shared pointer C is: " << &*sharedPointerC << std::endl;
	std::cout << "The * value of the thing the shared pointer C points to is: " << *sharedPointerC << std::endl;
	std::cout << "The count of shared pointer C is: " << sharedPointerC.use_count() << std::endl;
	

	
	
	
	//auto msp = std::make_shared<Example>(argument);

	
	sharedPointerA = nullptr;


	return;



}