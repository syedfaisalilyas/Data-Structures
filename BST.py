import random

class Node():
    def __init__(self,value):
        self.value = value
        self.left = None
        self.right = None
        self.parent = None

class BST():
    def __init__(self):
        self.root = None

    def isEmpty(self):
        if self.root == None:
            return True

    def insertNode(self,value):
        if self.root == None:
            self.root = Node(value)
            return self.root
        return self.insertHelper(self.root, value)

    def insertHelper(self, node, value):
        if node == None:
            return Node(value)
        if value < node.value:
            node.left = self.insertHelper(node.left, value)
            node.left.parent = node
        elif value > node.value:
            node.right = self.insertHelper(node.right, value)
            node.right.parent = node
        return node

    def findNode(self, value):
        return self.findHelper(self.root, value)

    def findHelper(self, node, value):
        if node == None or node.value == value:
            return node
        if value < node.value:
            return self.findHelper(node.left, value)
        else:
            return self.findHelper(node.right, value)

    def deleteNode(self, value):
        while self.findNode(value) != None:
            self.deleteHelper(self.findNode(value))

    def deleteHelper(self, node):
        if node == None:
            return
        if node.left == None:
            self.transplant(node, node.right)
        elif node.right == None:
            self.transplant(node, node.left)
        else:
            successor = self.minimum(node.right)
            if successor.parent != node:
                self.transplant(successor, successor.right)
                successor.right = node.right
                successor.right.parent = successor
            self.transplant(node, successor)
            successor.left = node.left
            successor.left.parent = successor
    def transplant(self, node, child):
        if node.parent == None:
            self.root = child
        elif node == node.parent.left:
            node.parent.left = child
        else:
            node.parent.right = child
        if child != None:
            child.parent = node.parent

    def minimum(self, node):
        while node.left != None:
            node = node.left
        return node

    def inOrderTraversal(self, node):
        if node:
            self.inOrderTraversal(node.left)
            print(node.value, end=" ")
            self.inOrderTraversal(node.right)

    def preOrderTraversal(self, node):
        if node:
            print(node.value, end=" ")
            self.preOrderTraversal(node.left)
            self.preOrderTraversal(node.right)

    def postOrderTraversal(self, node):
        if node:
            self.postOrderTraversal(node.left)
            self.postOrderTraversal(node.right)
            print(node.value, end=" ")

    def numberOfNodes(self, node):
        if node == None:
            return 0
        return 1 + self.numberOfNodes(node.left) + self.numberOfNodes(node.right)

    def Height(self, node):
        if node == None:
            return 0
        return 1 + max(self.Height(node.left), self.Height(node.right))

    def isBST(self, node):
        if node == None:
            return True
        if node.left and node.left.value > node.value:
            return False
        if node.right and node.right.value < node.value:
            return False
        return self.isBST(node.left) and self.isBST(node.right)

    def LeafNodes(self, node):
        if node == None:
            return
        if node.left == None and node.right == None:
            print(node.value, end=" ")
        self.LeafNodes(node.left)
        self.LeafNodes(node.right)

    def isSparseTree(self):
        numNodes = self.numberOfNodes(self.root)
        numLeaves = self.countLeaves(self.root)
        return numNodes < 0.5 * numLeaves

    def countLeaves(self, node):
        if node == None:
            return 0
        if node.left == None and node.right == None:
            return 1
        return self.countLeaves(node.left) + self.countLeaves(node.right)

    def visualizeTree(self):
        self.visualizeHelper(self.root, 0)

    def visualizeHelper(self, node, depth):
        if node == None:
            return
        self.visualizeHelper(node.right, depth + 1)
        print("  " * depth + str(node.value))
        self.visualizeHelper(node.left, depth + 1)

    def buildBalancedTree(self, arr):
        random.shuffle(arr)
        self.root = self.balanceHelper(arr)

    def balanceHelper(self, arr):
        if len(arr) < 1:
            return None
        middle = len(arr) // 2
        root = Node(arr[middle])
        root.left = self.balanceHelper(arr[:middle])
        root.right = self.balanceHelper(arr[middle + 1:])
        return root

if __name__ == "__main__":
    bst = BST()
    values = [50, 30, 70, 20, 40, 60, 80, 35, 37]
    for val in values:
        bst.insertNode(val)

    print("In-Order Traversal:")
    bst.inOrderTraversal(bst.root)
    print()

    print("Pre-Order Traversal:")
    bst.preOrderTraversal(bst.root)
    print()

    print("Post-Order Traversal:")
    bst.postOrderTraversal(bst.root)
    print()

    print("Number of Nodes:", bst.numberOfNodes(bst.root))
    print("Tree Height:", bst.Height(bst.root))
    print("Is BST:", bst.isBST(bst.root))

    print("Leaf Nodes:")
    bst.LeafNodes(bst.root)
    print()

    print("Is Sparse Tree:", bst.isSparseTree())

    print("Visualize Tree:")
    bst.visualizeTree()

    # print(11111111111111111111111111111111111)
    # balanced_values = [50, 30,7,2, 70, 20, 40, 60, 80, 35, 37]
    # balanced_bst = BST()
    # balanced_bst.buildBalancedTree(balanced_values)
    #
    # print("\nBalanced Tree - In-Order Traversal:")
    # balanced_bst.inOrderTraversal(balanced_bst.root)
    # print()
    #
    # print("Number of Nodes:", balanced_bst.numberOfNodes(balanced_bst.root))
    # print("Tree Height:", balanced_bst.Height(balanced_bst.root))
    # print("Is BST:", balanced_bst.isBST(balanced_bst.root))
    #
    # print("Leaf Nodes:")
    # balanced_bst.LeafNodes(balanced_bst.root)
    # print()
    #
    # print("Is Sparse Tree:", balanced_bst.isSparseTree())
    #
    # print("Visualize Tree:")
    # balanced_bst.visualizeTree()