#include<bits/stdc++.h>
using namespace std;


int CalculateFactorial( int x )
{
    int factorial;

    if( x == 1 )
    {
        return 1;
    }

    else
    {
        factorial = x*CalculateFactorial(x-1);

        return factorial;
    }
}



int main()
{
    int number;

    cin >> number;

    cout << CalculateFactorial(number) << endl;

    return 0;
}

