# STL Containers

## Introduction

In this module we will learn about STL containers. What's that ? STL containers are standard containers use to store a stack, so a bloc on N elements, with different structure types.
If you already use "vector" "deque" or other you may be already familiar with that.

### Templated containers
The STL is the "Standard Template Library" and store a lot of useful templates of class and functions like vectors, deque, and many others, that wraps specific types inside it that we mention with 
```cpp
vector<int> int_vector; // Int vector
deque<char> char_deque; // Char deque
```

### Iterators
An iterator is an index in the container type. If you use Vector, Vector::iterator is the iterator type of Vector, a useful type we can use to find, manipulate data.
```cpp
typedef typename std::stack<int>::container_type::iterator iterator; // iterator for stack<int> container.
```

### Algorithms 
Algorithms are a part of the STL, and are used to manipulate data inside or outside templated containers.
