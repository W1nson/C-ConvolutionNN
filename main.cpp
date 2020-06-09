#include <iostream>
#include <stdlib.h>
#include <typeinfo>
#include <math.h>
using namespace std;


class Matrix
{
public:
    Matrix();
    Matrix(float **temp, int row, int col);
    Matrix(int row, int col);
    void random();
    Matrix add(Matrix temp);
    Matrix subtract(Matrix temp);
    Matrix scale(float temp);
    Matrix dot(Matrix temp);
    Matrix modi(string function);
    void print();
private:
    int row, col;
    float **ary;
};

Matrix::Matrix()
{
    row = 0;
    col = 0;
    Matrix::ary = new float*[row];
    for(int i = 0; i < row; i++)
    {
        ary[i] = new float[col];
    }
}

Matrix::Matrix(float **temp, int row, int col)
{
    Matrix::row = row;
    Matrix::col = col;
    Matrix::ary = new float*[row];
    for(int i = 0; i < row; i++)
    {
        ary[i] = new float[col];
        for(int j = 0; j < col; j++)
            ary[i][j] = temp[i][j];
    }
}

Matrix::Matrix(int row, int col)
{
    Matrix::row = row;
    Matrix::col = col;
    Matrix::ary = new float*[row];
    for(int i = 0; i < row; i++)
    {
        ary[i] = new float[col];
    }
}

void Matrix::random()
{
    float temp = ((float)rand()/(RAND_MAX));
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            ary[i][j] = ((float)rand()/(RAND_MAX));
        }
    }
}

Matrix Matrix::add(Matrix temp)
{
    Matrix result;
    if(temp.row == row && temp.col == col)
    {
        result.ary = new float*[row];
        for(int i = 0; i < row; i++)
        {
            result.ary[i] = new float[col];
            for(int j = 0; j < col; j++)
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
Matrix Matrix::subtract(Matrix temp)
{
    Matrix result;
    if(temp.row == row && temp.col == col)
    {
        result.ary = new float*[row];
        for(int i = 0; i < row; i++)
        {
            result.ary[i] = new float[col];
            for(int j = 0; j < col; j++)
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

Matrix Matrix::dot(Matrix temp)
{
    Matrix result;
    float sum = 0;
    if(temp.row == col)
    {
        result.ary = new float*[row];
        for(int i = 0; i < row; i++)
        {
            result.ary[i] = new float[temp.col];
            for(int j = 0; j < col; j++)
            {
                for(int k = 0; k < col; k++)
                {
                    sum += ary[i][k] * temp.ary[k][i];
                }
                result.ary[i][j] = sum;
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

Matrix Matrix::scale(float temp)
{
    Matrix result;
    result.ary = new float*[row];
    for(int i = 0; i < row; i++)
    {
        result.ary[i] = new float[col];
        for(int j = 0; j < col; j++)
        {
            result.ary[i][j] = temp * ary[i][j];
        }
    }
    result.row = row;
    result.col = col;
    return result;
}

Matrix Matrix::modi(string function)
{
    float temp = 0;
    Matrix result;
    result.ary = new float*[row];
    for(int i = 0; i < row; i++)
    {
        result.ary[i] = new float[col];
        for(int j = 0; j < col; j++)
        {
            if(function.compare("sigmoid"))
            {
               temp = 1 / (1 + exp(ary[i][j]));
            }
            else if(function.compare("relu"))
            {
                if(ary[i][j] >= 0)
                    temp = ary[i][j];
                else
                    temp = 0;
            }
            else if(function.compare("leakyrelu"))
            {
                if(ary[i][j] >= 0)
                    temp = ary[i][j];
                else
                    temp = 0.01 * ary[i][j];
            }
            result.ary[i][j] = temp;
        }
    }
    return result;
}



void Matrix::print()
{
    for(int i = 0; i < Matrix::row; i++)
    {
        for(int j = 0; j < Matrix::col; j++)
        {
            std::cout << "Array[" << i << "][" << j << "]: " << Matrix::ary[i][j] << std::endl;
        }
    }
}




class Network
{
    Network();
    void forward();
    void backward();
    void train(Matrix input, Matrix output);
};

class layer
{
    layer(string filter, string activa, float size[]);
    void flatten();
    void Dense();
    void Conv2D();
};


int main()
{
    float **ary;
    ary = new float *[2];
    ary[
    
    float *point = *ary;
    srand(1);
//    Matrix test = Matrix(3, 3);
//    Matrix test2 = Matrix(2, 3);
//    test.random();
//    test.print();
//    cout << endl;
//    test2.random();
//    test2.print();
//    cout << endl;
//    Matrix result;
//    result = test2.dot(test);
//    result.print();
    Matrix array = Matrix(ary, 2, 2);
    array.print();
    
}
