#include "listnode.hpp"
#include "listiterator.hpp"
#include "constlistiterator.hpp"
#include "list.hpp"
#include <iostream>
#include <vector>
#include <string>


int main(void) {
    {
        List<int> *lst = new List<int>(3, 5);
        std::cout << *lst << std::endl;
        std::vector<int> vec{1, 2, 3, 4};
        lst->PushFront(vec);
        // delete lst;
        std::cout << *lst << std::endl;
        // std::cout << *lst << std::endl;
    }
    // std::shared_ptr<int> a = nullptr;
    // {
    //     auto nde = List<int>::ListNode::CreateNode(5, nullptr);
    //     auto nde2 = List<int>::ListNode::CreateNode(6, nullptr);
    //     nde->SetNext(nde2);
    //     a = nde2->GetData();
    //     std::cout << *nde->GetData() << std::endl;
    // }
    // int &b = *a;
    // std::cout << a.use_count() << std::endl;

    return 0;
}