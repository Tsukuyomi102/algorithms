#include <iostream>
#include <limits>
#include <vector>
#include <map>
#include <algorithm>

#include "solution.h"

Solution::Solution(const Graph& g) {
    graph = g;
}

// floyd's algorithm
Path* Solution::Floyd(int v, Path* data) 
{
    data = (Path*)calloc(graph.get_length(), sizeof(Path));
    int *distaces = new int [graph.get_length()];
    int *out = new int[graph.get_length()];
    for (int i = 0; i < graph.get_length(); ++i) 
    {
        if (i == v) 
        {
            distaces[i] = 0;
            data[i] = Path(v);
        }
        else 
        {
            distaces[i] = std::numeric_limits<int>::max();
        }
        out[i] = 0;
    }

    int min = std::numeric_limits<int>::max(), index = -1;
    do 
    {
        min = std::numeric_limits<int>::max();
        for (int i = 0; i < graph.get_length(); ++i) 
        {
            if ((out[i] == 0) && (distaces[i] < min)) 
            {
                min = distaces[i];
                index = i;
            }
        }
        if (min != std::numeric_limits<int>::max()) 
        {
            for (int i = 0; i < graph.get_length(); ++i) 
            {
                if (graph.get_data()[index][i] > 0) 
                {
                    int temp = min + graph.get_data()[index][i];
                    if (temp < distaces[i]) 
                    {
                        distaces[i] = temp;
                        data[i] = data[index];
                        data[i].push_back(i, graph.get_data()[index][i]);
                    }
                }
            }
            out[index] = 1;
        }
    } while (min < std::numeric_limits<int>::max());

    return data;
}

// calculating
Path Solution::calc(std::vector<int> v, int start) 
{
    std::map<int, Path*> distaces;
    Path* temp = (Path*)calloc(graph.get_length(), sizeof(Path));
    temp = Floyd(start, temp);
    distaces[start] = temp;
    for (size_t i = 0; i < v.size(); ++i) 
    {
        temp = Floyd(v[i], temp);
        distaces[v[i]] = temp;
    }

    Path p = Path(start);
    std::sort(v.begin(), v.end());
    for (size_t i = 0; i < v.size(); ++i) 
    {
        int last = p.get_path()[p.get_path().size() - 1];
        p.push_back(distaces[last][v[i]]);
    }
    p.show_the_path(p);
    return p;
}