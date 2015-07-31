#include "MinHeap.h"
#include "log.h"
#include <limits.h>

template <typename T>
void MinHeap<T>::insert(T key)
{
	if (Heap<T>::isHeapFull()) {
		Heap<T>::reallocate();
	}

    Heap<T>::heap_size++;
	int index = Heap<T>::getCurrentIndex();
	Heap<T>::heap_array[index] = key;

	while (index > 0 && (Heap<T>::heap_array[index] < Heap<T>::heap_array[Heap<T>::parent(index)])) {
		Heap<T>::swap(Heap<T>::heap_array[index], Heap<T>::heap_array[Heap<T>::parent(index)]);
		index = Heap<T>::parent(index);
	}
}

template <typename T>
void MinHeap<T>::remove(int index)
{
	if (index > Heap<T>::getCurrentIndex()) {
		LOG("Index provided is greater than the number of elements in heap");
		return;
	}

	decrease(index, INT_MIN);
	extractMin();
}

template <typename T>
void MinHeap<T>::increase(int index, int value)
{
	if (Heap<T>::heap_array[index]->distance() > value) {
		LOG("Given value is greater than the one present at the index. \
				Call decrease instead");
	}
}

template <typename T>
void MinHeap<T>::decrease(int index, int value)
{
	if (Heap<T>::heap_array[index]->distance() < value) {
		LOG("Given value is greater than the one present at the index. \
				Call increase instead");
		return;
	}

	//Heap<T>::heap_array[index] = value;
	Heap<T>::heap_array[index]->set(value);

	while (index > 0 && (Heap<T>::heap_array[index] < Heap<T>::heap_array[Heap<T>::parent(index)])) {
		Heap<T>::swap(Heap<T>::heap_array[index], Heap<T>::heap_array[Heap<T>::parent(index)]);
		index = Heap<T>::parent(index);
	}
}

template <typename T>
T MinHeap<T>::getMin()
{
	if (Heap<T>::isHeapEmpty()) {
		LOG("Heap is empty");
		//return INT_MIN;
	}

	return Heap<T>::heap_array[0];
}

template <typename T>
T MinHeap<T>::extractMin()
{
	if (Heap<T>::isHeapEmpty()) {
		LOG("Heap is empty");
		//return INT_MIN;
	}

	if (Heap<T>::heap_size == 1) {
		Heap<T>::heap_size--;
		return Heap<T>::heap_array[0];
	}

	T minimum = Heap<T>::heap_array[0];
	Heap<T>::heap_array[0] = Heap<T>::heap_array[Heap<T>::getCurrentIndex()];
	Heap<T>::heap_size--;

	heapify(0);
	return minimum;
}

template <typename T>
T MinHeap<T>::getMax()
{
	LOG("Object of MinHeap is created. Need to create MaxHeap!!");
}

template <typename T>
T MinHeap<T>::extractMax()
{
	LOG("Object of MinHeap is created. Need to create MaxHeap!!");	
}

template <typename T>
void MinHeap<T>::heapify(int index)
{
	int minimum = index;

	if (Heap<T>::heap_array[minimum] > Heap<T>::heap_array[Heap<T>::left(index)] &&
		Heap<T>::left(index) < Heap<T>::heap_size) {
		minimum = Heap<T>::left(index);
	}

	if (Heap<T>::heap_array[minimum] > Heap<T>::heap_array[Heap<T>::right(index)] && 
		Heap<T>::right(index) < Heap<T>::heap_size) {
		minimum = Heap<T>::right(index);
	}

	if (minimum != index) {
		Heap<T>::swap(Heap<T>::heap_array[index], Heap<T>::heap_array[minimum]);
		heapify(minimum);
	}
}

//template class MinHeap<int>;
template class MinHeap<Node*>;