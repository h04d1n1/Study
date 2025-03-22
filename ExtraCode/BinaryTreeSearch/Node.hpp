#pragma once

class Node {
    int data;
    Node *left;
    Node *right;
public:
    Node();
    Node(const int&);
    ~Node();
};