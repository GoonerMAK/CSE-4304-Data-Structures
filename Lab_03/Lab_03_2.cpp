#include<bits/stdc++.h>
using namespace std;


struct node
{
    int val;
    node * next;
};


class Singly_linked_list{
public:
    node *head, *tail;
    int Size;

    Singly_linked_list()
    {
        head = nullptr;
        tail = nullptr;
        Size = 0;
    }


    void PushBack(int n)
    {
        Size++;

        struct node* NewNode = (struct node*) malloc(sizeof(struct node));

        NewNode -> val = n;
        NewNode -> next = nullptr;


        if (head == nullptr)
        {
            head = NewNode;
            return;
        }

        node* temp = head;

        while (temp->next != nullptr)      // traverse list
        {
            // Update temp
            temp = temp->next;
        }

        temp->next = NewNode;

    }


    void display()
    {
        node *cur = head;

        while(cur != nullptr)
        {
            cout << cur->val << endl;
            cur = cur->next;
        }
        cout<<endl;
    }



    void HalfedList()
    {

        int arr[Size/2], len = 0, i=0;

        node *temp1 = head;


        while (temp1 != NULL)
        {
            arr[i] = temp1 -> val;
            temp1 = temp1->next;
            i++;


        }


        for(int j=Size/2 ; j<Size ; j++)
        {
            cout << arr[j] << " ";
        }

    }



};



int main()
{
    Singly_linked_list a;
    for(int i = 1 ; i <= 10; i++)
    {
        a.PushBack(i);
    }

    a.display();

    a.HalfedList();


}
