#pragma once

#include <math.h>

class Utility
{
public:
	Utility(void);
	virtual ~Utility(void);

	double EuclideanDistance();
	double GetTime();
	double CalculateTilt(double gx, double gy);
};

