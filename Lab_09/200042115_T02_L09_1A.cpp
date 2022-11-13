#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, flag = 0;
    cin >> n;
    int arr[n];

    for(int i=0 ; i<n ; i++)
    {
        cin >> arr[i];
    }

    int target;
    cin >> target;

    unordered_set<int> numbers;

    for (int i=0 ; i < n ; i++)
    {
        int temp = target - arr[i];

        if (numbers.find(temp) != numbers.end())
        {
            cout << "(" << arr[i] << "," << temp << ")" << endl;
            flag = 1;
        }

        else
        {
            numbers.insert(arr[i]);
        }

    }

    if( flag == 0)
    {
        cout << "No pairs found" << endl;
    }

    return 0;
}
