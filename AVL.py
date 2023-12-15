class Node:
    def __init__(self, value):
        self.value = value
        self.height = 1
        self.left = None
        self.right = None

class AVLTree:
    def __init__(self):
        self.root = None

    def height(self, node):
        if not node:
            return 0
        return node.height

    def balanceFactor(self, node):
        if not node:
            return 0
        return self.height(node.left) - self.height(node.right)

    def updateHeight(self, node):
        if not node:
            return 0
        node.height = 1 + max(self.height(node.left), self.height(node.right))

    def leftRotate(self, z):
        y = z.right
        T2 = y.left

        y.left = z
        z.right = T2

        self.updateHeight(z)
        self.updateHeight(y)

        return y

    def rightRotate(self, y):
        x = y.left
        T2 = x.right

        x.right = y
        y.left = T2

        self.updateHeight(y)
        self.updateHeight(x)

        return x

    def leftRightRotate(self, z):
        z.left = self.leftRotate(z.left)
        return self.rightRotate(z)

    def rightLeftRotate(self, z):
        z.right = self.rightRotate(z.right)
        return self.leftRotate(z)

    def isBST(self, node):
        if node == None:
            return True
        if node.left and node.left.value > node.value:
            return False
        if node.right and node.right.value < node.value:
            return False
        return self.isBST(node.left) and self.isBST(node.right)
    def insert(self, root, value):
        if not root:
            return Node(value)

        if value < root.value:
            root.left = self.insert(root.left, value)
        else:
            root.right = self.insert(root.right, value)

        self.updateHeight(root)

        balance = self.balanceFactor(root)

        # Left-Left Case
        if balance > 1 and value < (root.left.value if root.left else 0):
            return self.rightRotate(root)

        # Right-Right Case
        if balance < -1 and value > (root.right.value if root.right else 0):
            return self.leftRotate(root)

        # Left-Right Case
        if balance > 1 and value > (root.left.value if root.left else 0):
            return self.leftRightRotate(root)

        # Right-Left Case
        if balance < -1 and value < (root.right.value if root.right else 0):
            return self.rightLeftRotate(root)

        return root

    def insertValue(self, value):
        self.root = self.insert(self.root, value)

    def inOrderTraversal(self, root):
        if root:
            self.inOrderTraversal(root.left)
            print(root.value, end=" ")
            self.inOrderTraversal(root.right)

    def preOrderTraversal(self, root):
        if root:
            print(root.value, end=" ")
            self.preOrderTraversal(root.left)
            self.preOrderTraversal(root.right)


    def visualizeTree(self):
        self.visualizeHelper(self.root, 0)

    def visualizeHelper(self, node, depth):
        if node == None:
            return
        self.visualizeHelper(node.right, depth + 1)
        print("  " * depth + str(node.value))
        self.visualizeHelper(node.left, depth + 1)

    def isSparseTree(self):
        numNodes = self.numberOfNodes(self.root)
        numLeaves = self.countLeaves(self.root)
        return numNodes < 0.5 * numLeaves

    def numberOfNodes(self, node):
        if node == None:
            return 0
        return 1 + self.numberOfNodes(node.left) + self.numberOfNodes(node.right)

    def countLeaves(self, node):
        if node == None:
            return 0
        if node.left == None and node.right == None:
            return 1
        return self.countLeaves(node.left) + self.countLeaves(node.right)


if __name__ == "__main__":

    avl = AVLTree()
    values = [9, 5, 10, 0, 6, 11, -1, 1, 2, 7]
    for value in values:
        avl.insertValue(value)

    print("In-Order Traversal:")
    avl.inOrderTraversal(avl.root)
    print()

    print("Pre-Order Traversal:")
    avl.preOrderTraversal(avl.root)

    print()

    avl.visualizeTree()
    print(avl.isBST(avl.root))
    print(avl.isSparseTree())
