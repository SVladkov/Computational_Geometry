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
	vector<int> sides;

	vector<int> orientedSides;

	void makeSidesOriented()
	{
		int i = 0;

		for (vector<int>::iterator it = sides.begin(); it != sides.end(); it++)
		{
			vec2d<double> pointA = vertices[i];
			vec2d<double> pointB = vertices[*it];

			orientedSides = vector<int> ();

			if (vertices[pointA].x )

			i++;
		}
	}

public:
	Polygon(vec2d<double>* initialVertices, int numberOfVertices)
	{
		this->vertices = initialVertices;
		sides = vector<int>(numberOfVertices);
	}

	void addSide(int vertex1, int vertex2)
	{
		sides[vertex1] = vertex2;
	}

	bool checkIfPointIsInPolygon(int x, int y)
	{
		makeSidesOriented();

		return true;
	}
};

int main()
{
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

	myPolygon.checkIfPointIsInPolygon(2, 2);

	return 0;
}