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
    void fasttranspose(SparseMatrix s1);
};

void SparseMatrix ::fasttranspose(SparseMatrix s1)
{
    row = s1.Sparse[0][1];
    column = s1.Sparse[0][0];
    nze = s1.Sparse[0][2];

    Sparse[0][0] = row;
    Sparse[0][1] = column;
    Sparse[0][2] = nze;
    int total[10] = {0};
    int index[10];

    for (int i = 1; i <= nze; i++)
    {
        total[s1.Sparse[i][1]]++;
    }

    index[0] = 1;
    for (int i = 1; i < row; i++)
    {
        index[i] = index[i - 1] + total[i - 1];
    }

    for (int i = 1; i <= nze; i++)
    {
        int column_el = s1.Sparse[i][1];
        int location = index[column_el];
        Sparse[location][0] = s1.Sparse[i][1];
        Sparse[location][1] = s1.Sparse[i][0];
        Sparse[location][2] = s1.Sparse[i][2];

        index[column_el]++;
    }
}
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
    for (int i = 0; i <= nze; i++)
    {
        cout << Sparse[i][0] << " " << Sparse[i][1] << " " << Sparse[i][2] << endl;
    }
}

void SparseMatrix ::add(SparseMatrix s1, SparseMatrix s2)
{
    row = s1.row;
    column = s1.column;
    Sparse[0][0] = row;
    Sparse[0][1] = column;
    int i = 1, j = 1, k = 1;
    if (s1.row == s2.row && s2.column == s2.column)
    {
        while (i <= s1.nze && j <= s2.nze)
        {
            if (s1.Sparse[i][0] == s2.Sparse[j][0] && s1.Sparse[i][1] == s2.Sparse[j][1])
            {
                Sparse[k][0] = s1.Sparse[i][0];
                Sparse[k][1] = s1.Sparse[i][1];
                Sparse[k][2] = s1.Sparse[i][2] + s2.Sparse[j][2];
                i++;
                j++;
                k++;
            }
            else if (s1.Sparse[i][0] < s2.Sparse[j][0] || (s1.Sparse[i][0] == s2.Sparse[j][0] && s1.Sparse[i][1] < s2.Sparse[j][1]))
            {
                Sparse[k][0] = s1.Sparse[i][0];
                Sparse[k][1] = s1.Sparse[i][1];
                Sparse[k][2] = s1.Sparse[i][2];
                i++;
                k++;
            }
            else
            {
                Sparse[k][0] = s2.Sparse[j][0];
                Sparse[k][1] = s2.Sparse[j][1];
                Sparse[k][2] = s2.Sparse[j][2];
                j++;
                k++;
            }
        }
        while (i <= s1.nze)
        {
            Sparse[k][0] = s1.Sparse[i][0];
            Sparse[k][1] = s1.Sparse[i][1];
            Sparse[k][2] = s1.Sparse[i][2];
            i++;
            k++;
        }
        while (j <= s2.nze)
        {
            Sparse[k][0] = s1.Sparse[j][0];
            Sparse[k][1] = s1.Sparse[j][1];
            Sparse[k][2] = s1.Sparse[j][2];
            j++;
            k++;
        }
        nze = k - 1;
        Sparse[0][2] = nze;
    }
    else
    {
        cout << "The addition is not possible";
    }
}

int main()
{
    SparseMatrix M1;
    M1.create();
    cout << "\nSparse Matrix is:\n";
    M1.display();
}