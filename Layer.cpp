#include "Layer.h"

/*
layer::layer(string filter, string activa, float size[])
{
	if(filter)
}
void flatten();
void Dense();


Matrix layer::Conv2D(Matrix input, string filter, string activa )
{

	if (filter.compare("edge") == 0)
	{
		float** ary;
		ary = new float* [3];
		for (int i = 0; i < sizeof(ary); i++)
		{
			ary[i] = new float[3];
			for (int j = 0; j < sizeof(ary[i]); j++)
				ary[i][j] = -0.125;
		}
		ary[1][1] = 1; 

		weight = Matrix(ary, 3, 3);












	}
	else if (filter.compare("shift") == 0)
	{
		float** ary;
		ary = new float* [3];
		for (int i = 0; i < sizeof(ary); i++)
		{
			ary[i] = new float[3];
			for (int j = 0; j < sizeof(ary[i]); j++)
				ary[i][j] = 0;
		}
		ary[1][1] = 1;
		ary[2][2] = -1; 
		
		weight = Matrix(ary, 3, 3); 
	}
}
*/