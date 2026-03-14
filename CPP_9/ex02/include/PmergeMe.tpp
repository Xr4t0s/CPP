#include "PmergeMe.hpp"

template<typename Container, typename RetContainer>
PmergeMe<Container, RetContainer>::PmergeMe() : _addedZero(false) {}
template<typename Container, typename RetContainer>
PmergeMe<Container, RetContainer>::PmergeMe(const PmergeMe<Container, RetContainer>& copy) : _pairs(copy._pairs), _addedZero(copy._addedZero) {}
template<typename Container, typename RetContainer>
PmergeMe<Container, RetContainer>&	PmergeMe<Container, RetContainer>::operator=(const PmergeMe<Container, RetContainer>& rhs) {
	if (this != &rhs) {
		this->_addedZero = rhs._addedZero;
		this->_pairs = rhs._pairs;
	}
	return *this;
}
template<typename Container, typename RetContainer>
PmergeMe<Container, RetContainer>::~PmergeMe() {}



/// @brief Run the algorithm based on the template used
/// @param input Raw input values
/// @param verbose Display or not the final container at the end of the algorithm
template<typename Container, typename RetContainer>
double	PmergeMe<Container, RetContainer>::run(char* input[]) {
	// Starting the chronometer
	clock_t start = clock();

	{
		// Creating sorted pairs into _pairs
		this->createOrderedPairs(input);

		// Pushing the highests number of the pairs into _ret, starting by pushing the first of the lowest
		// because it's already lower than the lowest of the highests (weird..)
		this->_ret.push_back(this->_pairs[0].first);
		for (std::size_t i = 0; i < _pairs.size(); i++) {
			this->_ret.push_back(_pairs[i].second);
		}
	}

	{
		// Creating the jacobsthal sequence using the number of pairs in _pairs
		// It will create limits we will use to insert by window/batch between two points
		// reducing large window between the first push and the last
		RetContainer	jacob = this->jacobsthal();

		// We uses that sequence to create and dynamic indexer
		// Using the limit of the sequence we will have and desc order from high limit to low
		// when minimum, go to higher window and desc again into pairs
		RetContainer	order = this->setOrderFromJacobsthal(jacob);
		
		// Running a insert algorithm using the previous indexer base on jacobsthal sequence
		this->sort(order);
	}
	// Stopping the chronometer
	clock_t end = clock();

	double elapsed_ms = (double)(end - start) * 1000000 / CLOCKS_PER_SEC;
	
	return elapsed_ms;
}

/// @brief Create the _pair stack (min,max) and sort it based on the max value
/// @param input Raw input values
template<typename Container, typename RetContainer>
void	PmergeMe<Container, RetContainer>::createOrderedPairs(char*	input[]) {
	std::size_t				index = 0;
	std::string				token = input[index];

	while (input[index]) {
		// Creating first pair entry
		uint first = std::strtol(input[index++], NULL, 10);;

		{
			// Check if second entry exist
			// If not, push 0 to fake a pair, then set _addedZero = true
			// Remove the added 0 at the end of the algorithm
			if (!input[index]) {
				uint second = 0;
				std::pair<uint, uint> pair(second, first);
				this->_pairs.push_back(pair);
				this->_addedZero = true;
				break;
			}
		}

		// Creating second pair entry
		uint second = std::strtol(input[index++], NULL, 10);

		// Compare the 2 entries and set the pair in the right order
		if (first > second) {
			std::pair<uint, uint> pair(second, first);
			this->_pairs.push_back(pair);
		} else {
			std::pair<uint, uint> pair(first, second);
			this->_pairs.push_back(pair);			
		}
	}

	// Sort all the _pairs container based on the right value
	std::sort(this->_pairs.begin(), this->_pairs.end(), comparePair);
}

/// @brief Generate the insertion order of the low _pairs values using the Jacobsthal sequence
/// @param jacob The jacobsthal sequence
/// @return A container used as indexor to insert the optimal value of _pairs lowest values into _ret container 
template<typename Container, typename RetContainer>
RetContainer	PmergeMe<Container, RetContainer>::setOrderFromJacobsthal(RetContainer jacob) {
	RetContainer order;
	
	// Skipping the first element : already inserted
	size_t prev = 1;

	// For Jacobsthal sequence size, push elements in desc order between jacob[i] && jacob[i+1]
	for (size_t i = 1; i < jacob.size(); i++) {
		size_t current = jacob[i];

		// Security check
		if (current > _pairs.size())
			current = _pairs.size();

		// Push all the window in the desc order
		for (size_t j = current; j > prev; j--)
			order.push_back(j);

		// Save the last index computed
		prev = jacob[i];
	}

	// Push last time
	for (size_t j = _pairs.size(); j > prev; j--)
			order.push_back(j);

	// Will always be 1
	order.insert(order.begin(), 1);

	return order;
}

/// @brief Create a jacobsthal sequence based on the _pairs container size
/// @return A RetContainer filled with the sequence
template<typename Container, typename RetContainer>
RetContainer PmergeMe<Container, RetContainer>::jacobsthal() {
	// Jacobsthal -> J[n] = J[n - 1] + 2(J[n - 2])
	// With J[0] = 0 and J[1] = 1
	RetContainer sequence;
	
	int j0 = 0;
	int j1 = 1;
	
	// thank you gpt
	int	n	=	this->_pairs.size();
	while (j1 < n) {
		sequence.push_back(j1);
		int next = j1 + 2 * j0;
		j0 = j1;
		j1 = next;
	}

	return sequence;
}

/// @brief Insert the lowest values of _pairs into _ret using the order based on the jacobsthal sequence
/// @param order Order determined by JacobSthal sequence 
template<typename Container, typename RetContainer>
void	PmergeMe<Container, RetContainer>::sort(RetContainer order) {

	for (std::size_t i = 1; i < order.size(); i++) {
		// Extracts the index of the value to insert from the order established
		std::size_t idx = order[i] - 1;

		// left (or first here) is the value
		// right (or second here) is the limit of left
		uint value = _pairs[idx].first;
		uint limit = _pairs[idx].second;

		// Left value of the pair is lower than right value
		// Set limit for the left value insertion limit to its right value
		RetIterator limit_it = std::find(this->_ret.begin(), this->_ret.end(), limit);

		// Binary search only before the limit
		RetIterator pos = std::lower_bound(this->_ret.begin(), limit_it, value);

		// Normal insertion
		this->_ret.insert(pos, value);
	}

	if (this->_addedZero)
		this->_ret.erase(this->_ret.begin());

}
