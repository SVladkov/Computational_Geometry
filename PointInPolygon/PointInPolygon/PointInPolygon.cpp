#include <iostream>
#include <vector>
#include <list>
#include "vecta.h"

using namespace std;
using namespace vecta;

class Polygon
{
private:
	vector<vec2d<double> > vertices;

	vector<pair<vec2d<double>, vec2d<double> > > makeOrientedSides()
	{
		vector<pair<vec2d<double>, vec2d<double> > > result = vector<pair<vec2d<double>, vec2d<double> > >();
		
		int numberOfVertices = vertices.size();

		for (int i=0; i<numberOfVertices; i++)
		{
			vec2d<double> pointA = vertices[i];
			vec2d<double> pointB = vertices[(i + 1) % numberOfVertices];

			if (pointA.y > pointB.y) // A should be the lower point
			{
				vec2d<double> temp = pointA;
				pointA = pointB;
				pointB = temp;
			}

			pair<vec2d<double>, vec2d<double> > side = make_pair(pointA, pointB);

			result.push_back(side);
		}

		return result;
	}

public:
	Polygon()
	{
		vertices = vector<vec2d<double> >();
	}

	void addVertex(vec2d<double> vertex) 
	{
		vertices.push_back(vertex);
	}

	bool checkIfPointIsInPolygon(vec2d<double> point)
	{
		vector<pair<vec2d<double>, vec2d<double> > > sides = makeOrientedSides();

		int crossings = 0;

		int sidesCount = sides.size();
		for (int i=0; i<sidesCount; i++)
		{
			vec2d<double> pointA = sides[i].first;
			vec2d<double> pointB = sides[i].second;

			if ((point.x >= pointA.x || point.x >= pointB.x) && (point.y > pointA.y && point.y <= pointB.y))
			{
				crossings++;
			}
		}

		return crossings % 2 == 1;
	}
};

int main()
{
	int numberOfVertices;
	cin >> numberOfVertices;

	Polygon polygon = Polygon();

	for (int i=0; i<numberOfVertices; i++)
	{
		double pointX;
		cin >> pointX;

		double pointY;
		cin >> pointY;

		vec2d<double> vertex = vec2d<double>(pointX, pointY);

		polygon.addVertex(vertex);
	}
	
	double pointX;
	cin >> pointX;

	double pointY;
	cin >> pointY;

	vec2d<double> point = vec2d<double>(pointX, pointY);

	bool isIn = polygon.checkIfPointIsInPolygon(point);

	if (isIn)
	{
		cout << "Yes";
	}
	else
	{
		cout << "No";
	}

	return 0;
}