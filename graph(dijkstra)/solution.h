#ifndef SOLUTION_H
#define SOLUTION_H

#include "graph.h"
#include "path.h"


class Solution 
{

private:
    Graph graph;                                

public:
    Solution(const Graph& g);
    Path* Floyd(int v, Path* data);
    Path calc(std::vector<int> v, int start);        

};

#endif