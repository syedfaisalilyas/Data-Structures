#include <iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;

    node(int val)
    {
        data =val;
        next = NULL;
    }
};

class queue
{
  public:
  node* front;
  node* back;

  queue()
  {
    front =NULL;
    back = NULL;
  }

  void push(int x)
  {
    node* n = new node(x);
    if(front==NULL)
    {
        back =n;
        front =n;
    }
    back->next = n;
    back = n;
  }

  void pop()
  {
    if(front == NULL)
    {
        cout<<"EMPTY";
        return;
    }
    node* todelete = front;
    front=front->next;
    delete todelete;
  }

  int peek()
  {
    if(front == NULL)
    {
        cout<<"EMPTY";
        return -1;
    }
    return front->data;
  }

  void empty()
  {
    if(front == NULL)
    {
        cout<<true;
    }
    cout<<false;
  }
};


main()
{
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.pop();
    cout<<q.peek();
}