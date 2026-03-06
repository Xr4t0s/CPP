#include "utils/Types.hpp"

OutputChar::OutputChar() : self(0), displayable(false), error(false) {}
OutputInt::OutputInt() : self(0), displayable(false), error(false) {}
OutputDouble::OutputDouble() : self(0), displayable(false), error(false) {}
OutputFloat::OutputFloat() : self(0), displayable(false), error(false) {}

OutputChar::OutputChar(const OutputChar& copy) : self(copy.self), displayable(copy.displayable), error(copy.error) {}
OutputInt::OutputInt(const OutputInt& copy) : self(copy.self), displayable(copy.displayable), error(copy.error) {}
OutputDouble::OutputDouble(const OutputDouble& copy) : self(copy.self), displayable(copy.displayable), error(copy.error) {}
OutputFloat::OutputFloat(const OutputFloat& copy) : self(copy.self), displayable(copy.displayable), error(copy.error) {}

OutputChar&	OutputChar::operator=(const OutputChar& rhs) {
	if (this != &rhs) {
		this->self = rhs.self;
		this->displayable = rhs.displayable;
		this->error = rhs.error;
	}
	return *this;
}
OutputInt&	OutputInt::operator=(const OutputInt& rhs) {
	if (this != &rhs) {
		this->self = rhs.self;
		this->displayable = rhs.displayable;
		this->error = rhs.error;
	}
	return *this;
}
OutputDouble&	OutputDouble::operator=(const OutputDouble& rhs) {
	if (this != &rhs) {
		this->self = rhs.self;
		this->displayable = rhs.displayable;
		this->error = rhs.error;
	}
	return *this;
}
OutputFloat&	OutputFloat::operator=(const OutputFloat& rhs) {
	if (this != &rhs) {
		this->self = rhs.self;
		this->displayable = rhs.displayable;
		this->error = rhs.error;
	}
	return *this;
}

void	OutputChar::display() const {
	if (this->displayable) {
		std::cout << "char\t\t: '" << this->self << "'" << std::endl;
	} else {
		if (this->error)
			std::cout << "char\t\t: " << "impossible" << std::endl;
		else
			std::cout << "char\t\t: " << "non displayable" << std::endl;
	}
}
void	OutputInt::display() const {
	if (this->displayable) {
		std::cout << "int\t\t: " << this->self << std::endl;
	} else {
		if (this->error)
			std::cout << "int\t\t: " << "impossible" << std::endl;
		else
			std::cout << "int\t\t: " << "non displayable" << std::endl;
	}
}
void	OutputDouble::display() const {
	if (this->displayable) {
		std::cout << "double\t\t: " << this->self << (std::fmod(this->self, 1.0) == 0.0 ? ".0" : "") << std::endl;
	} else {
		if (this->error)
			std::cout << "double\t\t: " << "impossible" << std::endl;
		else
			std::cout << "double\t\t: " << "non displayable" << std::endl;
	}
}
void	OutputFloat::display() const {
	if (this->displayable) {
		std::cout << "float\t\t: " << this->self << (std::fmod(this->self, 1.0f) == 0.0f ? ".0f" : "f") << std::endl;
	} else {
		if (this->error)
			std::cout << "float\t\t: " << "impossible" << std::endl;
		else
			std::cout << "float\t\t: " << "non displayable" << std::endl;
	}
}

OutputChar::~OutputChar() {}
OutputInt::~OutputInt() {}
OutputDouble::~OutputDouble() {}
OutputFloat::~OutputFloat() {}