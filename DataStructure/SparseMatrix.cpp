#include <iostream>
using namespace std;

class SparseMatrix
{
private:
    int row;
    int column;
    int nze;
    int Sparse[10][3];

public:
    void create();
    void display();
    void add(SparseMatrix s1, SparseMatrix s2);
    void transpose(SparseMatrix s1);
};

void SparseMatrix ::create()
{
    cout << "Enter the number of rows :";
    cin >> row;
    cout << "Enter the number of cols :";
    cin >> column;
    cout << "enter the number of non zero elements";
    cin >> nze;

    Sparse[0][0] = row;
    Sparse[0][1] = column;
    Sparse[0][2] = nze;

    cout << "enter the row column and the non zero element";
    for (int i = 1; i <= nze; i++)
    {
        cin >> Sparse[i][0] >> Sparse[i][1] >> Sparse[i][2];
    }
}
void SparseMatrix ::display()
{
    for (int i = 0; i < nze; i++)
    {
        cout << Sparse[i][0] << " " << Sparse[i][1] << " " << Sparse[i][2] << endl;
    }
}

void SparseMatrix ::transpose(SparseMatrix s1)
{
    int total[s1]
}
int main()
{
    SparseMatrix M1;
    M1.create();
    cout << "\nSparse Matrix is:\n";
    M1.display();
}