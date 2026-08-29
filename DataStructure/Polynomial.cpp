#include <iostream>
#include <math.h>
using namespace std;

struct term
{
    int coeff;
    int exp;
};

class Polynomial
{
    term t[10];
    int n;

public:
    void create();
    void display();
    void degree();
    void evaluate();
    void add(Polynomial p1, Polynomial p2);
};

void Polynomial ::create()
{
    cout << "enter how many terms you want in your polynomial:";
    cin >> n;
    cout << "enter the coeff and exp of the terms respectively:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> t[i].coeff >> t[i].exp;
    }
}

void Polynomial ::display()
{
    for (int i = 0; i < n; i++)
    {
        cout << t[i].coeff << "x^" << t[i].exp << "+";
    }
    cout << "\b \b";

    // OR
    //  for(int i = 0 ; i < n - 1 ; i++){
    //      cout<<t[i].coeff<<"x^"<<t[i].exp<<"+";
    //  }
    //  cout<<t[n-1].coeff<<"x^"<<t[n-1].exp;
}

void Polynomial ::degree()
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (t[i].exp > max)
        {
            max = t[i].exp;
        }
    }
    cout << endl;
    cout << "The degree of the polynomial " << " is " << max << endl;
    ;
}

void Polynomial ::evaluate()
{
    int x;
    cout << "enter the value of x:-";
    cin >> x;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += t[i].coeff * pow(x, t[i].exp);
    }

    cout << "the value of the polynomial when x = " << x << " is " << sum;
}

void Polynomial ::add(Polynomial p1, Polynomial p2)
{
    int i = 0, j = 0, k = 0;
    int n1, n2;
    n1 = p1.n;
    n2 = p2.n;
    while (i > n1 && j > n2)
    {
        if (p1.t[i].exp == p2.t[i].exp)
        {
            t[k].coeff = p1.t[i].coeff + p2.t[j].coeff;
            t[k].exp = p1.t[i].exp;
            i++;
            j++;
            k++;
        }

        else if (p1.t[i].exp > p2.t[i].exp)
        {
            t[k].coeff = p1.t[i].coeff;
            t[k].exp = p1.t[i].exp;
            i++;
            k++;
        }

        else if (p1.t[i].exp < p2.t[i].exp)
        {
            t[k].coeff = p2.t[i].coeff;
            t[k].exp = p2.t[i].exp;
            j++;
            k++;
        }
    }
    while (i > n1 && j < n2)
    {
        t[k].coeff = p2.t[j].coeff;
        t[k].exp = p2.t[j].exp;
        j++;
        k++;
    }
    while (j > n2 && i < n1)
    {
        t[k].coeff = p1.t[i].coeff;
        t[k].exp = p1.t[i].exp;
        i++;
        k++;
    }
}

int main()
{
    Polynomial p1;
    p1.create();
    p1.display();
    p1.degree();
    p1.evaluate();

    return 0;
}