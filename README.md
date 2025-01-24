# **HeapT Class and `largestm` Template Function**

This project includes the **HeapT** class and a standalone template function, `largestm`, demonstrating a robust Min-Heap implementation and an efficient algorithm for finding the largest elements in a collection.

---

## Features

## **HeapT Class**

The HeapT class is a template-based dynamic Min-Heap. It provides functionality for managing a priority queue efficiently and supports any comparable data type.

1. **Key Features**:

    - **Dynamic Min-Heap**: The heap is implemented using a dynamically allocated array. Efficient methods ensure heap property maintenance during insertions and removals.
    - **Template Support**: Generic design allows storing any data type that supports comparison.

2. **Key Methods**:

    - **Constructor**: Initializes the heap with a specified capacity.
    - **Copy Constructor**: Creates a deep copy of an existing heap.
    - **Destructor**: Frees dynamically allocated memory.
    - **Assignment Operator**: Handles deep copy and self-assignment.=
    - **Insert**: Adds an element while maintaining the Min-Heap property using the bubbleUp helper method.
    - **Remove**: Removes and returns the root element (smallest) using the bubbleDown helper method.
    - **Peek**: Returns the smallest element without removing it.
    - **Merge**: Combines two heaps into a new one by inserting elements from both heaps.
    - **Size**: Returns the number of elements in the heap.

3. **Helper Methods**:

    - **Bubble Up**: Restores the heap property after insertion.
    - **Bubble Down**: Restores the heap property after removal.
    - **Swap**: Swaps two elements in the array.   
    - **Copy From**: Copies elements from one heap to another.

---
## **`largestm` Template Function**

The largestm function extracts the `m` largest elements from a vector efficiently by utilizing the HeapT class.

1. **Key Features**:

    - Maintains a Min-Heap of size m to track the largest elements. Ensures a time complexity of `O(nlogm)`, where n is the size of the input vector.
    - Handles edge cases, such as:
        - `m = 0`: Returns an empty vector.
        - `m > vector size`: Includes all elements in the result.

2. **Parameters**:

    - `const std::vector<T>& vec`: Input vector of elements of type T.
    - `int m`: Number of largest elements to extract.

3. **Return Value**:

     A vector containing the m largest elements in descending order.
   
4. **Algorithm Overview**:

    - Initializes a Min-Heap of size `m`.
    - Iterates through the vector:
        - Inserts elements into the heap until it reaches capacity.
        - Replaces the root (smallest in the heap) if a larger element is encountered.
    - Extracts elements from the heap and stores them in descending order in the result vector.
  
---

## **Code Files**: 
  `HeapT.h` 
   defines the HeapT template class, implementing:

  - Dynamic array management.
  - Min-Heap operations (insert, remove, peek).
  - Helper methods (bubbleUp, bubbleDown).

  `largestm.h` 
   defines the largestm template function:

  - Utilizes the HeapT class for efficient processing.
  - Ensures the result vector is sorted in descending order.

---

## **How to use**:

1. **Clone the repository**:
   ```bash
   git clone https://github.com/yourusername/heap-and-largestm.git
   cd heap-and-largestm

2. **Include the HeapT.h and `largestm.h` headers in your project**:
   ```bash
   #include "HeapT.h"
   #include "largestm.h"

3. **Use the HeapT class or the `largestm` function in your application**:
   ```bash
   std::vector<int> vec = {10, 20, 5, 3, 15};
   int m = 3;
   std::vector<int> largest = largestm(vec, m);

   for (int num : largest) {
    std::cout << num << " ";
   }
   // Output: 20 15 10
