#include<iostream>
using namespace std;

class Queue
{
private:
    int Front, Rear;

    int Size;
    int *arr;

public:

    Queue(int s)
    {
        Front = Rear = -1;
        Size = s;

        arr = new int[s];
    }

    void enQueue(int val);
    int deQueue();
    void displayQueue();
    int GetSize();
    int GetFront();
    int GetRear();
    bool isEmpty();
    bool isFull();

};


void Queue::enQueue(int val)
{

    if( Front == 0 && Rear == Size-1 )
    {
        cout << "FULL" << endl;
    }

    else if( Front == -1 )    /// first element
    {
        Front = Rear = 0;
        arr[Rear] = val;
    }

    else
    {
        Rear++;
        arr[Rear] = val;
    }

}



int Queue::deQueue()
{

    if( Front == -1)
    {
        cout << "EMPTY" << endl;
        return INT_MIN;
    }

    int data = arr[Front];
    arr[Front] = -1;

    if( Front == Rear )            /// if there was only one element in the array
    {
        Front = Rear = -1;
    }

    else
    {
        Front++;
    }

    return data;

}


int Queue::GetSize()
{
    return Size;
}


int Queue::GetFront()
{
    return arr[Front];
}


int Queue::GetRear()
{
    return arr[Rear];
}


bool Queue::isEmpty()
{
    if( Front == -1 )
        return true;

    else
        return false;
}


bool Queue::isFull()
{
    if( Front == 0 && Rear == Size-1 )
        return true;

    else
        return false;
}



void Queue::displayQueue()
{
    if (Front == -1)
    {
        cout << "EMPTY" << endl;
        return;
    }

    cout << "Queue: ";

    for (int i = Front; i <= Rear; i++)
    {
        cout << arr[i] << " ";
    }

    puts("");
}




int main()
{
    Queue q(4);

    q.enQueue(1);

    q.enQueue(2);

    q.enQueue(3);

    q.enQueue(4);

    q.displayQueue();

    cout << "Is it Full: " << q.isFull() << "   "  <<  "Is it Empty: " << q.isEmpty() << endl;

    cout << "Front element: " << q.GetFront() << "   Rear element: " << q.GetRear() << endl;

    cout << "Size: " << q.GetSize() << endl;

    cout << "Popping: " << q.deQueue() << endl;

    cout << "Popping: " << q.deQueue() << endl;

    q.displayQueue();

    cout << "Popping: " << q.deQueue() << endl;

    cout << "Popping: " << q.deQueue() << endl;

    cout << "Is it Full: " << q.isFull() << "   "  <<  "Is it Empty: " << q.isEmpty() << endl;

    q.enQueue(6);

    q.enQueue(7);

    q.enQueue(8);

    q.displayQueue();

    cout << "Is it Full: " << q.isFull() << "   "  <<  "Is it Empty: " << q.isEmpty() << endl;


}




