#ifndef PATH_H
#define PATH_H

#include <vector>

class Path
{
private:
	std::vector<int> path;
	int length;

public:
	Path(int start);
	Path& operator= (const Path& p);
	std::vector<int> get_path()const;
	int get_length()const;
	void push_back(int user_value, int length);
	void push_back(Path p);
	void show_the_path(Path& p);
};
#endif // !PATH_H

