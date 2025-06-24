/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayeku <abougrai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:03:39 by rayeku            #+#    #+#             */
/*   Updated: 2025/04/01 16:54:30 by rayeku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// Constructor(s)
BitcoinExchange::BitcoinExchange(void) : _line(""), _path("data.csv") {

	if (this->_checkCsvFile()) { throw FormatFileException(); }
	
		std::ifstream	file(this->_path.c_str());
	if (!file.is_open()) { throw ErrorFileException(); }
	else if (file.peek() == EOF) { throw EmptyCsvFileException(); }
	
		std::getline(file, this->_line);
	if (this->_line != CSVHEADER) { throw InvalidCsvHeaderException(); }
	
	while (std::getline(file, this->_line))
	{
		double	btcValue;
		std::stringstream	data(this->_line);
		std::string			date;
		std::getline(data, date, ',');
		
		data >> btcValue;
		if (!data.eof() || data.fail()) { throw InvalidValueException(); }
		try { _checkDate(date); }
		catch(const std::exception& e) { throw InvalidDateException(); }
		this->_btcData[date] = btcValue;
	}
	if (this->_btcData.empty()) { throw NoDataException(); } 
	file.close();
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src) { *this = src; }

// Deconstructor(s)
BitcoinExchange::~BitcoinExchange(void) {}

// Copy assignation overload
BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &src) {
	if (this != &src)
		this->_btcData = src._btcData;
	return (*this);
}

// Method(s)
bool	BitcoinExchange::_checkCsvFile(void) {
		struct stat csvFile;
	if (stat(this->_path.c_str(), &csvFile) || (csvFile.st_mode & S_IXUSR) || !S_ISREG(csvFile.st_mode))
		return (true);
	return (false);
}

bool BitcoinExchange::_isBissextile(int year) { return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)); }

void	BitcoinExchange::_checkDate(std::string date) {

	if (date.size() != 10 || date[4] != '-' || date[7] != '-') { throw InvalidDateException(); }

	std::istringstream	dateChecker(date);
	int		year, month, day;
	char	dash1, dash2;

	if (!(dateChecker >> year >> dash1 >> month >> dash2 >> day) || dash1 != '-' || dash2 != '-'
		|| month < 1 || month > 12 || day < 1 || day > 31
		|| (month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
			throw InvalidDateException();
	if (month == 2 && day > (_isBissextile(year) ? 29 : 28)) { throw InvalidDateException(); }
	if (_isValidDate(year, month, day)) { throw InvalidDateException(); }
}

bool	BitcoinExchange::_isValidDate(int &year, int &month, int &day) {
	time_t currentTime = time(0);
	tm *localTime = localtime(&currentTime);

	int currentYear = 1900 + localTime->tm_year;
	int currentMonth = 1 + localTime->tm_mon;
	int currentDay = localTime->tm_mday;

	if (year > currentYear ||
		(year == currentYear && month > currentMonth) ||
		(year == currentYear && month == currentMonth && day > currentDay))
			return (true);
	return (false);
}

double	BitcoinExchange::_checkValue(std::string valueStr) {
	double	value;

	if (valueStr.empty() || std::count(valueStr.begin(), valueStr.end(), '.') > 1)
		throw InvalidValueException();

	try { value = BitcoinExchange::ft_stod(valueStr); }
	catch (std::invalid_argument &e) { throw InvalidValueException(); }
	catch (std::out_of_range &e) { throw ValueOutOfRangeException(); }

	if (value < 0 || value > 1000) { throw ValueOutOfRangeException(); }
	return (value);
}

void	BitcoinExchange::handleData(const char *filename) {
	std::string line;
	int			checkLines;

	std::ifstream	file(filename);
	if (!file.is_open()) { throw ErrorFileException(); }
	else if (file.peek() == EOF) { throw EmptyDatabaseFileException(); }
	std::getline(file, line);
	if(line != DBHEADER) { throw InvalidDbHeaderException(); }

	checkLines = 0;
	while (std::getline(file, line))
	{
		std::stringstream	ss(line);
		std::string			date;
		std::string			btcValue;
		double				exchangedValue;
		std::getline(ss, date, '|');
		date.erase(std::remove(date.begin(), date.end(), ' '), date.end());
		std::getline(ss, btcValue, '\n');
		btcValue.erase(std::remove(btcValue.begin(), btcValue.end(), ' '), btcValue.end());

		try {
			if (date.empty()) { throw InvalidDateException(); }
			_checkDate(date);
			exchangedValue = _checkValue(btcValue);
			printValue(date, exchangedValue);
		}
		catch(const std::exception& e) {
			std::cerr << RED ITALIC << "Error: " << e.what() << RESET << std::endl;
		}
		checkLines++;
	}
	if (!checkLines) { throw ErrorFileException(); }
	file.close();
}

void	BitcoinExchange::printValue(std::string date, double value) {
	if (this->_btcData.count(date))
	{
		std::cout << CYAN << date << RESET;
		std::cout << " => ";
		std::cout << YELLOW << value  << RESET;
		std::cout << " = ";
		std::cout << MAGENTA << this->_btcData[date] * value << RESET << std::endl;	
	}
	else
	{
		std::map<std::string, double>::iterator	it;
		it = this->_btcData.upper_bound(date);
		if (it == this->_btcData.begin()) { throw NoPreviousDateException(); }
		else
		{
			--it;
			std::cout << CYAN << date << RESET;
			std::cout << " => ";
			std::cout << YELLOW << value << RESET;
			std::cout << " = ";
			std::cout << MAGENTA << it->second * value << RESET << std::endl;
		}
	}
}

double BitcoinExchange::ft_stod(const std::string &input)
{
	double value;
	std::istringstream ss(input);

	ss >> value;
	if (ss.fail() || !ss.eof()) { throw std::invalid_argument("stod : Failed"); }
	return (value);
}
void	BitcoinExchange::printData(void) const {
	for (std::map<std::string, double>::const_iterator it = this->_btcData.begin(); it != this->_btcData.end(); it++)
		std::cout << "Date: \t" << it->first << " | Value: \t" << it->second << std::endl;
}

// Exception(s)
const char * BitcoinExchange::FormatFileException::what() const throw() { return (FORMATFILE); }
const char * BitcoinExchange::ErrorFileException::what() const throw() { return (ERRORFILE); }
const char * BitcoinExchange::EmptyCsvFileException::what() const throw() { return (EMPTYCSVFILE); }
const char * BitcoinExchange::InvalidCsvHeaderException::what() const throw() { return (INVALIDCSVHEADER); }
const char * BitcoinExchange::InvalidDateException::what() const throw() { return (INVALIDDATE); }
const char * BitcoinExchange::NoDataException::what() const throw() { return (NODATA); }
const char * BitcoinExchange::EmptyDatabaseFileException::what() const throw() { return (EMPTYDATAFILE); }
const char * BitcoinExchange::InvalidDbHeaderException::what() const throw() { return (INVALIDDBHEADER); }
const char * BitcoinExchange::InvalidValueException::what() const throw() { return (INVALIDVALUE); }
const char * BitcoinExchange::ValueOutOfRangeException::what() const throw() { return (OORVALUE); }
const char * BitcoinExchange::NoPreviousDateException::what() const throw() { return (NOPREVDATE); }
