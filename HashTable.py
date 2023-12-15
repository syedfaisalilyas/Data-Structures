class KeyNode:
    def __init__(self, key, value):
        self.key = key
        self.value = value

class MyHashTable:
    def __init__(self, hashSize):
        self.array = [None] * hashSize
        self.size = hashSize
        self.keysOccupied = 0

    def getHashTableSize(self):
        return self.size

    def getNumberOfKeys(self):
        return self.keysOccupied

    def hashFunction(self, key):
        return len(key) % self.size

    def updateKey(self, key, value):
        index = self.hashFunction(key)
        node = KeyNode(key, value)

        while self.array[index] is not None:
            if self.array[index].key == key:
                self.array[index].value = value
                return
            index = (index + 1) % self.size

        self.array[index] = node
        self.keysOccupied += 1

        if self.keysOccupied > self.size // 2:
            self.rehash()

    def searchKey(self, key):
        index = self.hashFunction(key)

        while self.array[index] is not None:
            if self.array[index].key == key:
                return self.array[index].value
            index = (index + 1) % self.size

        return None

    def rehash(self):
        oldArray = self.array
        self.size *= 2
        self.array = [None] * self.size
        self.keysOccupied = 0

        for node in oldArray:
            if node is not None:
                self.updateKey(node.key, node.value)

if __name__ == "__main__":
    hashTable = MyHashTable(hashSize=10)
    hashTable.updateKey("apple", 5)
    hashTable.updateKey("banana", 8)
    hashTable.updateKey("orange", 12)
    hashTable.updateKey("grapes", 7)
    hashTable.updateKey("kiwi", 4)
    hashTable.updateKey("watermelon", 20)
    hashTable.updateKey("strawberry", 3)

    # carHashTable = MyHashTable(hashSize=10)
    # carHashTable.updateKey("Toyota Camry", "Sedan")
    # carHashTable.updateKey("Honda Accord", "Sedan")
    # carHashTable.updateKey("Ford Mustang", "Sports Car")
    # carHashTable.updateKey("Chevrolet Silverado", "Truck")
    # carHashTable.updateKey("Tesla Model 3", "Electric")
    # carHashTable.updateKey("Jeep Wrangler", "SUV")
    # carHashTable.updateKey("BMW 3 Series", "Luxury Sedan")
