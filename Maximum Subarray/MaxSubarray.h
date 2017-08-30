#pragma once
#include <iterator>
#include <tuple>

template <class Iter, class T = std::iterator_traits<Iter>::value_type>
std::tuple<Iter, Iter, T> findMax(Iter begin, Iter end);


template <class Iter, class T = std::iterator_traits<Iter>::value_type>
std::tuple<Iter, Iter, T> findCrossMax(Iter begin, Iter mid, Iter end);
