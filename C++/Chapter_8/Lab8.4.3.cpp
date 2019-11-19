#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



class Matrix
{
public:
    int** matrix;
    int rows;
    int columns;
    Matrix(int rows, int columns)
    {
        this->rows = rows;
        this->columns = columns;
    }
    Matrix(int** matrix, int rows, int columns)
    {
        this->rows = rows;
        this->columns = columns;
        this->matrix = matrix;
    }
    void fillMatrix0(int rows, int columns)
    {
        this->matrix = new int*[this->rows];
        for (int i = 0; i < rows; i++)
        {
            this->matrix[i] = new int[this->columns];
            for (int j = 0; j < columns; j++)
            {
                this->matrix[i][j] = 0;
            }
        }
    }
    void print()
    {
        for (int i = 0; i < rows; i++)
        {
            cout << "\n";
            for (int j = 0; j < columns; j++)
            {
                cout << this->matrix[i][j] << " ";
            }
        }
        cout << "\n";
    }
};
istream& operator >> (ostream &is, Matrix &matrix)
{
    for (int i = 0; i < matrix.rows; i++)
    {
        matrix.matrix[i] = new int[matrix.columns];
        for (int j = 0; j < matrix.columns; j++)
        {
            is << matrix.matrix[i][j];
        }
    }
}
Matrix* operator * (Matrix &matrix1, Matrix &matrix2)
{
    if (matrix1.rows != matrix2.columns)
        throw "One of matrix sizes is not valid";
    Matrix* newMatrix = new Matrix(matrix1.rows, matrix2.columns);
    newMatrix->fillMatrix0(newMatrix->rows, newMatrix->columns);
    for (int i = 0; i < matrix1.rows; i++)
    {
        for (int j = 0; j < matrix2.columns; j++)
        {
            for (int k = 0; k < matrix1.columns; k++)
            {
                newMatrix->matrix[i][j] += matrix1.matrix[i][k] * matrix2.matrix[k][j];
            }
        }
    }
    return newMatrix;
}
Matrix* operator * (Matrix &matrix, int val)
{
    Matrix* newMatrix = new Matrix(matrix.rows, matrix.columns);
    newMatrix->matrix = new int*[newMatrix->rows];
    for (int i = 0; i < matrix.rows; i++)
    {
        newMatrix->matrix[i] = new int[newMatrix->columns];
        for (int j = 0; j < matrix.columns; j++)
        {
            newMatrix->matrix[i][j] = matrix.matrix[i][j] * val;
        }
    }
    return  newMatrix;
}
Matrix* operator + (Matrix &matrix, int val)
{
    Matrix* newMatrix = new Matrix(matrix.rows, matrix.columns);
    newMatrix->matrix = new int*[newMatrix->rows];
    for (int i = 0; i < matrix.rows; i++)
    {
        newMatrix->matrix[i] = new int[newMatrix->columns];
        for (int j = 0; j < matrix.columns; j++)
        {
            newMatrix->matrix[i][j] = matrix.matrix[i][j] + val;
        }
    }
    return  newMatrix;
}
Matrix* operator + (Matrix &matrix1, Matrix &matrix2)
{
    if (matrix1.rows != matrix2.rows || matrix1.columns != matrix2.columns)
        throw "One of matrix sizes is not valid";
    Matrix* newMatrix = new Matrix(matrix1.rows, matrix1.columns);
    newMatrix->matrix = new int*[newMatrix->rows];
    for (int i = 0; i < newMatrix->rows; i++)
    {
        newMatrix->matrix[i] = new int[newMatrix->rows];
        for (int j = 0; j < newMatrix->columns; j++)
        {
            newMatrix->matrix[i][j] = matrix1.matrix[i][j] + matrix2.matrix[i][j];
        }
    }
    return newMatrix;
}
Matrix* operator - (Matrix &matrix, int val)
{
    Matrix* newMatrix = new Matrix(matrix.rows, matrix.columns);
    newMatrix = matrix + (- val);
    return  newMatrix;
}
Matrix* operator - (Matrix &matrix1, Matrix &matrix2)
{
    Matrix* newMatrix = new Matrix(matrix1.rows, matrix1.columns);
    newMatrix = matrix1 + *(matrix2 * (-1));
    return newMatrix;
}

int main()
{

    int* mA[2] = {new int[2], new int[2]};
    int* mB[2] = {new int[2], new int[2]};
    mA[0] = new int[2] {1, 1}; mA[1] = new int[2] {1, 1};
    mB[0] = new int[2] {3, 3}; mB[1] = new int[2] {3, 3};
    Matrix* A = new Matrix(mA, 2, 2);
    Matrix* B = new Matrix(mB, 2, 2);
    A = *A + 1;
    A->print();
    A = *A * 2;
    A->print();
    A = *A - 1;
    A->print();
    Matrix* sumAB = *A + *B;
    sumAB->print();
    Matrix* subAB = *A - *B;
    subAB->print();
    Matrix* multAB = *A * *B;
    multAB->print();

    int* mA[2] = {new int[2], new int[2]};
    mA[0] = new int[2] {1, 1}; mA[1] = new int[2] {1, 1};
    Matrix* A = new Matrix(mA, 2, 2);
    int* mC[2] = {new int[3], new int[3]};
    mC[0] = new int[3] {3, 3, 3}; mC[1] = new int[3] {3, 3, 3};
    Matrix* C = new Matrix(mC, 2, 3);
    try
    {
        Matrix* sumAC = *A + *C;
        sumAC->print();
        Matrix* subAC = *A - *C;
        subAC->print();
        Matrix* multAC = *A * *C;
        multAC->print();
    }
    catch (const char* msg)
    {
        cout << msg << endl;
    }

    return 0;
}
