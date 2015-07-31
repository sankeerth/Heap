#ifndef MAXHEAP_H
#define MAXHEAP_H

#include "heap.h"

template <typename T>
class MaxHeap : public Heap<T>
{
public:
	MaxHeap() {}
	~MaxHeap() {}
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