#ifndef CCIRCLE_H
#define CCIRCLE_H
#include "cShape.h"


class cCircle : public cShape
{
private:
	float fLength;
	float fWidth;
	float radius;

public:
	cCircle(string n, float x, float y, float r, float g, float b)
	{
		this->setName(n);
		this->setPosx(x);
		this->setPosy(y);
		this->setRed(r);
		this->setGre(g);
		this->setBlu(b);
	};
};
#endif // !CCIRCLE_H
