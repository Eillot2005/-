#pragma once
class Graph
{
private:
	int** matrix;
	int vertexNum;//顶点数
	int edgeNum;//边数
public:
	Graph(int vertexNum);
	~Graph();
	void addEdge(int v1, int v2, int weight);//添加边, v1为起点，v2为终点，weight为权值
	void removeEdge(int v1, int v2);
	int getWeight(int v1, int v2);
	int getVertexNum();
	int getEdgeNum();
	int getFirstNeighbor(int v);//返回v的第一个邻接点
	int getNextNeighbor(int v, int w);//w为v的邻接点，返回v的下一个邻接点
	int getIndegree(int v);//返回v的入度
	int getOutdegree(int v);//返回v的出度
	void printMatrix();
};

