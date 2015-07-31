#include "MaxHeap.h"
#include "log.h"
#include <limits.h>

template <typename T>
void MaxHeap<T>::insert(T key)
{
	if (Heap<T>::isHeapFull()) {
		Heap<T>::reallocate();
	}

	Heap<T>::heap_size++;
	int index = Heap<T>::getCurrentIndex();
	Heap<T>::heap_array[index] = key;

	while (index > 0 && (Heap<T>::heap_array[index] > Heap<T>::heap_array[Heap<T>::parent(index)])) {
		Heap<T>::swap(Heap<T>::heap_array[index], Heap<T>::heap_array[Heap<T>::parent(index)]);
		index = Heap<T>::parent(index);
	}
}

template <typename T>
void MaxHeap<T>::remove(int index)
{
	if (index > Heap<T>::getCurrentIndex()) {
		LOG("Index provided is greater than the number of elements in heap");
		return;
	}

	increase(index, INT_MAX);
	extractMax();
}

template <typename T>
void MaxHeap<T>::increase(int index, int value)
{
	if (Heap<T>::heap_array[index]->distance() > value) {
		LOG("Given value is greater than the one present at the index. \
				Call decrease instead");
		return;
	}

	//Heap<T>::heap_array[index] = value;
	Heap<T>::heap_array[index]->set(value);

	while (index > 0 && (Heap<T>::heap_array[index] > Heap<T>::heap_array[Heap<T>::parent(index)])) {
		Heap<T>::swap(Heap<T>::heap_array[index], Heap<T>::heap_array[Heap<T>::parent(index)]);
		index = Heap<T>::parent(index);
	}
}

template <typename T>
void MaxHeap<T>::decrease(int index, int value)
{
	if (Heap<T>::heap_array[index]->distance() < value) {
		LOG("Given value is greater than the one present at the index. \
				Call increase instead");
		return;
	}
}

template <typename T>
T MaxHeap<T>::getMin()
{
	LOG("Object of MaxHeap is created. Need to create MinHeap!!");
}

template <typename T>
T MaxHeap<T>::extractMin()
{
	LOG("Object of MaxHeap is created. Need to create MinHeap!!");
}

template <typename T>
T MaxHeap<T>::getMax()
{
	if (Heap<T>::isHeapEmpty()) {
		LOG("heap is empty");
		//return INT_MAX;
	}

	return Heap<T>::heap_array[0];
}

template <typename T>
T MaxHeap<T>::extractMax()
{
	if (Heap<T>::isHeapEmpty()) {
		LOG("heap is empty");
		//return INT_MAX;
	}

	if (Heap<T>::heap_size == 1) {
		Heap<T>::heap_size--;
		return Heap<T>::heap_array[0];
	}

	T maximum = Heap<T>::heap_array[0];
	Heap<T>::heap_array[0] = Heap<T>::heap_array[Heap<T>::getCurrentIndex()];
	Heap<T>::heap_size--;

	heapify(0);
	return maximum;
}

template <typename T>
void MaxHeap<T>::heapify(int index)
{
	int maximum = index;

	if (Heap<T>::heap_array[maximum] < Heap<T>::heap_array[Heap<T>::left(index)] && 
		Heap<T>::left(index) < Heap<T>::heap_size) {
		maximum = Heap<T>::left(index);
	}

	if (Heap<T>::heap_array[maximum] < Heap<T>::heap_array[Heap<T>::right(index)] &&
		Heap<T>::right(index) < Heap<T>::heap_size) {
		maximum = Heap<T>::right(index);
	}

	if (index != maximum) {
		Heap<T>::swap(Heap<T>::heap_array[index], Heap<T>::heap_array[maximum]);
		heapify(maximum);
	}
}

//template class MaxHeap<int>;
template class MaxHeap<Node*>;