/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayeku <abougrai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:23:27 by rayeku            #+#    #+#             */
/*   Updated: 2025/03/31 08:02:36 by rayeku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_CPP
# define BITCOINEXCHANGE_CPP

# include <map>
# include <string>
# include <iostream>
# include <fstream>
# include <exception>
# include <sstream>
# include <algorithm>
# include <sys/stat.h>

// Typeface(s)
# define BOLD "\033[1m"
# define ITALIC "\033[3m"

// Color(s)
# define RED "\033[31m"
# define RESET "\033[0m"
# define CYAN "\033[36m"
# define YELLOW "\033[33m"
# define MAGENTA "\033[35m"
# define BROWN "\033[38;5;94m"
# define ORANGE "\033[38;5;202m"

// Define(s)
# define DBHEADER "date | value"
# define CSVHEADER "date,exchange_rate"

# define ERRORFILE RED BOLD "Error file" RESET
# define WRONGARG RED BOLD "Wrong Argument" RESET
# define INVALIDDATE RED BOLD "Invalid date" RESET
# define NODATA RED BOLD "No data to work with" RESET
# define INVALIDVALUE RED BOLD "Invalid value" RESET
# define FORMATFILE RED BOLD "Invalid format file" RESET
# define NOPREVDATE RED BOLD "No previous date available" RESET
# define INVALIDDBHEADER RED BOLD "Invalid database header" RESET
# define EMPTYCSVFILE RED BOLD "Error .csv file seems empty" RESET
# define INVALIDCSVHEADER RED BOLD "Invalid csv file header" RESET
# define OORVALUE RED BOLD "Value is out of range (0 to 1000)" RESET
# define EMPTYDATAFILE RED BOLD "Error database file seems empty" RESET

class BitcoinExchange
{
	private:
		std::map<std::string, double> _btcData;
		std::string		_line;
		std::string 	_path;
		
		double	_checkValue(std::string valueStr);
		bool	_isValidDate(int &year, int &month, int &day);
		bool	_isBissextile(int year);
		bool 	_checkCsvFile(void);
		void	_checkDate(std::string date);

	public:
		BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const &src);
		~BitcoinExchange(void);

		BitcoinExchange &operator=(BitcoinExchange const &src);

		void	printValue(std::string date, double value);
		void	handleData(const char *filename);
		void	printData(void) const;
		static double	ft_stod(const std::string &input);
		
		class	FormatFileException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		
		class	ErrorFileException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		
		class	EmptyCsvFileException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class	InvalidCsvHeaderException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class	InvalidDateException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class	NoDataException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
			class	EmptyDatabaseFileException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class	InvalidDbHeaderException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		
		class	InvalidValueException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class	ValueOutOfRangeException : public std::exception
		{
			public:
				virtual const char* what() const throw();
				
		};

		class	NoPreviousDateException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

};
      
#endif
