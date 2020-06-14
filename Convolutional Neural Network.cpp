#include "Matrix.h"
#include "Layer.h" 
#include "Network.h"

using namespace std; 


int main()
{
	srand(1);

	float input[10][10] = {
	{ 1, -1, -1, -1, 1, 1, -1, -1, -1, -1},
	{-1, 1, -1, 1, -1,-1, 1, -1, 1, -1},
	{-1, -1, 1, -1, -1,-1, -1, 1, -1,-1},
	{-1, 1, -1, 1, -1,-1, 1, -1, 1,-1},
	{ 1, -1, -1, -1, 1, 1, -1, -1, -1,-1},
	{ 1, -1, -1, -1, 1, 1, -1, -1, -1,-1},
	{-1, 1, -1, 1, -1, -1, 1, -1, 1,-1},
	{-1, -1, 1, -1, -1, -1, -1, 1, -1,-1},
	{-1, 1, -1, 1, -1, -1, 1, -1, 1,-1},
	{-1, 1, -1, 1, -1, -1, 1, -1, 1,-1} };

	//inputing the regular 2d array to the pointer format 
	//and import into the Matrix class to turn it into matrx.
	float** ary;
	ary = new float* [sizeof(input) / sizeof(input[0])];
	for (int i = 0; i < sizeof(input) / sizeof(input[0]); i++)
	{
		ary[i] = new float[sizeof(input[0]) / sizeof(float)];
		for (int j = 0; j < sizeof(input[0]) / sizeof(float); j++)
			ary[i][j] = input[i][j];
	}


	
	Matrix img = Matrix(ary, 10, 10);
	Layer trial = Layer(img, 3);
	trial.input.printGrid();
	trial.Conv2D("edge", "relu");
	trial.MaxPool(2);
	trial.Conv2D("edge", "relu");
	trial.MaxPool(2);
	trial.flatten();
	trial.Dense(512, "sigmoid");
	trial.Dense(256, "sigmoid");
	trial.Dense(128, "sigmoid");
	trial.Dense(64, "sigmoid");
	trial.Dense(10, "softmax");
	trial.result.printGrid();

	cout << "size of output" << trial.result.row << "x" << trial.result.col << endl;


	return 0;
}
