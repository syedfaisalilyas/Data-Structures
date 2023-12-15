#include <iostream>
using namespace std;

#define size 10

int Hash(int key) {
    return key % size;
}

int probe(int H[], int key) {
    int index = Hash(key);
    int i = 0;
    while (H[(index + i) % size] != 0 && i < size) {
        i++;
    }
    return (index + i) % size;
}

void Insert(int H[], int key) {
    int index = Hash(key);
    if (H[index] != 0) {
        index = probe(H, key);
    }
    H[index] = key;
}

int search(int H[], int key) {
    int index = Hash(key);
    int i = 0;
    while (H[(index + i) % size] != key && H[(index + i) % size] != 0 && i < size) {
        i++;
    }
    if (H[(index + i) % size] == key) {
        return (index + i) % size;
    }
    return -1; // Element not found
}

int main() {
    int H[size] = {0};
    Insert(H, 12);
    Insert(H, 24);
    Insert(H, 11);
    Insert(H, 7);

    int result = search(H, 2);
    if (result != -1) {
        cout << "Key found at index: " << result << endl;
    } else {
        cout << "Key not found" << endl;
    }
    return 0;
}
