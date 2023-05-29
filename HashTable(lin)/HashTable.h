#include <iostream>
#include <string>

#include "Data.h"

#ifndef HASHTABLE_H
#define HASHTABLE_H

class HashTable
{

public:
	HashTable();
	void insert(Data* value);
	void delete_by_key(int key);
	std::string find_by_key(int key);
	std::string output(int index);
	int get_size();

private:
	int size;
	int count;

	Data **arr;

	int _hash(int account_number);
	void _rehash();

	int _probe(int problem_index);
	int __probe(Data** arr, int problem_index);

	bool _check_for_nullptr(int index);
	void _insert(Data **arr, Data* value);
	int _find_by_key(int key);
};

#endif

