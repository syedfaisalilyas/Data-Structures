#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node* prev;
    node* next;

    node(int val)
    {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

void InsertAtHead(node* &head, int val)
{
    node* n = new node(val);
    if (head == NULL)
    {
        head = n;
    }
    else
    {
        n->next = head;
        head->prev = n;
        head = n;
    }
}

void InsertAtEnd(node* &head, int value)
{
    if (head == NULL)
    {
        InsertAtHead(head, value);
        return;
    }
    node* n = new node(value);
    node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}

void displaydata(node* &head)
{
    node* temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void deleteathead(node* &head)
{
    node* temp = head;
    head = head->next;
    temp->next->prev =NULL;
    delete temp;
}

void deleteatpos(node* &head,int pos)
{
    node* temp = head;
    int count=1;
    if(pos == 1)
    {
        deleteathead(head);
        return;
    }
    while(temp->next!= NULL && count!=pos)
    {
       temp = temp->next ;
       count++;
    }

    temp->prev->next= temp->next;
    temp->next->prev = temp->prev;
    delete temp;
    
}

int main()
{
    node* head = NULL;
    InsertAtHead(head, 1);
    InsertAtHead(head, 2);
    InsertAtHead(head, 3);
    InsertAtEnd(head, 4);
    deleteatpos(head,2);
    deleteathead(head);
    displaydata(head);
    return 0;
}

















// #include <iostream>
// using namespace std;

// class Node {
// public:
//     int data;
//     Node* next;
//     Node* prev;

//     Node(int val) : data(val), next(nullptr), prev(nullptr) {}
// };

// class DoublyLinkedList {
// private:
//     Node* head;
//     Node* tail;

// public:
//     DoublyLinkedList() : head(nullptr), tail(nullptr) {}

//     bool isEmpty() {
//         return head == nullptr;
//     }

//     void insertAtEnd(int data) {
//         Node* newNode = new Node(data);
//         if (isEmpty()) {
//             head = newNode;
//             tail = newNode;
//         } else {
//             tail->next = newNode;
//             newNode->prev = tail;
//             tail = newNode;
//         }
//     }

//     void deleteAtEnd() {
//         if (isEmpty()) {
//             cout << "Doubly Linked List is empty" << endl;
//             return;
//         }

//         if (head == tail) {
//             delete head;
//             head = tail = nullptr;
//         } else {
//             Node* temp = tail->prev;
//             temp->next = nullptr;
//             delete tail;
//             tail = temp;
//         }
//     }

//     void display() {
//         if (isEmpty()) {
//             cout << "Doubly Linked List is empty" << endl;
//         } else {
//             Node* temp = head;
//             while (temp != nullptr) {
//                 cout << temp->data << " <-> ";
//                 temp = temp->next;
//             }
//             cout << "NULL" << endl;
//         }
//     }

//     ~DoublyLinkedList() {
//         while (!isEmpty()) {
//             deleteAtEnd();
//         }
//     }
// };

// int main() {
//     DoublyLinkedList dll;
//     dll.insertAtEnd(1);
//     dll.insertAtEnd(2);
//     dll.insertAtEnd(3);
//     dll.display();

//     dll.deleteAtEnd();
//     dll.display();

//     return 0;
// }
