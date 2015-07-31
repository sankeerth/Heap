#ifndef HEAP_H
#define HEAP_H

#include "../graph/Graph.h"

template <typename T>
class Heap {
  public:
  	Heap();
  	virtual ~Heap();

    T getMinimum() { return getMin(); }
    T extractMinimum() {return extractMin(); }
    T getMaximum() { return getMax(); }
    T extractMaximum() {return getMin(); }
    void increaseKey(int index, int value) { increase(index, value); }
    void decreaseKey(int index, int value) { decrease(index, value); }
    void insertKey(T key) { insert(key); }
    void removeKey(int index) { remove(index); }
    bool isHeapFull();
    bool isHeapEmpty();
    void print();
  protected:
  	int left(int index) { return 2*index+1; }
    int right(int index) { return 2*index+2; }
    int parent(int index) { return (index-1)/2; }
    int getCurrentIndex() { return heap_size-1; }
  	void reallocate();
  	void swap(T& x, T& y);

  	T *heap_array;
  	int heap_size;  	
  private:
  	virtual void increase(int index, int value);
  	virtual void decrease(int index, int value);
  	virtual void insert(T key);
  	virtual void remove(int index);
  	virtual T getMin();
  	virtual T extractMin();
  	virtual T getMax();
  	virtual T extractMax();

  	int m_maxHeapSize;
};


#endif