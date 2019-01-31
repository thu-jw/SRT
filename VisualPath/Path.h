#pragma once
#include <vector>
#include <iostream>
#include "Color.h"
using namespace std;

struct Point
{
	Point(float _x, float _y):x(_x), y(_y)
	{}
	float x, y;
};
class Path
{
public:
	Path(){}
	void loadPath(const char* filename);
	int size() { return p.size(); }
	Point & operator[](int i) { return p[i]; }
	friend void operator<<(ostream & os, Path & p)
	{
		cout << "timescale = " << p.timescale << endl;
		for (auto & point : p.p)
		{
			os << "(" << point.x << ", " << point.y << ")" << "->" << endl;
		}
		os << "end" << endl;
	}
	void setColor(const Color &c) 
	{ color = c; }
	Color color;
	float timescale;//����֮���ʱ����
	void draw();
private:
	vector<Point> p;//·����Ϣ
};
