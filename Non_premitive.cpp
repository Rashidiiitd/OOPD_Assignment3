#include <iostream>
#include <string>
#include <vector>
#include <cassert>
using namespace std;
class QuaternaryTreeException : public exception {
public:
    QuaternaryTreeException(const string& message) : message(message) {}

    const char* what() const throw() {
        return message.c_str();
    }

private:
    string message;
};

template <typename T>
class QuadTreeNode {
public:
    T key;
    QuadTreeNode<T>* children[4];

    QuadTreeNode(const T& key) : key(key) {
        for (int i = 0; i < 4; i++) {
            children[i] = nullptr;
        }
    }
};

class Person {
    string name;
    int age;

public:
    Person(const string& name, int age) : name(name), age(age) {}

    int getKey() const {
        return age;
    }

    friend ostream& operator<<(ostream& out, const Person& person) {
        out << "Person: " << person.name << " (Age: " << person.age << ")";
        return out;
    }
};

class Animal {
    string name;
    int age;

public:
    Animal(const string& name, int age) : name(name), age(age) {}

    int getKey() const {
        return age;
    }

    friend ostream& operator<<(ostream& out, const Animal& animal) {
        out << "Animal: " << animal.name << " (Age: " << animal.age << ")";
        return out;
    }
};

template <typename T>
class QuaternarySearchTree {
public:
    QuadTreeNode<T>* root;

    QuaternarySearchTree() : root(nullptr) {}

    int findChildIndex(QuadTreeNode<T>* node, const T& key) {
        int k = key.getKey();
        int keyVal = key.getKey();

        if (keyVal >= 0 && keyVal < k / 2) {
            return 0;
        } else if (keyVal >= k / 2 && keyVal < k) {
            return 1;
        } else if (keyVal >= k && keyVal < 3 * k / 2) {
            return 2;
        } else {
            return 3;
        }
    }

    void insert(const T& key) {
        insertRecursive(root, new QuadTreeNode<T>(key));
    }

    void insertRecursive(QuadTreeNode<T>*& node, QuadTreeNode<T>* newNode) {
        if (!node) {
            node = newNode;
        } else {
            int index = findChildIndex(node, newNode->key);
            insertRecursive(node->children[index], newNode);
        }
    }

    bool deleteNode(const T& key) {
        return deleteNodeRecursive(root, key);
    }

    bool deleteNodeRecursive(QuadTreeNode<T>*& node, const T& key) {
        if (!node) {
            return false;
        }

        if (node->key.getKey() == key.getKey()) {
            delete node;
            node = nullptr;
            return true;
        }

        int index = findChildIndex(node, key);
        if (deleteNodeRecursive(node->children[index], key)) {
            return true;
        }

        return false;
    }

    void printPreorder() {
        printPreorderRecursive(root);
    }

    void printPreorderRecursive(QuadTreeNode<T>* node) {
        if (!node) {
            return;
        }

        cout << node->key << endl;

        for (int i = 0; i < 4; i++) {
            printPreorderRecursive(node->children[i]);
        }
    }

    void printPostorder() {
        printPostorderRecursive(root);
    }

    void printPostorderRecursive(QuadTreeNode<T>* node) {
        if (!node) {
            return;
        }

        for (int i = 0; i < 4; i++) {
            printPostorderRecursive(node->children[i]);
        }

        cout << node->key << endl;
    }
};

int main() {
    QuaternarySearchTree<Person> personTree;
    QuaternarySearchTree<Animal> animalTree;
    int choice;

    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Insert a person" << endl;
        cout << "2. Insert an animal" << endl;
        cout << "3. Delete a person" << endl;
        cout << "4. Delete an animal" << endl;
        cout << "5. Print person tree (postorder)" << endl;
        cout << "6. Print person tree (preorder)" << endl;
        cout << "7. Print animal tree (postorder)" << endl;
        cout << "8. Print animal tree (preorder)" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        try {
            switch (choice) {
                case 1: {
                    string name;
                    int age;
                    cout << "Enter person's name: ";
                    cin >> name;
                    cout << "Enter person's age: ";
                    cin >> age;
                    assert(age >= 0); // Ensure age is non-negative
                    personTree.insert(Person(name, age));
                    cout << "Person inserted successfully." << endl;
                    break;
                }
                case 2: {
                    string name;
                    int age;
                    cout << "Enter animal's name: ";
                    cin >> name;
                    cout << "Enter animal's age: ";
                    cin >> age;
                    assert(age >= 0); // Ensure age is non-negative
                    animalTree.insert(Animal(name, age));
                    cout << "Animal inserted successfully." << endl;
                    break;
                }
                case 3: {
                    int age;
                    cout << "Enter the age of the person to delete: ";
                    cin >> age;
                    assert(age >= 0); // Ensure age is non-negative
                    if (personTree.deleteNode(Person("", age))) {
                        cout << "Person deleted successfully." << endl;
                    } else {
                        cout << "Person not found." << endl;
                    }
                    break;
                }
                case 4: {
                    int age;
                    cout << "Enter the age of the animal to delete: ";
                    cin >> age;
                    assert(age >= 0); // Ensure age is non-negative
                    if (animalTree.deleteNode(Animal("", age))) {
                        cout << "Animal deleted successfully." << endl;
                    } else {
                        cout << "Animal not found." << endl;
                    }
                    break;
                }
                case 5:
                    if (personTree.root) {
                        cout << "Printing person tree in postorder:" << endl;
                        personTree.printPostorder();
                    } else {
                        cout << "The person tree is empty." << endl;
                    }
                    break;
                case 6:
                    if (personTree.root) {
                        cout << "Printing person tree in preorder:" << endl;
                        personTree.printPreorder();
                    } else {
                        cout << "The person tree is empty." << endl;
                    }
                    break;
                case 7:
                    if (animalTree.root) {
                        cout << "Printing animal tree in postorder:" << endl;
                        animalTree.printPostorder();
                    } else {
                        cout << "The animal tree is empty." << endl;
                    }
                    break;
                case 8:
                    if (animalTree.root) {
                        cout << "Printing animal tree in preorder:" << endl;
                        animalTree.printPreorder();
                    } else {
                        cout << "The animal tree is empty." << endl;
                    }
                    break;
                case 9:
                    cout << "Exiting program." << endl;
                    exit(0);
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        } catch (const QuaternaryTreeException& ex) {
            cerr << "Error: " << ex.what() << endl;
        }
    }

    return 0;
}
