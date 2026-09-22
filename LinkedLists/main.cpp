/*
Brandon Fisher
Main implementation file
*/ 



#include "LinkedList.h"
#include <iostream>
#include <vector>


int main() {
	LinkedList<int> list;
	std::cout << "Add 1 to the list: " << std::endl;
	list.addNode(1);
	//Create a list to track odd numbers...you'll see why...
	std::vector<int> oddNums;
	int count = list.getSize();

	std::cout << list << '\n' << std::endl;
	std::cout << "Count: " <<  count << '\n' << std::endl;

	std::cout << "Count to 500: " << std::endl;
	for (int i = 2; i < 501; ++i) {
		list.addNode(i);
		count = list.getSize();
		if ((i % 2) == 1) {
			//append to that odd list we were talking about earlier
			oddNums.push_back(i);
		}
	}

	for (int i = 0; i < 10; ++i) {
		bool foundNode = list.findNode(oddNums[i]);
		std::cout << "Found " << oddNums[i] << ": " << std::boolalpha << foundNode << std::endl;
	}

	std::cout << list << '\n' << std::endl;
	std::cout << "Count: " << count << '\n' << std::endl;

	std::cout << "Now delete all the odd Numbers (not including 1...): " << std::endl;
	for (int i = 0; i < oddNums.size(); ++i) {
		//Here's where that list is useful
		list.removeNode(oddNums[i]);
		count = list.getSize();
	}

	for (int i = 0; i < 10; ++i) {
		bool foundNode = list.findNode(oddNums[i]);
		std::cout << "Found " << oddNums[i] << ": " << std::boolalpha << foundNode << std::endl;
	}

	std::cout << list << '\n' << std::endl;
	std::cout << "Count: " << count << '\n' << std::endl;
	
	std::cout << "Remove First and Last numbers: " << std::endl;
	list.removeNode(1);
	list.removeNode(500);
	count = list.getSize();

	std::cout << list << '\n' << std::endl;
	std::cout << "Count: " << count << '\n' << std::endl;


	std::cout << "Now try to remove odd numbers again..." << std::endl;
	for (int i = 0; i < oddNums.size(); ++i) {
		//That list again...
		list.removeNode(oddNums[i]);
		
	}
	count = list.getSize();
	std::cout << list << '\n' << std::endl;
	std::cout << "Count: " << count << '\n' << std::endl;

	
	std::cout << "El Fin :)" << std::endl;

}