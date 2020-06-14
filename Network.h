#pragma once
#include "Matrix.h"
#include "Layer.h"
#include <iostream> 
#include <stdlib.h>
#include <math.h>

using namespace std; 

class Network
{
public:
	Network();
	void add(Layer input); 
	void forward();
	void backward();
	void train(Matrix input, Matrix output);
private:

	int count; 
	Matrix result; 


};
