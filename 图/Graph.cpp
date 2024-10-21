#include "Graph.h"
#include<iostream>
using namespace std;

Graph::Graph(int vertexNum)
{
	this->vertexNum = vertexNum;
	this->edgeNum = 0;
	matrix = new int* [vertexNum];
	for (int i = 0; i < vertexNum; i++)
	{
		matrix[i] = new int[vertexNum];
		for (int j = 0; j < vertexNum; j++)
		{
			matrix[i][j] = 0;
		}
	}
}
Graph::~Graph()
{
	for (int i = 0; i < vertexNum; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}
void Graph::addEdge(int v1, int v2, int weight)
{
	matrix[v1][v2] = weight;
	edgeNum++;
}
void Graph::removeEdge(int v1, int v2)
{
	matrix[v1][v2] = 0;
	edgeNum--;
}
int Graph::getWeight(int v1, int v2)
{
	return matrix[v1][v2];
}
int Graph::getVertexNum()
{
	return vertexNum;
}
int Graph::getEdgeNum()
{
	return edgeNum;
}
int Graph::getFirstNeighbor(int v)
{
	for (int i = 0; i < vertexNum; i++)
	{
		if (matrix[v][i] > 0)
		{
			return i;
		}
	}
	return -1;
}
int Graph::getNextNeighbor(int v, int w)
{
	for (int i = w + 1; i < vertexNum; i++)
	{
		if (matrix[v][i] > 0)
		{
			return i;
		}
	}
	return -1;
}
int Graph::getIndegree(int v)
{
	int count = 0;
	for (int i = 0; i < vertexNum; i++)
	{
		if (matrix[i][v] > 0)
		{
			count++;
		}
	}
	return count;
}
int Graph::getOutdegree(int v)
{
	int count = 0;
	for (int i = 0; i < vertexNum; i++)
	{
		if (matrix[v][i] > 0)
		{
			count++;
		}
	}
	return count;
}
void Graph::printMatrix()
{
	for (int i = 0; i < vertexNum; i++)
	{
		for (int j = 0; j < vertexNum; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}
