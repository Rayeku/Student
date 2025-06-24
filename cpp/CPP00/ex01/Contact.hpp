/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 07:02:14 by abougrai          #+#    #+#             */
/*   Updated: 2024/05/01 14:36:44 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <cstdlib>

class Contact
{
  public:
	Contact();
	~Contact();
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string number;
	std::string secret;

};

#endif