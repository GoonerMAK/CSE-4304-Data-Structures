#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    priority_queue<int> stones;

    vector<int> arr;

    while(1)
    {
        cin >> n;
        if(n<0){break;}
        arr.push_back(n);
        stones.push(n);
    }

        int largest, second_largest, temp;

    while (stones.size() > 2)
    {
        largest = stones.top();
        stones.pop();

        second_largest = stones.top();
        stones.pop();

        if( largest > second_largest )
        {
            stones.push(largest - second_largest);
        }

    }


    if( stones.size() == 2 )
    {
        largest = stones.top();
        stones.pop();

        second_largest = stones.top();
        stones.pop();

        if(largest == second_largest)
        {
            stones.push(0);
        }

        else
        {
            stones.push(largest-second_largest);
        }
    }

    cout << "top: " << stones.top() << endl;

    return 0;
}
