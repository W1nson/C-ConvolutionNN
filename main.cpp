#include "Matrix.h"
#include "Layer.h" 
#include "Network.h"

using namespace std; 


int main()
{
	srand(1);
	
	
	
	float input[5][5] = { { 1, -1, -1, -1, 1}, {-1, 1, -1, 1, -1}, {-1, -1, 1, -1, -1}, {-1, 1, -1, 1, -1}, { 1, -1, -1, -1, 1} };

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

	Layer trial = Layer(); 
	
	Matrix img = Matrix(ary, 5, 5);
	img.printGrid(); 

	Matrix edge = trial.Conv2D(img, "edge");
	cout << endl;
	edge.printGrid();


	/*
	Matrix test = Matrix(2, 3); 
	int* size = test.getSize();
	cout << size[0] << "x" << size[1] << endl;
	test.random(); 
	test.print(); 
	cout << endl; 

	test.transpose(); 
	test.print(); 

	cout << endl; 
	test.setSquare(); 
	test.print(); 
	*/

	return 0;
}




/* 
Matrix h1 = layer.Con2D(input, "edge", "relu")




*/
