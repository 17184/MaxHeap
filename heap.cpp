#include <algorithm>
#include <iostream>
#include <vector>
#include "heap.h"

void maxHeapify(std::vector<int>& arr, size_t index, size_t heapSize) {
    size_t left = 2 * index + 1;
    size_t right = 2 * index + 2;
    size_t largest = index;

    if (left < heapSize && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < heapSize && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != index) {
        std::swap(arr[index], arr[largest]);
        maxHeapify(arr, largest, heapSize);
    }
}

void buildMaxHeap(std::vector<int>& arr) {
    size_t heapSize = arr.size();
    for (int i = heapSize / 2 - 1; i >= 0; --i) {
        maxHeapify(arr, i, heapSize);
    }
}

void heapSort(std::vector<int>& arr) {
    size_t heapSize = arr.size();
    buildMaxHeap(arr);

    for (int i = heapSize - 1; i > 0; --i) {
        std::swap(arr[0], arr[i]);
        maxHeapify(arr, 0, i);
    }
}

void MaxHeap::buildHeap(std::vector<int>& heap) {
    for (int i = heap.size() / 2 - 1; i >= 0; --i) {
        maxHeapify(heap, i, heap.size());
    }
}

size_t MaxHeap::getLeft(size_t index) const {
	return 2 * index + 1;
}

size_t MaxHeap::getRight(size_t index) const {
	return 2 * index + 2;
}

size_t MaxHeap::getParent(size_t index) const {
	return (index - 1) / 2;
}

MaxHeap::MaxHeap(std::vector<int>&& v) : heap(v){
	buildHeap(v);
} 
void MaxHeap::insert(int val) {
    heap.push_back(val);
    int idx = heap.size() - 1;
    while (idx > 0 && heap[getParent(idx)] < heap[idx]) {
        std::swap(heap[idx], heap[getParent(idx)]);
        idx = getParent(idx);
    }
}

int MaxHeap::extractMax() {
    if (heap.empty()) {
        throw std::out_of_range("Heap is empty\n");
    }
    int mx = heap.front();
    heap[0] = heap.back();
    heap.pop_back();
    maxHeapify(heap, 0, heap.size());
    return mx;
}

void MaxHeap::increaseKey(size_t idx, int newVal) {
    if (idx >= 0 && idx < heap.size() && newVal > heap[idx]) {
        heap[idx] = newVal;
        while (idx > 0 && heap[getParent(idx)] < heap[idx]) {
            std::swap(heap[idx], heap[getParent(idx)]);
            idx = getParent(idx);
        }
    } else {
        throw std::out_of_range("Invalid input or index or you need to input a bigger value than the current heap[index]\n");
    }
}

void MaxHeap::heapSort() {
    buildHeap(heap);
    for (int i = heap.size() - 1; i > 0; --i) {
        std::swap(heap[0], heap[i]);
        maxHeapify(heap, 0, i);
    }
}

void MaxHeap::print() {
    for (int i = 0; i < heap.size(); ++i) {
        std::cout << heap[i] << " ";
    }
    std::cout << std::endl;
}

