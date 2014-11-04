#include <iostream>
#include "Polygon.h"

using namespace std;
using namespace vecta;



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

	return 0;
}