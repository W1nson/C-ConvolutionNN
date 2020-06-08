#include <iostream> 

using namespace std;

class Matrix 
{
    Matrix(int row, int col); 
    void add(Matrix temp); 
    void subtract(Matrix temp); 
    void multiply(Matrix temp); 
    void modi(string function); 
    void print()
    ~Matrix(); 
}

class Network 
{
    Network(); 
    void forward(); 
    void backward(); 
    void train(Matrix input, Matrix output);
}

class layer
{
    layer(string filter, string activa, double size[]); 
    void flatten(); 
    void Dense(); 
    void Conv2D();
}