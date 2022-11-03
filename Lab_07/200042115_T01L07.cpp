#include<bits/stdc++.h>
using namespace std;

priority_queue<double, vector<double>, greater<double> > first_half;
priority_queue<double> second_half;


void AdjustQueue(int size_first, int size_second)
{
    if( size_first - size_second > 1 )
    {
        second_half.push(first_half.top());
        first_half.pop();
    }

    else if( size_second - size_first > 1 )
    {
        first_half.push(second_half.top());
        second_half.pop();
    }
}



void AddNum(double x)
{
    if( first_half.empty() )
    {
        first_half.push(x);
    }

    else
    {
        if( x >= first_half.top() )
        {
            first_half.push(x);
        }

        else if( x < first_half.top() )
        {
            second_half.push(x);
        }
    }

    AdjustQueue( first_half.size(), second_half.size() );

}


void FindMedian()
{
    if( first_half.size() > second_half.size() )
    {
        cout << first_half.top() << endl;
    }

    else if( second_half.size() > first_half.size() )
    {
        cout << second_half.top() << endl;
    }

    else
    {
        cout << ((first_half.top() + second_half.top())/2)  << endl;
    }
}



int main()
{
    AddNum(8);
    AddNum(7);
    AddNum(9);
    FindMedian();
    AddNum(1);
    AddNum(6);
    AddNum(12);
    AddNum(11);
    AddNum(41);
    AddNum(16);
    FindMedian();

    return 0;
}

