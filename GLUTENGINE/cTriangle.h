#ifndef CTRIANGLE_H
#define CTRIANGLE_H
#include <vector>
#include "cShape.h"
#endif // !CTRIANGLE_H

class cTriangle : public cShape
{
private:

public:
	cTriangle(string n, float x, float y, float r, float g, float b)
	{
		this->setName(n);
		this->setPosx(x);
		this->setPosy(y);
		this->setRed(r);
		this->setGre(g);
		this->setBlu(b);
	};
};