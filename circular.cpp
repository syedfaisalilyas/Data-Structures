#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertathead(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        n->next = n;
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
    head = n;
}

void insertAtTail(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        insertathead(head, val);
        return;
    }
    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
}

void displaylist(node *&head)
{
    if (head == NULL)
    {
        return;
    }
    node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

void deleteathead(node* &head)
{
      node* temp=head;
      while(temp->next!=head)
      {
       temp= temp->next;
      }
      node* todelete = head;
      temp->next = head->next;
      head = head->next;
      delete todelete;

}

void deletion(node* &head,int pos)
{
    node* temp=head;
    int count =1 ;
    if(pos ==1)
    {
        deleteathead(head);
        return;
    }
    while(count!=pos-1)
    {
       temp= temp->next;
    }
    node* todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
    
}

int main()
{
    node *head = NULL;
    insertathead(head, 1);
    insertathead(head, 2);
    insertathead(head, 3);
    insertathead(head, 4);
    insertAtTail(head, 5);
    displaylist(head);
    deletion(head,2);
    displaylist(head);
    deleteathead(head);
    displaylist(head);
    return 0;
}
