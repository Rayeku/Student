/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 09:16:26 by rayeku            #+#    #+#             */
/*   Updated: 2024/11/29 13:54:59 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

// Typeface(s)
#define BOLD "\033[1m"
#define ITALIC "\033[3m"

// Color(s)
#define RED "\033[31m"
#define RESET "\033[0m"
#define CYAN "\033[36m"
#define BROWN "\033[38;5;94m"
#define ORANGE "\033[38;5;202m"

// Include(s)
#include <iostream>
#include <string>
#include <stdexcept>

// Defined String(s)
#define OOB RED "Elem is out of bounds" RESET

template <typename T>
class Array
{
private:
    T *_array;
    unsigned int _size;

public:
    // Constructor(s)
    Array();
    Array(unsigned int n);
    Array(const Array<T> &Array);
    Array(Array<T> &Array);

    // Deconstructor(s)
    ~Array();

    // Copy assignation overload
    Array<T> &operator=(const Array<T> &Array);

    // Method(s)
    unsigned int size();
    void printElem();
    void printElemConst() const;


    // Subscript operator(s)
    T &operator[](unsigned int index);
    const T &operator[](unsigned int index) const;
};

template <typename T>
Array<T>::Array() : _array(new T[0]()), _size(0)
{
    // std::cout << "Default constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]()), _size(n)
{
    // std::cout << "Array constructor called" << std::endl;
}

template <typename T>
Array<T>::~Array()
{
    // std::cout << "Array destructor called" << std::endl;
    delete[] _array;
}

template <typename T>
Array<T>::Array(const Array<T> &copy) : _size(copy.size()), _array(new T[copy.size()])
{
    // std::cout << "Array Copy constructor called" << std::endl;
    for (unsigned int i = 0; i < this->_size; ++i)
        _array[i] = copy._array[i];
}

template <typename T>
Array<T>::Array(Array<T> &copy) : _size(copy.size()), _array(new T[copy.size()])
{
    // std::cout << "Array Copy constructor called" << std::endl;
    for (unsigned int i = 0; i < this->_size; ++i)
        _array[i] = copy._array[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &copy)
{
    // std::cout << "Array Copy assignment called" << std::endl;
    if (this == &copy)
        return *this;

    delete[] _array;
    _array = new T[copy._size];
    this->_size = copy._size;
    for (unsigned int i = 0; i < this->_size; i++)
        _array[i] = copy._array[i];
    return (*this);
}

template <typename T>
unsigned int Array<T>::size()
{
    return (this->_size);
}
template <typename T>
T &Array<T>::operator[](unsigned int elem)
{
    if (elem >= _size)
        throw std::out_of_range(OOB);
    return (_array[elem]);
}

template <typename T>
const T &Array<T>::operator[](unsigned int elem) const
{
    if (elem >= _size)
        throw std::out_of_range(OOB);
    return (_array[elem]);
}

template <typename T>
void Array<T>::printElem()
{
    for (unsigned int i = 0; i < this->_size; i++)
        std::cout << ORANGE << this->_array[i] << RESET << std::endl;
}

#endif