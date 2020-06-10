#include "Matrix.h"
#include "Layer.h" 
#include "Network.h"

/* 
[  0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0
   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0
   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0
   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0
   0  74 109  22   0   0   0   0   0   0   0   0   0   0   0   0   0   0
   0   0  75 243 255  57   0   0   0   0   0   0   0   0   0   0   0   0
   0   0   0   0 152 255 202  37   0   0   0   0   0   0   0   0   0   0
   0   0   0   0   1 105 250 215  36   0   0   0   0   0   0   0   0   0
   0   0   0   0   0   0  34 223 255 107   0   0   0   0   0   0   0   0
   0   0   0   0   0   0   0   4 139 255 180  13   0   0   0   0   0   0
   0   0   0   0   0   0   0   0   0  70 249 225  53   0   0   0   0   0
   0   0   0   0   0   0   0   0   0   0  49 217 249  91   0   0   0   0
   0   0   0   0   0   0   0   0   0   0   0   2 170 255 214  29   0   0
   0   0   0   0   0   0   0   0   0   0   0   0   0  77 239 253 119   0
   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0 211 255 173
   3   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0  64 240
 255  98   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   4
 159 255 186  25   0   0   0   0   0   0   0   0   0   0   0   0   0   0
   0   8 179 255 124   0   0   0   0   0   0   0   0   0   0   0   0   0
   0   0   0   0 111 223 108   0   0   0   0   0   0   0   0   0   0   0
   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0
   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0   0
   0   0   0   0]







*/



int main()
{
	srand(1);
	
	float input[3][5] = {{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5}}; 
	
	ary = new float* [sizeof(input) / sizeof(input[0])];
	for (int i = 0; i < sizeof(input) / sizeof(input[0]); i++)
	{
		ary[i] = new float[sizeof(input[0]) / sizeof(float)];
		for (int j = 0; j < sizeof(input[0]) / sizeof(float); j++)
			ary[i][j] = input[i][j];
	}
	
	Matrix array = Matrix(ary, 3,5); 


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
