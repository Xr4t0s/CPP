# 🗿 Static casts

## Introduction

In this module, we will learn how to use **C++ casts**. There's different type of casts in C++ :
-	static_cast<>
-	reinterpret_cast<>
-	dynamic_cast<>
- (const_cast<>)

> With those, you can upcast and downcast the data you're manipulating


## EX00
For this first exercise, we've only used the **static_cast** on our variables to simply interpret them like we want, but we had to make sure we're not loosing precision because between different types, bits aren't ordered the same way (like for an integer and a double/float).

## EX01
For the second exercice we learn how to use reintepret cast to force our custom interpretation if we're already sure about what we receive. So basically if a raw octet-stream is received in input and you know what structure is hidding behind this stream, you can for sur reintepret it like you want.

## EX03
In the third exercice, we learn how to use dynamic cast on pointers and references, we learn how to try an interpretation and manipulate the result

## Examples
```cpp
static_cast<int>('4'); // 52
static_cast<double>(42.42f); // 42.42
static_cast<float>(42);	// 42.0f
```

```cpp
// From data to octet stream for example
uintptr_t Serializer::serialize(Data* ptr) {
	uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);

	return raw;
}

// Reverse function to interpret octet stream like Data*
Data*			Serializer::deserialize(uintptr_t raw) {
	Data* data = reinterpret_cast<Data *>(raw);

	return data;
}
```

```cpp
// Dynamic cast on pointer
Base* ret = dynamic_cast<A*>(p);
if (!ret) {
	std::cout << "Type of pointer is not A" << std::endl;
	// <SNIP>
}

// Dynamic cast on reference
try {
	Base& ret1 = dynamic_cast<A&>(p);
	std::cout << "Type of reference is A" << std::endl;
	static_cast<void>(ret1);
} catch (std::exception& bc) {
	std::cout << "Cast error : " << bc.what() << std::endl;
	// <SNIP>
}
```
> Note that after these operations, you will store values over various forms, if you don't know what you're doing you risks to loose precision or precious data from what you're trying to cast.