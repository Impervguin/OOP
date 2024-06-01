#include "tree.h"
#include <iostream>


int main() {
    BSTree<double> tree({204, 1, 402, 4,62, 74, 18, -21, 9});
    std::cout << tree << std::endl;

    auto it = tree.begin();
    for (int i = 0; i < 5; i++) {
        std::cout << *it << std::endl;
        it++;
    }
    std::cout << std::endl;

    for (int i = 0; i < 3; i++) {
        std::cout << *it << std::endl;
        it--;
    }
    std::cout << std::endl;

    for (int i = 0; i < 5; i++) {
        std::cout << *it << std::endl;
        it++;
    }
    std::cout << std::endl;

    for (auto cit = tree.cbegin(); cit != tree.cend(); cit++) {
        std::cout << *cit << std::endl;
    }
    std::cout << std::endl;

    for (auto rit = tree.rbegin(); rit != tree.rend(); rit++) {
        std::cout << *rit << std::endl;
    }

    for (auto crit = tree.crbegin(); crit != tree.crend(); crit++) {
        std::cout << *crit << std::endl;
    }
}