class Node:
    def __init__(self, data):
        self.data = data
        self.right = None
        self.left = None

class BST:
    def __init__(self):
        self.root = None

    def insert(self, data):
        newNode = Node(data)
        if self.root is None:
            self.root = newNode
        else:
            current = self.root
            while True:
                if data <= current.data:
                    if current.left is None:
                        current.left = newNode
                        return
                    else:
                        current = current.left
                else:
                    if current.right is None:
                        current.right = newNode
                        return
                    else:
                        current = current.right 

    def getMin(self):
        current = self.root
        while current.left is not None:
            current = current.left
        return current.data

    def getMax(self):
        current = self.root 
        while current.right is not None:
            current = current.right
        return current.data 
