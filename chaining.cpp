










// #include <iostream>
// using namespace std;

// struct Node {
//     int data;
//     Node *next;
// };

// void SortedInsert(Node *&H, int x) {
//     Node *t = new Node;
//     Node *q = nullptr;
//     Node *p = H;

//     t->data = x;
//     t->next = nullptr;

//     if (H == nullptr) {
//         H = t;
//     }
//     else 
//     {
//         while (p && p->data < x) {
//             q = p;
//             p = p->next;
//         }
//         if (p == H) {
//             t->next = H;
//             H = t;
//         } else {
//             t->next = q->next;
//             q->next = t;
//         }
//     }
// }

// Node *Search(Node *p, int key) {
//     while (p != nullptr) {
//         if (key == p->data) {
//             return p;
//         }
//         p = p->next;
//     }
//     return nullptr;
// }

// int Hash(int key) {
//     return key % 10;
// }

// void Insert(Node *H[], int key) {
//     int index = Hash(key);
//     SortedInsert(H[index], key);
// }

// int main() {
//     Node *HT[10] = {nullptr};
//     Node *temp = nullptr;

//     Insert(HT, 12);
//     Insert(HT, 22);
//     Insert(HT, 42);

//     temp = Search(HT[Hash(21)], 21);

//     if (temp != nullptr) {
//         cout << temp->data << endl;
//     } else {
//         cout << "Key not found" << endl;
//     }

//     return 0;
// }
