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
};

#endif
