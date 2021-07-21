//
// Created by temTeng on 2021/7/20.
//

#include <string>
#include "ThreadedBinaryTreeTest.h"
#include "../src/Tree/ThreadedBinaryTree.h"

void ThreadedBinaryTreeTest::test() {

    ThreadedBinaryTree *threadedBinaryTree = new ThreadedBinaryTree();

    threadedBinaryTree->inorderTraverseNotRecursive("abc");

    delete threadedBinaryTree;
}
