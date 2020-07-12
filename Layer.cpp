#include "Layer.h"
using namespace std; 

Layer::Layer(Matrix in, int num)
{
	
	input = in; 
	weight = new Matrix[num];
	h_out = new Matrix[num];
	count = 0;

}

void Layer::flatten()
{
	int count = 0; 
	int r = 0;
	Matrix temp = Matrix(1, result.row * result.col);
	for (int i = 0; i < result.row*result.col; i++)
	{
		if (count < result.col)
		{
			temp.ary[0][i] = result.ary[r][count];
			count++; 
		}
		else if(r < result.row)
		{
			r++;
			count = 0; 
			temp.ary[0][i] = result.ary[r][count];
			count++;
		}
	}
	result = temp; 
}

void Layer::Dense(int size, string activate)
{
	cout << "before: " << count << endl;
	if (input.row != 0 && input.col != 0)
	{
		input = result;
	}
	else
		cout << "you don't have input" << endl; 
	Matrix temp = Matrix(input.col, size);
	temp.random(); 
	weight[count] = temp;  
	result = input.dot(temp); 
	result.modi(activate);
	h_out[count] = result;
	count++;
	cout << "after: " << count << endl;
}

void Layer::MaxPool(int pool)
{
	if (input.row != 0 && input.col != 0)
		input = result;
	else
		cout << "you don't have input" << endl;

	result = Matrix(input.row / pool, input.col / pool);

	float temp[10] = { 0,0,0,0,0,0,0,0,0,0 };
	for (int i = 0; i < input.row; i += pool)
	{
		for (int j = 0; j < input.col; j += pool)
		{
			if (pool == 2)
			{
				temp[0] = input.ary[i][j];
				temp[1] = input.ary[i][j + 1];
				temp[2] = input.ary[i + 1][j];
				temp[3] = input.ary[i + 1][j + 1];
			}
			else if (pool == 3)
			{
				temp[0] = input.ary[i][j];
				temp[1] = input.ary[i][j + 1];
				temp[2] = input.ary[i][j + 2];
				temp[3] = input.ary[i + 1][j];
				temp[4] = input.ary[i + 1][j + 1];
				temp[5] = input.ary[i + 1][j + 2];
				temp[6] = input.ary[i + 2][j];
				temp[7] = input.ary[i + 2][j + 1];
				temp[8] = input.ary[i + 2][j + 2];
			}

			float max = temp[0];
			for (int k = 1; k < 10; k++)
			{
				if (temp[k] > max)
				{
					max = temp[k];
				}
			}
			//cout << max << endl; 
			//cout << j << endl;
			result.ary[i / pool][j / pool] = max;
		}
	}
}

void Layer::Conv2D(string filter, string activate, int filter_size)
{
	float** patato;
	
	if (filter.compare("edge") == 0)
	{
		patato = new float* [3];
		for (int i = 0; i < 3; i++)
		{
			patato[i] = new float[3];
			for (int j = 0; j < 3; j++)
				patato[i][j] = -0.125;
		}
		patato[1][1] = 1;
		feature = Matrix(patato, 3, 3);
	}
	else if (filter.compare("shift") == 0)
	{
		patato = new float* [3];
		for (int i = 0; i < 3; i++)
		{
			patato[i] = new float[3];
			for (int j = 0; j < 3; j++)
				patato[i][j] = 0;
		}
		patato[1][1] = 1;
		patato[2][2] = -1;
		feature = Matrix(patato, 3, 3);
	}
	else
	{
		feature = Matrix(filter_size, filter_size); 
		feature.random(); 
	}

	
	
	int* size = input.getSize();
	int og_row = size[0];
	int og_col = size[1];
	int row = og_row - 1;
	int col = og_col - 1;

	Matrix temp = Matrix(filter_size, filter_size);
	result = Matrix(og_row, og_col);
	for (int i = 0; i <= row; i++)
	{
		for (int j = 0; j <= col; j++)
		{
			if (i == 0 && j == 0)
			{
				temp.ary[1][1] = input.ary[0][0];
				temp.ary[1][2] = input.ary[0][1];
				temp.ary[2][1] = input.ary[1][0];
				temp.ary[2][2] = input.ary[1][1];
			}
			else if (i == row && j == col)
			{
				temp.ary[0][0] = input.ary[row - 1][col - 1];
				temp.ary[0][1] = input.ary[row - 1][col];
				temp.ary[1][0] = input.ary[row][col - 1];
				temp.ary[1][1] = input.ary[row][col];
			}
			else if (i == 0 && j == col)
			{
				temp.ary[1][0] = input.ary[0][col - 1];
				temp.ary[1][1] = input.ary[0][col];
				temp.ary[2][0] = input.ary[1][col - 1];
				temp.ary[2][1] = input.ary[1][col];
			}
			else if (i == row && j == 0)
			{
				temp.ary[0][1] = input.ary[row - 1][0];
				temp.ary[0][2] = input.ary[row - 1][1];
				temp.ary[1][1] = input.ary[row][0];
				temp.ary[1][2] = input.ary[row][1];
			}
			else if (i == 0)
			{
				temp.ary[1][0] = input.ary[0][j - 1];
				temp.ary[1][1] = input.ary[0][j];
				temp.ary[1][2] = input.ary[0][j + 1];
				temp.ary[2][0] = input.ary[1][j - 1];
				temp.ary[2][1] = input.ary[1][j];
				temp.ary[2][2] = input.ary[1][j + 1];
			}
			else if (j == 0)
			{
				temp.ary[0][1] = input.ary[i - 1][0];
				temp.ary[1][1] = input.ary[i][0];
				temp.ary[2][1] = input.ary[i + 1][0];
				temp.ary[0][2] = input.ary[i - 1][1];
				temp.ary[1][2] = input.ary[i][1];
				temp.ary[2][2] = input.ary[i + 1][1];
			}
			else if (i == row)
			{
				temp.ary[0][0] = input.ary[i - 1][j - 1];
				temp.ary[0][1] = input.ary[i - 1][j];
				temp.ary[0][2] = input.ary[i - 1][j + 1];
				temp.ary[1][0] = input.ary[i][j - 1];
				temp.ary[1][1] = input.ary[i][j];
				temp.ary[1][2] = input.ary[i][j + 1];
			}
			else if (j == col)
			{
				temp.ary[0][0] = input.ary[i - 1][j - 1];
				temp.ary[1][0] = input.ary[i][j - 1];
				temp.ary[2][0] = input.ary[i + 1][j - 1];
				temp.ary[0][1] = input.ary[i - 1][j];
				temp.ary[1][1] = input.ary[i][j];
				temp.ary[2][1] = input.ary[i + 1][j];
			}
			else
			{
				temp.ary[0][0] = input.ary[i - 1][j - 1];
				temp.ary[1][0] = input.ary[i][j - 1];
				temp.ary[2][0] = input.ary[i + 1][j - 1];
				temp.ary[0][1] = input.ary[i - 1][j];
				temp.ary[1][1] = input.ary[i][j];
				temp.ary[2][1] = input.ary[i + 1][j];
				temp.ary[0][2] = input.ary[i - 1][j + 1];
				temp.ary[1][2] = input.ary[i][j + 1];
				temp.ary[2][2] = input.ary[i + 1][j + 1];
			}
			result.ary[i][j] = temp.conv(feature);
			temp = Matrix(filter_size, filter_size);
		}
	}
	result.modi(activate);
}

void Layer::BackProp(Matrix train_in, Matrix train_out, float lr)
{
	/*
	error = train_out.subtract(result);
	//cout << "error: " << error.row << "x" << error.col << endl;
	error.printGrid();
	totalError = 0;
	for (int i = 0; i < error.col; i++)
	{
		totalError += error.ary[0][i];
	}

	//delta_weight = lr * error * x
	//delta_bias = lr * error
	//error * lr
	error.scale(lr);
	//transpose the previous layer

	cout << "input: " << input.row << "x" << input.col << endl;
	input.transpose();
	cout << "input: " << input.row << "x" << input.col << endl;
	//input.printGrid();
	//derivative of the sigmoid output
	// output * (1-output)
	Matrix temp = Matrix(1, h_out[0].row, h_out[0].col);
	temp = temp.subtract(h_out[0]);
	Matrix derive = h_out[0].multi(temp);
	derive = derive.multi(error);
	cout << "output: " << derive.row << "x" << derive.col << endl;
	temp.printGrid();
	cout << "derive: " << temp.row << "x" << temp.col << endl;
	derive.printGrid();
	Matrix dw = input.dot(derive);
	cout << "delta_weight: " << dw.row << "x" << dw.col << endl;
	dw.printGrid();
	cout << "weight: " << weight[0].row << "x" << weight[0].col << endl;
	weight[0].printGrid();

	//change the weight
	weight[0] = weight[0].subtract(dw);
	cout << "weight after: " << endl;
	weight[0].printGrid();
	
	cout << "count: " << count << endl;
	*/
	
	
	error = train_out.subtract(result);
	while (count >= 1) 
	{
		
		
		//cout << "error: " << error.row << "x" << error.col << endl;
		error.printGrid();
		totalError = 0;
		for (int i = 0; i < error.col; i++)
		{
			totalError += error.ary[0][i];
		}
		cout << totalError << endl; 
		//delta_weight = lr * error * x
		//delta_bias = lr * error
		//error * lr
		error.scale(lr);
		//transpose the previous layer

		cout << "input: " << input.row << "x" << input.col << endl;
		input.transpose();
		cout << "input: " << input.row << "x" << input.col << endl;
		//input.printGrid();
		//derivative of the sigmoid output
		// output * (1-output)
		Matrix temp = Matrix(1, h_out[count - 1].row, h_out[count-1].col);
		temp = temp.subtract(h_out[count - 1]);
		Matrix derive = h_out[count - 1].multi(temp);
		derive = derive.multi(error);
		cout << "output: " << derive.row << "x" << derive.col << endl;
		temp.printGrid();
		cout << "derive: " << temp.row << "x" << temp.col << endl;
		derive.printGrid();
		Matrix dw = input.dot(derive);
		cout << "delta_weight: " << dw.row << "x" << dw.col << endl;
		dw.printGrid();
		cout << "weight: " << weight[count - 1].row << "x" << weight[count - 1].col << endl;
		weight[count - 1].printGrid();

		//change the weight
		weight[count - 1] = weight[count - 1].subtract(dw);
		cout << "weight after: " << endl;
		weight[count - 1].printGrid();

		cout << "count: " << count << endl;
		count--; 
	}








}	


