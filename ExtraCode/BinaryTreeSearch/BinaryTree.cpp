#include"Node.cpp"
#include<stdexcept>
#include<stack>
#include<iostream>

class BinaryTree {
    Node* root;
    size_t size;

    Node* findMin(Node* node) const {
        while (node && node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

public:
    BinaryTree() noexcept : root(nullptr), size(0) {}

    BinaryTree(const int* data, const size_t s) : root(nullptr), size(0) {
        if (data && s > 0) {
            for (size_t i = 0; i < s; ++i) {
                insert(data[i]);
            }
        }
    }

    int& operator[](const int& index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of bounds");
        }

        Node* current = root;
        std::stack<Node*> stack;
        int count = 0;

        // In-order traversal (left-root-right)
        while (current != nullptr || !stack.empty()) {
            while (current != nullptr) {
                stack.push(current);
                current = current->left;
            }

            current = stack.top();
            stack.pop();

            if (count == index) {
                return current->value;
            }
            count++;

            current = current->right;
        }
        throw std::runtime_error("Element not found");
    }

    bool insert(const int value) {
        // Tree is empty
        if (!root) {
            root = new Node(value);
            size++;
            return true;
        }

        Node* current = root;
        Node* parent = nullptr;

        // Finding correct place
        while (current) {
            parent = current;

            if (value == current->value) {
                return false;  // No duplicates
            }

            if (value < current->value) {
                current = current->left;
            } else {
                current = current->right;
            }
        }

        // Creating new Node
        Node* newNode = new Node(value);

        // Inserting in correct place
        if (value < parent->value) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }
        size++;
        return true;
    }

    void printTree() const {
        printNode(root);
        std::cout << "\n";
    }

    void printNode(const Node* node) const {
        if (!node) return;
        printNode(node->left);
        std::cout << node->value << " ";
        printNode(node->right);
    }
};