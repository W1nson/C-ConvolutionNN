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
	Matrix flatten();
	Matrix Dense(Matrix input, int size, string activate);
	Matrix MaxPool(Matrix input, int pool); 
	Matrix Conv2D(Matrix input, string filter, string activate);
	
private:
	Matrix result;
	Matrix weight; 
};

