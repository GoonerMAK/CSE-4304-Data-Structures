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

    if( n > leftchild  &&  arr[rightchild] < arr[parent] )
    {
        parent = rightchild;
    }

    if( n > rightchild  &&  arr[leftchild] < arr[parent] )
    {
        parent = leftchild;
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


void deleteRoot(int arr[], int n)
{
    int lastElement = arr[n-1];

    arr[0] = lastElement;      ///  swaping the last element with the root

    n = n-1;           ///  decreasing size

    Heapify(arr, n, 0);
}


int Heap_Minimum(int arr[])
{
    return arr[0];
}


int Heap_extract_min(int arr[], int n)
{
    int temp = arr[0];

    deleteRoot(arr, n);       ///  deleting the root (minimum value)

    return temp;
}


void Min_heap_insert(int value, int arr[], int n)
{
    n = n + 1;          /// increasing the size

    arr[n-1] = value;        ///  adding the value at the very last

    BuildHeap(arr, n);       ///  building the heap again
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

    cout << Heap_extract_min(arr, n) << endl;

    PrintArray(arr, --n);

    cout << Heap_Minimum(arr) << endl;

    Min_heap_insert(45, arr, n);

    PrintArray(arr, ++n);

}

