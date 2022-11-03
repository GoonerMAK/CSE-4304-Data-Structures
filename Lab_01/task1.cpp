#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[100000] = {0}, brr[100000] = {0} , i=0, big=0, big2=0;

    while(1)
    {
        int number;

        cin >> number;

        if( number <= 0 )
        {
            break;
        }

        else
        {
            if( number > big )
            {
                big = number;
            }

            arr[i] = number;
            i++;
        }
    }


    for(int j=0 ; j<i ; j++)
    {
        brr[ arr[j]-1 ]++;
    }


    for(int j=0 ; j<big ; j++)
    {
        if( brr[j] > big2 )
        {
            big2 = brr[j];
        }
    }

//    cout << big2 << endl;


    int highest = big2;

    for(int j=0 ; j<big ; j++)
    {

        for(int k=0 ; k<big ; k++)
        {
            if( brr[k] == highest  &&  highest!=0 )
            {
                cout << k+1 << " occurs: " << highest << " times" << endl;
            }
        }

        highest--;

    }


    return 0;



}
