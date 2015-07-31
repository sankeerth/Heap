#include "heap.h"
#include "log.h"

namespace {
	const int HEAP_START_SIZE = 20;
}

template <typename T>
Heap<T>::Heap()
	: heap_size(0)
	, m_maxHeapSize(HEAP_START_SIZE)
{
	heap_array = new T [HEAP_START_SIZE];
}

template <typename T>
Heap<T>::~Heap()
{
	LOG("Dtor");
	delete [] heap_array;
}

template <typename T>
T Heap<T>::getMin()
{
	LOG("Implemented in derived class");
}

template <typename T>
T Heap<T>::extractMin()
{
	LOG("Implemented in derived class");
}

template <typename T>
T Heap<T>::getMax()
{
	LOG("Implemented in derived class");
}

template <typename T>
T Heap<T>::extractMax()
{
	LOG("Implemented in derived class");
}

template <typename T>
void Heap<T>::increase(int index, int value)
{
	LOG("Implemented in derived class");
}

template <typename T>
void Heap<T>::decrease(int index, int value)
{
	LOG("Implemented in derived class");
}

template <typename T>
void Heap<T>::insert(T key)
{
	LOG("Implemented in derived class");
}

template <typename T>
void Heap<T>::remove(int index)
{
	LOG("Implemented in derived class");
}

template <typename T>
bool Heap<T>::isHeapFull()
{
	return (m_maxHeapSize == heap_size); 
}

template <typename T>
bool Heap<T>::isHeapEmpty()
{
	return (heap_size == 0);
}

template <typename T>
void Heap<T>::reallocate()
{
	heap_size = heap_size*2;
	T *heap = new T [heap_size];
	for (int i = 0; i < heap_size/2; ++i) {
		heap[i] = heap_array[i];
	}

	delete [] heap_array;
	heap_array = heap;
}

template <typename T>
void Heap<T>::swap(T& x, T& y)
{
	T temp = x;
	x = y;
	y = temp;
}

template <typename T>
void Heap<T>::print()
{
	for (int i = 0; i < heap_size; i++) {
		//LOG(heap_array[i]);
	}
}

//template class Heap<int>;
template class Heap<Node*>;