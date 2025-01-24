#pragma once
#include <stdexcept>
#include <iostream>

using namespace std;
using std::out_of_range;

template <class T>
class HeapT
{
public:
    // Constructor
    HeapT(int n);
    // Copy constructor
    HeapT(const HeapT& other);
    // Destructor
    ~HeapT();
    // Operator
    HeapT& operator=(const HeapT& other);
    // Insert function
    void insert(const T& val);
    // Remove function
    T remove();
    // Peek function
    T peek() const;
    // Merge function
    HeapT merge(const HeapT& other) const;
    // Size function
    int size() const;

private:
    // 
    T* arr;
    int elementCount;
    int capacity;

    //Helper methods
    void bubbleUp(int index);
    void bubbleDown(int index);
    void swap(T& a, T& b);
    void copyFrom(const HeapT& other);
};

// Constructor
template <class T>
HeapT<T>::HeapT(int n){
    arr = new T[n];
    capacity = n;
    elementCount = 0;
}

// Destructor
template <class T>
HeapT<T>::~HeapT(){
    delete[] arr;
}

// Copy constructor
template <class T>
HeapT<T>::HeapT(const HeapT& other){
    capacity = other.capacity;
    elementCount = other.elementCount;
    arr = new T[capacity];
    copyFrom(other);
}

// Assignment operator
template <class T>
HeapT<T>& HeapT<T>::operator=(const HeapT& other) {
    if (this != &other) {
        delete[] arr;
        capacity = other.capacity;
        elementCount = other.elementCount;
        arr = new T[capacity];
        copyFrom(other);
    }
    return *this;
}

// Insert Method
template <class T>
void HeapT<T>::insert(const T& val){
    // Check if the heap is full
    if (elementCount==capacity){
        throw::runtime_error("Array is full");
    }

    else{
        // Insert element at the last position
        arr[elementCount] = val;
        // Use bubble up to rearrange
        bubbleUp(elementCount);
        // Increase element count
        elementCount++;
    }
}

// Remove Method
template <class T>
T HeapT<T>::remove(){
    // Check if the heap is empty
    if (elementCount==0){
        throw::runtime_error("Array is empty");
    }

    else{
        // Store the value of root node
        T root = arr[0];
        // Swap the root node with last element
        arr[0] = arr[elementCount-1];
        // Reduce element count
        elementCount--;
        // Use bubble down to rearrange
        bubbleDown(0);
        return root;
    }
}

template <class T>
T HeapT<T>::peek() const{
    // Check if the heap is empty
    if (elementCount==0){
        throw::runtime_error("Array is empty");
    }

    else{
        return arr[0];
    }
}

template <class T>
HeapT<T> HeapT<T>::merge(const HeapT& other) const{
    // Create a new heap 
    HeapT merged(capacity + other.capacity);
    // Insert elements in the new heap from heap 1
    for (int i = 0; i<elementCount; i++){
        merged.insert(arr[i]);
    }
     // Insert elements in the new heap from heap 2
    for (int i = 0; i<other.elementCount; i++){
        merged.insert(other.arr[i]);
    }
    return merged;
}

template <class T>
int HeapT<T>::size() const{
    return elementCount;
}

template <class T>
void HeapT<T>::bubbleUp(int index) {
    // Check if the index is 0
    if (index==0){
        return;
    }
    // Define parent node
    int parent = (index - 1) / 2;
    // For min heap, parent should be smaller than child
    // Check if parent is greater than child
    if (index > 0 && arr[index] < arr[parent]){
        // Swap
        swap(arr[index], arr[parent]);
        // Re check using parent as index
        bubbleUp(parent);
    }
}

template <class T>
void HeapT<T>::bubbleDown(int index) {
    // Take root node to correct position
    // Define the left & right children
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int smallest = index;

    // For min heap, parent should be smaller than child
    // Check if root is greater than left child
    if (left < elementCount && arr[left] < arr[smallest]) {
        smallest = left;
    }
    // Check again if root is greater than right child
    if (right < elementCount && arr[right] < arr[smallest]) {
        smallest = right;
    }
    // Swap the elements and recheck
    if (smallest != index) {
        swap(arr[index], arr[smallest]);
        bubbleDown(smallest);
    }
}

template <class T>
void HeapT<T>::swap(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}

template <class T>
void HeapT<T>::copyFrom(const HeapT& other) {
    for (int i = 0; i < other.elementCount; ++i) {
        arr[i] = other.arr[i];
    }
}