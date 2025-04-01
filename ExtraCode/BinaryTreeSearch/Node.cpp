struct Node {
    int value;
    Node* left;
    Node* right;
    
    explicit Node(const int& val) : value(val), left(nullptr), right(nullptr) {}
};