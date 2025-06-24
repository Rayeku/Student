/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrai <abougrai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 11:57:09 by abougrai          #+#    #+#             */
/*   Updated: 2024/05/02 13:06:10 by abougrai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

std::string GetCopyName(std::string fileName)
{
	return (fileName + ".replace");
}
int	CheckReplace(std::string s1, std::string s2)
{
	if (s1.empty())
		return (false);
	return (true);
}
int	ReturnHandler(int value, std::string fileName)
{
	if (value == ERRARG)
		std::cout << INVARG << std::endl;
	else if (value == ERRFILE)
		std::cout << ACCESS << " : " << ORANGE_DARK << fileName << RESET << std::endl;
	else if (value == ERRCOPY)
		std::cout << NOCOPY << " : " << ORANGE_DARK << fileName << RESET << std::endl;
	else if (value == SUCESSCPY)
		std::cout << YESCOPY << std::endl;
	else if (value == SUCESSREP)
		std::cout << YESREP << std::endl;
	if (value > 10)
		return (CAPART);
	return (value);
}

int	Replace(std::ofstream &copy, std::ifstream &src, std::string s1,std::string s2)
{
	size_t	pos(0);

	std::string line("");
	while (getline(src, line))
	{
		while (line.find(s1) != line.npos)
		{
			pos = line.find(s1);
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			// line = line;
		}
		copy << line;
		if (!src.eof())
			copy << std::endl;
		else if (!src.eof())
			copy << s2;
	}
	return (SUCESSREP);
}

int	OnlyCopy(std::ofstream &copy, std::ifstream &src)
{
	std::string line("");
	while (getline(src, line))
	{
		copy << line;
		if (!src.eof())
			copy << std::endl;
	}
	return (SUCESSCPY);
}

int	CopyAndReplace(std::string fileName, std::string s1, std::string s2)
{
	std::string copyName = GetCopyName(fileName);
	std::ifstream src(fileName.c_str());
	std::ofstream copy;
	if (src.is_open())
	{
		copy.open(copyName.c_str());
		if (copy.is_open())
		{
			if (CheckReplace(s1, s2))
				return (ReturnHandler(Replace(copy, src, s1, s2), fileName));
			else
				return (ReturnHandler(OnlyCopy(copy, src), fileName));
		}
		else
			return (src.close(), ReturnHandler(ERRCOPY, fileName));
	}
	else
		return (ReturnHandler(ERRFILE, fileName));
	return (copy.close(), src.close(), SUCESSCPY);
}

int	main(int ac, char **av)
{
	if (ac == 4)
		return (CopyAndReplace(av[1], av[2], av[3]));
	else
		return (ReturnHandler(ERRARG, ""));
}
