#ifndef MINHEAP_H
#define MINHEAP_H

#include "heap.h"

template <typename T>
class MinHeap : public Heap<T>
{
public:
	MinHeap() {}
	~MinHeap() {}
private:
	void insert(T key);
	void remove(int index);
	void increase(int index, int value);
  	void decrease(int index, int value);
	T getMin();
  	T extractMin();
  	T getMax();
  	T extractMax();
	void heapify(int index);
};

#endif