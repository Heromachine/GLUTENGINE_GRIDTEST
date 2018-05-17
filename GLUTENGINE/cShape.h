#ifndef CSHAPE_H
#define CSHAPE_H

#include <iostream>
#include <string>
#include "cBaseNode.h"
using namespace std; 
class Shape : BaseNode
{
private:

	float r = 1.0f, b = 1.0f, g = 1.0f;

	vector <float> color;
	string name;

public:
	Shape()
	{
	}

	float getCr() { return this->r; }
	float getCg() { return this->g; }
	float getCb() { return this->b; }
	string getName() { return name; }
	void setRed(float r) { this->r = r; }
	void setGre(float g) { this->g = g; }
	void setBlu(float b) { this->b = b; }
	void setName(string n) { name = n; }

};


#endif // !CSHAPE_H
#pragma once
