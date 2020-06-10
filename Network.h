#pragma once
#include "Matrix.h"
#include <iostream> 
#include <stdlib.h>
#include <math.h>

using namespace std; 

class Network
{
public:
	Network();
	void forward();
	void backward();
	void train(Matrix input, Matrix output);
private:
};
