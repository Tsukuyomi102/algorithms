#include <iostream>
#include <vector>

#include "path.h"

Path::Path(int start)
{
	path.push_back(start);
	length = 0;
}

Path& Path::operator=(const Path& p) 
{
	path = p.get_path();
	length = p.get_length();
	return *this;
}

std::vector<int> Path::get_path()const
{
	return path;
}

int Path::get_length()const 
{
	return length;
}

void Path::push_back(int user_value, int l)
{
	path.push_back(user_value);
	length += l;
}

void Path::push_back(Path p)
{
	for (size_t i = 0; i < p.get_path().size(); i++)
	{
		int last = path[path.size() - 1];
		if (last != p.get_path()[i])
		{
			path.push_back(p.get_path()[i]);
		}
	}
	length += p.get_length();
}

void Path::show_the_path(Path& p)
{
	size_t n = p.get_path().size();
	for (size_t i = 0; i < n; i++)
	{
		std::cout << p.get_path()[i] + 1;
		if (i != n - 1)
		{
			std::cout << "->";
		}
		else
		{
			std::cout << " (";
		}
	}
	std::cout << p.get_length() << ")" << '\n';
}