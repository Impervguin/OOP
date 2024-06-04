#include "tree.h"
#include <iostream>
#include <vector>


#define GREEN "\033[32m"
#define CYAN "\033[36m"
#define RED "\033[31m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define RESET "\033[0m"

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vector) {
    os << "{";
    auto a = vector.cbegin();
    if (a != vector.cend()) {
        os << *a;
        a++;
    }
    for (; a != vector.cend(); a++) {
        os << ", " << *a;
    }
    os << "}";
    return os;
}

void test_tree_add1() {
    // Обычная вставка элемента
    std::cout << CYAN << "Tree test add 1: " << RESET;
    BSTree<int> tree({2, 62, 13, 56, 12, 23, 15});
    BSTree<int> expected({2, 62, 13, 56, 12, 23, 15, 35});

    int input = 35;

    tree.Add(input);
    if (tree == expected) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
    }
}

void test_tree_add2() {
    // Обычная вставка элемента +=
    std::cout << CYAN << "Tree test add 2: " << RESET;
    BSTree<int> tree({2, 62, 13, 56, 12, 23, 15});
    BSTree<int> expected({2, 62, 13, 56, 12, 23, 15, 35});

    int input = 35;

    tree += input;
    if (tree == expected) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
    }
}

void test_tree_add3() {
    // Обычная вставка элемента, элемент уже есть
    std::cout << CYAN << "Tree test add 3: " << RESET;
    BSTree<int> tree({2, 62, 13, 56, 12, 23, 15});
    BSTree<int> expected({2, 62, 13, 56, 12, 23, 15});

    int input = 15;

    tree.Add(input);
    if (tree == expected) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
    }
}

void test_tree_add4() {
    // Обычная вставка элемента +=, элемент уже есть
    std::cout << CYAN << "Tree test add 4: " << RESET;
    BSTree<int> tree({2, 62, 13, 56, 12, 23, 15});
    BSTree<int> expected({2, 62, 13, 56, 12, 23, 15});

    int input = 15;

    tree += input;
    if (tree == expected) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
    }
}

void test_tree_add5() {
    // Обычная вставка элемента через контейнер без пересечений
    std::cout << CYAN << "Tree test add 5: " << RESET;
    BSTree<int> tree({2, 62, 13, 56, 12, 23, 15});
    BSTree<int> expected({2, 62, 13, 56, 12, 23, 15, 1, 2, 3, 4, 5});

    std::vector<int> input = {1, 2, 3, 4, 5};

    tree.Add(input);
    if (tree == expected) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
    }
}

void test_tree_add6() {
    // Обычная вставка элемента += через контейнер без пересечений
    std::cout << CYAN << "Tree test add 6: " << RESET;
    BSTree<int> tree({2, 62, 13, 56, 12, 23, 15});
    BSTree<int> expected({2, 62, 13, 56, 12, 23, 15, 1, 2, 3, 4, 5});

    std::vector<int> input = {1, 2, 3, 4, 5};

    tree += (input);
    if (tree == expected) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
    }
}

void test_tree_add7() {
    // Обычная вставка элемента через контейнер c пересечениями
    std::cout << CYAN << "Tree test add 7: " << RESET;
    BSTree<int> tree({2, 62, 13, 56, 12, 23, 15});
    BSTree<int> expected({2, 62, 13, 56, 12, 23, 15, 1, 2, 3, 4, 5});

    std::vector<int> input = {1, 2, 3, 4, 5, 23, 12};

    tree.Add(input);
    if (tree == expected) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
    }
}

void test_tree_add8() {
    // Обычная вставка элемента += через контейнер с пересечениями
    std::cout << CYAN << "Tree test add 8: " << RESET;
    BSTree<int> tree({2, 62, 13, 56, 12, 23, 15});
    BSTree<int> expected({2, 62, 13, 56, 12, 23, 15, 1, 2, 3, 4, 5});

    std::vector<int> input = {1, 2, 3, 4, 5, 23, 12};

    tree += (input);
    if (tree == expected) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
    }
}

void test_tree_add9() {
    // Обычная вставка элемента &&
    std::cout << CYAN << "Tree test add 9: " << RESET;
    BSTree<int> tree({2, 62, 13, 56, 12, 23, 15});
    BSTree<int> expected({2, 62, 13, 56, 12, 23, 15, 35});

    int input = 35;

    tree.Add(std::move(input));
    if (tree == expected) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
    }
}

void test_tree_add10() {
    // Обычная вставка элемента += &&
    std::cout << CYAN << "Tree test add 10: " << RESET;
    BSTree<int> tree({2, 62, 13, 56, 12, 23, 15});
    BSTree<int> expected({2, 62, 13, 56, 12, 23, 15, 35});

    int input = 35;

    tree += std::move(input);
    if (tree == expected) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
    }
}

void test_tree_add11() {
    // Перенос дерева
    std::cout << CYAN << "Tree test add 11: " << RESET;
    BSTree<int> tree({2, 62, 13, 56, 12, 23, 15});
    BSTree<int> expected({2, 62, 13, 56, 12, 23, 15, 9, 40, 12});

    BSTree<int> movetree({9, 40, 12});

    tree.Add(std::move(movetree));
    if (tree == expected && movetree.size() == 0) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
        std::cout << "Moved: " << movetree << " Size: " <<movetree.size() << std::endl;
    }
}

void test_tree_add12() {
    // Перенос дерева +=
    std::cout << CYAN << "Tree test add 12: " << RESET;
    BSTree<int> tree({2, 62, 13, 56, 12, 23, 15});
    BSTree<int> expected({2, 62, 13, 56, 12, 23, 15, 9, 40, 12});

    BSTree<int> movetree({9, 40, 12});

    tree += std::move(movetree);
    if (tree == expected && movetree.size() == 0) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
        std::cout << "Moved: " << movetree << " Size: " <<movetree.size() << std::endl;
    }
}


void add_tests() {
    test_tree_add1();
    test_tree_add2();
    test_tree_add3();
    test_tree_add4();
    test_tree_add5();
    test_tree_add6();
    test_tree_add7();
    test_tree_add8();
    test_tree_add9();
    test_tree_add10();
    test_tree_add11();
    test_tree_add12();
    std::cout << std::endl;
}


void test_tree_copy_add1() {
    // Обычная вставка элемента
    std::cout << CYAN << "Tree test copy add 1: " << RESET;
    BSTree<int> tree({2, 62, 13, 56, 12, 23, 15});
    BSTree<int> expected({2, 62, 13, 56, 12, 23, 15, 35});

    int input = 35;

    auto copytree = tree.CopyAdd(input);
    if (copytree == expected) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
        std::cout << "Copied: " << copytree << " Size: " << copytree.size() << std::endl;
    }
}

void test_tree_copy_add2() {
    // Обычная вставка элемента +=
    std::cout << CYAN << "Tree test copy add 2: " << RESET;
    BSTree<int> tree({2, 62, 13, 56, 12, 23, 15});
    BSTree<int> expected({2, 62, 13, 56, 12, 23, 15, 35});

    int input = 35;

    auto copytree = tree + input;
    if (copytree == expected) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
        std::cout << "Copied: " << copytree << " Size: " << copytree.size() << std::endl;
    }
}

void test_tree_copy_add3() {
    // Обычная вставка элемента, элемент уже есть
    std::cout << CYAN << "Tree test copy add 3: " << RESET;
    BSTree<int> tree({2, 62, 13, 56, 12, 23, 15});
    BSTree<int> expected({2, 62, 13, 56, 12, 23, 15});

    int input = 15;

    auto copytree = tree.CopyAdd(input);
    if (copytree == expected) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
        std::cout << "Copied: " << copytree << " Size: " << copytree.size() << std::endl;
    }
}

void test_tree_copy_add4() {
    // Обычная вставка элемента +=, элемент уже есть
    std::cout << CYAN << "Tree test copy add 4: " << RESET;
    BSTree<int> tree({2, 62, 13, 56, 12, 23, 15});
    BSTree<int> expected({2, 62, 13, 56, 12, 23, 15});

    int input = 15;

    auto copytree = tree + input;
    if (copytree == expected) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
        std::cout << "Copied: " << copytree << " Size: " << copytree.size() << std::endl;
    }
}

void test_tree_copy_add5() {
    // Обычная вставка элемента через контейнер без пересечений
    std::cout << CYAN << "Tree test copy add 5: " << RESET;
    BSTree<int> tree({2, 62, 13, 56, 12, 23, 15});
    BSTree<int> expected({2, 62, 13, 56, 12, 23, 15, 1, 2, 3, 4, 5});

    std::vector<int> input = {1, 2, 3, 4, 5};

   auto copytree = tree.CopyAdd(input);
    if (copytree == expected) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
        std::cout << "Copied: " << copytree << " Size: " << copytree.size() << std::endl;
    }
}

void test_tree_copy_add6() {
    // Обычная вставка элемента += через контейнер без пересечений
    std::cout << CYAN << "Tree test copy add 6: " << RESET;
    BSTree<int> tree({2, 62, 13, 56, 12, 23, 15});
    BSTree<int> expected({2, 62, 13, 56, 12, 23, 15, 1, 2, 3, 4, 5});

    std::vector<int> input = {1, 2, 3, 4, 5};

    auto copytree = tree + input;
    if (copytree == expected) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
        std::cout << "Copied: " << copytree << " Size: " << copytree.size() << std::endl;
    }
}

void test_tree_copy_add7() {
    // Обычная вставка элемента через контейнер c пересечениями
    std::cout << CYAN << "Tree test copy add 7: " << RESET;
    BSTree<int> tree({2, 62, 13, 56, 12, 23, 15});
    BSTree<int> expected({2, 62, 13, 56, 12, 23, 15, 1, 2, 3, 4, 5});

    std::vector<int> input = {1, 2, 3, 4, 5, 23, 12};

    auto copytree = tree.CopyAdd(input);
    if (copytree == expected) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
        std::cout << "Copied: " << copytree << " Size: " << copytree.size() << std::endl;
    }
}

void test_tree_copy_add8() {
    // Обычная вставка элемента += через контейнер с пересечениями
    std::cout << CYAN << "Tree test copy add 8: " << RESET;
    BSTree<int> tree({2, 62, 13, 56, 12, 23, 15});
    BSTree<int> expected({2, 62, 13, 56, 12, 23, 15, 1, 2, 3, 4, 5});

    std::vector<int> input = {1, 2, 3, 4, 5, 23, 12};

    auto copytree = tree + input;
    if (copytree == expected) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
        std::cout << "Copied: " << copytree << " Size: " << copytree.size() << std::endl;
    }
}

void test_tree_copy_add9() {
    // Обычная вставка элемента &&
    std::cout << CYAN << "Tree test copy add 9: " << RESET;
    BSTree<int> tree({2, 62, 13, 56, 12, 23, 15});
    BSTree<int> expected({2, 62, 13, 56, 12, 23, 15, 35});

    int input = 35;

    auto copytree = tree.CopyAdd(std::move(input));
    if (copytree == expected) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
        std::cout << "Copied: " << copytree << " Size: " << copytree.size() << std::endl;
    }
}

void test_tree_copy_add10() {
    // Обычная вставка элемента += &&
    std::cout << CYAN << "Tree test copy add 10: " << RESET;
    BSTree<int> tree({2, 62, 13, 56, 12, 23, 15});
    BSTree<int> expected({2, 62, 13, 56, 12, 23, 15, 35});

    int input = 35;

    auto copytree = tree + std::move(input);
    if (copytree == expected) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
        std::cout << "Copied: " << copytree << " Size: " << copytree.size() << std::endl;
    }
}

void test_tree_copy_add11() {
    // Перенос дерева
    std::cout << CYAN << "Tree test copy add 11: " << RESET;
    BSTree<int> tree({2, 62, 13, 56, 12, 23, 15});
    BSTree<int> expected({2, 62, 13, 56, 12, 23, 15, 9, 40, 12});

    BSTree<int> movetree({9, 40, 12});

    auto copytree = tree.CopyAdd(std::move(movetree));
    if (copytree == expected && movetree.size() == 0) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
        std::cout << "Moved: " << movetree << " Size: " <<movetree.size() << std::endl;
    }
}

void test_tree_copy_add12() {
    // Перенос дерева +=
    std::cout << CYAN << "Tree test copy add 12: " << RESET;
    BSTree<int> tree({2, 62, 13, 56, 12, 23, 15});
    BSTree<int> expected({2, 62, 13, 56, 12, 23, 15, 9, 40, 12});

    BSTree<int> movetree({9, 40, 12});

    auto copytree = tree + std::move(movetree);
    if (copytree == expected && movetree.size() == 0) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
        std::cout << "Moved: " << movetree << " Size: " <<movetree.size() << std::endl;
    }
}


void copy_add_tests() {
    test_tree_copy_add1();
    test_tree_copy_add2();
    test_tree_copy_add3();
    test_tree_copy_add4();
    test_tree_copy_add5();
    test_tree_copy_add6();
    test_tree_copy_add7();
    test_tree_copy_add8();
    test_tree_copy_add9();
    test_tree_copy_add10();
    test_tree_copy_add11();
    test_tree_copy_add12();
    std::cout << std::endl;
}


void find_test_1() {
    std::cout << CYAN << "Tree test find 1: " << RESET;
    BSTree<int> tree({2, 62, 13, 56, 12, 23, 15});
    bool expected = false;

    int input = 3;

    auto res = tree.Find(input);

    if (res == expected) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected <<  std::endl;
        std::cout << "Actual: " << res << std::endl;
        std::cout << "Value: " << input << std::endl;
        std::cout << "Tree: " << tree << std::endl;
    }
}

void find_test_2() {
    std::cout << CYAN << "Tree test find 2: " << RESET;
    BSTree<int> tree({2, 62, 13, 56, 12, 23, 15});
    bool expected = true;

    int input = 56;

    auto res = tree.Find(input);

    if (res == expected) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected <<  std::endl;
        std::cout << "Actual: " << res << std::endl;
        std::cout << "Value: " << input << std::endl;
        std::cout << "Tree: " << tree << std::endl;
    }
}

void find_test_3() {
    std::cout << CYAN << "Tree test find 3: " << RESET;
    BSTree<int> tree({2, 62, 13, 56, 12, 23, 15});
    bool expected = true;

    std::vector<int> input{12, 13, 15};

    auto res = tree.Find(input);

    if (res == expected) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected <<  std::endl;
        std::cout << "Actual: " << res << std::endl;
        std::cout << "Value: " << input << std::endl;
        std::cout << "Tree: " << tree << std::endl;
    }
}

void find_test_4() {
    std::cout << CYAN << "Tree test find 4: " << RESET;
    BSTree<int> tree({2, 62, 13, 56, 12, 23, 15});
    bool expected = false;

    std::vector<int> input{12, 13, 15, 14};

    auto res = tree.Find(input);

    if (res == expected) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected <<  std::endl;
        std::cout << "Actual: " << res << std::endl;
        std::cout << "Value: " << input << std::endl;
        std::cout << "Tree: " << tree << std::endl;
    }
}

void  find_test_5() {
    std::cout << CYAN << "Tree test find 5: " << RESET;
    BSTree<int> tree({2, 62, 13, 56, 12, 23, 15});
    bool expected = false;

    std::vector<int> input{1, 3, 5};

    auto res = tree.Find(input);

    if (res == expected) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected <<  std::endl;
        std::cout << "Actual: " << res << std::endl;
        std::cout << "Value: " << input << std::endl;
        std::cout << "Tree: " << tree << std::endl;
    }
}


void find_tests() {
    find_test_1();
    find_test_2();
    find_test_3();
    find_test_4();
    find_test_5();
    std::cout << std::endl;
}


void tree_test_remove1() {
    // Удаление существующего элемента
    std::cout << CYAN << "Tree test remove 1: " << RESET;
    BSTree<int> tree({2, 62, 13, 56, 12, 23, 15, 35});
    BSTree<int> expected({2, 62, 13, 56, 12, 23, 15});

    int input = 35;

    tree.Remove(input);
    if (tree == expected) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
        std::cout << "Value: " << input << std::endl;
    }
}

void tree_test_remove2() {
    // Удаление несуществующего элемента
    std::cout << CYAN << "Tree test remove 2: " << RESET;
    BSTree<int> tree({2, 62, 13, 56, 12, 23, 15});
    BSTree<int> expected({2, 62, 13, 56, 12, 23, 15});

    int input = 35;

    tree.Remove(input);
    if (tree == expected) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
        std::cout << "Value: " << input << std::endl;
    }
}

void tree_test_remove3() {
    // Удаление существующего элемента
    std::cout << CYAN << "Tree test remove 3: " << RESET;
    BSTree<int> tree({2, 62, 13, 56, 12, 23, 15, 35});
    BSTree<int> expected({2, 62, 13, 56, 12, 23, 15});

    int input = 35;

    tree -= (input);
    if (tree == expected) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
        std::cout << "Value: " << input << std::endl;
    }
}

void tree_test_remove4() {
    // Удаление несуществующего элемента
    std::cout << CYAN << "Tree test remove 4: " << RESET;
    BSTree<int> tree({2, 62, 13, 56, 12, 23, 15});
    BSTree<int> expected({2, 62, 13, 56, 12, 23, 15});

    int input = 35;

    tree -= (input);
    if (tree == expected) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
        std::cout << "Value: " << input << std::endl;
    }
}

void tree_test_remove5() {
    // Удаление существующих элементов
    std::cout << CYAN << "Tree test remove 5: " << RESET;
    BSTree<int> tree({2, 62, 13, 56, 12, 23, 15, 35});
    BSTree<int> expected({23, 15});

    std::vector<int> input{2, 62, 13, 56, 12, 35};

    tree.Remove(input);
    if (tree == expected) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
        std::cout << "Value: " << input << std::endl;
    }
}

void tree_test_remove6() {
    // Удаление частично существующих элементов
    std::cout << CYAN << "Tree test remove 6: " << RESET;
    BSTree<int> tree({2, 62, 13, 56, 12, 23, 15, 35});
    BSTree<int> expected({23, 15, 12, 56});

    std::vector<int> input{2, 62, 13, 72, -723, 35};

    tree.Remove(input);
    if (tree == expected) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
        std::cout << "Value: " << input << std::endl;
    }
}

void tree_test_remove7() {
    // Удаление несуществующих элементов
    std::cout << CYAN << "Tree test remove 7: " << RESET;
    BSTree<int> tree({2, 62, 13, 56, 12, 23, 15, 35});
    BSTree<int> expected({2, 62, 13, 56, 12, 23, 15, 35});

    std::vector<int> input{521, 4, -142};

    tree.Remove(input);
    if (tree == expected) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
        std::cout << "Value: " << input << std::endl;
    }
}

void tree_test_remove8() {
    // Удаление существующих элементов
    std::cout << CYAN << "Tree test remove 8: " << RESET;
    BSTree<int> tree({2, 62, 13, 56, 12, 23, 15, 35});
    BSTree<int> expected({23, 15});

    std::vector<int> input{2, 62, 13, 56, 12, 35};

    tree -= input;
    if (tree == expected) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
        std::cout << "Value: " << input << std::endl;
    }
}

void tree_test_remove9() {
    // Удаление частично существующих элементов
    std::cout << CYAN << "Tree test remove 9: " << RESET;
    BSTree<int> tree({2, 62, 13, 56, 12, 23, 15, 35});
    BSTree<int> expected({23, 15, 12, 56});

    std::vector<int> input{2, 62, 13, 72, -723, 35};

    tree -= input;
    if (tree == expected) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
        std::cout << "Value: " << input << std::endl;
    }
}

void tree_test_remove10() {
    // Удаление несуществующих элементов
    std::cout << CYAN << "Tree test remove 10: " << RESET;
    BSTree<int> tree({2, 62, 13, 56, 12, 23, 15, 35});
    BSTree<int> expected({2, 62, 13, 56, 12, 23, 15, 35});

    std::vector<int> input{521, 4, -142};

    tree -= input;
    if (tree == expected) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
        std::cout << "Value: " << input << std::endl;
    }
}


void remove_tests() {
    tree_test_remove1();
    tree_test_remove2();
    tree_test_remove3();
    tree_test_remove4();
    tree_test_remove5();
    tree_test_remove6();
    tree_test_remove7();
    tree_test_remove8();
    tree_test_remove9();
    tree_test_remove10();
    std::cout << std::endl;
}

void tree_test_copy_remove1() {
    // Удаление существующего элемента
    std::cout << CYAN << "Tree test copy remove 1: " << RESET;
    BSTree<int> tree({2, 62, 13, 56, 12, 23, 15, 35});
    BSTree<int> expected({2, 62, 13, 56, 12, 23, 15});

    int input = 35;
    BSTree<int> source_tree(tree);
    auto copytree = tree.CopyRemove(input);
    if (copytree == expected && tree == source_tree) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
        std::cout << "Value: " << input << std::endl;
    }
}

void tree_test_copy_remove2() {
    // Удаление несуществующего элемента
    std::cout << CYAN << "Tree test copy remove 2: " << RESET;
    BSTree<int> tree({2, 62, 13, 56, 12, 23, 15});
    BSTree<int> expected({2, 62, 13, 56, 12, 23, 15});

    int input = 35;

    BSTree<int> source_tree(tree);
    auto copytree = tree.CopyRemove(input);
    if (copytree == expected && tree == source_tree) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
        std::cout << "Value: " << input << std::endl;
    }
}

void tree_test_copy_remove3() {
    // Удаление существующего элемента
    std::cout << CYAN << "Tree test copy remove 3: " << RESET;
    BSTree<int> tree({2, 62, 13, 56, 12, 23, 15, 35});
    BSTree<int> expected({2, 62, 13, 56, 12, 23, 15});

    int input = 35;

    BSTree<int> source_tree(tree);
    auto copytree = tree - (input);
    if (copytree == expected && tree == source_tree) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
        std::cout << "Value: " << input << std::endl;
    }
}

void tree_test_copy_remove4() {
    // Удаление несуществующего элемента
    std::cout << CYAN << "Tree test copy remove 4: " << RESET;
    BSTree<int> tree({2, 62, 13, 56, 12, 23, 15});
    BSTree<int> expected({2, 62, 13, 56, 12, 23, 15});

    int input = 35;

    BSTree<int> source_tree(tree);
    auto copytree = tree - input;
    if (copytree == expected && tree == source_tree) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
        std::cout << "Value: " << input << std::endl;
    }
}

void tree_test_copy_remove5() {
    // Удаление существующих элементов
    std::cout << CYAN << "Tree test copy remove 5: " << RESET;
    BSTree<int> tree({2, 62, 13, 56, 12, 23, 15, 35});
    BSTree<int> expected({23, 15});

    std::vector<int> input{2, 62, 13, 56, 12, 35};

    BSTree<int> source_tree(tree);
    auto copytree = tree.CopyRemove(input);
    if (copytree == expected && tree == source_tree) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
        std::cout << "Value: " << input << std::endl;
    }
}

void tree_test_copy_remove6() {
    // Удаление частично существующих элементов
    std::cout << CYAN << "Tree test copy remove 6: " << RESET;
    BSTree<int> tree({2, 62, 13, 56, 12, 23, 15, 35});
    BSTree<int> expected({23, 15, 12, 56});

    std::vector<int> input{2, 62, 13, 72, -723, 35};

    BSTree<int> source_tree(tree);
    auto copytree = tree.CopyRemove(input);
    if (copytree == expected && tree == source_tree) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
        std::cout << "Value: " << input << std::endl;
    }
}

void tree_test_copy_remove7() {
    // Удаление несуществующих элементов
    std::cout << CYAN << "Tree test copy remove 7: " << RESET;
    BSTree<int> tree({2, 62, 13, 56, 12, 23, 15, 35});
    BSTree<int> expected({2, 62, 13, 56, 12, 23, 15, 35});

    std::vector<int> input{521, 4, -142};

    BSTree<int> source_tree(tree);
    auto copytree = tree.CopyRemove(input);
    if (copytree == expected && tree == source_tree) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
        std::cout << "Value: " << input << std::endl;
    }
}

void tree_test_copy_remove8() {
    // Удаление существующих элементов
    std::cout << CYAN << "Tree test copy remove 8: " << RESET;
    BSTree<int> tree({2, 62, 13, 56, 12, 23, 15, 35});
    BSTree<int> expected({23, 15});

    std::vector<int> input{2, 62, 13, 56, 12, 35};

    BSTree<int> source_tree(tree);
    auto copytree = tree - (input);
    if (copytree == expected && tree == source_tree) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
        std::cout << "Value: " << input << std::endl;
    }
}

void tree_test_copy_remove9() {
    // Удаление частично существующих элементов
    std::cout << CYAN << "Tree test copy remove 9: " << RESET;
    BSTree<int> tree({2, 62, 13, 56, 12, 23, 15, 35});
    BSTree<int> expected({23, 15, 12, 56});

    std::vector<int> input{2, 62, 13, 72, -723, 35};

    BSTree<int> source_tree(tree);
    auto copytree = tree - (input);
    if (copytree == expected && tree == source_tree) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
        std::cout << "Value: " << input << std::endl;
    }
}

void tree_test_copy_remove10() {
    // Удаление несуществующих элементов
    std::cout << CYAN << "Tree test copy remove 10: " << RESET;
    BSTree<int> tree({2, 62, 13, 56, 12, 23, 15, 35});
    BSTree<int> expected({2, 62, 13, 56, 12, 23, 15, 35});

    std::vector<int> input{521, 4, -142};

    BSTree<int> source_tree(tree);
    auto copytree = tree - (input);
    if (copytree == expected && tree == source_tree) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
        std::cout << "Value: " << input << std::endl;
    }
}

void copy_remove_tests() {
    tree_test_copy_remove1();
    tree_test_copy_remove2();
    tree_test_copy_remove3();
    tree_test_copy_remove4();
    tree_test_copy_remove5();
    tree_test_copy_remove6();
    tree_test_copy_remove7();
    tree_test_copy_remove8();
    tree_test_copy_remove9();
    tree_test_copy_remove10();
    std::cout << std::endl;
}


void tree_test_intersection1() {
    // Пересечение с пустым вектором
    std::cout << CYAN << "Tree test intersection 1: " << RESET;
    BSTree<int> tree({52, 214, 1, 24, -12, -52, -34});
    BSTree<int> expected({});

    std::vector<int> input{};

    tree.Intersection(input);
    if (tree == expected) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
        std::cout << "Value: " << input << std::endl;
    }
}

void tree_test_intersection2() {
    // Пересечение с пустым вектором
    std::cout << CYAN << "Tree test intersection 2: " << RESET;
    BSTree<int> tree({52, 214, 1, 24, -12, -52, -34});
    BSTree<int> expected({});

    std::vector<int> input{};

    tree &= input;
    if (tree == expected) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
        std::cout << "Value: " << input << std::endl;
    }
}

void tree_test_intersection3() {
    // Пересечение с совпадающим вектором
    std::cout << CYAN << "Tree test intersection 3: " << RESET;
    BSTree<int> tree({52, 214, 1, 24, -12, -52, -34});
    BSTree<int> expected({52, 214, 1, 24, -12, -52, -34});

    std::vector<int> input{52, 214, 1, 24, -12, -52, -34};

    tree.Intersection(input);
    if (tree == expected) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
        std::cout << "Value: " << input << std::endl;
    }
}

void tree_test_intersection4() {
    // Пересечение с совпадающим вектором
    std::cout << CYAN << "Tree test intersection 4: " << RESET;
    BSTree<int> tree({52, 214, 1, 24, -12, -52, -34});
    BSTree<int> expected({52, 214, 1, 24, -12, -52, -34});

    std::vector<int> input{52, 214, 1, 24, -12, -52, -34};

    tree &= (input);
    if (tree == expected) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
        std::cout << "Value: " << input << std::endl;
    }
}

void tree_test_intersection5() {
    // Пересечение с большим вектором
    std::cout << CYAN << "Tree test intersection 5: " << RESET;
    BSTree<int> tree({52, 214, 1, 24, -12, -52, -34});
    BSTree<int> expected({52, 214, 1, 24, -12, -52, -34});

    std::vector<int> input{52, 214, 1, 24, -12, -52, -34, 102, 42, 12, -42, 282};

    tree.Intersection(input);
    if (tree == expected) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
        std::cout << "Value: " << input << std::endl;
    }
}

void tree_test_intersection6() {
    // Пересечение с большим вектором
    std::cout << CYAN << "Tree test intersection 6: " << RESET;
    BSTree<int> tree({52, 214, 1, 24, -12, -52, -34});
    BSTree<int> expected({52, 214, 1, 24, -12, -52, -34});

    std::vector<int> input{52, 214, 1, 24, -12, -52, -34, 102, 42, 12, -42, 282};

    tree &= (input);
    if (tree == expected) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
        std::cout << "Value: " << input << std::endl;
    }
}

void tree_test_intersection7() {
    // Частичное пересечение c вектором
    std::cout << CYAN << "Tree test intersection 7: " << RESET;
    BSTree<int> tree({52, 214, 1, 24, -12, -52, -34});
    BSTree<int> expected({214, -12, -34});

    std::vector<int> input{214, -12, 5234, 12, 54, -34, 888};

    tree.Intersection(input);
    if (tree == expected) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
        std::cout << "Value: " << input << std::endl;
    }
}

void tree_test_intersection8() {
    // Частичное пересечение c вектором
    std::cout << CYAN << "Tree test intersection 8: " << RESET;
    BSTree<int> tree({52, 214, 1, 24, -12, -52, -34});
    BSTree<int> expected({214, -12, -34});

    std::vector<int> input{214, -12, 5234, 12, 54, -34, 888};

    tree &= input;
    if (tree == expected) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
        std::cout << "Value: " << input << std::endl;
    }
}

void intersection_tests() {
    tree_test_intersection1();
    tree_test_intersection2();
    tree_test_intersection3();
    tree_test_intersection4();
    tree_test_intersection5();
    tree_test_intersection6();
    tree_test_intersection7();
    tree_test_intersection8();
    std::cout << std::endl;
}



void tree_test_copy_intersection1() {
    // Пересечение с пустым вектором
    std::cout << CYAN << "Tree test copy intersection 1: " << RESET;
    BSTree<int> tree({52, 214, 1, 24, -12, -52, -34});
    BSTree<int> source_tree(tree);
    BSTree<int> expected({});

    std::vector<int> input{};

    auto copytree = tree.IntersectionCopy(input);
    if (copytree == expected && source_tree == tree) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
        std::cout << "Value: " << input << std::endl;
    }
}

void tree_test_copy_intersection2() {
    // Пересечение с пустым вектором
    std::cout << CYAN << "Tree test copy intersection 2: " << RESET;
    BSTree<int> tree({52, 214, 1, 24, -12, -52, -34});
    BSTree<int> source_tree(tree);
    BSTree<int> expected({});

    std::vector<int> input{};

    auto copytree = tree & (input);
    if (copytree == expected && source_tree == tree) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
        std::cout << "Value: " << input << std::endl;
    }
}

void tree_test_copy_intersection3() {
    // Пересечение с совпадающим вектором
    std::cout << CYAN << "Tree test copy intersection 3: " << RESET;
    BSTree<int> tree({52, 214, 1, 24, -12, -52, -34});
    BSTree<int> source_tree(tree);
    BSTree<int> expected({52, 214, 1, 24, -12, -52, -34});

    std::vector<int> input{52, 214, 1, 24, -12, -52, -34};

    auto copytree = tree.IntersectionCopy(input);
    if (copytree == expected && source_tree == tree) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
        std::cout << "Value: " << input << std::endl;
    }
}

void tree_test_copy_intersection4() {
    // Пересечение с совпадающим вектором
    std::cout << CYAN << "Tree test copy intersection 4: " << RESET;
    BSTree<int> tree({52, 214, 1, 24, -12, -52, -34});
    BSTree<int> source_tree(tree);
    BSTree<int> expected({52, 214, 1, 24, -12, -52, -34});

    std::vector<int> input{52, 214, 1, 24, -12, -52, -34};

    auto copytree = tree.IntersectionCopy(input);
    if (copytree == expected && source_tree == tree) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
        std::cout << "Value: " << input << std::endl;
    }
}

void tree_test_copy_intersection5() {
    // Пересечение с большим вектором
    std::cout << CYAN << "Tree test copy intersection 5: " << RESET;
    BSTree<int> tree({52, 214, 1, 24, -12, -52, -34});
    BSTree<int> source_tree(tree);
    BSTree<int> expected({52, 214, 1, 24, -12, -52, -34});

    std::vector<int> input{52, 214, 1, 24, -12, -52, -34, 102, 42, 12, -42, 282};

    auto copytree = tree.IntersectionCopy(input);
    if (copytree == expected && source_tree == tree) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
        std::cout << "Value: " << input << std::endl;
    }
}

void tree_test_copy_intersection6() {
    // Пересечение с большим вектором
    std::cout << CYAN << "Tree test copy intersection 6: " << RESET;
    BSTree<int> tree({52, 214, 1, 24, -12, -52, -34});
    BSTree<int> source_tree(tree);
    BSTree<int> expected({52, 214, 1, 24, -12, -52, -34});

    std::vector<int> input{52, 214, 1, 24, -12, -52, -34, 102, 42, 12, -42, 282};

    auto copytree = tree & (input);
    if (copytree == expected && source_tree == tree) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
        std::cout << "Value: " << input << std::endl;
    }
}

void tree_test_copy_intersection7() {
    // Частичное пересечение c вектором
    std::cout << CYAN << "Tree test copy intersection 7: " << RESET;
    BSTree<int> tree({52, 214, 1, 24, -12, -52, -34});
    BSTree<int> source_tree(tree);
    BSTree<int> expected({214, -12, -34});

    std::vector<int> input{214, -12, 5234, 12, 54, -34, 888};

    auto copytree = tree & (input);
    if (copytree == expected && source_tree == tree) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
        std::cout << "Value: " << input << std::endl;
    }
}

void tree_test_copy_intersection8() {
    // Частичное пересечение c вектором
    std::cout << CYAN << "Tree test copy intersection 8: " << RESET;
    BSTree<int> tree({52, 214, 1, 24, -12, -52, -34});
    BSTree<int> source_tree(tree);
    BSTree<int> expected({214, -12, -34});

    std::vector<int> input{214, -12, 5234, 12, 54, -34, 888};
    
    auto copytree = tree & (input);
    if (copytree == expected && source_tree == tree) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
        std::cout << "Value: " << input << std::endl;
    }
}

void intersection_copy_tests() {
    tree_test_copy_intersection1();
    tree_test_copy_intersection2();
    tree_test_copy_intersection3();
    tree_test_copy_intersection4();
    tree_test_copy_intersection5();
    tree_test_copy_intersection6();
    tree_test_copy_intersection7();
    tree_test_copy_intersection8();
    std::cout << std::endl;
}

void tree_test_symmetric1() {
    std::cout << CYAN << "Tree test symmetric 1: " << RESET;
    BSTree<int> tree({52, 214, 1, 24, -12, -52, -34});
    BSTree<int> expected({52, 214, 1, 24, -12, -52, -34});

    std::vector<int> input{};

    tree.SymmetricDifference(input);
    if (tree == expected) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
        std::cout << "Value: " << input << std::endl;
    }
}

void tree_test_symmetric2() {
    std::cout << CYAN << "Tree test symmetric 2: " << RESET;
    BSTree<int> tree({52, 214, 1, 24, -12, -52, -34});
    BSTree<int> expected({});

    std::vector<int> input{52, 214, 1, 24, -12, -52, -34};

    tree.SymmetricDifference(input);
    if (tree == expected) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
        std::cout << "Value: " << input << std::endl;
    }
}


void tree_test_symmetric3() {
    std::cout << CYAN << "Tree test symmetric 3: " << RESET;
    BSTree<int> tree({214, 1, 24, -12, -52, -34});
    BSTree<int> expected({24, 52});

    std::vector<int> input{52, 214, 1, -12, -52, -34};

    tree.SymmetricDifference(input);
    if (tree == expected) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
        std::cout << "Value: " << input << std::endl;
    }
}

void tree_test_symmetric4() {
    std::cout << CYAN << "Tree test symmetric 4: " << RESET;
    BSTree<int> tree({214, 1, 24, -12, -52, -34});
    BSTree<int> expected({2, 3, 4, 5});

    std::vector<int> input{214, 1, -12, -52, -34, 24, 2, 3, 4, 5};

    tree ^= (input);
    if (tree == expected) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
        std::cout << "Value: " << input << std::endl;
    }
}



void tree_test_symmetric5() {
    std::cout << CYAN << "Tree test symmetric 5: " << RESET;
    BSTree<int> tree({52, 214, 1, 24, -12, -52, -34});
    BSTree<int> expected({52, 214, 1, 24, -12, -52, -34});

    std::vector<int> input{};

    tree.SymmetricDifference(input);
    if (tree == expected) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
        std::cout << "Value: " << input << std::endl;
    }
}

void tree_test_symmetric6() {
    std::cout << CYAN << "Tree test symmetric 6: " << RESET;
    BSTree<int> tree({52, 214, 1, 24, -12, -52, -34});
    BSTree<int> expected({});

    std::vector<int> input{52, 214, 1, 24, -12, -52, -34};

    tree ^= (input);
    if (tree == expected) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
        std::cout << "Value: " << input << std::endl;
    }
}


void tree_test_symmetric7() {
    std::cout << CYAN << "Tree test symmetric 7: " << RESET;
    BSTree<int> tree({214, 1, 24, -12, -52, -34});
    BSTree<int> expected({24, 52});

    std::vector<int> input{52, 214, 1, -12, -52, -34};

    tree ^= (input);
    if (tree == expected) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
        std::cout << "Value: " << input << std::endl;
    }
}

void tree_test_symmetric8() {
    std::cout << CYAN << "Tree test symmetric 8: " << RESET;
    BSTree<int> tree({214, 1, 24, -12, -52, -34});
    BSTree<int> expected({2, 3, 4, 5});

    std::vector<int> input{214, 1, -12, -52, -34, 24, 2, 3, 4, 5};

    tree ^= (input);
    if (tree == expected) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
        std::cout << "Value: " << input << std::endl;
    }
}

void symmetric_tests() {
    tree_test_symmetric1(); 
    tree_test_symmetric2();
    tree_test_symmetric3();
    tree_test_symmetric4();
    tree_test_symmetric5();
    tree_test_symmetric6();
    tree_test_symmetric7();
    tree_test_symmetric8();

    std::cout << std::endl;

}


void tree_test_copy_symmetric1() {
    std::cout << CYAN << "Tree test copy symmetric 1: " << RESET;
    BSTree<int> tree({52, 214, 1, 24, -12, -52, -34});
    BSTree<int> source(tree);
    BSTree<int> expected({52, 214, 1, 24, -12, -52, -34});

    std::vector<int> input{};

    auto copytree = tree.SymmetricDifferenceCopy(input);
    if (copytree == expected && source == tree) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
        std::cout << "Value: " << input << std::endl;
    }
}

void tree_test_copy_symmetric2() {
    std::cout << CYAN << "Tree test copy symmetric 2: " << RESET;
    BSTree<int> tree({52, 214, 1, 24, -12, -52, -34});
    BSTree<int> source(tree);
    BSTree<int> expected({});

    std::vector<int> input{52, 214, 1, 24, -12, -52, -34};

    auto copytree = tree.SymmetricDifferenceCopy(input);
    if (copytree == expected && source == tree) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
        std::cout << "Value: " << input << std::endl;
    }
}


void tree_test_copy_symmetric3() {
    std::cout << CYAN << "Tree test copy symmetric 3: " << RESET;
    BSTree<int> tree({214, 1, 24, -12, -52, -34});
    BSTree<int> source(tree);
    BSTree<int> expected({24, 52});

    std::vector<int> input{52, 214, 1, -12, -52, -34};

    auto copytree = tree.SymmetricDifferenceCopy(input);
    if (copytree == expected && source == tree) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
        std::cout << "Value: " << input << std::endl;
    }
}

void tree_test_copy_symmetric4() {
    std::cout << CYAN << "Tree test copy symmetric 4: " << RESET;
    BSTree<int> tree({214, 1, 24, -12, -52, -34});
    BSTree<int> source(tree);
    BSTree<int> expected({2, 3, 4, 5});

    std::vector<int> input{214, 1, -12, -52, -34, 24, 2, 3, 4, 5};

    auto copytree = tree.SymmetricDifferenceCopy(input);
    if (copytree == expected && source == tree) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
        std::cout << "Value: " << input << std::endl;
    }
}



void tree_test_copy_symmetric5() {
    std::cout << CYAN << "Tree test copy symmetric 5: " << RESET;
    BSTree<int> tree({52, 214, 1, 24, -12, -52, -34});
    BSTree<int> source(tree);
    BSTree<int> expected({52, 214, 1, 24, -12, -52, -34});

    std::vector<int> input{};

    auto copytree = tree ^ (input);
    if (copytree == expected && source == tree) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
        std::cout << "Value: " << input << std::endl;
    }
}

void tree_test_copy_symmetric6() {
    std::cout << CYAN << "Tree test copy symmetric 6: " << RESET;
    BSTree<int> tree({52, 214, 1, 24, -12, -52, -34});
    BSTree<int> source(tree);
    BSTree<int> expected({});

    std::vector<int> input{52, 214, 1, 24, -12, -52, -34};

    auto copytree = tree ^ (input);
    if (copytree == expected && source == tree) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
        std::cout << "Value: " << input << std::endl;
    }
}


void tree_test_copy_symmetric7() {
    std::cout << CYAN << "Tree test copy symmetric 7: " << RESET;
    BSTree<int> tree({214, 1, 24, -12, -52, -34});
    BSTree<int> source(tree);
    BSTree<int> expected({24, 52});

    std::vector<int> input{52, 214, 1, -12, -52, -34};

    auto copytree = tree ^ (input);
    if (copytree == expected && source == tree) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
        std::cout << "Value: " << input << std::endl;
    }
}

void tree_test_copy_symmetric8() {
    std::cout << CYAN << "Tree test copy symmetric 8: " << RESET;
    BSTree<int> tree({214, 1, 24, -12, -52, -34});
    BSTree<int> source(tree);
    BSTree<int> expected({2, 3, 4, 5});

    std::vector<int> input{214, 1, -12, -52, -34, 24, 2, 3, 4, 5};

    auto copytree = tree ^ (input);
    if (copytree == expected && source == tree) {
        std::cout << GREEN << "OK" << RESET << std::endl;
    } else {
        std::cout << RED << "FAIL" << RESET << std::endl;
        std::cout << "Expected: " << expected << " Size: " << expected.size() <<  std::endl;
        std::cout << "Actual: " << tree << " Size: " << tree.size() << std::endl;
        std::cout << "Value: " << input << std::endl;
    }
}

void symmetric_copy_test() {
    tree_test_copy_symmetric1();
    tree_test_copy_symmetric2();
    tree_test_copy_symmetric3();
    tree_test_copy_symmetric4();
    tree_test_copy_symmetric5();
    tree_test_copy_symmetric6();
    tree_test_copy_symmetric7();
    tree_test_copy_symmetric8();

    std::cout << std::endl;
}

int main() {
    add_tests();
    copy_add_tests();
    find_tests();
    remove_tests();
    copy_remove_tests();
    intersection_tests();
    intersection_copy_tests();
    symmetric_tests();
    symmetric_copy_test();
    return 0;
}