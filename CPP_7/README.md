# Templates and STL

This module introduces C++ templates.

## Introduction

So what's a template ? Basically if you have a fonction that compares two values, of the same type of course, and return something like the max or the min value, if you want to use that same function with another type of value, like `double` or `float`, you will have to overload your function, as many time as you have to compate different types.

Here comes the templates. We learn in this module that you can pre fabricate your functions, so g++ or other compilation tools can write the code for you. Yes, litteraly, it generates the code for all the types you can receive. Here's an example.

## Example

```cpp
int	min(int a, int b) {
	return a < b ? a : b;
}

// Here if we want to use that with floats, we can't whitout writing this function :
float	min(float a, float b) {
	return a < b ? a : b;
}

// But you can also declare a function template like this
template< typename Type >
Type	min(Type a, Type b) {
	return a < b ? a : b;
}
```

With this last function, g++ will generate function for all generic types, you can for sur send two class if they have the <, >, <=, >=, ==, != overloads and can be compared with the ternary operation.

```cpp
// You can send different types like 
template< typename T, typename F>

// Or also declare a class template like this
template< typename T >
class Example {
	private:
		T	_secret;
};

Example<int>	example;
// Here example._secret is an integer
Example<std::string>	example;
// Here example._secret is a std::string
```

The standard template library is full of containers and some perfect template class like vectors, arrays, sets and many more.
The \<algorithm> can be used with template class so we can iterate or do operations the easy way on these template. 