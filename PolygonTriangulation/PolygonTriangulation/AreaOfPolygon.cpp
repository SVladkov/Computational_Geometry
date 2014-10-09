#include <iostream>
#include <vector>
#include <list>
#include "vecta.h"

using namespace std;
using namespace vecta;

class Polygon
{
private:
	vec2d<double>* vertices;
	vector<list<int> > sides;

public:
	Polygon(vec2d<double>* initialVertices, int numberOfVertices)
	{
		vertices = initialVertices;
		sides = vector<list<int> >(numberOfVertices);
	}

	void addSide(int vertex1, int vertex2)
	{
		sides[vertex1].push_back(vertex2);
		sides[vertex2].push_back(vertex1);
	}
};

int main()
{
	//vec2d<int> p1(4, 5);	

	int numberOfVertices = 0;
	cin >> numberOfVertices;

	vec2d<double>* vertices = new vec2d<double>[numberOfVertices];

	double y = 0;
	double x = 0;

	for (int i = 0; i < numberOfVertices; i++)
	{
		cout << "Vertex " << i << ": ";

		cin >> x;
		cin >> y;

		vertices[i] = vec2d<double>(x, y);
	}

	Polygon myPolygon(vertices, numberOfVertices);

	int startVertex;
	int endVertex;

	for (int i = 0; i < numberOfVertices; i++)
	{
		cin >> startVertex;
		cin >> endVertex;

		myPolygon.addSide(startVertex, endVertex);
	}

	return 0;
}