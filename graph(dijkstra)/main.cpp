#include <iostream>

#include "Graph.h"
#include "Path.h"
#include "Solution.h"

int main()
{
    int menu = 1;
    while (menu != 0)
    {
        std::cout << '\n' << "Input the method of graph" << '\n' <<
            "1 - deafult graph" << '\n' <<
            "2 - your graph" << '\n' <<
            "0 - quit" << '\n';
        std::cin >> menu;

        if (menu == 1)
        {
            Graph graph = Graph();
            graph.show_the_graph(graph);
            Solution s(graph);
            std::cout << "Input the 2 points, first - the start point, second - the end point: ";
            int start, end;
            std::cin >> start >> end;
            s.calc({ end-1, end-1 }, start-1);
        }

        if (menu == 2)
        {
            std::cout << "Input the number of points in graph: ";
            int point;
            std::cin >> point;
            Graph graph = Graph(point);
            graph.show_the_graph(graph);
            Solution s(graph);
            std::cout << "Input the 2 points, first - the start point, second - the end point: ";
            int start, end;
            std::cin >> start >> end;
            s.calc({ end - 1, end - 1 }, start - 1);
        }
    }
}