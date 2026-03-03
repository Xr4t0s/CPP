# 👥 **Intern**

## **🚀  Introduction**

In this exercice we will delegate the creation of the forms to an Intern. He will be able to create form, using the function `AForm* makeForm(const std::string& name, const std::string& target);`.

Let's get into this.

```cpp
AForm*	Intern::makeForm(const std::string& name, const std::string& target) {
	const std::string forms[3] = {
		"shrubbery request",
		"robotomy request",
		"presidential request"
	};

	AForm* (*func_ptr[3])(const std::string&) = {
		&shruberry,
		&robotomy,
		&president
	};

	for (int i = 0; i < 3; i++) {
		if (forms[i] == name) {
			std::cout << "Intern creates " << name << std::endl;
			return func_ptr[i](target);
		}
	}

	std::cout << "Intern couldn't create form \"" << name << "\"" << std::endl;
	return NULL;
}
```

Here we use function pointers to select the good form, create it, and return it to the caller.

We can now use the Intern like that :
```cpp
Bureaucrat boss(1, "Boss");
Intern someRandomIntern;
AForm* form;

form = someRandomIntern.makeForm("presidential request", "Boss");

try {
	boss.signForm(*form);
	boss.executeForm(*form);
} catch (std::exception& e) {}
```

All the creations will pass by a random Intern so bureaucrat can do their job lol.
