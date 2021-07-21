//
// Created by temTeng on 2021/7/20.
//

#ifndef DATASTRUCTUREANDALGORITHMINCPP_THREADEDBINARYTREE_H
#define DATASTRUCTUREANDALGORITHMINCPP_THREADEDBINARYTREE_H


class ThreadedBinaryTree {
private:
    typedef enum PointerTag {
        LINK, THREAD
    } PointerTag;

    class ThreadedBinaryNode {
    public:
        explicit ThreadedBinaryNode(char data) {
            this->data = data;
        }

        char data;

        ThreadedBinaryNode *pLeftNode = nullptr;
        PointerTag leftTag;
        ThreadedBinaryNode *pRightNode = nullptr;
        PointerTag rightTag;
    };

    ThreadedBinaryNode *pRootNode;
public:
    ThreadedBinaryTree();

    void preorderCreateBinaryTree(ThreadedBinaryNode *&pBinaryNode);


    void inorderThreadingBinaryTree(ThreadedBinaryNode *pPreCursor, ThreadedBinaryNode *pCurrentCursor,
                                    ThreadedBinaryNode *pPostCursor);

    void inorderTraverseNotRecursive(std::string message);
};


#endif //DATASTRUCTUREANDALGORITHMINCPP_THREADEDBINARYTREE_H
