# Importing the required modules
import sys

# Defining the class for the Red Black Tree
class RedBlackTree:
    # Defining the class for the node
    class Node:
        # Defining the constructor
        def __init__(self, data):
            # Setting the data
            self.data = data
            # Setting the left and right child to None
            self.left = None
            self.right = None
            # Setting the color to red
            self.color = "red"
    
    # Defining the constructor
    def __init__(self):
        # Setting the root to None
        self.root = None
    
    # Defining the method to insert a node
    def insert(self, data):
        # Creating a new node
        new_node = self.Node(data)
        # Checking if the root is None
        if self.root is None:
            # Setting the root to the new node
            self.root = new_node
            # Setting the color of the root to black
            self.root.color = "black"
        # If the root is not None
        else:
            # Calling the method to insert the node
            self.insert_node(self.root, new_node)
    
    # Defining the method to insert the node
    def insert_node(self, root, new_node):
        # Checking if the root is None
        if root is None:
            # Setting the root to the new node
            root = new_node
            # Setting the color of the root to black
            root.color = "black"
        # If the root is not None
        else:
            # Checking if the data of the new node is less than the data of the root
            if new_node.data < root.data:
                # Checking if the left child of the root is None
                if root.left is None:
                    # Setting the left child of the root to the new node
                    root.left = new_node
                    # Setting the color of the left child to red
                    root.left.color = "red"
                # If the left child of the root is not None
                else:
                    # Calling the method to insert the node
                    self.insert_node(root.left, new_node)
            # Checking if the data of the new node is greater than the data of the root
            elif new_node.data > root.data:
                # Checking if the right child of the root is None
                if root.right is None:
                    # Setting the right child of the root to the new node
                    root.right = new_node
                    # Setting the color of the right child to red
                    root.right.color = "red"
                # If the right child of the root is not None
                else:
                    # Calling the method to insert the node
                    self.insert_node(root.right, new_node)
            # If the data of the new node is equal to the data of the root
            else:
                # Printing the message
                print("The node already exists")

    # Defining the method to print the tree
    def print_tree(self):
        # Checking if the root is None
        if self.root is None:
            # Printing the message
            print("The tree is empty")
        # If the root is not None
        else:
            # Calling the method to print the tree
            self.print_tree_node(self.root)

    # Defining the method to print the tree
    def print_tree_node(self, root):
        # Checking if the root is None
        if root is None:
            # Returning
            return
        # If the root is not None
        else:
            # Calling the method to print the left child
            self.print_tree_node(root.left)
            # Printing the data of the root
            print(root.data)
            # Calling the method to print the right child
            self.print_tree_node(root.right)

# Defining the main function
def main():
    # Creating an object of the class RedBlackTree
    tree = RedBlackTree()
    tree.insert(30)
    tree.insert(40)
    tree.insert(10)
    tree.insert(20)
    
    tree.print_tree()

# Calling the main function
if __name__ == "__main__":
    main()

