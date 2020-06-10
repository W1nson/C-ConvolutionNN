#pragma once
#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;


class Matrix
{
public:
	Matrix();
	Matrix(float** temp, int row, int col);
	Matrix(int row, int col);
	void random();
	Matrix add(Matrix temp);
	Matrix subtract(Matrix temp);
	void scale(float temp);
	Matrix dot(Matrix temp, float = 0.0);
	void modi(string function);
	void transpose(); 
	void setSquare(); 
	int* getSize(); 
	void print();
private:
	int row, col;
	float** ary;
};

