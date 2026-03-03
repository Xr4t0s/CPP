# 📜 **Forms**

## **🚀  Introduction**

In this module, we will try harder to understand how **exceptions** have to be handled if you have a lot of **exception types**.

> **Managing and handling errors** in our programs is **absolutely necessary** when our code comes to be bigger and a lot more modular, we will need to know **what**'s going on, **when**, and **where** it's going on. It's useful when you have a **lot of operations in a row**, but for with simple functions like boolean or else, it's overkill, so **don't spam**.

---

## **Forms**

### The subject ask us trop create a **Form** class that have some private attributes :
- the **name** of the form
- the **signed status** of the form
- a **minimum grade to sign** this form
- a **minimum grade to execute** this form

We add our errors, implements base functions and getters, like [this].

[this]: include/Form.hpp

Then we have to create `beSigned()` function, that takes a Bureaucrat as a parameter, and change de signed status if the grade of the Bureaucrat is high enough to do this action. This function **have to throw a Form::Exception**.

> 1. The subject asks :
add a beSigned() member function ... that takes a Bureaucrat as a
parameter .. changes the form’s status .. if the bureaucrat’s grade is high enough ... Remember, grade 1 is higher than grade 2.
> 2. **If the grade is too low, throw a Form::GradeTooLowException.** We have to compare Bureaucrat grade to Form required grade, so if the Bureaucrat can't sign, that means that the Form grade is **too high**, and not too low, so we preferred to throw the Bureaucrat exception here.

```cpp
void	Form::beSigned( const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > this->_signReqGrade)
		// throw Form::GradeTooHighException();
		throw Bureaucrat::GradeTooLowException(); 	// subject ask for AForm::GradeTooLow
	_signed = true;
}
```

### Now we can do something like this : 

```cpp
#include <iostream>

class Bureaucrat {
	private:
		const std::string 	_name;
		int					_grade;
	
	public:
		struct GradeTooHighException : std::exception {
			public:
				const char* what() const throw();
		};
		struct GradeTooLowException : std::exception {
			public:
				const char* what() const throw();
		};
		// ...
		const std::string& 	getName( void ) const;
		const int&			getGrade( void ) const;

		void upgrade( void );
		void downgrade( void );

		void signForm( Form& );
		// ...
};

class Form {
	private:
		const std::string	_name;
		bool				_signed;
		const int			_signReqGrade;
		const int			_execReqGrade;
	
	public:
		struct GradeTooHighException : std::exception {
			public:
				const char* what() const throw();
		};
		struct GradeTooLowException : std::exception {
			public:
				const char* what() const throw();
		};
		// ...		
		const std::string& 	getName( void ) const;
		bool				getSigned( void ) const;
		const int&			getSignGrade( void ) const;
		const int&			getExecGrade( void ) const;

		void beSigned( const Bureaucrat& bureaucrat);
		// ...
};

int main() {
	try {
		Form
	}
}

```
