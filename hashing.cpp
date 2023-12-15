#include <iostream>
#include <list>
#include <vector>
#include <string>

using namespace std;

class KeyNode {
public:
    string key;
    int value;

    KeyNode(const string& k, int v) : key(k), value(v) {}
};

class MyHashTable {
private:
    vector<list<KeyNode>> hashTable;
    size_t tableSize;
    size_t keysOccupied;

public:
    MyHashTable(size_t hSize) : tableSize(hSize), keysOccupied(0) {
        hashTable.resize(tableSize);
    }

    size_t GetHashTableSize() const {
        return tableSize;
    }

    size_t GetNumberOfKeys() const {
        return keysOccupied;
    }

    size_t HashFunction(const string& key) const {
        size_t hash = 0;
        for (char ch : key) {
            hash = (hash * 31) + ch;
        }
        return hash % tableSize;
    }

    void UpdateKey(const string& key, int value) {
        size_t index = HashFunction(key);
        for (auto& node : hashTable[index]) {
            if (node.key == key) {
                node.value = value;
                return;
            }
        }
        hashTable[index].emplace_back(key, value);
        keysOccupied++;

        if (keysOccupied > tableSize * 0.75) {
            Rehash();
        }
    }

    bool SearchKey(const string& key, int& result) const {
        size_t index = HashFunction(key);
        for (const auto& node : hashTable[index]) {
            if (node.key == key) {
                result = node.value;
                return true;
            }
        }
        return false;
    }

    void Rehash() {
        size_t newSize = tableSize * 2;
        vector<list<KeyNode>> newHashTable(newSize);

        for (const auto& bucket : hashTable) {
            for (const auto& node : bucket) {
                size_t newIndex = HashFunction(node.key);
                newHashTable[newIndex].emplace_back(node);
            }
        }

        hashTable = move(newHashTable);
        tableSize = newSize;
    }

    const list<KeyNode>& operator[](size_t index) const {
        return hashTable[index];
    }
};

int main() {
    MyHashTable wordCountTable(10);

    string text = "This is a sample text. This text is used to demonstrate the word count program.";

    size_t startPos = 0;
    size_t endPos = text.find(" ");
    while (endPos != string::npos) {
        string word = text.substr(startPos, endPos - startPos);
        int count;
        if (wordCountTable.SearchKey(word, count)) {
            wordCountTable.UpdateKey(word, count + 1);
        } else {
            wordCountTable.UpdateKey(word, 1);
        }
        startPos = endPos + 1;
        endPos = text.find(" ", startPos);
    }

    for (size_t i = 0; i < wordCountTable.GetHashTableSize(); ++i) {
        for (const auto& node : wordCountTable[i]) {
            cout << "Word: " << node.key << ", Count: " << node.value << endl;
        }
    }

    return 0;
}
