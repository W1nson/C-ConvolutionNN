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
	void Conv2D(string = NULL, string = NULL, int = 3 );
	void BackProp(Matrix train_in, Matrix train_out, float = 0.1);

	Matrix input, result, *h_out, * weight, error, feature; 
	float totalError = 0; 
	int count; 

};