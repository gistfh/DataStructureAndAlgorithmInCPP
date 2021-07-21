//
// Created by temTeng on 2021/7/20.
//

#ifndef DATASTRUCTUREANDALGORITHMINCPP_BINARYTREE_H
#define DATASTRUCTUREANDALGORITHMINCPP_BINARYTREE_H

#include <iostream>
#include <functional>

class BinaryTree {
private:
    class BinaryNode {
    public:
        char data;
        BinaryNode *leftChild = nullptr;
        BinaryNode *rightChild = nullptr;

        explicit BinaryNode(char data) {
            this->data = data;
        }
    };

    BinaryNode *nodeCur;
    BinaryNode *rootNode;

public:

    BinaryTree();

    ~BinaryTree();

    void preorderCreateBiTree(BinaryNode *&binaryNode);

    void preorderTraversal(const std::function<void(BinaryNode *)> &function, std::string message);

    void preorderTraversalRecursive(BinaryNode *currentNode, const std::function<void(BinaryNode *)> function);

    void postorderTraversal(const std::function<void(BinaryNode *)> &function, std::string message);

    void
    postorderTraversalRecursive(BinaryNode *currentNode, const std::function<void(BinaryTree::BinaryNode *)> &function);
};

#endif //DATASTRUCTUREANDALGORITHMINCPP_BINARYTREE_H
