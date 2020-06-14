#include <iostream> 
#include <stdlib.h>

using namespace std;

class Matrix 
{
    public: 
        Matrix(int row, int col); 
        void random(); 
        void add(Matrix temp); 
        void subtract(Matrix temp); 
        void multiply(Matrix temp); 
        void modi(string function); 
        void print()
        ~Matrix(); 

    private: 
        int row, col; 
        float ary[][];
}

Matrix::Matrix(int row, int col)
{
    Matrix.row = row; 
    Matrix.col = col; 
    Matrix.ary[row][col]; 
}

Matrix::random()
{
    for(int i = 0; i < Matrix.row; i++)
    {
        for(int j = 0; j < Matrix.col; j++)
        {
            Matrix.ary[i][j] = rand()
        }
    }
    
}

Matrix::print()
{
    for(int i = 0; i < Matrix.row; i++)
    {
        for(int j = 0; j < Matrix.col; j++)
        {
            std::cout << "Array[" << i << "][" << j << "]: " << Matrix.ary[i][j] << std::endl; 
        }
    }
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
    layer(string filter, string activa, float size[]); 
    void flatten(); 
    void Dense(); 
    void Conv2D();
}


int main()
{
    Matrix test = new Matrix::Matrix(1,3); 
    test.random(); 
    test.print(); 
}