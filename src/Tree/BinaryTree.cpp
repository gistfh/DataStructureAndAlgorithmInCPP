//
// Created by temTeng on 2021/7/20.
//

#include "BinaryTree.h"

#include <iostream>
#include <functional>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;


BinaryTree::BinaryTree() {
    preorderCreateBiTree(this->rootNode);
}

void BinaryTree::preorderCreateBiTree(BinaryTree::BinaryNode *&binaryNode) {
    char data = 0;
    scanf_s("%c", &data);
    //如果输入为一个空格则头指针设置为空，并退出
    if (data == ' ') {
        binaryNode = nullptr;
    } else {
        //如果输入不为空，头指针指向root节点
        binaryNode = new BinaryNode(data);
        preorderCreateBiTree(binaryNode->leftChild);
        preorderCreateBiTree(binaryNode->rightChild);
    }
}

void BinaryTree::
preorderTraversal(const std::function<void(BinaryTree::BinaryNode *)> &function, std::string message) {
    cout << message << endl;
    preorderTraversalRecursive(this->rootNode, function);

}

void BinaryTree::
preorderTraversalRecursive(BinaryNode *currentNode, const std::function<void(BinaryNode *)> function) {
    if (currentNode != nullptr) {
        function(currentNode);
        preorderTraversalRecursive(currentNode->leftChild, function);
        preorderTraversalRecursive(currentNode->rightChild, function);
    }
}


void BinaryTree::postorderTraversal(const std::function<void(BinaryNode *)> &function, std::string message) {
    cout << message << endl;
    postorderTraversalRecursive(this->rootNode, function);
}

void BinaryTree::postorderTraversalRecursive(BinaryTree::BinaryNode *currentNode,
                                             const std::function<void(BinaryTree::BinaryNode *)> &function) {
    if (currentNode != nullptr) {
        postorderTraversalRecursive(currentNode->leftChild, function);
        postorderTraversalRecursive(currentNode->rightChild, function);
        function(currentNode);
    }
}

BinaryTree::~BinaryTree() {
    postorderTraversal(
            [](auto binaryNode) -> void {
                if (binaryNode != nullptr) {
                    delete binaryNode;
                    binaryNode = nullptr;
                }
            },
            ""
    );
}

