#include <iostream>
#include<vector>
using namespace std;

vector<int> arr;

int ping(int t)
{
    int Count = 0;

    arr.push_back(t);

    for(int i=0 ; i<arr.size() ; i++)
    {
        if( arr[i] >= (t-3000) && arr[i]<=t )
        {
            Count++;
        }
    }

    return Count;
}

int main()
{
    cout << ping(1) << endl;
    cout << ping(2) << endl;
    cout << ping(3) << endl;
    cout << ping(4) << endl;
    cout << ping(3001) << endl;
    cout << ping(3002) << endl;
    cout << ping(3003) << endl;
    cout << ping(6003) << endl;
    cout << ping(10003) << endl;
    return 0;
}

