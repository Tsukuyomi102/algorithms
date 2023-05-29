#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <utility>
#include <vector>
#include <optional>

#include "Data.h"


template<typename TKey, typename TValue>
class HashTable
{
public:
	HashTable(size_t initialSize)
	{
		_size = initialSize == 0 ? 1 : initialSize;
		_count = 0;
		_arr = new std::optional<std::pair<TKey, TValue>>[initialSize];
	}

	std::optional<TValue> Get(TKey key)
	{
		if (!_hasKey(key))
			return {};

		return _probeValue(key);
	}

	void Add(TKey key, TValue value)
	{
		if (_hasKey(key))
			return;

		if (_count == _size)
			_resize(_size * 2);

		int index = _probeSpace(key);
		_arr[index] = std::pair<TKey, TValue>(key, value);

		_keys.push_back(key);
		++_count;
	}

	int Remove(TKey key)
	{
		for (size_t i = 0; i < _size; ++i)
		{
			if (_arr[i].has_value() && _arr[i].value().first == key)
			{
				_arr[i].reset();
				_keys.erase(std::find(_keys.begin(), _keys.end(), key));
				return 1;
			}

		}
		
		return 0;
		--_count;
	}

	std::string ToString() 
	{
		std::string output = "";
		for (size_t i = 0; i < _size; i++)
		{
			if (_arr[i].has_value())
			{
				 output += _arr[i].value().second.ToString() + '\n';
			}
		}
		return output;
	}


private:
	size_t _size;
	size_t _count;
	std::vector<TKey> _keys;
	std::optional<std::pair<TKey, TValue>>* _arr;

	bool _hasKey(TKey key)
	{
		return std::find(_keys.begin(), _keys.end(), key) != _keys.end();
	}

	int _hash(TKey key)
	{
		return key % _size;
	}

	int _doubleHash(TKey key)
	{
		return (_hash(key) + (key ^ _size)) % _size;
	}

	std::optional<TValue> _probeValue(TKey key)
	{
		int start = _doubleHash(key);
		int index = start;
		do
		{
			if (_arr[index].has_value() && _arr[index].value().first == key)
				return _arr[index].value().second;

			index = (index + 1) % _size;

			if (index == start)
				return {};
		} while (true);
	}

	int _probeSpace(TKey key)
	{
		int start = _doubleHash(key);
		int index = start;
		do
		{
			if (!_arr[index].has_value())
				return index;

			index = (index + 1) % _size;
		} while (true);
	}

	void _resize(int newSize)
	{
		int oldSize = _size;
		auto oldArr = _arr;

		_count = 0;
		_keys.clear();
		_size = newSize;
		_arr = new std::optional<std::pair<TKey, TValue>>[newSize];

		for (size_t i = 0; i < oldSize; ++i)
		{
			auto val = oldArr[i];
			if (val.has_value())
				Add(val.value().first, val.value().second);
		}

		delete[] oldArr;
	}
};

#endif // !HASHTABLE_H