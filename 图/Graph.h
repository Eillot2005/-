#pragma once
class Graph
{
private:
	int** matrix;
	int vertexNum;//������
	int edgeNum;//����
public:
	Graph(int vertexNum);
	~Graph();
	void addEdge(int v1, int v2, int weight);//��ӱ�, v1Ϊ��㣬v2Ϊ�յ㣬weightΪȨֵ
	void removeEdge(int v1, int v2);
	int getWeight(int v1, int v2);
	int getVertexNum();
	int getEdgeNum();
	int getFirstNeighbor(int v);//����v�ĵ�һ���ڽӵ�
	int getNextNeighbor(int v, int w);//wΪv���ڽӵ㣬����v����һ���ڽӵ�
	int getIndegree(int v);//����v�����
	int getOutdegree(int v);//����v�ĳ���
	void printMatrix();
};

