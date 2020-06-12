#pragma once
#include "Matrix.h"
#include <iostream> 
#include <stdlib.h> 
#include <math.h> 


class Layer
{
public:
	Layer(); 
	Layer(string filter, string activa, float size[]);
	void flatten();
	void Dense();
	Matrix Conv2D(Matrix input, string filter);

private:
	Matrix weight;
};

