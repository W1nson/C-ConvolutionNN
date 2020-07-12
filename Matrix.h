#pragma once
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <iomanip>
using namespace std;


class Matrix
{
public:
	Matrix();
	Matrix(float** temp, int row, int col);
	Matrix(int row, int col);
	Matrix(float temp, int row, int col);
	void random();
	Matrix add(Matrix temp);
	Matrix subtract(Matrix temp);
	Matrix multi(Matrix temp);
	void scale(float temp);
	Matrix dot(Matrix temp, float = 0.0);
	float conv(Matrix temp); 
	void modi(string function);
	void transpose(); 
	void setSquare(); 
	int* getSize(); 
	void print();
	void printGrid(); 


	int row, col;
	float** ary;
};

