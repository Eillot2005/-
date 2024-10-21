#include <iostream>
#include"Graph.h"
using namespace std;

int main()
{
	cout << "创建一个有5个顶点的图" << endl;
	Graph g(5);
	cout << "添加边" << endl;
	cout << "0-1 0-2 0-3 1-2 1-4 2-3 3-4" << endl;
	g.addEdge(0, 1, 1);
	g.addEdge(0, 2, 1);
	g.addEdge(0, 3, 1);
	g.addEdge(1, 2, 1);
	g.addEdge(1, 4, 1);
	g.addEdge(2, 3, 1);
	g.addEdge(3, 4, 1);
	g.printMatrix();
	cout << g.getWeight(0, 1) << endl;
	cout << g.getWeight(0, 2) << endl;
	cout << g.getWeight(0, 3) << endl;
	cout << g.getWeight(1, 2) << endl;
	cout << g.getWeight(1, 4) << endl;
	cout << g.getWeight(2, 3) << endl;
	cout << g.getWeight(3, 4) << endl;
	cout << g.getVertexNum() << endl;
	cout << g.getEdgeNum() << endl;
	cout << g.getFirstNeighbor(0) << endl;
	cout << g.getNextNeighbor(0, 1) << endl;
	cout << g.getIndegree(0) << endl;
	cout << g.getOutdegree(0) << endl;
	return 0;
}
