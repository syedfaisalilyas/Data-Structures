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

bool isEmpty(node* &head)
{
    return head == nullptr;
}

void InsetrtAtTail(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void DisplayData(node *&head)
{
    node *temp = head;
    while (temp->next != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << NULL;
}

void InsertAtposition(node *&head, int val, int index)
{
    node *n = new node(val);
    if (index == 0)
    {
        n->next = head;
        head = n;
        return;
    }
    else
    {
        node *temp = head;
        for (int i = 0; i < index - 1 && temp != nullptr; i++)
        {
            temp = temp->next;
        }
        if (temp->next == NULL)
        {
            cout << "Node cant be inserted here";
            return;
        }
        n->next = temp->next;
        temp->next = n;
    }
}

void InsertAtHead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
}

bool SearhinList(node *&head, int key)
{
    node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void DeleteFIRSTNODE(node *&head)
{
    if (head == NULL)
    {
        return;
    }
    node *todelete = head;
    head = head->next;
    delete todelete;
}

void DeleteAtposition(node *&head, int val, int index)
{
    node *n = new node(val);
    node *temp = head;
    
    if (index == 0) {
        node* todelete = head;
        head = head->next;
        delete todelete;
        return;
    }
    for (int i = 0; i < index - 1 && temp != nullptr; i++)
    {
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        cout << "Node cant be deleted here";
        return;
    }
    node* todelete = temp->next;
    temp->next =temp->next->next;
    delete todelete;
    
}

void DeleteLastNode(node *&head)
{
    if (head == NULL)
    {
        return;
    }
    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }
    node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
}

void DeleteLinkedList(node* &head)
{
    while (head!=NULL)
    {
        node* todel = head;
        head = head->next;
        delete todel;
    }
}

void reverselinkedlist(node* &head)
{
    node* prev = NULL;
    node* current = head;
    node* next = NULL;
    while(current!= NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
}

// void reverserecursive(node* &head)
// {
//     if(head==NULL || head->next ==NULL)
//     {
//      return;
//     }
//     node* n = reverserecursive(head->next);
//     head->next->next=head;
//     head->next=NULL;
// }

void sortedlinkedlist(node* &head)
{
    if(head == NULL)
    {
        return;
    }
    node* current = head;
    node* index = NULL;
    int temp;
    while(current !=NULL)
    {
        index = current->next;
        while (index!=NULL)
        {
            if(current->data > index->data)
            {
                temp = current->data;
                current->data =index->data;
                index->data = temp;
            }
            index=index->next;
        }
        current=current->next;
        
    }
}

void removeduplicates(node* &head)
{
    if(head == NULL)
    {
        return;
    }
    node* current = head;
    node* index = NULL;
    int temp;
    while(current !=NULL)
    {
        index = current;
        while (index->next!=NULL)
        {
            if(current->data == index->next->data)
            {
                node* todel = index->next;
                index->next =  index->next->next;
                delete todel;
            }
            else
            {
            index=index->next;
            }
        }
        current=current->next;
        
    }
}


// LinkedListNode* findMiddle(LinkedListNode* head) {
//     if (head == NULL) return NULL;

//     LinkedListNode* slow = head;
//     LinkedListNode* fast = head;

//     while (fast != NULL && fast->next != NULL) {
//         slow = slow->next;
//         fast = fast->next->next;
//     }

//     return slow;
// }

int main() {
    node* head = NULL;
    InsertAtHead(head, 12);
    InsertAtHead(head, 178);
    InsertAtHead(head, 1788);
    DisplayData(head);

    // insertAtHead(head, 345);
    // displayList(head);

    // cout << "Search for 178: " << searchInList(head, 178) << endl;

    // deleteFirstNode(head);
    // displayList(head);

    // deleteLastNode(head);
    // displayList(head);

    // deleteNodeAtPosition(head, 2);
    // displayList(head);

    // sortLinkedList(head);
    // displayList(head);

    // removeDuplicates(head);
    // displayList(head);

    // LinkedListNode* middle = findMiddle(head);
    // if (middle != NULL) {
    //     cout << "Middle Element: " << middle->data << endl;
    // } else {
    //     cout << "The list is empty." << endl;
    // }

    // deleteLinkedList(head);

    return 0;
}
