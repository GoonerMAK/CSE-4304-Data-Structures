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


    void Reverse()
    {
        // Initialize current, previous and next pointers
        node* current = head;
        node *next = NULL;

        while (current != NULL) {
            // Store next
            next = current->next;
            // Reverse current node's pointer
            current->next = tail;
            // Move pointers one position ahead.
            tail = current;
            current = next;
        }
        head = tail;

    }


    void HalfedList()                      /// later implement with slow and fast pointer
    {
        node *temp1 = head;

        int i=0;

        while (temp1 != NULL)
        {
            if( i >= Size/2 )
            {
                cout << temp1 -> val << endl;
                temp1 = temp1->next;
            }

            else
            {
                i++;
                temp1 = temp1->next;
            }


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

    a.HalfedList();


}

