#include "Polygon.h"

Polygon::Polygon(vec2d<double>* initialVertices, int numberOfVertices)
{
	this->vertices = initialVertices;
	this->sides = vector<list<int> >(numberOfVertices);
}

void Polygon::addSide(int vertex1, int vertex2)
{
	sides[vertex1].push_back(vertex2);
	sides[vertex2].push_back(vertex1);
}