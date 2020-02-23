#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
    node *prev;
};

class linked_list
{

public:

    node *head, *tail;

    linked_list()
    {
        head = NULL;
        tail = NULL;
    }

    void push(int n)
    {
        node *tmp = new node;
        (*tmp).data = n;
        tmp->next = NULL;
        tmp->prev = tail;

        if (head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tmp;
        }
    }

    void enqueue(int n)
    {
        node *tmp = new node;
        (*tmp).data = n;
        tmp->next = head;
        tmp->prev = NULL;

        if (head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            head->prev = tmp;
            head = tmp;
        }
    }

    int pop()
    {
        if (tail == NULL)
        {
            return -1;
        }
        node *ptr = tail;
        int val = tail->data;
        tail = tail->prev;

        delete ptr;
        return val;
    }

    int dequeue()
    {
        if (head == NULL)
        {
            return -1;
        }
        node *ptr = head;

        int val = head->data;

        head = head->next;
        delete ptr;
        return val;
    }
};

int main()
{
    int b = 0;
    linked_list a;
    a.push(1);
    a.push(2);
    a.push(3);

    cout << a.pop();
    cout << a.dequeue();
    a.push(1);
    a.push(2);
    a.enqueue(3);
    cout << a.dequeue();
    cin >> b;
    return 0;
}