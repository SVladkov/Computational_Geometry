#include <iostream>
#include <algorithm>
#include <stack>

#include "vecta.h"

using namespace std;
using namespace vecta;

vec2d<double> startPoint;

vec2d<double> findStartPoint(vec2d<double>* vertices, int numberOfVertices)
{
	double lowestY = vertices[0].y;
	double leftmostX = INT_MAX;

	for (int i=0; i<numberOfVertices; i++)
	{
		if (vertices[i].y < lowestY)
		{
			lowestY = vertices[i].y;
		}
		
		if (vertices[i].y == lowestY)
		{
			if (vertices[i].x < leftmostX)
			{
				leftmostX = vertices[i].x;
			}
		}
	}

	return vec2d<double>(leftmostX, lowestY);
}

/*bool compareAngles(vec2d<double> point1, vec2d<double> point2)
{
	return (point1.x - startPoint.x)*(point2.y - startPoint.y) - (point1.y - startPoint.y)*(point2.x - startPoint.x) > 0;
}*/

bool compareAngles(vec2d<double> point1, vec2d<double> point2)
{
	if((point1 - startPoint) || (point2 - startPoint))
	{
		return len(point1 - startPoint) > len(point2 - startPoint);
	}

	return (point1 - startPoint) < (point2 - startPoint);
}

void sortByAngle(vec2d<double>* vertices, int numberOfVertices, vec2d<double> startPoint)
{
	sort(vertices, vertices + numberOfVertices, compareAngles);
}

stack<vec2d<double> > wrap(vec2d<double>* vertices, int numberOfVertices)
{
	stack<vec2d<double> > visited;

	vec2d<double> fakeStartPoint(startPoint.x, startPoint.y);

	visited.push(fakeStartPoint);
	visited.push(startPoint);

	for (int i=0; i<numberOfVertices - 1; i++)
	{
		visited.push(vertices[i]);

		vec2d<double> first;
		vec2d<double> second;
		vec2d<double> third;

		third = visited.top();
		visited.pop();

		second = visited.top();
		visited.pop();

		first = visited.top();
		visited.pop();

		if (second - first < third - first)
		{
			visited.push(first);
			visited.push(second);
			visited.push(third);
		}
		else
		{
			visited.push(first);
			visited.push(third);
		}
	}

	return visited;
}

void grahamScan(vec2d<double>* vertices, int numberOfVertices, vec2d<double> startPoint)
{
	sortByAngle(vertices, numberOfVertices, startPoint);

	stack<vec2d<double> > result = wrap(vertices, numberOfVertices);

	cout << "The wrap: " << endl;

	while (!result.empty())
	{
		cout << result.top().x << " " << result.top().y << endl;
		result.pop();
	}

	cout << "---------------" << endl;
}

void printVertices(vec2d<double>* vertices, int numberOfVertices)
{
	for (int i=0; i<numberOfVertices; i++)
	{
		cout << vertices[i].x << " " << vertices[i].y << endl;
	}
}

int main()
{
	int numberOfVertices = 0;
	cin >> numberOfVertices;

	vec2d<double>* vertices = new vec2d<double>[numberOfVertices];

	for (int i=0; i<numberOfVertices; i++)
	{
		cin >> vertices[i].x;
		cin >> vertices[i].y;
	}

	startPoint = findStartPoint(vertices, numberOfVertices);

	grahamScan(vertices, numberOfVertices, startPoint);

	//printVertices(vertices, numberOfVertices);

	return 0;
}