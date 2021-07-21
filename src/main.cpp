#include <iostream>

#include "../test/BinaryTreeTest.h"
#include "../test/ThreadedBinaryTreeTest.h"


int main() {
    std::cout << "Hello, World!" << std::endl;

    ThreadedBinaryTreeTest::test();

    return 0;
}
