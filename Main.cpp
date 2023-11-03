#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;

// Define the quaternary search tree node
template <typename T>
struct QuadTreeNode {
    T key;
    QuadTreeNode* children[4];

    QuadTreeNode(T k) : key(k) {
        for (int i = 0; i < 4; i++) {
            children[i] = nullptr;
        }
    }
};

// Define the quaternary search tree class
template <typename T>
class QuaternarySearchTree {
public:
    QuadTreeNode<T>* root;

public:
    QuaternarySearchTree() : root(nullptr) {}

    // Constructor accepting an array of objects to initialize the tree
    QuaternarySearchTree(const vector<T>& objects) : root(nullptr) {
        for (const T& obj : objects) {
            insert(obj);
        }
    }

    // Function to insert a new element
    void insert(const T& key) {
        //cout << "Inserting: " << key << endl;
        insertRecursive(root, new QuadTreeNode<T>(key));
    }

    // Function to delete an element, store nodes in a dynamic array, and reconstruct the tree
    void remove(const T& key) {
        vector<QuadTreeNode<T>*> nodes;
        collectNodes(root, key, nodes);
        root = nullptr; // Clear the old tree
        reconstructTree(nodes, root);
    }

    // Function to print elements in preorder
    void printPreorder() {
        printPreorderRecursive(root);
        cout << endl;
    }

    // Function to print elements in postorder
    void printPostorder() {
        printPostorderRecursive(root);
        cout << endl;
    }

private:
    // Helper function to insert a node recursively
    void insertRecursive(QuadTreeNode<T>*& node, QuadTreeNode<T>* newNode) {
        if (node == nullptr) {
            node = newNode;
        } else {
            int index = findChildIndex(node, newNode->key);
            if (node->children[index] == nullptr) {
                node->children[index] = newNode;
            } else {
                insertRecursive(node->children[index], newNode);
            }
        }
    }

    // Helper function to find the ind
    int findChildIndex(QuadTreeNode<T>* node, const T& key) {
        T k = node->key;
        if (key >= 0 && key < k / 2) {
            return 0;
        } else if (key >= k / 2 && key < k) {
            return 1;
        } else if (key >= k && key < 2 * k) {
            return 2;
        } else {
            return 3;
        }
    }

    // Helper function to collect nodes in a dynamic array
    void collectNodes(QuadTreeNode<T>* node, const T& key, vector<QuadTreeNode<T>*>& nodes) {
        if (node == nullptr) {
            return;
        }

        if (node->key != key) {
            nodes.push_back(node);
        }

        for (int i = 0; i < 4; i++) {
            collectNodes(node->children[i], key, nodes);
        }
    }

    // Helper function to reconstruct the tree from the nodes in the dynamic array
    void reconstructTree(vector<QuadTreeNode<T>*>& nodes, QuadTreeNode<T>*& node) {
        root = nullptr; // Clear the old tree
        for (QuadTreeNode<T>* n : nodes) {
            insert(n->key); // Reinsert each node into the tree
        }
    }

    // Recursive function to print elements in preorder
    void printPreorderRecursive(QuadTreeNode<T>* node) {
        if (node == nullptr) {
            return;
        }

        cout << node->key << " ";
        for (int i = 0; i < 4; i++) {
            printPreorderRecursive(node->children[i]);
        }
    }

    // Recursive function to print elements in postorder
    void printPostorderRecursive(QuadTreeNode<T>* node) {
        if (node == nullptr) {
            return;
        }

        for (int i = 0; i < 4; i++) {
            printPostorderRecursive(node->children[i]);
        }
        cout << node->key << " ";
    }
};

int main() {
    QuaternarySearchTree<int> tree;
    vector<int> initialValues = {50,30,10,20,40,80,35,45};
    tree = QuaternarySearchTree<int>(initialValues);

    int choice;
    int element;

    do {
        cout << "********************************:" << endl;
        cout << "********************************:" << endl;
        cout << "Enter 1 for Insert Element" << endl;
        cout << "Enter 2 for Delete Element" << endl;
        cout << "Enter 3 for Print Preorder" << endl;
        cout << "Enter 4 for Print Postorder" << endl;
        cout << "Enter 5 for Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        try {
            switch (choice) {
                case 1:
                    cout << "Enter the element to inse0rt: ";
                    cin >> element;
                    tree.insert(element);
                    break;

                case 2:
                    cout << "Enter the element to delete: ";
                    cin >> element;
                    assert(tree.root!=nullptr);
                    tree.remove(element);
                    break;

                case 3:
                    assert(tree.root!=nullptr);
                    tree.printPreorder();
                    break;

                case 4:
                    assert(tree.root!=nullptr);
                    tree.printPostorder();
                    break;

                case 5:
                    cout << "Exiting the program." << endl;
                    break;

                default:
                    cerr << "Invalid choice. Please choose a valid option." << endl;
            }
        } catch (const exception& e) {
            cerr << e.what() << endl;
        }
    } while (choice != 5);

    return 0;
}