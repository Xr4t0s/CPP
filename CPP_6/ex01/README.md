# 🗿 Reinterpret casts

## Introduction

In this module, we will learn how to use **C++ casts**. There's different type of casts in C++ :
-	static_cast<>
-	reinterpret_cast<>
-	dynamic_cast<>
- (const_cast<>)

> With those, you can upcast and downcast the data you're manipulating

For this second exercise, we've only used the **reinterpret_cast** on our variables to simply reinterpret them like we want, but we had to make sure we're not loosing precision because between different types, bits aren't ordered the same way (like for an integer and a double/float).

## Proof-of-concept
I will show you the part we enter in if you send a character in input.

```cpp
case CHAR:
	this->output_char.displayable = std::isprint(this->output_char.self);
	this->output_char.error = false;

	this->output_int.self = static_cast<int>(this->output_char.self);
	this->output_int.displayable = true;
	
	this->output_double.self = static_cast<double>(this->output_char.self);
	this->output_double.displayable = true;

	this->output_float.self = static_cast<float>(this->output_char.self);
	this->output_float.displayable = true;
	
	break;
```

So basically here in case of CHAR, we already have the character stored into `this->output_char.self`. So we cast this variable to create the others from it, like that : 
```cpp
static_cast<int>(this->output_char.self);
static_cast<double>(this->output_char.self);
static_cast<float>(this->output_char.self);
```

> Note that after this operation, you will store the value over various forms, if you don't know what you're doing you risks to loose precision or precious data from what you're trying to cast.