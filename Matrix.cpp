#include "Matrix.h"

Matrix::Matrix()
{
	row = 0;
	col = 0;
	Matrix::ary = new float* [row];
	for (int i = 0; i < row; i++)
	{
		ary[i] = new float[col];
	}
}

Matrix::Matrix(float** temp, int row, int col)
{
	Matrix::row = row;
	Matrix::col = col;
	Matrix::ary = new float* [row];
	for (int i = 0; i < row; i++)
	{
		ary[i] = new float[col];
		for (int j = 0; j < col; j++)
			ary[i][j] = temp[i][j];
	}

}

Matrix::Matrix(int row, int col)
{
	Matrix::row = row;
	Matrix::col = col;
	Matrix::ary = new float* [row];
	for (int i = 0; i < row; i++)
	{
		ary[i] = new float[col];
	}
}

void Matrix::random()
{
	float temp = ((float)rand() / (RAND_MAX));
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			ary[i][j] = ((float)rand() / (RAND_MAX));
		}
	}
}

Matrix Matrix::add(Matrix temp)
{
	Matrix result;
	if (temp.row == row && temp.col == col)
	{
		result.ary = new float* [row];
		for (int i = 0; i < row; i++)
		{
			result.ary[i] = new float[col];
			for (int j = 0; j < col; j++)
			{
				result.ary[i][j] = ary[i][j] + temp.ary[i][j];
			}
		}
		result.row = row;
		result.col = col;
		return result;
	}
	else
	{
		cout << "size is not same" << endl;
		return result;
	}
}
Matrix Matrix::subtract(Matrix temp)
{
	Matrix result;
	if (temp.row == row && temp.col == col)
	{
		result.ary = new float* [row];
		for (int i = 0; i < row; i++)
		{
			result.ary[i] = new float[col];
			for (int j = 0; j < col; j++)
			{
				result.ary[i][j] = ary[i][j] - temp.ary[i][j];
			}
		}
		result.row = row;
		result.col = col;
		return result;
	}
	else
	{
		cout << "size is not same" << endl;
		return result;
	}
}

Matrix Matrix::dot(Matrix temp, float bias)
{
	Matrix result;
	float sum = 0;
	float product = 0.0; 
	if (temp.row == col)
	{
		result.ary = new float* [row];
		for (int i = 0; i < row; i++)
		{
			result.ary[i] = new float[temp.col];
			for (int j = 0; j < temp.col; j++)
			{
				for (int k = 0; k < col; k++)
				{
					product = ary[i][k] * temp.ary[k][i]; 
					sum = sum + product; 
					cout << "location: org[" << i << "][" << k << "] X temp[" << k << "][" << i << "]: ";
					cout << product << endl;
				}
				result.ary[i][j] = sum + bias;
				cout << sum << endl; 
				sum = 0; 
			}
		}
		result.row = row;
		result.col = temp.col;
		return result;
	}
	else
	{
		cout << "voilates dot product" << endl;
		return result;
	}
}

void Matrix::scale(float temp)
{
	Matrix result;
	result.ary = new float* [row];
	for (int i = 0; i < row; i++)
	{
		result.ary[i] = new float[col];
		for (int j = 0; j < col; j++)
		{
			result.ary[i][j] = temp * ary[i][j];
		}
	}
	ary = result.ary; 
}

void Matrix::modi(string function)
{
	if (function.compare("sigmoid") == 0)
	{
		cout << "Activation Fucntion is sigmoid" << endl;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				ary[i][j] = 1 / (1 + exp(ary[i][j]));
			}
		}
	}
	else if (function.compare("relu") == 0)
	{	
		cout << "Activation Fucntion is relu" << endl; 
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (ary[i][j] < 0)
					ary[i][j] = 0;
			}
		}
	}
	else if (function.compare("leakyrelu") == 0)
	{
		cout << "Activation Fucntion is leakyrelu" << endl;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (ary[i][j] < 0)
					ary[i][j] = 0.01 * ary[i][j];
			}
		}
	}
	else
		cout << "please type the right activation function!" << endl;
}


void Matrix::transpose()
{
	Matrix result = Matrix(col, row);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			result.ary[j][i] = ary[i][j];
		}
	}
	ary = result.ary;
	int size = col;
	col = row;
	row = size;
}


void Matrix::setSquare()
{
	
	if (row > col)
	{
		Matrix temp = Matrix(row, row);
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				temp.ary[i][j] = ary[i][j]; 
			}
			temp.ary[i][row - 1] = 0; 
		}
		ary = temp.ary; 
		col = row;
		
	}
	else if (row < col)
	{
		Matrix temp = Matrix(col, col);
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				temp.ary[i][j] = ary[i][j];
			}
		}
		for (int k = 0; k < col; k++)
		{
			temp.ary[col][k] = 0; 
		}
		ary = temp.ary; 
		row = col;
	}
	else
	{
		cout << "It's a squre matrix" << endl;
	}
}

int* Matrix::getSize()
{
	int size[2];
	size[0] = row;
	size[1] = col;
	return size;
}


void Matrix::print()
{
	cout << "the size of this 2D array is: " << row << "x" << col << endl;
	for (int i = 0; i < Matrix::row; i++)
	{
		for (int j = 0; j < Matrix::col; j++)
		{
			std::cout << "2D Array[" << i << "][" << j << "]: " << Matrix::ary[i][j] << std::endl;
		}
	}

}

