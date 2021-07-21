//
// Created by temTeng on 2021/7/20.
//
#include <iostream>

#include "BinaryTreeTest.h"
#include "../src/Tree/BinaryTree.h"

using std::cout;
using std::cin;
using std::endl;

void BinaryTreeTest::test() {
    auto *binaryTree = new BinaryTree();

    binaryTree->preorderTraversal(
            [](auto binaryNode) -> void {
                cout << "=>" << binaryNode->data << "\t" << endl;
            },
            "前序遍历: ");

    binaryTree->postorderTraversal(
            [](auto binaryNode) -> void {
                cout << "->" << binaryNode->data << "\t" << endl;
            },
            "后序遍历: "
    );

    delete binaryTree;

}
