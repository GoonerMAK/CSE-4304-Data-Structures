#include<bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int>> cookies;

    int n, k, counter = 0, value;     ///  k = minimum sweetness, n = cookies
    cin >> n >> k;

    for(int i=0 ; i<n ; i++)
    {
        cin >> value;
        cookies.push(value);
    }

    int smallest, second_smallest, temp;

    while( cookies.size() > 1 )
    {
        if( cookies.top() < k )       ///  smallest sweetness isn't enough
        {
            smallest = cookies.top();
            cookies.pop();

            second_smallest = cookies.top();
            cookies.pop();

            temp = (smallest*1) + (second_smallest*2);      ///  the operation

            cookies.push(temp);

            counter++;
        }

        else
        {
            break;
        }

    }


    cout << counter << endl;
}
