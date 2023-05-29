#include <iostream>
#include <fstream>
#include <string>

#include "timer.h"

std::string marks = "!,. ";


std::string gen_random(const int length)
{
	std::string str;

	for (int i = 0, j = 0; i < length; i++)
	{
		j = rand() % 10 + 1;

		if (j > length - i)
		{
			j = length - i;
		}

		i += j;

		for (int k = 0; k < j; k++) 
		{
			str += (char)(rand() % 32 + 122);
		}
		str += ' ';
	}
	str[str.size() - 1] = '.';

	return str;
}

int find_the_length_of_the_last_word(std::string text)
{
	int count = 0;
	int length = text.length();
	int attemps = length - 1;
	std::string space = " ";
	while (text[attemps] != space[0])
	{
		count++;
		attemps--;
		if (text[attemps] == space[0])
		{
			break;
		}
	}
	return count - 2;
}

std::string delete_the_last_word(std::string text, int lenght_of_the_last_word)
{
	std::string new_text = "";
	for (size_t i = 0; i < text.length() - lenght_of_the_last_word; i++)
	{
		new_text += text[i];
	}

	return new_text;
}

void compare_symbols(std::string text, int length_of_the_last_word)
{
	int count_for_length = 0;
	int count_of_big_words = 0;
	int count_of_equals_words = 0;
	int count_of_bad_attemps = 0;
	int count_of_great_attemps = 0;

	for (size_t i = 0; i < text.length() + 1; i++)
	{
		if ((text[i] != marks[0])
			&& (text[i] != marks[1])
			&& (text[i] != marks[2])
			&& (text[i] != marks[3])
			&& (text[i] != marks[4]))
			count_for_length++;
		else
		{
			if ((count_for_length) > length_of_the_last_word)
			{
				count_of_big_words++;
				count_of_great_attemps++;
				count_for_length = 0;
			}

			if ((count_for_length) == length_of_the_last_word)
			{
				count_of_equals_words++;
				count_of_great_attemps++;
				count_for_length = 0;
			}

			else
			{
				count_for_length = 0;
				count_of_bad_attemps++;
			}
		}

	}

	std::cout << "Big words = " << count_of_big_words << '\n'
		<< "Equal words = " << count_of_equals_words << '\n'
		<< "Bad attemps = " << count_of_bad_attemps << '\n'
		<< "Great attemps = " << count_of_great_attemps << '\n';
}

std::string substring(std::string source_string, int position_of_begin, int position_of_end)
{
	std::string substring = "";

	for (size_t i = position_of_begin; i < position_of_end; i++)
	{
		substring += source_string[i];
	}

	return substring;
}

void algorithm_of_knuth_morris_pratt(std::string source_string)
{
	int repetition = 0;
	int count = 0;
	std::string comparable_temporary_string = "";
	int pattern_length = 0;

	for (int i = 1; i < source_string.length(); i++)
	{
		count = 0;

		std::string temporary_string = substring(source_string, 0, i);
		for (int j = 0; j < source_string.length(); j += i)
		{
			if (j + i < source_string.length())
			{
				comparable_temporary_string = substring(source_string, j, j + i);

				if (temporary_string == comparable_temporary_string)
				{
					count++;

					if ((count > 1) && (count > repetition))
					{
						repetition = count + 1;
						pattern_length = ((j + i) - j);
					}
				}

				else
				{
					break;
				}
			}
		}
	}

	std::cout << "Number of repetitions = " << repetition << '\n';
	std::cout << "The minimum possible length of the source string = " << pattern_length << '\n';
}


Timer timer = Timer();
int main() 
{
	Timer timer = Timer();
	int menu = 1;
	while (menu > 0)
	{
		std::cout << '\n' << 
			"1 - compare the number of symbols with the last word" << '\n' <<
			"2 - algorithm to find the pattern of the hude word" << '\n' <<
			"0 - quit from program" << '\n';

		std::cout << "Input the number of task: ";
		std::cin >> menu;
		if (menu == 1)
		{
			std::string text = "";
			std::cout << "Input the text: ";
			std::cin.ignore();
			std::getline(std::cin, text);
			std::cout << "Doing...\n";
			timer.now();
			int length_of_the_last_word = find_the_length_of_the_last_word(text) + 1;
			text = delete_the_last_word(text, length_of_the_last_word + 2);
			compare_symbols(text, length_of_the_last_word);
			timer.now();
			std::cout << "Elapsed: " << timer;
		}

		if (menu == 2)
		{
			std::string source_string;
			std::cout << "Input the text: ";
			std::cin.ignore();
			std::getline(std::cin, source_string);
			algorithm_of_knuth_morris_pratt(source_string);
		}
	} 
}