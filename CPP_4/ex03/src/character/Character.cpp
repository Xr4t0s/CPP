#include "character/Character.hpp"

Character::Character() : ICharacter(), _name("") {
	std::cout << "Character default constructor called" << std::endl;
	for (int i = 0; i < 4; i++) _bag[i] = NULL;
}

Character::Character(const std::string& name) : ICharacter(), _name(name) {
	std::cout << "Character name constructor called" << std::endl;
	for (int i = 0; i < 4; i++) _bag[i] = NULL;
}

Character::Character( const Character& copy ) {
	std::cout << "Character copy constructor called" << std::endl;
	this->_name = copy.getName();
	for (int i = 0; i < 4; i++) {
		if (copy._bag[i] != NULL) {
			this->_bag[i] = copy._bag[i]->clone();
		} else {
			this->_bag[i] = NULL;
		}
	}
}

Character&	Character::operator=( const Character& rhs ) {
	std::cout << "Character assignation constructor called" << std::endl;
	if (this != &rhs) {
		this->_name = rhs.getName();
		for (int i = 0; i < 4; i++) {
			delete this->_bag[i];
		}
		for (int i = 0; i < 4; i++) {
			if (rhs._bag[i] != NULL) {
				this->_bag[i] = rhs._bag[i]->clone();
			} else {
				this->_bag[i] = NULL;
			}
		}
	}
	return *this;
}

Character::~Character() {
	std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (_bag[i]) {
			delete _bag[i];
			_bag[i] = NULL;
		}
	}
}

const std::string& Character::getName() const { return _name; }

void	Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (_bag[i] == NULL) {
			_bag[i] = m;
			break;
		}
	}
}

void	Character::unequip(int idx) {
	if (idx < 0 || idx > 3) return;
	_bag[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx > 3 || _bag[idx] == NULL) return;
	_bag[idx]->use(target);
}
