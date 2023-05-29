#include <string>

#ifndef DATA_H
#define DATA_H

struct FullName
{

public:
	std::string first_name;
	std::string second_name;
	std::string patronymic;
};

struct Address
{

public:
	std::string street;
	int number_of_house;
	int number_of_flat;
};

struct Data
{

public:
	int account_number;
	FullName fullname;
	Address address;

	std::string ToString()
	{
		std::string output = "";
		output += std::to_string(account_number) + "\t" + "| ";
		output += fullname.first_name + "\t" + "| ";
		output += fullname.second_name + "\t" + "| ";
		output += fullname.patronymic + "\t" + "| ";
		output += address.street + "\t" + "| ";
		output += std::to_string(address.number_of_house) + "\t" + "| ";
		output += std::to_string(address.number_of_flat) + "\t" + "| ";

		return output;
	}
};

#endif
