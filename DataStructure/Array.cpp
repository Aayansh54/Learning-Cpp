#include <iostream>
using namespace std;

class ArrayADT
{
private:
    int A[10], n;

public:
    void create();
    void display();
    bool search();
    void update();
    void insert();
    void Delete();
};

void ArrayADT ::create()
{
    cout << "enter how many elements you want in your array(less than 10)";
    cin >> n;
    if (n >= 10)
        cout << "size cannot be greater or equal to 10" << endl;
    cout << "enter the elements of array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
}

void ArrayADT ::display()
{
    cout << "here are the elements of array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
}

bool ArrayADT ::search()
{
    int target;
    char choice;
    cout << "enter the element you want to search for:";
    cin >> target;
    cout << "is the array sorted?(y/n):";
    cin >> choice;
    if (choice == 'n')
    {
        for (int i = 0; i < n; i++)
        {
            if (A[i] == target)
                return true;
        }
    }
    else if (choice == 'y')
    {
        int left = 0;
        int right = n - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (A[mid] == target)
            {
                return true;
            }
            else if (A[mid] < target)
                right = mid - 1;
            else
                left = mid + 1;
        }
    }
    else
        cout << "please enter a valid choice" << endl;
    return false;
}

void ArrayADT ::update()
{
    int index;
    int val;
    cout << "enter the index you want to update:";
    cin >> index;
    if (index < 0 || index >= 10)
        cout << "please enter valid index" << endl;
    else
    {
        cout << "enter the value you want to enter :";
        cin >> val;
        A[index] = val;
    }
    display();
}

void ArrayADT ::insert()
{
    int idx;
    int value;
    cout << "enter the index postion where you want to enter the element:";
    cin >> idx;
    if (idx < 0 || idx >= 9)
        cout << "please enter valid index" << endl;
    else
    {
        cout << "enter the value you want to enter:";
        cin >> value;
        for (int i = n - 1; i >= idx; i--)
        {
            A[i + 1] = A[i];
        }
        A[idx] = value;
        n++;
    }
    display();
}

void ArrayADT ::Delete()
{
    int index;
    cout << "enter the index position you want to delete: ";
    cin >> index;
    if (index < 0 || index >= 9)
        cout << "please enter valid index" << endl;
    else
    {
        for (int i = index; i < n - 1; i++)
        {
            A[i] = A[i + 1];
        }
        n--;
        display();
    }
}

int main()
{
    ArrayADT arr;
    arr.create();
    arr.display();
    arr.update();
    if (arr.search())
    {
        cout << "target is found at index" << endl;
    }
    else
        cout << "target is not found ";
    arr.insert();
    arr.Delete();
    return 0;
}