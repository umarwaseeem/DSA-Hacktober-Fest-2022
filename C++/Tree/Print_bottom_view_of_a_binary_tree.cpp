// Print bottom view of a binary tree
#include <iostream>
#include <map>
using namespace std;

// Data structure to store a binary tree node
struct Node
{
    int key;
    Node *left, *right;

    Node(int key)
    {
        this->key = key;
        this->left = this->right = nullptr;
    }
};

// Recursive function to perform preorder traversal on the tree and fill the map.
// Here, the node has `dist` horizontal distance from the tree's root,
// and the `level` represents the node's level.

void printBottom(Node* node, int dist, int level, auto &map)
{
    // base case: empty tree
    if (node == nullptr) {
        return;
    }

    // if the current level is more than or equal to the maximum level seen so far
    // for the same horizontal distance or horizontal distance is seen for
    // the first time, update the map

    if (level >= map[dist].second)
    {
        // update value and level for the current distance
        map[dist] = { node->key, level };
    }

    // recur for the left subtree by decreasing horizontal distance and
    // increasing level by 1
    printBottom(node->left, dist - 1, level + 1, map);

    // recur for the right subtree by increasing both level and
    // horizontal distance by 1
    printBottom(node->right, dist + 1, level + 1, map);
}

// Function to print the bottom view of a given binary tree
void printBottom(Node* root)
{
    // create an empty map where
    // key —> relative horizontal distance of the node from the root node, and
    // value —> pair containing the node's value and its level

    map<int, pair<int, int>> map;

    // perform preorder traversal on the tree and fill the map
    printBottom(root, 0, 0, map);

    // traverse the map and print the bottom view
    for (auto it: map) {
        cout << it.second.first << " ";
    }
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);

    printBottom(root);

    return 0;
}
