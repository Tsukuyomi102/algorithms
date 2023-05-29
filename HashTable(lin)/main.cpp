#include <iostream>
#include <string>

#include "HashTable.h"
#include "Data.h"

void show_the_table(HashTable& table)
{
	for (int i = 0; i < table.get_size(); i++)
	{
		std::cout << "|" << table.output(i);
	}
	std::cout << '\n';
}

void filling_the_table(HashTable& table)
{
	Data *value_object = new Data();
	(*value_object).account_number = 7456981;
	(*value_object).address.street = "Programist street";
	(*value_object).address.number_of_house = 3;
	(*value_object).address.number_of_flat = 65;
	(*value_object).fullname.first_name = "Egor";
	(*value_object).fullname.second_name = "Svirin";
	(*value_object).fullname.patronymic = "Alekseevich";
	table.insert(value_object);

	Data* value_object1 = new Data();
	(*value_object1).account_number = 7456988;
	(*value_object1).address.street = "Podolskaya street";
	(*value_object1).address.number_of_house = 21;
	(*value_object1).address.number_of_flat = 3;
	(*value_object1).fullname.first_name = "Ivan";
	(*value_object1).fullname.second_name = "Ivanov";
	(*value_object1).fullname.patronymic = "Ivanovich";
	table.insert(value_object1);

	Data* value_object2 = new Data();
	(*value_object2).account_number = 7456989;
	(*value_object2).address.street = "Podolskaya street";
	(*value_object2).address.number_of_house = 28;
	(*value_object2).address.number_of_flat = 5;
	(*value_object2).fullname.first_name = "Alexey";
	(*value_object2).fullname.second_name = "Grivov";
	(*value_object2).fullname.patronymic = "Ivanovich";
	table.insert(value_object2);

	Data* value_object3 = new Data();
	(*value_object3).account_number = 7456987;
	(*value_object3).address.street = "Podolskaya street";
	(*value_object3).address.number_of_house = 21;
	(*value_object3).address.number_of_flat = 3;
	(*value_object3).fullname.first_name = "Polina";
	(*value_object3).fullname.second_name = "Elcapo";
	(*value_object3).fullname.patronymic = "Egorovna";
	table.insert(value_object3);

	Data* value_object4 = new Data();
	(*value_object4).account_number = 7436123;
	(*value_object4).address.street = "Hohushevoe street";
	(*value_object4).address.number_of_house = 1;
	(*value_object4).address.number_of_flat = 84;
	(*value_object4).fullname.first_name = "Jora";
	(*value_object4).fullname.second_name = "Jigite";
	(*value_object4).fullname.patronymic = "Alexeevich";
	table.insert(value_object4);
}

void insert(HashTable& table)
{
	Data* new_value_object = new Data();
	std::cout << "Input you number of account: ";
	std::cin >> (*new_value_object).account_number;
	std::cout << '\n';

	std::cout << "Input the first name: ";
	std::cin >> (*new_value_object).fullname.first_name;
	std::cout << '\n';

	std::cout << "Input the second name: ";
	std::cin >> (*new_value_object).fullname.second_name;
	std::cout << '\n';

	std::cout << "Input the patronymic: ";
	std::cin >> (*new_value_object).fullname.patronymic;
	std::cout << '\n';

	std::cout << "Input your street: ";
	std::cin >> (*new_value_object).address.street;
	std::cout << '\n';

	std::cout << "Input the number of your house: ";
	std::cin >> (*new_value_object).address.number_of_house;
	std::cout << '\n';

	std::cout << "Input the number of your flat: ";
	std::cin >> (*new_value_object).address.number_of_flat;
	std::cout << '\n';
	table.insert(new_value_object);
}

int main()
{
	HashTable table = HashTable();
	filling_the_table(table);
	int restart_button = 1;
	while (restart_button == 1)
	{
		int type_of_task;
		std::cout << "Choose the type of function that you want: " << '\n' <<
			"1 - Insert the new information in table" << '\n' <<
			"2 - Delete the table by key" << '\n' <<
			"3 - Find the table by key" << '\n' <<
			"4 - See the table" << '\n';
		std::cin >> type_of_task;
		std::cout << '\n';

		if (type_of_task == 1)
		{
			insert(table);
			show_the_table(table);
		}

		if (type_of_task == 2)
		{
			int key;
			std::cout << "Input the key, that you wanna delete: ";
			std::cin >> key;
			table.delete_by_key(key);
			std::cout << '\n';
			show_the_table(table);
		}

		if (type_of_task == 3)
		{
			int key;
			std::cout << "Input the key, that you wanna see: ";
			std::cin >> key;
			std::cout << table.find_by_key(key) << '\n';
		}

		if (type_of_task == 4)
		{
			show_the_table(table);
		}

		std::cout << "Do you wanna continue (press 1 if you wanna do it): ";
		std::cin >> restart_button;
		std::cout << '\n';
	}
}