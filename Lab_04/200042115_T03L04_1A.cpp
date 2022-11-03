#include<iostream>
#include<queue>
using namespace std;

queue<int> line;

    // Push into the Stack
    void push_s(int x)
    {
        int Size = line.size();

        line.push(x);

        for(int i=0 ; i<Size ; i++)
        {
            int temp = line.front();
            line.push(temp);
            line.pop();
        }

    }

    // Removes the element on top of the stack.
    void pop_s()
    {
        line.pop();
    }

    // Get the top element.
    int top_s()
    {
        return line.front();
    }

    // Return whether the stack is empty.
    bool empty_s()
    {
        return line.empty();
    }

int main()
{
    push_s(10);
    cout << top_s() << endl;

    push_s(20);
    cout << top_s() << endl;

    pop_s();
    cout << top_s() << endl;

    push_s(100);
    cout << top_s() << endl;

    cout << empty_s() << endl;

    pop_s();

    pop_s();

    cout << empty_s() << endl;

    return 0;
}
