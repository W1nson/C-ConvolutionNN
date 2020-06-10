#include "Matrix.h"
#include "Layer.h" 
#include "Network.h"


int main()
{
	srand(1);
	
	/*float** ary;
	ary = new float* [2];
	for (int i = 0; i < sizeof(ary); i++)
	{
		ary[i] = new float[2];
		for (int j = 0; j < sizeof(ary[i]); j++)
			ary[i][j] = 2;
	}
	Matrix array = Matrix(ary, 2, 2);	*/


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

	return 0;
}




/* 
Matrix h1 = layer.Con2D(input, "edge", "relu")




*/