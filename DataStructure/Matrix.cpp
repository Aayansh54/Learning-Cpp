#include<iostream>
using namespace std;

class Matrix
{
    int A[5][5], r , c;

    public:
        void create();
        void display();
        void transpose();
        void add(Matrix m1 , Matrix m2);
        void sub(Matrix m1 , Matrix m2);
        void mul(Matrix m1 , Matrix m2);
};

void Matrix :: create()
{
    cout<<"Enter how many rows and columns you want respectively:-";
    cin>>r>>c;
    cout<<"enter the elements of the matrix:"<<endl;
    for(int i = 0  ; i < r ; i++){
        for( int j = 0 ; j < c ; j++){
            cin>>A[i][j];
        }
    }
}

void Matrix :: display()
{   cout<<"these are the elements of matrix"<<endl;
    for(int i = 0  ; i < r ; i++){
        for( int j = 0 ; j < c ; j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
}

void Matrix::transpose(){
    cout<<"here is the transpose of the matrix"<<endl;
    for(int i = 0 ; i < c ;  i++){
        for( int j = 0 ; j < r ; j++){
            cout<<A[j][i]<<" ";
        }
        cout<<endl;
    }
}

void Matrix :: add(Matrix m1 , Matrix m2){
    if((m1.r == m2.r) && (m1.c == m2.c))
    {
        r = m1.r;
        c = m1.c;
        for(int i = 0 ; i < r ; i++){
            for(int j = 0 ; j < c ; j++){
                 A[i][j] = m1.A[i][j] + m2.A[i][j];
            }
        }
    }
    else{
        cout<<"Addition is not possible";
    }
}

void Matrix :: mul(Matrix m1, Matrix m2){
    int sum = 0;
    if( m1.c == m2.r){
        r = m1.r;
        c = m2.c;

        for(int i = 0 ; i < r ; i++){
            int sum = 0;
            for(int j = 0 ; j < c ; j++)
            {
                sum += m1.A[i][j] * m2.A[j][i];
            }
            for(int i = 0 ; i < r ; i++){
                for(int j = 0 ; j < c ; j++){
                    A[i][j] = sum;
                }
            }
        }
    }
}

main(){
    Matrix m1,m2,m3;
    cout<<"CREATION OF THE FIRST MATRIX:"<<endl;
    m1.create();
    m1.display();
    // m1.transpose();
    cout<<"CREATION OF THE SECOND MATRIX:"<<endl;
    m2.create();
    m2.display();
    // cout<<"ADDING THE TWO MATRICES :"<<endl;
    // m3.add(m1,m2);
    // m3.display();
    m3.mul(m1,m2);
    m3.display();
}