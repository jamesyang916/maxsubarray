#include "MaxSubarray.h"
#include <vector>
#include <iostream>
#define INF = 2e32

template <class Iter, class T = std::iterator_traits<Iter>::value_type>
std::tuple<Iter, Iter, T> findCrossMax(Iter begin, Iter mid, Iter end) {
	T leftSum = 0;
	T sum = 0;
	Iter maxLeft;
	for (Iter i = mid - 1; i >= begin; --i) {
		sum += *i;
		if (sum >= leftSum) {
			leftSum = sum;
			maxLeft = i;
		}
		if (i == begin)
			break;
	}
	T rightSum = 0;
	Iter maxRight;
	sum = 0;
	for (Iter j = mid; j < end; ++j) {
		sum += *j;
		if (sum >= rightSum) {
			rightSum = sum;
			maxRight = j;
		}
	}
	return std::make_tuple(maxLeft, maxRight, leftSum + rightSum);
}


template <class Iter, class T = std::iterator_traits<Iter>::value_type>
std::tuple<Iter, Iter, T> findMax(Iter begin, Iter end) {
	// Base case: 1 element
	if (begin >= end - 1) {
		return std::make_tuple(begin, end - 1, *begin);
	}
	
	// Induction case: n elements
	Iter mid = begin + std::distance(begin, end) / 2;
	auto leftMax = findMax(begin, mid);
	auto rightMax = findMax(mid, end);
	auto crossMax = findCrossMax(begin, mid, end);

	if (std::get<2>(leftMax) >= std::get<2>(rightMax) &&
		std::get<2>(leftMax) >= std::get<2>(crossMax)) {
		return leftMax;
	}
	else if (std::get<2>(rightMax) >= std::get<2>(leftMax) &&
		std::get<2>(rightMax) >= std::get<2>(crossMax)) {
		return rightMax;
	}
	else {
		return crossMax;
	}
}



int main() {
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(3);
	vec.push_back(-4);
	vec.push_back(5);
	vec.push_back(15);
	vec.push_back(-2);
	vec.push_back(14);
	auto res = findMax(vec.begin(), vec.end());
	for (std::vector<int>::const_iterator it = std::get<0>(res);
		it <= std::get<1>(res); ++it) {
		std::cout << *it << ", ";
	}
	return 0;
}