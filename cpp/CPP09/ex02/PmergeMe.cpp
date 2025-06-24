/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayeku <abougrai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 07:30:26 by rayeku            #+#    #+#             */
/*   Updated: 2025/04/03 13:40:54 by rayeku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// Constructor(s)
PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(std::vector<int> const &input) : _vector(input), _time(-1) {
	for (std::vector<int>::const_iterator it = input.begin(); it != input.end(); ++it) { _deque.push_back(*it); }
}

PmergeMe::PmergeMe(PmergeMe const &src) { *this = src; }

// Deconstructor(s)
PmergeMe::~PmergeMe(void) {}

// Copy assignation overload
PmergeMe &PmergeMe::operator=(PmergeMe const &src) {
	if (this != &src) {
		this->_vector = src._vector;
		this->_deque = src._deque;
	}
	return (*this);
}

// Method(s)
bool	PmergeMe::isNumber(std::string argument) {
	
	std::stringstream	ss(argument);
	long	number = 0;
	
	ss >> number;
	if (argument.empty()) { throw std::invalid_argument(ErrorArg); };
	if (ss.fail() || !ss.eof()) { throw std::invalid_argument(ErrorArg); }
	if (number < 0 || number > std::numeric_limits<int>::max()) { throw std::invalid_argument(OOBValue); }

	return (true);
}

std::vector<size_t>	indexAssignation(size_t n) {
	std::vector<size_t>	jacob = generateJacobsthal(n); // 0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461 ...
	std::vector<size_t> indexes;
	if (n == 0) { return (indexes); }
	indexes.push_back(1);
	if (n == 1) { return (indexes); }
	for (size_t i = 1; i < jacob.size(); i++) 
	{
		if (jacob[i] > indexes.back()) 
		{
			size_t tmp = jacob[i - 1];
			indexes.push_back(jacob[i]);
			for (size_t j = jacob[i] - 1; j > tmp; j--) { indexes.push_back(j); }
		}
	}
	for (size_t k = n; k > jacob.back(); k--) { indexes.push_back(k); }
	return (indexes);
}

std::vector<size_t>		generateJacobsthal(size_t n) {
	std::vector<size_t>	jacob;
	if (n == 0) { return (jacob); }
	jacob.push_back(0);
	if (n == 1) { return (jacob); }
	jacob.push_back(1);
	size_t i = 2;
	while (jacob.back() <= n) 
	{
		size_t nextValue = jacob[i - 1] + 2 * jacob[i - 2];
		if (nextValue > n) { break; }
		jacob.push_back(nextValue);
		++i;
	}
	return (jacob);
}

template <template <typename, typename> class Container, typename T, typename PairAlloc, typename Alloc>
Container<T, Alloc> getSmallestValues(const Container<std::pair<T, T>, PairAlloc>& pairs, const Container<T, Alloc>& upperValues)
{
    typedef typename Container<T, Alloc>::const_iterator cont_it;
    typedef typename Container<std::pair<T, T>, PairAlloc>::const_iterator pair_it;
    
    Container<T, Alloc> smallest;

    for (cont_it it = upperValues.begin(); it != upperValues.end(); ++it) {
        for (pair_it p_it = pairs.begin(); p_it != pairs.end(); ++p_it) {
            if (p_it->second == *it)  { smallest.push_back(p_it->first); break;}
        }
    }
    return (smallest);
}

template <typename Iterator, typename Container>
Iterator binarySearch(Iterator start, Iterator end, const Container& value) {
    typename std::iterator_traits<Iterator>::difference_type count = std::distance(start, end);

    while (count > 0) {
        typename std::iterator_traits<Iterator>::difference_type step = count / 2;
        Iterator mid = start;
        std::advance(mid, step);

        if (*mid < value) {
            start = ++mid;
            count -= step + 1;
        } else {
            count = step;
        }
	}
    return (start);
}

template <template <typename, typename> class Container, typename T, typename Alloc>
void	sortProcess(Container<T, Alloc> &cont, typename Container<T, Alloc>::iterator first, typename Container<T, Alloc>::iterator last)
{
	(void)cont;
	typedef typename Alloc::template rebind<std::pair<T, T> >::other PairAlloc;
	typedef typename Container<T, Alloc>::iterator	cont_it;
	typedef typename Container<std::pair<T, T>, PairAlloc>::iterator pair_it;

	size_t	diff = std::distance(first, last);
	if (diff <= 1) { return; }
	Container<std::pair<T, T>, PairAlloc> pairs;
	Container<T, Alloc>		oddNumberElem;

	cont_it	it = first;
	while (std::distance(it, last) >= 2) // pair creation
	{
		T	first_val = *(it++);
		T	second_val = *(it++);
		if (second_val < first_val) { std::swap(first_val, second_val); }
		pairs.push_back(std::make_pair(first_val, second_val));
	}
	if (it != last) { oddNumberElem.push_back(*it); }
	
	Container<T, Alloc>		upperValues; // biggest value container

	for (pair_it p_it = pairs.begin(); p_it != pairs.end(); ++p_it) { upperValues.push_back(p_it->second); }
	if (upperValues.size() >= 2) { sortProcess(upperValues, upperValues.begin(), upperValues.end()); }

	Container<T, Alloc> 	remainingSmallest = getSmallestValues(pairs, upperValues);  // smallest value container

	std::vector<size_t>		indexes = indexAssignation(remainingSmallest.size());
	for (size_t i = 0; i < indexes.size(); i++)
	{
		size_t	targetIndex = indexes[i];
		cont_it insertTarget = remainingSmallest.begin();
		if (targetIndex == 1) { upperValues.insert(upperValues.begin(), *insertTarget); }
		else
		{
			T	targetValue;
			std::advance(insertTarget, targetIndex - 1);
			for (pair_it p_it = pairs.begin(); p_it != pairs.end(); ++p_it) {
				if (p_it->first == *insertTarget) { targetValue = p_it->second; break; }
			}
			cont_it valuePos;
			for (valuePos = upperValues.begin(); valuePos != upperValues.end(); ++valuePos) { if (*valuePos == targetValue) { break; } }
			cont_it	insertPos = binarySearch(upperValues.begin(), valuePos, *insertTarget);
			upperValues.insert(insertPos, *insertTarget);
		}
	}

	if (!oddNumberElem.empty())
	{
		cont_it insertPos = binarySearch(upperValues.begin(), upperValues.end(), *oddNumberElem.begin());
		upperValues.insert(insertPos, *oddNumberElem.begin());
	}

	std::copy(upperValues.begin(), upperValues.end(), first); // copy back result
	return ;
}

void PmergeMe::printTimeTaken(const std::string& container) const {
	if (_time == -1) {
		if (_vector.empty() && _deque.empty()) { std::cout << PrintErr1; }
		else { std::cout << PrintErr2; }
		return ;
	}

	std::cout << "Time to process a range of ";
	if (!_vector.empty() && container == VECTOR) { std::cout << _vector.size() << " element" << (_vector.size() > 1 ? "s" : "") << " with " << getType(VECTOR); }
	else if (!_deque.empty() && container == DEQUE) { std::cout << _deque.size() << " element" << (_deque.size() > 1 ? "s" : "") << " with " << getType(DEQUE); }
	else { std::cout << RED BOLD << "Error container" << RESET << std::endl; return ; }

	std::cout << "\t-> ";

	if (_time > MIN) { std::cout << std::fixed << std::setprecision(2) << int(_time / 60000000) << "." << int(_time / 1000000) % 60 << "m";}
	else if (_time > SECS) { std::cout << std::fixed << std::setprecision(5) << _time / 1000000 << "s";}
	else if (_time > MS) { std::cout << std::fixed << std::setprecision(5) << _time / 1000 << "ms"; }
	else { std::cout << std::fixed << std::setprecision(5) << _time << "us"; }

	std::cout << std::endl;
}

void PmergeMe::finalPrint() {

	std::cout << BEFORE << _vector << std::endl;

	clock_t start1 = clock();
	sortProcess(_vector, _vector.begin(), _vector.end());
	clock_t end1 = clock();
	std::cout << AFTER << _vector << "\n\n";
	_time = static_cast<double>(end1 - start1) / CLOCKS_PER_SEC * 1000000;
	printTimeTaken(VECTOR);

	clock_t start2 = clock();
	sortProcess(_deque, _deque.begin(), _deque.end());
	clock_t end2 = clock();
	_time = static_cast<double>(end2 - start2) / CLOCKS_PER_SEC * 1000000;
	printTimeTaken(DEQUE);
}

std::string PmergeMe::getType(const std::string& container) const {
	if (container == VECTOR) { return (ORANGE BOLD "std::vector" RESET); }
	else if (container == DEQUE) { return (ORANGE BOLD "std::deque" RESET); }
	else { return (RED BOLD "Error : container type" RESET); }
}

// Ostream overload(s)
template <typename T>
std::ostream & operator<<(std::ostream &o, std::vector<T> const &rhs) {
	for (typename std::vector<T>::const_iterator it = rhs.begin(); it != rhs.end(); ++it) {
		o << " " << *it;
	}
	return (o);
}

template <typename T>
std::ostream& operator<<(std::ostream& o, std::deque<T> const& rhs) {
	for (typename std::deque<T>::const_iterator it = rhs.begin(); it != rhs.end(); ++it) {
		o << " " << *it;
	}
	return (o);
}
