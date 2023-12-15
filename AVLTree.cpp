#include <iostream>
using namespace std;

class Node {
public:
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int k) : key(k), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
public:
    Node* root;

    AVLTree() : root(nullptr) {}

    int height(Node* node) {
        return (node == nullptr) ? 0 : node->height;
    }

    int balanceFactor(Node* node) {
        return (node == nullptr) ? 0 : height(node->left) - height(node->right);
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = 1 + max(height(y->left), height(y->right));
        x->height = 1 + max(height(x->left), height(x->right));

        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = 1 + max(height(x->left), height(x->right));
        y->height = 1 + max(height(y->left), height(y->right));

        return y;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    Node* insert(Node* root, int key) {
        if (root == nullptr) {
            return new Node(key);
        }

        if (key < root->key) {
            root->left = insert(root->left, key);
        } else if (key > root->key) {
            root->right = insert(root->right, key);
        } else {
            return root; // Duplicate keys are not allowed
        }

        root->height = 1 + max(height(root->left), height(root->right));

        int balance = balanceFactor(root);

        // Left Left Case
        if (balance > 1 && key < root->left->key) {
            return rightRotate(root);
        }

        // Right Right Case
        if (balance < -1 && key > root->right->key) {
            return leftRotate(root);
        }

        // Left Right Case
        if (balance > 1 && key > root->left->key) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        // Right Left Case
        if (balance < -1 && key < root->right->key) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    Node* deleteNode(Node* root, int key) {
        if (root == nullptr) {
            return root;
        }

        if (key < root->key) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->key) {
            root->right = deleteNode(root->right, key);
        } else {
            if (root->left == nullptr || root->right == nullptr) {
                Node* temp = root->left ? root->left : root->right;

                if (temp == nullptr) {
                    temp = root;
                    root = nullptr;
                } else {
                    *root = *temp;
                }

                delete temp;
            } else {
                Node* temp = minValueNode(root->right);
                root->key = temp->key;
                root->right = deleteNode(root->right, temp->key);
            }
        }

        if (root == nullptr) {
            return root;
        }

        root->height = 1 + max(height(root->left), height(root->right));

        int balance = balanceFactor(root);

        // Left Left Case
        if (balance > 1 && balanceFactor(root->left) >= 0) {
            return rightRotate(root);
        }

        // Left Right Case
        if (balance > 1 && balanceFactor(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        // Right Right Case
        if (balance < -1 && balanceFactor(root->right) <= 0) {
            return leftRotate(root);
        }

        // Right Left Case
        if (balance < -1 && balanceFactor(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    void insertKey(int key) {
        root = insert(root, key);
    }

    void deleteKey(int key) {
        root = deleteNode(root, key);
    }

    void inorderTraversal(Node* root) {
        if (root != nullptr) {
            inorderTraversal(root->left);
            cout << root->key << " ";
            inorderTraversal(root->right);
        }
    }

    void printTree() {
        inorderTraversal(root);
        cout << endl;
    }
};

int main() {
    AVLTree avlTree;

    avlTree.insertKey(10);
    avlTree.insertKey(20);
    avlTree.insertKey(30);
    avlTree.insertKey(40);
    avlTree.insertKey(50);
    avlTree.insertKey(25);

    cout << "Inorder traversal of the AVL Tree: ";
    avlTree.printTree();

    avlTree.deleteKey(30);

    cout << "Inorder traversal after deleting 30: ";
    avlTree.printTree();

    return 0;
}
