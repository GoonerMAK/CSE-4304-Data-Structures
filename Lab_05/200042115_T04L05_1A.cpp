#include<bits/stdc++.h>
using namespace std;
int main()
{
    int meetings, time, counter;
    cin >> meetings;

    priority_queue<int> Start;

    priority_queue<int> End;

    for(int i=0 ; i<(2*meetings) ; i++)
    {
        cin >> time;

        if( i%2 == 0 )
        {
            Start.push(time);
        }

        else
        {
            End.push(time);
        }
    }


    for(int i=0 ; i<meetings ; i++)
    {
        if( Start.top() < End.top() )
        {
            counter++;
            End.pop();
        }

        else
        {
            break;
        }
    }

    cout << counter << endl;

    return 0;
}
