#include <iostream>
#include <algorithm>
#include <vector>

#include "vecta.h"

using namespace std;
using namespace vecta;

class Segment
{
private:
	pair<int, int> segment;

public:
	Segment(int startPoint, int endPoint)
	{
		segment = make_pair(startPoint, endPoint);
	}

	int getStartPoint()
	{
		return segment.first;
	}

	int getEndPoint()
	{
		return segment.second;
	}
};

enum Ending
{
	Start,
	End
};

class EndingPoint
{
private:
	int x;
	Ending ending;

public:
	EndingPoint(int initialX, Ending initialEnding)
	{
		x = initialX;
		ending = initialEnding;
	}

	int getX()
	{
		return x;
	}

	Ending getEnding()
	{
		return ending;
	}
};

void processInput(vector<Segment>& segments)
{
	int n = 0;
	cin >> n;

	for (int i=0; i<n; i++)
	{
		int firstPoint;
		cin >> firstPoint;

		int secondPoint;
		cin >> secondPoint;

		Segment segment(firstPoint, secondPoint);

		segments.push_back(segment);
	}	
}

void extractPoints(vector<Segment>& segments, vector<EndingPoint>& endingPoints)
{
	for(vector<Segment>::iterator it = segments.begin(); it != segments.end(); it++)
	{
		EndingPoint start = EndingPoint((*it).getStartPoint(), Start);
		endingPoints.push_back(start);

		EndingPoint end = EndingPoint((*it).getEndPoint(), End);
		endingPoints.push_back(end);		
	}
}

bool comparePoints(EndingPoint firstPoint, EndingPoint secondPoint)
{
	return firstPoint.getX() < secondPoint.getX();
}

int findCommonLength(vector<EndingPoint> points)
{
	sort(points.begin(), points.end(), comparePoints);

	int length = 0;
	int counter = 0;

	counter++;

	int size = points.size();
	for (int i=1; i<size; i++)
	{
		if (points[i].getEnding() == Start)
		{
			counter++;
		}
		else
		{
			counter--;
		}

		if (counter > 0)
		{
			length += points[i].getX() - points[i - 1].getX();
		}
	}

	return length;
}

int main()
{
	vector<Segment> segments = vector<Segment>();
	processInput(segments);

	vector<EndingPoint> points = vector<EndingPoint>();
	extractPoints(segments, points);

	int length = findCommonLength(points);

	return 0;
}