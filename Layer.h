#pragma once
#include "Matrix.h"
#include <iostream> 
#include <stdlib.h> 
#include <math.h> 


class Layer
{
public:
	Layer(Matrix in, int num); 
	Layer(string filter, string activa, float size[]);
	void flatten();
	void Dense(int size, string activate);
	void MaxPool(int pool); 
	void Conv2D(string filter, string activate);

	Matrix input, result, *weight; 
	int count; 

};

