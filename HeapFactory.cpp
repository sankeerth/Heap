#include "HeapFactory.h"

template <typename T>
Heap<T>* HeapFactory::create(HeapType type)
{
	switch(type) {
		case Min:
			return new MinHeap<T>();
		case Max:
			return new MaxHeap<T>();
	}
	return 0;
}