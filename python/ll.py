class Node:
    def __init__(self, data, next=None):
        self.data = data
        self.next = next


class Linkedlist:
    def __init__(self):
        self.head = None

    def append(self, data):
        newNode = Node(data)
        if self.head is None:
            self.head = newNode
        else:
            current = self.head
            while current.next is not None:
                current = current.next
            current.next = newNode

    def remove(self, value):
        previous = None
        current = self.head 
        found = False

        while not found and current != None:
            if current.data == value:
                found = True
            else:
                previous = current 
                current = current.next

        if current == None:
            return False
        elif previous == None:
            self.head = current.next
            return True
        else:
            previous.next = current.next 
            return True

    def printList(self):
        current = self.head
        value = 1
        while current is not None:
            print(current.data)
            current = current.next

    def __len__(self):
        if self.head is None:
            return 0
        current = self.head
        counter = 1
        while current.next is not None:
            counter += 1
            current = current.next
        return counter
    
    def retReverseLL(self):
        prev = None
        curr = self.head
        while curr is not None:
            nextT = curr.next
            curr.next = prev
            prev = curr
            curr = nextT
        return prev
