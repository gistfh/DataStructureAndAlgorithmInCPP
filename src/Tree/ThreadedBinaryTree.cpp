//
// Created by temTeng on 2021/7/20.
//

#include <cstdio>
#include <iostream>
#include "ThreadedBinaryTree.h"


ThreadedBinaryTree::ThreadedBinaryTree() {
    preorderCreateBinaryTree(this->pRootNode);
    inorderThreadingBinaryTree(nullptr, this->pRootNode, nullptr);

}

void ThreadedBinaryTree::preorderCreateBinaryTree(
        ThreadedBinaryTree::ThreadedBinaryNode *&pBinaryNode) {//*&表示以引用的形式传入指针，可以修改指针指向new 出来的对象
    char data = 0;
    scanf_s("%c", &data);
    //如果输入为一个空格则头指针设置为空，并退出
    if (data == '_') {
        pBinaryNode = nullptr;
    } else {
        //如果输入不为空，头指针指向root节点
        pBinaryNode = new ThreadedBinaryNode(data);
        pBinaryNode->leftTag = PointerTag::LINK;
        pBinaryNode->rightTag = PointerTag::LINK;

        preorderCreateBinaryTree(pBinaryNode->pLeftNode);
        preorderCreateBinaryTree(pBinaryNode->pRightNode);
    }

}

void ThreadedBinaryTree::inorderThreadingBinaryTree(ThreadedBinaryTree::ThreadedBinaryNode *pPreCursor,
                                                    ThreadedBinaryTree::ThreadedBinaryNode *pCurrentCursor,
                                                    ThreadedBinaryTree::ThreadedBinaryNode *pPostCursor) {

    if (nullptr != pCurrentCursor) {
        //左指针递归
        if (nullptr != pCurrentCursor->pLeftNode) {
            inorderThreadingBinaryTree(pPreCursor, pCurrentCursor->pLeftNode, pCurrentCursor);
        } else if (nullptr == pCurrentCursor->pLeftNode) {
            pCurrentCursor->leftTag = PointerTag::THREAD;
            pCurrentCursor->pLeftNode = pPreCursor;
        }

        //右指针递归
        if (nullptr != pCurrentCursor->pRightNode) {
            inorderThreadingBinaryTree(pCurrentCursor, pCurrentCursor->pRightNode, pPostCursor);
        } else if (nullptr == pCurrentCursor->pRightNode) {
            pCurrentCursor->rightTag = PointerTag::THREAD;
            pCurrentCursor->pRightNode = pPostCursor;
        }
    }

}

void ThreadedBinaryTree::inorderTraverseNotRecursive(std::string message) {
    std::cout << message << std::endl;
    if (nullptr != this->pRootNode) {
        ThreadedBinaryNode *curNode = this->pRootNode;
        //走到最左边
        while (nullptr != curNode->pLeftNode) {
            curNode = curNode->pLeftNode;
        }
        do {
            std::cout << curNode->data << std::endl;
            curNode = curNode->pRightNode;
        } while (nullptr != curNode);
    }

}
