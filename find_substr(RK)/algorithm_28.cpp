#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <math.h>

std::string delimeters = "., !?:;";

#define tonum(c) (c >= 'A' && c <= 'Z' ? c - 'A' : c - 'a' + 26)

void show_the_array(std::vector<std::string> vec)
{
	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << "{ " << vec[i] << " }";
	}
}

void find_the_words(std::string text, std::string sub, std::vector<std::string> vec)
{
	std::string word = "";

	int length_of_word = 0;
	int begin = 0;

	for (size_t i = 0; i < text.length(); i++)
	{
		if ((text[i] != delimeters[0])
			&& (text[i] != delimeters[1])
			&& (text[i] != delimeters[2])
			&& (text[i] != delimeters[3])
			&& (text[i] != delimeters[4])
			&& (text[i] != delimeters[5])
			&& (text[i] != delimeters[6]))
		{
			length_of_word++;
		}

		else
		{
			word = text.substr(begin, length_of_word);
			begin = i + 1;
			length_of_word = 0;
			if ((word.substr(word.length() / 2, word.length() / 2) == sub))
			{
				vec.push_back(word);
			}
		}
	}

	show_the_array(vec);
}

int mod(int a, int p, int m)
{
	if (p == 0)
	{
		return 1;
	}

	int sqr = mod(a, p / 2, m) % m;

	if (p & 1)
	{
		return ((a % m) * sqr) % m;
	}

	else
	{
		return sqr;
	}
}

int RabinKarpMatch(std::string T, std::string P, int d, int q)
{
	int count = 0;
	int length_of_text;
	int length_of_pattern;
	int p, t, h, found;
	length_of_text = T.length();
	length_of_pattern = P.length();
	h = mod(d, length_of_pattern - 1, q);
	p = t = 0;

	for (int i = 0; i < length_of_pattern; i++)
	{
		p = (d * p + tonum(P[i])) % q;
		t = (d * t + tonum(T[i])) % q;
	}

	for (int i = 0; i <= length_of_text; i++)
	{
		if (p == t)
		{
			found = 1;
			for (int j = 0; j < length_of_pattern; j++)
				if (P[j] != T[i + j])
				{
					found = 0;
					break;
				}
			if (found)
			{
				count++;
			}
			
		}
		else
		{
			t = (d * (t - ((tonum(T[i]) * h) % q)) + tonum(T[i + length_of_pattern])) % q;
		}
	}
	return count;
}

int main()
{
	int menu = 1;
	while (menu > 0)
	{
		std::cout << '\n' <<
			"1 - Find all words, that substring in the end of the word" << '\n' <<
			"2 - algorithm to find the pattern of the hude word" << '\n' <<
			"0 - quit from program" << '\n';
		std::cin >> menu;
		if (menu == 1)
		{
			std::vector<std::string> vec;
			std::string text;
			std::string sub;

			std::cout << "Input the text: ";
			std::cin.ignore();
			std::getline(std::cin, text);
			std::cout << "Input the substring: ";
			std::cin >> sub;
			find_the_words(text, sub, vec);
		}

		if (menu == 2)
		{
			std::ifstream file("find.txt");

			std::string line;
			std::string sub = "";
			std::string text = "";

			if (file)
			{
				std::getline(file, line);
				sub = line;
			}

			while (std::getline(file, line))
			{
				text = line;
			}

			std::cout << "The substring: " << sub << '\n';
			std::cout << "The text: " <<  text << '\n';

			int d = 1;
			int q = 1000;
			int occurrences = 0;

			occurrences = RabinKarpMatch(text, sub, d, q);
			if (occurrences > 0)
			{
				std::cout << "\nThe number of occurrences of a substring in the text: " << occurrences << '\n';
			}
			else
			{
				std::cout << "No substring in text";
			}
		}
	}
}