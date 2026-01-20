# 🤵‍♂️ **Bureaucrat**

## **🗒️ Introduction**

In this module, we learn about how you can manage your own *try-catch* op with **exceptions**.
We learn that you can create *class* (or *struct*) to define your own **exceptions**.

We learn how to herit from *std::exception* and how to handle *throwing* exceptions with the **throw** keyword, and also to *catch* with de **catch** keyword, while *trying* with the **try** keyword. Rude to understand, but really useful in production.

> **Managing and handling errors** in our programs is **absolutely necessary** when our code comes to be bigger and a lot more modular, we will need to know **what**'s going on, **when**, and **where** it's going on. It's useful when you have a **lot of operations in a row**, but for with simple functions like boolean or else, it's overkill, so please **don't spam**. 

---

## **Exceptions**

> Here we declare an error as a *struct* because heritage is public by default

### An **exception** can be constructed like that :

> This is an error that can be throwed 🔽
```cpp
struct SpamError : std::exception {
	public:
		const char*	what() const throw();
}
```

> This is a class containing this Error 🔽
```cpp
class Errors {
	public:
		Errors();
		// ...
		struct SpamError : std::exception {
			public:
				const char*	what() const throw();
		}
		// ...
		~Errors();
}
```
> My [bureaucrat implementation]

[bureaucrat implementation]: include/Bureaucrat.hpp

---

### Now, we want to use this to **handle an error**, in this example we :
- **Create an *Errors* class**
- **Declare a *SpamError* struct inside, who herits from std::exception**
- **Override *what()***
- **Throw the error when you have too**
- **Catch it when you have too**

```cpp
#include <iostream>

// Of course we put exceptions in concerned class
class Errors {
	public:

		// ...
		
		struct SpamError : std::exception { // Our exception
			public:
				const char*	what() const throw();
		};

		// ...
		
		void someFunction( void );
		
		// ...
};

// We override std::exception::what() function to allow returning custom errors
const char*	Errors::SpamError::what() const throw() {
	return "Target can't process, stop spamming";
}

// Function that throw in case of spam 
void Errors::someFunction( void ) {
	if (true) {
		throw Errors::SpamError();
	}
}

int main() {
	Errors err;

	try {
		err.someFunction(); // If spammed, function will throw something...
	} catch (std::exception& e) { // ...and we catch it here, ...
		std::cout << e.what() << std::endl; // ...then we use what to print the value of the error
	}

	return 0;
}
```

It gives :
```bash
➜  CPP_5 git:(main) ✗ ./a.out
Target can't process, stop spamming
```

That's all, nothing else here but creating the Bureaucrat class : you can see [here] in the definitions, the constructors and the upgrade and downgrade functions verifies if grades are not over/underflowing, and if it's the case, they throws correctly errors so we can catch them in [main].

[here]: src/Bureaucrat.cpp 
[main]: src/main.cpp

## **Notes**
- You can see that we used `catch (std::exception& e) {...}` to catch our exception as a reference, because if we don't , polymorphism **will not be respected** and so, the `what()` function will not be **interpreted as overrided**, and you will see the basic `what()` message when you catch your error, so don't forget that : **always catch custom errors as references.**

- We can also **re-throw** something to a higher *catch*, like that :
```cpp
try {
	err.someFunction();
} catch (std::exception& e) {
	std::cout << e.what() << std::endl;
	throw ; // Here we throw
}
```
We want to write `throw e;`, right ? Because we want to rethrow the same error. But no, we don't because C++ throw what's already thrown, so here an *SpamError*. But if you **throw *e***, *e* will be interpret as a std::exception. I think you can also cast the return but it's obviously useless to do something like that. 
