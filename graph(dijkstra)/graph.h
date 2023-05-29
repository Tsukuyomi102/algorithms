#ifndef GRAPH_H
#define GRAPH_H

class Graph 
{
private:
	int n;
	int** value;

public:
	Graph(int n);
	Graph();
	int** get_data() const;
	int const get_length() const;
	void show_the_graph(Graph& graph);
};
#endif