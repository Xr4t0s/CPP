#ifndef __MAX_TPP__
#define __MAX_TPP__

template< typename T >
T	max(const T& a, const T& b) {
	return a <= b ? b : a;
}

#endif
