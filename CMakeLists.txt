cmake_minimum_required(VERSION 3.19)
project(DataStructureAndAlgorithmInCPP)

set(CMAKE_CXX_STANDARD 11)

add_executable(
        DataStructureAndAlgorithmInCPP
        src/main.cpp
        src/Tree/BiTree.cpp
        src/Tree/BiTree.h
        src/Tree/BinaryTree.cpp
        src/Tree/BinaryTree.h
        src/Tree/ThreadedBinaryTree.cpp
        src/Tree/ThreadedBinaryTree.h
        test/ClassTemplateTest.cpp
        test/ClassTemplateTest.h
        test/BinaryTreeTest.cpp
        test/BinaryTreeTest.h
        test/ThreadedBinaryTreeTest.cpp
        test/ThreadedBinaryTreeTest.h)