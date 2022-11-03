#include<iostream>
using namespace std;

void Swap(int *a, int *b)
{
        int temp = *b;
        *b = *a;
        *a = temp;
}



void Heapify(int arr[], int n, int i)
{
    int parent = i;                    ///  we start from the last non-leaf node
    int leftchild = 2 * i + 1;
    int rightchild = 2 * i + 2;

    ///   these are all index(s)

    ///   for leaf nodes... the value of leftchild and rightchild becomes greater than size... which is n

    if( n > leftchild  &&  arr[leftchild] > arr[parent] )
    {
        parent = leftchild;
    }

    if( n > rightchild  &&  arr[rightchild] > arr[parent] )
    {
        parent = rightchild;
    }

    if( parent != i )              ///  properly placing the parent node (because of the first two if statements)
    {
        Swap(&arr[i], &arr[parent]);

        Heapify(arr, n, parent);    /// Recursively heapifying the affected sub-tree
    }

}




void BuildHeap(int arr[], int n)
{
    int LastNonLeafNode = (n/2) - 1;

    for(int i = LastNonLeafNode ; i>=0 ; i--)
    {
        Heapify(arr, n , i);
    }

}


void HeapSort(int arr[], int n)
{
    for (int i = n - 1 ; i >= 0 ; i--)
    {
        Swap(&arr[0], &arr[i]);

        Heapify(arr, i, 0);
    }

}


void PrintArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }

    cout << "\n";
}


void PrintSortedArray(int arr[], int n)
{
    for (int i = n-1 ; i >= 0 ; i--)
    {
        cout << arr[i] << " ";
    }

    cout << "\n";
}


int main()
{
    int n;
    cin >> n;
    int arr[n];

    for(int i=0 ; i<n ; i++)
    {
        cin >> arr[i];
    }

    BuildHeap(arr, n);
    PrintArray(arr, n);

    HeapSort(arr, n);
    PrintArray(arr, n);
    PrintSortedArray(arr, n);

}
