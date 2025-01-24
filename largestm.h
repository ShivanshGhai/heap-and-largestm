#include <vector>
#include <iostream>
#include "HeapT.h"

template <typename T>
vector<T> largestm(const vector<T>& vec, int m){
    if (m==0){
        return vec;
    }

    // Define a heap of size m
    HeapT<T> heap(m);
    //Iterate through the entire vector
    for (int i=0; i<vec.size(); i++){
        // Insert elements in the heap until m
        if (heap.size() < m){
            heap.insert(vec[i]);
        }
        // Check whether the root is smaller than the remaining elements
        else if (vec[i]>heap.peek()){
            heap.remove();
            heap.insert(vec[i]);
        }
    }

    // Create a vector result 
    vector<T> result;
    while (heap.size()>0){
        // Insert the elements in result
        result.insert(result.begin(), heap.remove());
    }

    // return result
    return result;
}