#include <iostream>
#include <exception>
#include <iterator>

using namespace std;


class MyException : public std::exception
{
private:
    char* mess;
public:
    char* get_mess()
    {
        return this->mess;
    }
    MyException(char* mess)
    {
        this->mess = mess;
    }
};

class Matrix
{
private:
    int countRows;
    int countColumns;
    int** matrix;
public:
    Matrix(int rows, int columns)
    {
        if (rows >= 1 && columns >= 1)
        {
            this->countRows = rows;
            this->countColumns = columns;
        }
        else
        {
            this->countRows = 1;
            this->countColumns = 1;
        }
    }
    void FillMatrix(int** arr, int countRows, int countColumns);
    void AddValueToMatrix(int val);
    Matrix AddMatrixToMatrix(Matrix matrix2);
};
void Matrix::FillMatrix(int **arr, int countRows, int countColumns)
{
    if (this->countRows != countRows || this->countColumns != countColumns)
        throw MyException("Matrix dimension and array dimension do not match");
    this->matrix = new int*[countRows];
    for (int i = 0; i < countRows; i++)
    {
        matrix[i] = new int[countColumns];
        for (int j = 0; j < countColumns; j++)
        {
            this->matrix[i][j] = arr[i][j];
        }
    }
}
void Matrix::AddValueToMatrix(int val)
{
    for (int i = 0; i < this->countRows; i++)
    {
        for (int j = 0; j < this->countColumns; j++)
        {
            this->matrix[i][j] += val;
        }
    }
}
Matrix Matrix::AddMatrixToMatrix(Matrix matrix2)
{
    if (this->countRows != matrix2.countRows || this->countColumns != matrix2.countColumns)
        throw MyException("Dimensions of the matrices are not equals");
    else
    {
        Matrix* newMatrix = new Matrix(this->countRows, this->countColumns);
        newMatrix->matrix = new int*[newMatrix->countRows];
        for (int i = 0; i < newMatrix->countRows; i++)
        {
            newMatrix->matrix[i] = new int[newMatrix->countColumns];
            for (int j = 0; j < newMatrix->countColumns; j++)
            {
                newMatrix->matrix[i][j] = this->matrix[i][j] + matrix2.matrix[i][j];
            }
        }
        return *newMatrix;
    }
}

int main(void)
{
   
    int fMR, fMC, sMR, sMC, tMR, tMC;
    try
    {
        cout << "Enter count of rows for first matrix: ";
        cin >> fMR;
        cout << "\n Enter count of columns for first matrix: ";
        cin >> fMC;
        Matrix* matrix1 = new Matrix(fMR, fMC);
        int *arr1[2] = {new int[3]{0, 0,0}, new int[3]{0, 0,0}};
        matrix1->FillMatrix(arr1, 2, 3);
        cout << "\n Enter count of rows for second matrix: ";
        cin >> sMR;
        cout << "\n Enter count of columns for second matrix: ";
        cin >> sMC;
        Matrix* matrix2 = new Matrix(sMR, sMC);
        int *arr2[2] = {new int[3]{1,1, 1}, new int[3]{1,1, 1}};
        matrix2->FillMatrix(arr2, 2, 3);
        cout << "\n Enter count of rows for third matrix: ";
        cin >> tMR;
        cout << "\n Enter count of columns for third matrix: ";
        cin >> tMC;
        Matrix* matrix3 = new Matrix(tMR, tMC);
        int *arr3[3] = {new int[3]{0, 0, 0}, new int[3]{0, 0, 0}, new int[3]{0, 0, 0}};
        matrix3->FillMatrix(arr3, 3, 3);
        matrix1->AddMatrixToMatrix(*matrix2);
        matrix2->AddMatrixToMatrix(*matrix3);
        matrix3->AddMatrixToMatrix(*matrix1);
    }
    catch (MyException &e)
    {
        cout << e.get_mess() << endl;
    }

  
    return 0;
}
