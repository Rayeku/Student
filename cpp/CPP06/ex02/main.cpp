/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayeku <abougrai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 06:19:19 by rayeku            #+#    #+#             */
/*   Updated: 2024/10/22 09:00:39 by rayeku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main(void)
{	
	Base *test1 = Base::generate();
	if (!test1)
		return (1);
	Base::identify(test1);
	delete test1;


	Base *test2 = Base::generate();
	if (!test2)
		return (1);
	Base::identify(*test2);
	delete test2;
	// std::cout << std::endl;

	// Base *test3 = NULL;
	// Base::identify(test3);
	// Base::identify(*test3);
	// std::cout << std::endl;

	// Base *test4 = new Base;
	// if (!test4)
	// 	return (1);
	// Base::identify(test4);

	// Base *test5 = new Base;
	// if (!test5)
	// 	return (1);
	// Base::identify(*test5);
	// delete test5;
	return (0);
}

// #include <thread>
// #include <chrono> 
// std::this_thread::sleep_for(std::chrono::seconds(1));
