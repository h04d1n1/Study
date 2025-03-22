#pragma once

class BinaryTree {
    Node* root;
public:
    BinaryTree() : root(nullptr) {}
    ~BinaryTree() {
        delete root;
    }
};
