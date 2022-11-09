#include <bits/stdc++.h>
using namespace std;


bool isSubset(int arr1[], int m, int arr2[], int n)
{
    map<int, int> frequency;

    for (int i = 0; i < m; i++)
    {
        frequency[arr1[i]]++;
    }

    for (int i = 0; i < n; i++)
    {
        if (frequency[arr2[i]] > 0)
        {
            frequency[arr2[i]]--;
        }

        else
        {
            return false;
        }
    }

    return true;
}



int main()
{
    int m;
    cin >> m;
    int arr1[m];

    for(int i=0 ; i<m ; i++)
    {
        cin >> arr1[i];
    }

    int n;
    cin >> n;
    int arr2[n];
    for(int i=0 ; i<n ; i++)
    {
        cin >> arr2[i];
    }


    if (isSubset(arr1, m, arr2, n))
        cout << "arr2[] is subset of arr1[] " << endl;
    else
        cout << "arr2[] is not a subset of arr1[] " << endl;

    return 0;
}
