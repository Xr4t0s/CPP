#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {
	private:
		std::string _ideas[100];

	public:
		Brain();
		Brain( const Brain& copy );
		Brain&	operator=( const Brain& rhs );

		const std::string&	getIdea(int index) const;
		void				setIdea(int index, const std::string& idea);

		~Brain();
};

#endif