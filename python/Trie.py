class Node:
    def __init__(self, char):
        self.char = char
        self.children = {}
        self.isEnd = False
        self.counter = 0
        
class Trie:
    def __init__(self):
        self.root = Node("")
    
    def insert(self, word):
        current = self.root 
        for char in word:
            if char in current.children:
                current = current.children[char]
            else:
                new_node = Node(char)
                current.children[char] = new_node
                current = new_node
        current.isEnd = True
        current.counter += 1 
    
    def depthFirstSearch(self, node, prefix):
        if node.isEnd:
            self.output.append((prefix + node.char, node.counter))
        for cNode in node.children.values():
            self.depthFirstSearch(cNode, prefix + node.char)
    
    def query(self, prefix):
        self.output = []
        node = self.root
        for char in prefix:
            if char in node.children:
                node = node.children[char]
            else:
                return []
                
        self.depthFirstSearch(node, prefix[:-1])
        return sorted(self.output, key=lambda x: x[1], reverse=True)
        
        
 
    
