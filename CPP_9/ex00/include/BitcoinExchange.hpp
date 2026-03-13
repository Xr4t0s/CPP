#ifndef __BITCOIN_EXCHANGE_HPP__
#define __BITCOIN_EXCHANGE_HPP__

class BitcoinExchange {
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& copy);
		BitcoinExchange&	operator=(const BitcoinExchange& rhs);
		
		~BitcoinExchange();
};

#endif
