#include <iostream>
using namespace std;

void InsertionSort(int nums[], int n)
{
    int comp = 1;
    int shifts = 0;
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int key = nums[i];

        while (j >= 0 && nums[j] >= key)
        {
            nums[j + 1] = nums[j];
            shifts++;
            comp++;
            j--;
        }
        nums[j + 1] = key;
    }
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }

    cout << endl
         << "the number of comparision happened are :" << comp << "and number of shifts are :" << shifts;
}

int main()
{
    int n;
    cout << "enter the size of array:";
    cin >> n;
    int nums[n];
    cout << "Enter the elements of array:";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << "Befor Sorting" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    cout << "After Sorting" << endl;
    InsertionSort(nums, n);
}
