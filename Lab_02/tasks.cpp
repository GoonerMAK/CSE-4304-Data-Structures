#include<bits/stdc++.h>
using namespace std;

class Dynamic_Array
{
public:
    int Size;
    int Capacity;
    int *arr;


    Dynamic_Array()
    {
        Size = 0;
        Capacity = 1;
        arr = new int[Capacity];
    }


    int Get(int i)
    {

        if ( (i < 0 ) or (i >= Size) )
        {
            cout << "Index out of Range" << endl;
            return -1;
        }
        return arr[i];

    }


    void Set(int i,int val)
    {
        if ((i < 0 ) or (i >= Size))
        {
            cout << " Index out of Range" << endl;
            return;
        }
        arr[i] = val;

    }


    void PushBack(int val)
    {

        if( Size == Capacity )
        {
            Capacity = Capacity * 2;
            int *temp = new int[Capacity];


            for(int i=0 ; i<Size ; i++)
            {
                temp[i] = arr[i];
            }

            arr = temp;

            delete[] temp;
        }


        arr[Size] = val;
        Size++;

    }


    int Get_Size()
    {
        return Size;
    }


    int Get_Capacity()
    {
        return Capacity;
    }


    void Remove()
    {
        if( Size == 0 )
        {
            cout << "Can't Remove" << endl;
        }

        Size--;

    }



    void increment()
    {
        int i = Size-1;
        arr[i]++;

            while( arr[i] == 10 )
            {
                arr[i] = 0;
                i--;

                if( i == 0 )
                {
                    arr[i]++;
                    break;
                }

                arr[i]++;
            }

    }


};


int main()
{
    Dynamic_Array arr;

    while( 1 )
    {
        int digit;
        cin >> digit;

        if( digit < 0 )
        {
            break;
        }

        else
        {
            arr.PushBack(digit);
        }

    }



    arr.increment();

    // arr.Remove();



    for(int i=0 ; i<arr.Get_Size() ; i++)
    {
         cout << arr.Get(i);
//         arr.PushBack(100 + i);
//         cout <<"Val: "<< arr.Get(i) <<" Size: "<< arr.Get_Size()<<" Capacity: "<<arr.Get_Capacity()<< endl;

    }

    return 0;
}


