#include <iostream>
#include <string>

#include "Data.h"
#include "HashTable.h"

bool HashTable::_check_for_nullptr(int index)
{
	if (arr[index] == nullptr)
	{
		return true;
	}

	else
	{
		return false;
	}
}

HashTable::HashTable()
{
	size = 5;
	count = 0;
	arr = new Data * [size] {};
}

int HashTable::get_size()
{
	return size;
}

int HashTable::_hash(int account_number)
{
	int index = account_number % size;
	return index;
}

void HashTable::_rehash()
{
	size = size * 2;
	Data** new_arr = new Data * [size] {};
	for (size_t i = 0; i < size / 2; i++)
	{
		_insert(new_arr, arr[i]);
	}

	delete[]arr;
	arr = new_arr;
}

void HashTable::insert(Data* value)
{
	if (size == count)
	{
		_rehash();
	}

	_insert(arr, value);
}

void HashTable::_insert(Data** arr, Data* value)
{
	int index = _hash((*value).account_number);
	if (!(_check_for_nullptr(index)))
	{
		index = __probe(arr, index);
	}
	arr[index] = value;
	count++;
}

int HashTable::_probe(int problem_index)
{
	return __probe(arr, problem_index);
}

int HashTable::__probe(Data** arr, int problem_index)
{
	int new_index = problem_index;
	for (size_t attempts_to_solving = 0; attempts_to_solving < size; attempts_to_solving++)
	{
		new_index = (problem_index + attempts_to_solving) % size;
		if (arr[new_index] == nullptr)
		{
			break;
		}
	}

	return new_index;
}

std::string HashTable::find_by_key(int key)
{
	for (int i = 0; i < size; i++)
	{
		if (!(_check_for_nullptr(i)))
		{
			if (arr[i]->account_number == key)
			{
				return '\n' + output(i);
			}
		}
	}

	return "This key is not found";
}

int HashTable::_find_by_key(int key)
{
	for (int i = 0; i < size; i++)
	{
		if (!(_check_for_nullptr(i)))
		{
			if (arr[i]->account_number == key)
			{
				return i;
			}
		}
	}

	return -1;
}

void HashTable::delete_by_key(int key)
{
	int index_for_delete = _find_by_key(key);
	
	if (index_for_delete == -1)
	{
		std::cout << "This key not found\n";
		return;
	}

	arr[index_for_delete] = nullptr;
}

std::string HashTable::output(int index)
{
	std::string output = "";
	if (_check_for_nullptr(index))
	{
		return "\n";
	}

	else
	{
		output += arr[index]->fullname.first_name + "\t" + "| ";
		output += arr[index]->fullname.second_name + "\t" + "| ";
		output += arr[index]->fullname.patronymic + "\t" + "| ";
		output += arr[index]->address.street + "\t\t" + "| ";
		output += std::to_string(arr[index]->address.number_of_house) + "\t" + "| ";
		output += std::to_string(arr[index]->address.number_of_flat) + "\t" + "| ";
		output += std::to_string(arr[index]->account_number) + "\t" + "| ";
		output += "\n";
		return output;
	}
}