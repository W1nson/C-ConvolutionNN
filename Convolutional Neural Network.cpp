
#include "Matrix.h"
#include "Layer.h" 
#include "Network.h"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <fstream>

using namespace cv;
using namespace std;


int main()
{
	char name[1];
	char data_1_red[1024];
	char data_1_green[1024];
	char data_1_blue[1024];
	ifstream data_set_1("data_batch_1.bin");
	data_set_1.read(name, 1);
	data_set_1.read(data_1_red, 1024);
	data_set_1.read(data_1_green, 1024);
	data_set_1.read(data_1_blue, 1024);
	Mat blue(32, 32, CV_8UC1, data_1_blue);
	Mat green(32, 32, CV_8UC1, data_1_green);
	Mat red(32, 32, CV_8UC1, data_1_red);
	Mat planes[] = { blue, green, red };
	Mat img1;
	merge(planes,3, img1);
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
	trial.flatten();
	trial.Dense(128, "sigmoid");
	trial.result.printGrid();
	trial.Dense(64, "sigmoid");
	trial.result.printGrid();
	trial.Dense(10, "softmax");
	trial.result.printGrid();

	cout << "size of output" << trial.result.row << "x" << trial.result.col << endl;
	cout << "blue = " << endl << " " << blue << endl << endl;
	cout << "green = " << endl << " " << green << endl << endl;
	cout << "red = " << endl << " " << red << endl << endl;
	cout << "image = " << endl << " " << img1 << endl << endl;
	cout << "name = " << name[0] << endl;
	cout << data_1_red[0] << endl;
	imshow("3 channel", img1);
	data_set_1.close();
	waitKey(0);

	return 0;
}