#include <iostream>
#include <string>
#include <fstream>
#include <cerrno>
#include <vector>


using namespace std;

class Matrix
{
private:
    int** matrix;
public:
    int** get_matrix()
    {
        return this->matrix;
    }
    Matrix() {}
    Matrix(int** arr)
    {
        this->matrix = arr;
    }
    void save_to_file(string path)
    {
        ofstream write(path);
        if (errno == EACCES)
        {
            string* err = new string("No rights to write to file: ");
            err->append(path);
            const char *errc = err->c_str();
            throw errc;
        }
        else
        {
            if (write.is_open())
            {
                for (int i = 0; i < 2; i++)
                {
                    for (int j = 0; j < 2; j++)
                    {
                        if (i == 0 && j == 1)
                            write << this->matrix[i][j] << endl;
                        else
                            write << this->matrix[i][j] << " ";
                    }
                }
            }
        }
        write.close();
    }
    static vector<string> split(string line, char c)
    {
        vector<string> result;
        string tmpstr="";
        for (int i=0;i<line.length();i++)
        {
            if (line[i]!=c)
                tmpstr+=line[i];
            else
            {
                result.push_back(tmpstr);
                tmpstr="";
            }
        }
        if (line[line.length()-1]!=' ')
            result.push_back(tmpstr);
        return result;
    }
    static Matrix load_from_file(string path)
    {
        Matrix* matrix = new Matrix();
        matrix->matrix = new int*[2];
        ifstream read(path);
        if (errno == EACCES)
        {
            string* err = new string("No rights to write to file: ");
            err->append(path);
            const char *errc = err->c_str();
            throw errc;
        }
        else if (read.fail())
        {
            string* err = new string( "File not found at: ");
            err->append(path);
            const char *errc = err->c_str();
            throw errc;
        }
        else
        {
            string line;
            int i = 0;
            if (read.is_open())
            {
                while (getline(read, line))
                {
                    vector<string> out = split(line, ' ');
                    if (i == 0)
                    {
                        matrix->matrix[0] = new int[2];
                        for (int i = 0; i < 2; i++)
                        {
                            matrix->matrix[0][i] = atoi(out[i].c_str());
                        }
                        i++;
                    }
                    else
                    {
                        matrix->matrix[1] = new int[2];
                        for (int i = 0; i < 2; i++)
                        {
                            matrix->matrix[1][i] = atoi(out[i].c_str());
                        }
                    }
                }
            }
            read.close();
            return *matrix;
        }
    }
};

int main()
{
    int* arr[2] = {new int[2] {0, 0}, new int[2] {0, 0}};
    Matrix saveToFile(arr);
    int** arr2;
    Matrix* loadFromFile = new Matrix();
    try
    {
        saveToFile.save_to_file("D:\\matrix.txt");
        *loadFromFile = Matrix::load_from_file("D:\\matrix.txt");
        arr2 = loadFromFile->get_matrix();
    }
    catch (const char* msg)
    {
        cout << msg << endl;
    }

    return 0;
}
