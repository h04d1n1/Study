#include"BinaryTree.cpp"

int main() {
    int data[] = {1, 4, 5, 10};
    BinaryTree binaryTree(data, 4);

    binaryTree.printTree();
    binaryTree.insert(6);
    binaryTree.printTree();

    return 0;
}