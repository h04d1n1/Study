#include "Node.hpp"

Node::Node() : data(0), left(nullptr), right(nullptr) {}
Node::Node(const int& data) : data(data), left(nullptr), right(nullptr) {}
Node::~Node() {
    delete left;
    delete right;
}