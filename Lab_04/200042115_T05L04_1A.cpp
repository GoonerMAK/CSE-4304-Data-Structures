#include<iostream>
#include<queue>
using namespace std;

int main()
{
    queue<int> line;

    queue<int> line2;

    int n;

    while(1)
    {
        cin >> n;

        if(n<0)
        {
            break;
        }

        line.push(n);
    }

    int index, i=0, ans = 0, temp, main, j=0;
    cin >> index;

    while ( !line.empty() )
    {
        if(i == index)
        {
            main = line.front();
        }

        temp = line.front();
        line.pop();
        line2.push(temp);
        i++;
    }

    while(!line2.empty())
    {
        if( j <= index )
        {
            if( (line2.front()-main) <= 0)
            {
                ans = ans + line2.front();
                line2.pop();
            }

            else
            {
                ans = ans + main;
                line2.pop();
            }

        }


        else if( j > index )
        {
            if( (line2.front()-(main-1)) <= 0)
            {
                ans = ans + line2.front();
                line2.pop();
            }

            else
            {
                ans = ans + main - 1;
                line2.pop();
            }

        }


    }

    cout << ans << endl;

}

