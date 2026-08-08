#include<iostream>
using namespace std;

class arrayClass{
public:
    int arr[10];
    int n;
public:
    void read();
    void display();
    void largest();
    void minimum();
    void secondlargest();
    void sum();
    void average();
    void evenOdd();
    void search();
    void frequency();
    void insert();
    void Delete();
    void copy(arrayClass a1);
};

void arrayClass :: read(){
    cout<<"Enter how many elements you want in your array:-";
    cin>>n;
    cout<<"Enter the elements of array:";
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
    }
}

void arrayClass :: display(){
    cout<<"here are the elements of the array:";
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
}

void arrayClass :: largest(){
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i] > max)
        max = arr[i];
    }
    cout<<"\nThe largest element of the array is "<< max;
}

void arrayClass :: minimum(){
    int min = 0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i] < min)
        min = arr[i];
    }
    cout<<"\nThe minimum element of the array is "<< min;
}

void arrayClass :: secondlargest(){
    int max = 0,secondMax = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= max)
        {
            secondMax = max;
            max = arr[i];
        }
        else if(arr[i] > secondMax)
        {
            secondMax = arr[i];
        }
    }
    cout<<"\nThe second largest element of the array is "<< secondMax;
}

void arrayClass :: sum()
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum+=arr[i];
    }
    cout<<"\n The sum of all elements in the array is " << sum;
}

void arrayClass :: average(){
    
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum+=arr[i];
    }
    cout<<"\n The average of all elements in the array is " << sum/n;
}

void arrayClass :: evenOdd(){
    int evenCount = 0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i] % 2 == 0)
        evenCount++;
    }
    cout<<"\neven count:"<<evenCount<<"\nodd count:"<<n - evenCount;
}

void arrayClass :: search(){
    int target;
    int i;
    cout<<"\nEnter the element you want to search for:-";
    cin>>target;
    for ( i = 0; i < n; i++)
    {
        if(arr[i] == target)
        {
            break;
        }
    }
    if(i < n)
    cout<<"The elements has been found at index "<<i;
    else
    cout<<"not found";
}

void arrayClass :: frequency(){
    int target,counter = 0;
    cout<<"\nEnter the element you want to search for:-";
    cin>>target;
    for (int i = 0; i < n; i++)
    {
        if(arr[i] == target)
        {
            counter++;
        }
    }
    cout<<"the element has appeared in the array " << counter <<" times";
}

void arrayClass :: copy(arrayClass a1){
    n = a1.n;
    for(int i = 0 ; i< n ; i++)
    {
        arr[i] = a1.arr[i];
    }
}
void arrayClass :: Delete(){
    int index;
    cout<<"enter the index you want to delete";
    cin>>index;
    for(int i = index ; i < n ; i++){
        arr[i] = arr[i+1];
    }
    n--;
}
void arrayClass :: insert(){
    int index,ele;
    cout<<"\nEnter the element and the index :-";
    cin>>ele>>index;
    for(int i = n-1 ; i >= index ; i--){
        arr[i+1] = arr[i];
    }
    arr[index] = ele;
    n++;
}
int main(){
    arrayClass A1;
    arrayClass copyA1;
    A1.read();
    A1.display();
    // A1.largest();
    // A1.secondlargest();
    // A1.sum();
    // A1.average();
    // A1.evenOdd();
    // A1.search();
    // A1.frequency();
    // cout<<"\n";
    // copyA1.copy(A1);
    // cout<<"\n";
    // copyA1.display();
    A1.insert();
    A1.display();
    A1.Delete();
    A1.display();
    return 0;
}