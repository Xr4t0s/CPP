#include "utils/Output.hpp"

Output::Output() {}

Output::Output(const Output& copy) :
	output_char(copy.output_char),
	output_int(copy.output_int),
	output_double(copy.output_double),
	output_float(copy.output_float)
{}

Output& Output::operator=(const Output& rhs) {
	if (this != &rhs) {
		this->output_char = rhs.output_char;
		this->output_int = rhs.output_int;
		this->output_double = rhs.output_double;
		this->output_float = rhs.output_float;
	}
	return *this;
}

void Output::display() const {
	this->output_char.display();
	this->output_int.display();
	this->output_float.display();
	this->output_double.display();
}

void Output::complete_from(const Type& from, bool display) {
	switch (from) {
		case CHAR:
			this->output_char.displayable = std::isprint(this->output_char.self);
			this->output_char.error = false;

			this->output_int.self = static_cast<int>(this->output_char.self);
			this->output_int.displayable = true;
			
			this->output_double.self = static_cast<double>(output_char.self);
			this->output_double.displayable = true;

			this->output_float.self = static_cast<float>(output_char.self);
			this->output_float.displayable = true;
			
			break;

		case INT:
			this->output_int.displayable = true;
			this->output_int.error = false;

			this->output_double.self = static_cast<double>(this->output_int.self);
			this->output_double.displayable = true;
			
			this->output_char.self = static_cast<char>(output_int.self);
			this->output_char.displayable = std::isprint(this->output_int.self);
			if (!this->output_char.displayable) {
				if (this->output_int.self < 0 || this->output_int.self > 127)
					this->output_char.error = true;
			}

			this->output_float.self = static_cast<float>(output_int.self);
			this->output_float.displayable = true;

			break;

		case DOUBLE:
			this->output_double.displayable = true;
			this->output_double.error = false;

			if (std::isinf(this->output_double.self) || std::isnan(this->output_double.self)) {
				this->output_char.displayable = false;
				this->output_char.error = true;

				this->output_int.displayable = false;
				this->output_int.error = true;

				this->output_float.self = static_cast<float>(output_double.self);
				this->output_float.displayable = true;
			} else {
				this->output_int.self = static_cast<int>(this->output_double.self);
				this->output_int.displayable = true;
				
				this->output_char.self = static_cast<char>(output_double.self);
				this->output_char.displayable = std::isprint(static_cast<int>(this->output_char.self));
				if (!this->output_char.displayable) {
					if (this->output_double.self < 0 || this->output_double.self > 127)
						this->output_char.error = true;
				}
	
				this->output_float.self = static_cast<float>(output_double.self);
				this->output_float.displayable = true;
			}

			break;

		case FLOAT:
			this->output_float.displayable = true;
			this->output_float.error = false;

			if (std::isinf(this->output_float.self) || std::isnan(this->output_float.self)) {
				this->output_char.displayable = false;
				this->output_char.error = true;

				this->output_int.displayable = false;
				this->output_int.error = true;

				this->output_double.self = static_cast<double>(this->output_float.self);
				this->output_double.displayable = true;
			} else {
				this->output_int.self = static_cast<int>(this->output_float.self);
				this->output_int.displayable = true;
				
				this->output_char.self = static_cast<char>(output_float.self);
				this->output_char.displayable = std::isprint(static_cast<int>(this->output_float.self));
				if (!this->output_char.displayable) {
					if (this->output_float.self < 0 || this->output_float.self > 127)
						this->output_char.error = true;
				}
	
				this->output_double.self = static_cast<double>(output_float.self);
				this->output_double.displayable = true;
			}

			break;

		default:
			break;
	}
	if (display) {
		this->display();
	}
}

Output::~Output() {}