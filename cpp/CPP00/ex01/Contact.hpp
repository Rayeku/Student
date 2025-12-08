/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayeku <abougrai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 07:02:14 by abougrai          #+#    #+#             */
/*   Updated: 2025/12/08 11:07:22 by rayeku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <cstdlib>

class Contact
{
	private:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string number;
		std::string secret;
	
  	public:
		Contact();
		~Contact();

	// Setter(s)
    void setFirstName(const std::string &fname) { firstName = fname; }
    void setLastName(const std::string &lname) { lastName = lname; }
    void setNickName(const std::string &nname) { nickName = nname; }
    void setNumber(const std::string &num) { number = num; }
    void setSecret(const std::string &sec) { secret = sec; }

    // Getter(s)
    std::string getFirstName() const { return firstName; }
    std::string getLastName() const { return lastName; }
    std::string getNickName() const { return nickName; }
    std::string getNumber() const { return number; }
    std::string getSecret() const { return secret; }

};

#endif