#include "Matrix.h"
using namespace std; 

// Constructor of the Matrix class
Matrix::Matrix()
{
	row = 0;
	col = 0;
	Matrix::ary = new float* [row];
	for (int i = 0; i < row; i++)
	{
		ary[i] = new float[col];
		for (int j = 0; j < col; j++)
		{
			ary[i][j] = 0;
		}	
	}
}

// Constructor of the Matrix class with the inputing the pre-existing 2d array. 
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

// Constructor of Matrix class with pre-existing size
Matrix::Matrix(int row, int col)
{
	Matrix::row = row;
	Matrix::col = col;
	Matrix::ary = new float* [row];
	for (int i = 0; i < row; i++)
	{
		ary[i] = new float[col];
		for (int j = 0; j < col; j++)
		{
			ary[i][j] = 0; 
		}
	}
}

//Constructor of matrix class fill with one number
Matrix::Matrix(float temp, int row, int col)
{
	Matrix::row = row;
	Matrix::col = col;
	Matrix::ary = new float* [row];
	for (int i = 0; i < row; i++)
	{
		ary[i] = new float[col];
		for (int j = 0; j < col; j++)
		{
			ary[i][j] = temp;
		}
	}
}

// Random function to create randome number from 0-1 for every element in the size of your matrix
// parameter: none 
// return: none 
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

// adding two of the same size matrix together and return a new Matrix
// parameter: Matrix temp
// return: Matrix result
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

// subtracting two of the same size matrix together and return a new Matrix. 
// parameter: Matrix temp 
// return: Matrix result 
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

// multiply the two matrix with same size together
// parameter: Matrix temp 
// return Matrix result
Matrix Matrix::multi(Matrix temp)
{
	Matrix result = Matrix(row, col);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			result.ary[i][j] = ary[i][j] * temp.ary[i][j];
		}
	}
	return result; 
}


// Dot product function for matrix multiplication with a bias include 
// parameter: Matrix temp, float bias = 0 
// return: Matrix
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
					product = ary[i][k] * temp.ary[k][j]; 
					sum = sum + product; 
				}
				result.ary[i][j] = sum + bias;
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

// This function is used for caluation the sum of multiplication of corresponding elements in the matrices
// it has to be the same size for both matrices 
// parameter: Matrix temp 
// return float
float Matrix::conv(Matrix temp)
{
	float sum = 0; 
	if (row == temp.row && col == temp.col)
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				sum += ary[i][j] * temp.ary[i][j];
			}
		}
		return sum;
	}
	else
	{
		cout << "Matrix convolve error: Matrix must be in the same size." << endl; 
		return 0; 
	}
}

// Scalar multiplication function for matrix multiplication with a bias include 
// parameter: float temp
// return: Matrix
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

// Modifying the matrix with the activation function in the obejct itself. 
// parameter: string function (sigmoid, relu, leakyrelu)
// return: none
void Matrix::modi(string function)
{
	if (function.compare("sigmoid") == 0)
	{
		//cout << "Activation Fucntion is sigmoid" << endl;
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
		//cout << "Activation Fucntion is relu" << endl; 
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
		//cout << "Activation Fucntion is leakyrelu" << endl;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (ary[i][j] < 0)
					ary[i][j] = float(0.01) * ary[i][j];
			}
		}
	}
	else if (function.compare("softmax") == 0)
	{
		//cout << "Activation Fucntion is softmax" << endl;
		float sum = 0; 
		for (int i = 0; i < col; i++)
		{
			sum += exp(ary[0][i]);
		}
		//cout << "sum: " << sum << endl;
		for (int j = 0; j < col; j++)
		{
			//cout << exp(ary[0][j]) << endl;
			ary[0][j] = exp(ary[0][j]) / sum; 
		}
	}
	else
		cout << "please type the right activation function!" << endl;
}

// Transposing the Matrix inside the object itself. 
// parameter: none 
// return: none 
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

// Setting the Matrix to become a square matrix by adding zeros on the missing row/col in the object itself 
// parameter: none
// return: none
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

// Getting the size of the matrix
// parameter: none
// return: *int array 
int* Matrix::getSize()
{
	int size[2];
	size[0] = row;
	size[1] = col;
	return size;
}

// printing the matrix with the location indicated. 
// parameter: none 
// return: none 
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

// printing the matrix with grid view
// parameter: none 
// return: none
void Matrix::printGrid()
{
	cout.precision(3);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << ary[i][j] << "\t"; 
		}
		cout << endl; 
	}
}

