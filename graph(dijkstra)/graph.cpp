#include <iostream>
#include <iomanip>

#include "graph.h"


//default graph
Graph::Graph()
{
	this->n = 10;
	value = new int* [10];
	for (size_t i = 0; i < 10; i++)
	{
		value[i] = new int[10];
	}

	value[0][0] = 0;	value[0][1] = 3;	value[0][2] = 4;	value[0][3] = 2;	value[0][4] = -1;		
	value[1][0] = 3;	value[1][1] = 0;	value[1][2] = -1;	value[1][3] = -1;	value[1][4] = -1;
	value[2][0] = 4;	value[2][1] = -1;	value[2][2] = 0;	value[2][3] = -1;	value[2][4] = -1;
	value[3][0] = 2;	value[3][1] = -1;	value[3][2] = -1;	value[3][3] = 0;	value[3][4] = 5;
	value[4][0] = -1;	value[4][1] = -1;	value[4][2] = -1;	value[4][3] = 5;	value[4][4] = 0;
	value[5][0] = -1;	value[5][1] = 3;	value[5][2] = 6;	value[5][3] = 2;	value[5][4] = 1;
	value[6][0] = -1;	value[6][1] = -1;	value[6][2] = -1;	value[6][3] = -1;	value[6][4] = 6;
	value[7][0] = -1;	value[7][1] = -1;	value[7][2] = -1;	value[7][3] = -1;	value[7][4] = -1;
	value[8][0] = -1;	value[8][1] = -1;	value[8][2] = -1;	value[8][3] = -1;	value[8][4] = 12;
	value[9][0] = -1;	value[9][1] = -1;	value[9][2] = -1;	value[9][3] = -1;	value[9][4] = -1;

	value[0][5] = -1;	value[0][6] = -1;	value[0][7] = -1;	value[0][8] = -1;	value[0][9] = -1;
	value[1][5] = 3;	value[1][6] = -1;	value[1][7] = -1;	value[1][8] = -1;	value[1][9] = -1;
	value[2][5] = 6;	value[2][6] = -1;	value[2][7] = -1;	value[2][8] = -1;	value[2][9] = -1;
	value[3][5] = 2;	value[3][6] = -1;	value[3][7] = -1;	value[3][8] = -1;	value[3][9] = -1;
	value[4][5] = 1;	value[4][6] = 6;	value[4][7] = -1;	value[4][8] = 12;	value[4][9] = -1;
	value[5][5] = 0;	value[5][6] = 8;	value[5][7] = 7;	value[5][8] = -1;	value[5][9] = -1;
	value[6][5] = 8;	value[6][6] = 0;	value[6][7] = -1;	value[6][8] = -1;	value[6][9] = 4;
	value[7][5] = 7;	value[7][6] = -1;	value[7][7] = 0;	value[7][8] = 6;	value[7][9] = 3;
	value[8][5] = -1;	value[8][6] = -1;	value[8][7] = 6;	value[8][8] = -1;	value[8][9] = 11;
	value[9][5] = -1;	value[9][6] = 4;	value[9][7] = 3;	value[9][8] = 11;	value[9][9] = 0;
}

//user graph
Graph::Graph(int n)
{
	std::cout << "If you see the same indexes, then input <0>, cuz its the same point" << '\n' <<
		"If the points havent connections, then input <-1>" << '\n';
	this->n = n;
	value = new int* [n];
	for (size_t i = 0; i < n; i++)
	{
		value[i] = new int[n];
	}

	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			std::cout << "Input " << i << "-" << j << ": ";
			std::cin >> value[i][j];
		}
	}
}

int** Graph::get_data() const
{
	int** v = new int* [n];
	for (size_t i = 0; i < n; i++)
	{
		v[i] = new int[n];
		for (size_t j = 0; j < n; j++)
		{
			v[i][j] = value[i][j];
		}
	}

	return v;
}

int const Graph::get_length() const
{
	return n;
}

void Graph::show_the_graph(Graph& graph)
{
	int** v = graph.get_data();
	std::cout << "  ";
	for (size_t i = 0; i < graph.get_length(); i++)
	{
		std::cout << std::setw(5) << i + 1 << " ";
	}
	std::cout << '\n';
	for (size_t i = 0; i < graph.get_length(); i++)
	{
		std::cout << i + 1 << " ";
		for (size_t j = 0; j < graph.get_length(); j++)
		{
			if (i < 9)
			{
				std::cout << std::setw(5) << std::right << v[i][j] << " ";
			}
			else
			{
				std::cout << std::setw(4) << v[i][j] << "  ";
 			}
			
		}
		std::cout << '\n';
	}
}