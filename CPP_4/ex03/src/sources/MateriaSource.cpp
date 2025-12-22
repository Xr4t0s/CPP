#include "sources/MateriaSource.hpp"

MateriaSource::MateriaSource() : IMateriaSource() {
	std::cout << "Default MateriaSource constructor called." << std::endl;
	for (int i = 0; i < 4; i++) _slots[i] = NULL;
}

MateriaSource::MateriaSource( const MateriaSource& copy ) {
	std::cout << "MateriaSource copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (copy._slots[i])
			this->_slots[i] = copy._slots[i]->clone();
		else
			this->_slots[i] = NULL;
	}
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& rhs) {
	if (this == &rhs) return *this;
	for (int i = 0; i < 4; i++) {
		if (this->_slots[i]) delete this->_slots[i];
	}
	for (int i = 0; i < 4; i++) {
		if (rhs._slots[i])
			this->_slots[i] = rhs._slots[i]->clone();
		else
			this->_slots[i] = NULL;
	}
	return *this;
}

MateriaSource::~MateriaSource() {
	std::cout << "MateriaSource destructor called." << std::endl;
	for (int i = 0; i < 4; i++) {
		if (this->_slots[i]) delete this->_slots[i];
	}
}

void	MateriaSource::learnMateria(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (!_slots[i]) {
			_slots[i] = m->clone();
			break;
		}
	}
}

AMateria* MateriaSource::createMateria(const std::string& type) {
	for (int i = 0; i < 4; i++) {
		if (_slots[i] && type == _slots[i]->getType()) return _slots[i]->clone();
	}
	return 0;
}