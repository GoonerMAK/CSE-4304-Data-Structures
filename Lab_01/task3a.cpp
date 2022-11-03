#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[10000] = {0}, i=0, ans = 0;

    while( 1 )
    {
        int number;

        cin >> number;

        if( number < 0 )
        {
            break;
        }

        else
        {
            arr[i] = number;
            i++;
        }

    }

    int Size = i, low = 0;

    int target, middle = ( (low + (Size-low-1) )/2);

    cin >> target;

//    cout << middle << endl;


    for(int j=low ; j<=middle ; j++  )
    {

        if( arr[j] == target )
        {
            ans = j;
            break;
        }

        else if( j == middle  &&  ans == 0 )
        {
            low = middle;
            middle = (Size-middle)/2 + middle;
        }

    }


    if( ans == 0 )
    {
        cout << -1 << endl;
    }


    else
    {
        cout << ans << endl;
    }


    return 0;
}

