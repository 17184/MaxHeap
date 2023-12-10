#include <iostream>
#include <stdexcept>
#include "heap.h"

int main()
{
	try {
		std::vector<int> myVector = {4, -7, 10, 3, 5, 1};
		MaxHeap mh(std::move(myVector));  // Use std::move to convert lvalue to rvalue

		mh.print();
		mh.increaseKey(2,20 );
		std::cout << "Index of 2 will be value of 10  - ";
		mh.print();
		mh.heapSort();
		std::cout << "After sort function - ";
		mh.print();
	} catch(const std::exception& e) {
		std::cerr << "Error: "  << e.what() << std::endl;
	}
}

