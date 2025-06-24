/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayeku <abougrai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 07:30:39 by rayeku            #+#    #+#             */
/*   Updated: 2025/04/03 13:19:08 by rayeku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

// Typeface(s)
# define BOLD "\033[1m"
# define ITALIC "\033[3m"

// Color(s)
# define RED "\033[31m"
# define RESET "\033[0m"
# define CYAN "\033[36m"
# define BROWN "\033[38;5;94m"
# define ORANGE "\033[38;5;202m"

// Include(s)
# include <iostream>
# include <iomanip>
# include <sstream>
# include <stdexcept>
# include <vector>
# include <deque>
# include <limits>
# include <algorithm>
# include <sys/time.h>
# include <iterator>

// Define(s)
# define WrongArg ORANGE BOLD "Invalid Argument\n" RESET
# define ErrorArg RED BOLD "Error\n" RESET
# define OOBValue RED BOLD "Value is out of bounds\n" RESET
# define BEFORE BROWN BOLD << "\n[Before sorting]" RESET
# define AFTER CYAN BOLD  "\n[After sorting]" RESET

# define PrintErr1 RED BOLD "Error : container seems empty\n" RESET
# define PrintErr2 RED BOLD "Error : sort before printing\n" RESET
# define VECTOR "vector"
# define DEQUE "deque"
# define MIN	60000000
# define SECS	1000000
# define MS		1000
 

class PmergeMe
{
private:
	PmergeMe();
	PmergeMe(PmergeMe const &src);
	PmergeMe&   operator=(PmergeMe const &src);

	std::vector<int>	_vector;
	std::deque<int>		_deque;
	double				_time;


public:
	PmergeMe(std::vector<int> const &input);
	~PmergeMe();

	std::string		getType(const std::string &container) const;
	static bool		isNumber(std::string av);
	
	void			printTimeTaken(const std::string& containerType) const;
	void			finalPrint();
};

std::vector<size_t>	generateJacobsthal(size_t n);
std::vector<size_t>	indexAssignation(size_t size);

template < typename Iterator, typename Container>
Iterator binarySearch(Iterator first, Iterator last, const Container& value);

template < template <typename, typename> class Container, typename T, typename Alloc >
void	sortProcess(Container<T, Alloc> &cont, typename Container<T, Alloc>::iterator first, typename Container<T, Alloc>::iterator last);

template <typename Container>
std::ostream & operator<<(std::ostream &o, std::vector<Container> const &rhs);

template <typename Container>
std::ostream& operator<<(std::ostream& o, std::deque<Container> const& rhs);

#endif