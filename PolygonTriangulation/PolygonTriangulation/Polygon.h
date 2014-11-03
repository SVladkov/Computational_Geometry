#pragma once

#include "vecta.h"
#include <vector>
#include <list>

using namespace std;
using namespace vecta;

class Polygon
{
private:
	vec2d<double>* vertices;
	vector<list<int>> sides;

public:
	Polygon(vec2d<double>*, int);
	void addSide(int, int);
};

