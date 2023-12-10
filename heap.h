#ifndef HEAP_H
#define HEAP_H
#include <vector>
#include <cstddef>

class MaxHeap {
private:
	std::vector<int> heap;
	
private:
	void buildHeap(std::vector<int>&);//in root i'll have max elemnt
	void MaxHeapify(std::vector<int>&, size_t index,size_t);//with recursion i'll have rule of heap, paremt[i] >= his childs
	size_t getLeft(size_t) const;
	size_t getRight(size_t) const;
	size_t getParent(size_t) const;

public:
	MaxHeap() = default;
	MaxHeap(std::vector<int>&&);
	void insert(int);
	int extractMax();
	void increaseKey(size_t, int);
	void heapSort();
	void print();
	  
	
};
#endif //HEAP_H

