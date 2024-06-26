// #include "listnode.hpp"
// #include "listiterator.hpp"
// #include "constlistiterator.hpp"
// #include "baselistiterator.hpp"
// #include "list.hpp"
#include "list.h"
#include <iostream>
#include <vector>
#include <string>

#define INFO_COLOR "\033[36m"
#define RESET_COLOR "\033[0m"

class NotCopyableInt
{
    public:
    int value;
    NotCopyableInt(int value) : value(value) {}
    NotCopyableInt(const NotCopyableInt& other) = delete;
    NotCopyableInt& operator=(const NotCopyableInt& other) = delete;
    ~NotCopyableInt() = default;

    bool operator==(const NotCopyableInt& other) {return value == other.value;};
    bool operator>(const NotCopyableInt& other) {return value > other.value;};
    bool operator<(const NotCopyableInt& other) {return value < other.value;};
    bool operator>=(const NotCopyableInt& other) {return value >= other.value;};
    bool operator<=(const NotCopyableInt& other) {return value <= other.value;};
    bool operator!=(const NotCopyableInt& other) {return value!= other.value;};

};

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

template <typename T>
void IterFunc(T& val) {
    std::cout << "Bad!" << std::endl;
}

template <std::input_iterator T>
void IterFunc(T& val) {
    std::cout << "Good!" <<std::endl;
}



int main(void) 
{
    // Initialization testing
    List<int> InitList;
    std::cout << INFO_COLOR << "Init1:" << RESET_COLOR << "Пустая инициализация: " << List<int>() << std::endl;
    std::cout << INFO_COLOR << "Init2:" << RESET_COLOR << "Инициализация через initializer_list: " << List<int>{7, 8, 9} << std::endl;
    std::cout << INFO_COLOR << "Init3:" << RESET_COLOR << "Инициализация с указанием размера и константы: " << List<int>(5, 20) << std::endl;
    List<int> initListFrom{1, 2, 3, 4, 5, 6, 7};
    List<int> initListTo(initListFrom.begin() + 1, initListFrom.begin() + 5);
    std::cout << INFO_COLOR << "Init4:" << RESET_COLOR << "Инициализация через итератор по " << initListFrom << ": " << initListTo << std::endl;
    std::cout << INFO_COLOR << "Init5:" << RESET_COLOR << "Копирование " << initListTo << ": " << List<int>(initListTo) << ". Исходный список: " << initListTo << std::endl;
    std::cout << INFO_COLOR << "Init5:" << RESET_COLOR << "Перенос " << initListTo << ": " << List<int>(std::move(initListTo)) << ". Исходный список: " << initListTo << std::endl;

    List<int> List1{0, 2, 42, -2, 0, -2};
    std::vector<double> Vector1{0, 2.5, 4.2, -2.7, 0, 2};
    std::cout << INFO_COLOR << "Init6:" << RESET_COLOR << "Инициализация через вектор double " << Vector1 << ": " << List<int>(Vector1) << std::endl;
    std::cout << INFO_COLOR << "Init7:" << RESET_COLOR << "Инициализация списка bool через список int " << List1 << ": " << List<bool>(List1) << std::endl;
    std::cout << INFO_COLOR << "Init8:" << RESET_COLOR << "Инициализация списка bool через итератор по вектору double" << Vector1 << ": " << List<bool>(Vector1.begin(), Vector1.end()) << std::endl;
    std::cout << INFO_COLOR << "Init8:" << RESET_COLOR << "Инициализация списка bool через константный итератор по вектору double" << Vector1 << ": " << List<bool>(Vector1.cbegin(), Vector1.cend()) << std::endl;
    std::cout << INFO_COLOR << "Init9:" << RESET_COLOR << "Инициализация через initializer_list double: " << List<int>{2.5, 1.2, 5.6} << std::endl;
    std::cout << INFO_COLOR << "Init10:" << RESET_COLOR << "Инициализация с указанием размера и константы double: " << List<int>(5, 2.6) << std::endl; 
    std::cout << INFO_COLOR << "Init11:" << RESET_COLOR << "Инициализация через вектор double " << Vector1 << "переносом: " << List<int>(std::move(Vector1)) << std::endl;
    List1 = {1.2, 2.2, 3.2, 4.2, 5.2, 7.2};
    std::cout << INFO_COLOR << "Init12:" << RESET_COLOR << "Инициализация через = initializer_list double: " << List1 <<  std::endl;
    std::cout << std::endl;

    // List<NotCopyableInt> a;

    std::cout << INFO_COLOR << "Проверка ListIterator:" << RESET_COLOR;
    auto iter = InitList.begin();
    IterFunc(iter);
    auto citer = InitList.cbegin();
    std::cout << INFO_COLOR << "Проверка ConstListIterator:" << RESET_COLOR;
    IterFunc(citer);

    std::cout << std::endl;

    // Iterator testing

    List<int> ItList{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    std::cout << INFO_COLOR << "Iter1:" << RESET_COLOR << "Итератор по " << ItList << ": ";
    for (auto it = ItList.begin(); it != ItList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << INFO_COLOR << "Iter2:" << RESET_COLOR << "Константный итератор по " << ItList << ": ";
    for (auto it = ItList.cbegin(); it != ItList.cend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << INFO_COLOR << "Iter3:" << RESET_COLOR << "Изменение значений на +1 по " << ItList << ": ";
    for (auto it = ItList.begin(); it != ItList.end(); ++it) {
        (*it)++;
    }
    std::cout << ItList << std::endl;

    ItList = List<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    std::cout << INFO_COLOR << "Iter4:" << RESET_COLOR << "Изменение типа итератора на конст" << ItList << ": ";
    for (ConstListIterator<int> it = ItList.begin(); it != ItList.cend(); ++it) {
        std::cout << *it << " ";
    }

    std::cout << std::endl;

    // PushBack testing
    List<int> listPushBack1{1, 2, 3};
    int data1 = 4;
    auto listPushBack2(listPushBack1);
    listPushBack2.PushBack(data1);
    std::cout << INFO_COLOR << "PushBack1: " << RESET_COLOR << "Список: " << listPushBack1 << " После вставки элемента " << data1 << ": " << listPushBack2 << std::endl;

    listPushBack1 = List<int>{1, 2, 3, 4, 5};
    listPushBack2 = List<int>{1, 2, 3};
    auto listPushBack3(listPushBack1);
    listPushBack3.PushBack(listPushBack2);
    std::cout << INFO_COLOR << "PushBack2: " << RESET_COLOR << "Список: " << listPushBack1 << " После вставки списка " << listPushBack2 << ": " << listPushBack3 << std::endl;

    listPushBack1 = List<int>{1, 2, 3, 4, 5};
    listPushBack2 = List<int>{1, 2, 3};
    listPushBack3 = listPushBack1;
    std::cout << INFO_COLOR << "PushBack3: " << RESET_COLOR << "Список: " << listPushBack1 << " После переноса списка " << listPushBack2 << ": ";
    listPushBack3.PushBack(std::move(listPushBack2));
    std::cout << listPushBack3 <<". Переносимый список: " << listPushBack2 << std::endl;

    listPushBack1 = List<int>{1, 2, 3, 4, 5};
    std::vector<double> vectorPush{2.3, 6.2};
    std::cout << INFO_COLOR << "PushBack4: " << RESET_COLOR << "Список: " << listPushBack1 << " После вставки вектора double: " << vectorPush << ": ";
    listPushBack1.PushBack(vectorPush);
    std::cout << listPushBack1 << std::endl;

    std::cout << std::endl;


    // PushFront testing
    List<int> listPushFront1{1, 2, 3};
    data1 = 4;
    auto listPushFront2(listPushFront1);
    listPushFront2.PushFront(data1);
    std::cout << INFO_COLOR << "PushFront1: " << RESET_COLOR << "Список: " << listPushFront1 << " После вставки элемента " << data1 << ": " << listPushFront2 << std::endl;

    listPushFront1 = List<int>{1, 2, 3, 4, 5};
    listPushFront2 = List<int>{1, 2, 3};
    auto listPushFront3(listPushFront1);
    listPushFront3.PushFront(listPushFront2);
    std::cout << INFO_COLOR << "PushFront2: " << RESET_COLOR << "Список: " << listPushFront1 << " После вставки списка " << listPushFront2 << ": " << listPushFront3 << std::endl;

    listPushFront1 = List<int>{1, 2, 3, 4, 5};
    listPushFront2 = List<int>{1, 2, 3};
    listPushFront3 = listPushFront1;
    std::cout << INFO_COLOR << "PushFront3: " << RESET_COLOR << "Список: " << listPushFront1 << " После переноса списка " << listPushFront2 << ": ";
    listPushFront3.PushFront(std::move(listPushFront2));
    std::cout << listPushFront3 <<". Переносимый список: " << listPushFront2 << std::endl;

    listPushFront1 = List<int>{1, 2, 3, 4, 5};
    std::cout << INFO_COLOR << "PushFront4: " << RESET_COLOR << "Список: " << listPushFront1 << " После вставки вектора double: " << vectorPush << ": ";
    listPushFront1.PushFront(vectorPush);
    std::cout << listPushFront1 << std::endl;

    std::cout << std::endl;

    // Pops testing
    List<int> listPops{5, 9, 6, 2, 3, 7, 1};
    std::cout << INFO_COLOR << "Pops1: " << RESET_COLOR << "Список: " << listPops << ". Полученный элемент при PopFront: " << listPops.PopFront() << ". Список после: " << listPops << "." << std::endl;
    std::cout << INFO_COLOR << "Pops2: " << RESET_COLOR << "Список: " << listPops << ". Полученный элемент при PopBack: " << listPops.PopBack() << ". Список после: " << listPops << "." << std::endl;
    
    
    listPops = List<int>{5, 9, 6, 2, 3, 7, 1};
    size_t popStart = 1, popEnd = 4;
    std::cout << INFO_COLOR << "Pops5: " << RESET_COLOR << "Список: " << listPops << ". Полученный список при Pop [begin() + " << popStart << "; begin() + " << popEnd << "]: ";
    auto listResPops = listPops.Pop(listPops.begin() + popStart, listPops.begin() + popEnd);
    std::cout << listResPops << ". Список после: " << listPops << "." << std::endl;

    listPops = List<int>{5, 9, 6, 2, 3, 7, 1};
    popStart = 0, popEnd = 4;
    std::cout << INFO_COLOR << "Pops6: " << RESET_COLOR << "Список: " << listPops << ". Полученный список при Pop [begin() + " << popStart << "; begin() + " << popEnd << "]: ";
    listResPops = listPops.Pop(listPops.begin() + popStart, listPops.begin() + popEnd);
    std::cout << listResPops << ". Список после: " << listPops << "." << std::endl;

    listPops = List<int>{5, 9, 6, 2, 3, 7, 1};
    popStart = 1, popEnd = 6;
    std::cout << INFO_COLOR << "Pops7: " << RESET_COLOR << "Список: " << listPops << ". Полученный список при Pop [begin() + " << popStart << "; begin() + " << popEnd << "]: ";
    listResPops = listPops.Pop(listPops.begin() + popStart, listPops.begin() + popEnd);
    std::cout << listResPops << ". Список после: " << listPops << "." << std::endl;

    listPops = List<int>{5, 9, 6, 2, 3, 7, 1};
    popStart = 0, popEnd = 6;
    std::cout << INFO_COLOR << "Pops8: " << RESET_COLOR << "Список: " << listPops << ". Полученный список при Pop [begin() + " << popStart << "; begin() + " << popEnd << "]: ";
    listResPops = listPops.Pop(listPops.begin() + popStart, listPops.begin() + popEnd);
    std::cout << listResPops << ". Список после: " << listPops << "." << std::endl;

    std::cout << std::endl;

    // Removes testing

    List<int> listRemoves = List<int>{5, 9, 6, 2, 3, 7, 1};
    size_t removeStart = 1, removeEnd = 4;
    std::cout << INFO_COLOR << "Removes3: " << RESET_COLOR << "Список: " << listRemoves << ". Полученный список при Remove [begin() + " << removeStart << "; begin() + " << removeEnd << "]: ";
    listRemoves.Remove(listRemoves.begin() + removeStart, listRemoves.begin() + removeEnd);
    std::cout << listRemoves << "." << std::endl;

    listRemoves = List<int>{5, 9, 6, 2, 3, 7, 1};
    removeStart = 0, removeEnd = 4;
    std::cout << INFO_COLOR << "Removes4: " << RESET_COLOR << "Список: " << listRemoves << ". Полученный список при Remove [begin() + " << removeStart << "; begin() + " << removeEnd << "]: ";
    listRemoves.Remove(listRemoves.begin() + removeStart, listRemoves.begin() + removeEnd);
    std::cout << listRemoves << "." << std::endl;

    listRemoves = List<int>{5, 9, 6, 2, 3, 7, 1};
    removeStart = 1, removeEnd = 6;
    std::cout << INFO_COLOR << "Removes5: " << RESET_COLOR << "Список: " << listRemoves << ". Полученный список при Remove [begin() + " << removeStart << "; begin() + " << removeEnd << "]: ";
    listRemoves.Remove(listRemoves.begin() + removeStart, listRemoves.begin() + removeEnd);
    std::cout << listRemoves << "." << std::endl;

    listRemoves = List<int>{5, 9, 6, 2, 3, 7, 1};
    removeStart = 0, removeEnd = 6;
    std::cout << INFO_COLOR << "Removes6: " << RESET_COLOR << "Список: " << listRemoves << ". Полученный список при Remove [begin() + " << removeStart << "; begin() + " << removeEnd << "]: ";
    listRemoves.Remove(listRemoves.begin() + removeStart, listRemoves.begin() + removeEnd);
    std::cout << listRemoves << "." << std::endl;

    std::cout << std::endl;


    // sublist testing
    List<int> listSubLists{5, 9, 6, 2, 3, 7, 1};
    size_t subListStart = 1, subListEnd = 4;
    std::cout << INFO_COLOR << "SubLists1: " << RESET_COLOR << "Список: " << listSubLists << ". Полученный список при SubList [begin() + " << subListStart << "; begin() + " << subListEnd << "]: ";
    auto subList = listSubLists.SubList(listSubLists.begin() + subListStart, listSubLists.begin() + subListEnd);
    std::cout << subList << "." << std::endl;

    listSubLists = List<int>{5, 9, 6, 2, 3, 7, 1};
    subListStart = 0, subListEnd = 4;
    std::cout << INFO_COLOR << "SubLists2: " << RESET_COLOR << "Список: " << listSubLists << ". Полученный список при SubList [begin() + " << subListStart << "; begin() + " << subListEnd << "]: ";
    subList = listSubLists.SubList(listSubLists.begin() + subListStart, listSubLists.begin() + subListEnd);
    std::cout << subList << "." << std::endl;

    listSubLists = List<int>{5, 9, 6, 2, 3, 7, 1};
    subListStart = 1, subListEnd = 6;
    std::cout << INFO_COLOR << "SubLists3: " << RESET_COLOR << "Список: " << listSubLists << ". Полученный список при SubList [begin() + " << subListStart << "; begin() + " << subListEnd << "]: ";
    subList = listSubLists.SubList(listSubLists.begin() + subListStart, listSubLists.begin() + subListEnd);
    std::cout << subList << "." << std::endl;

    listSubLists = List<int>{5, 9, 6, 2, 3, 7, 1};
    subListStart = 0, subListEnd = 6;
    std::cout << INFO_COLOR << "SubLists4: " << RESET_COLOR << "Список: " << listSubLists << ". Полученный список при SubList [begin() + " << subListStart << "; begin() + " << subListEnd << "]: ";
    subList = listSubLists.SubList(listSubLists.begin() + subListStart, listSubLists.begin() + subListEnd);
    std::cout << subList << "." << std::endl;

    const List<int> constListSubLists{5, 9, 6, 2, 3, 7, 1};
    subListStart = 1;
    subListEnd = 4;
    std::cout << INFO_COLOR << "SubLists13 (const): " << RESET_COLOR << "Список: " << constListSubLists << ". Полученный список при SubList начиная с begin() + " << subListStart << " до begin() + " << subListEnd << ": ";
    subList = constListSubLists.SubList(constListSubLists.cbegin() + subListStart, constListSubLists.cbegin() + subListEnd);
    std::cout << subList << "." << std::endl;

    const List<int> constListSubLists13{5, 9, 6, 2, 3, 7, 1};
    subListStart = 0;
    subListEnd = 4;
    std::cout << INFO_COLOR << "SubLists14 (const): " << RESET_COLOR << "Список: " << constListSubLists13 << ". Полученный список при SubList начиная с begin() + " << subListStart << " до begin() + " << subListEnd << ": ";
    subList = constListSubLists13.SubList(constListSubLists13.cbegin() + subListStart, constListSubLists13.cbegin() + subListEnd);
    std::cout << subList << "." << std::endl;

    const List<int> constListSubLists15{5, 9, 6, 2, 3, 7, 1};
    subListStart = 1;
    subListEnd = 6;
    std::cout << INFO_COLOR << "SubLists15 (const): " << RESET_COLOR << "Список: " << constListSubLists15 << ". Полученный список при SubList начиная с begin() + " << subListStart << " до begin() + " << subListEnd << ": ";
    subList = constListSubLists15.SubList(constListSubLists15.cbegin() + subListStart, constListSubLists15.cbegin() + subListEnd);
    std::cout << subList << "." << std::endl;

    const List<int> constListSubLists16{5, 9, 6, 2, 3, 7, 1};
    subListStart = 0;
    subListEnd = 6;
    std::cout << INFO_COLOR << "SubLists16 (const): " << RESET_COLOR << "Список: " << constListSubLists16 << ". Полученный список при SubList начиная с begin() + " << subListStart << " до begin() + " << subListEnd << ": ";
    subList = constListSubLists16.SubList(constListSubLists16.cbegin() + subListStart, constListSubLists16.cbegin() + subListEnd);
    std::cout << subList << "." << std::endl;


    std::cout << std::endl;

     
    // insert testing
    int insertValue = 4;
    List<int> listInserts = List<int>{1, 2, 3};
    int insertIndex = 2;
    std::cout << INFO_COLOR << "Inserts3: " << RESET_COLOR << "Список: " << listInserts << ". Список после вставки элемента после [begin() + " << insertIndex << "]: ";
    listInserts.Insert(listInserts.begin() + insertIndex, insertValue);
    std::cout << listInserts << "." << std::endl;

    double insertValued = 4.3;
    listInserts = List<int>{1, 2, 3};
    std::cout << INFO_COLOR << "Inserts5: " << RESET_COLOR << "Список: " << listInserts << ". Список после вставки элемента double " << insertValued << " после [begin() + " << insertIndex << "]: ";
    listInserts.Insert(listInserts.begin() + insertIndex, insertValued);
    std::cout << listInserts << "." << std::endl;

    listInserts = List<int>{1, 2, 3};
    List<int> insertList{5, 7, 2};
    std::cout << INFO_COLOR << "Inserts6: " << RESET_COLOR << "Список: " << listInserts << ". Список после переноса списка " << insertList << " после [begin() + " << insertIndex << "]: ";
    listInserts.Insert(listInserts.begin() + insertIndex, std::move(insertList));
    std::cout << listInserts << "." << "Переносимый список: " << insertList << std::endl;

    listInserts = List<int>{1, 2, 3};
    insertList = List<int>{5, 7, 2};
    insertIndex = 2;
    std::cout << INFO_COLOR << "Inserts7: " << RESET_COLOR << "Список: " << listInserts << ". Список после переноса списка " << insertList << " после [begin() + " << insertIndex << "]: ";
    listInserts.Insert(listInserts.begin() + insertIndex, std::move(insertList));
    std::cout << listInserts << "." << "Переносимый список: " << insertList << std::endl;
    

    listInserts = List<int>{1, 2, 3};
    std::vector<double> insertVec = std::vector<double>{2.5, 6.2, 5.9};
    insertIndex = 2;
    std::cout << INFO_COLOR << "Inserts13: " << RESET_COLOR << "Список: " << listInserts << ". Список после вставки вектора " << insertVec << " после [begin() + " << insertIndex << "]: ";
    listInserts.Insert(listInserts.begin() + insertIndex, insertVec);
    std::cout << listInserts << "." << std::endl;

    listInserts = List<int>{1, 2, 3};
    insertVec = std::vector<double>{2.5, 6.2, 5.9};
    insertIndex = 0;
    std::cout << INFO_COLOR << "Inserts14: " << RESET_COLOR << "Список: " << listInserts << ". Список после вставки вектора " << insertVec << " после [begin() + " << insertIndex << "]: ";
    listInserts.Insert(listInserts.begin() + insertIndex, insertVec);
    std::cout << listInserts << "." << std::endl;

    std::cout << std::endl;

    // Clear testing
    List<int> listClear{1, 2, 3};
    std::cout << INFO_COLOR << "Clear1: " << RESET_COLOR << "Список: " << listClear << ". Список после Clear: ";
    listClear.Clear();
    std::cout << listClear << "." << std::endl;
    std::cout << std::endl;

    // Reverse testing
    List<int> listReverse{1, 2, 3, 4, 5, 6, 7};
    std::cout << INFO_COLOR << "Reverse1: " << RESET_COLOR << "Список: " << listReverse << ". Список после Reverse: ";
    listReverse.Reverse();
    std::cout << listReverse << "." << std::endl;

    std::cout << std::endl;

    // Plus testing
    List<int> listPlus1{1, 2, 3};
    List<int> listPlus2{5, 9, 8};
    List<double> listPlus3{4.23, 5.32};
    std::vector<double> vecPlus{23.5, 21.3};
    std::cout << INFO_COLOR << "Список 1: " << RESET_COLOR << listPlus1 << INFO_COLOR << ". Список 2: " << RESET_COLOR << listPlus2 << INFO_COLOR << ". Список 3: " << RESET_COLOR << listPlus3 << ". " << std::endl;
    std::cout << INFO_COLOR << "Vector: " << RESET_COLOR << vecPlus << "." << std::endl;
    std::cout << INFO_COLOR << "(1) + (2): " << RESET_COLOR << listPlus1 + listPlus2 << ". " << INFO_COLOR << "Список 1: " << RESET_COLOR << listPlus1 << INFO_COLOR << ". Список 2: " << RESET_COLOR << listPlus2 << ". " << std::endl;
    std::cout << INFO_COLOR << "(1) + 10: " << RESET_COLOR << listPlus1 + 10 << "." << std::endl;
    std::cout << INFO_COLOR << "(1) + move(2): " << RESET_COLOR << listPlus1 + std::move(listPlus2) << ". " << INFO_COLOR << "Список 1: " << RESET_COLOR << listPlus1 << INFO_COLOR << ". Список 2: " << RESET_COLOR << listPlus2 << ". " << std::endl;
    std::cout << INFO_COLOR << "(1) + 10.23: " << RESET_COLOR << listPlus1 + 10.23 << "." << std::endl;
    std::cout << INFO_COLOR << "10.23 + (1): " << RESET_COLOR << 10.23 + listPlus1 << "." << std::endl;
    std::cout << INFO_COLOR << "(3) + (1): " << RESET_COLOR << listPlus3 + listPlus1 << "." << std::endl;
    std::cout << INFO_COLOR << "(1) + (3): " << RESET_COLOR << listPlus1 + listPlus3 << "." << std::endl;
    std::cout << INFO_COLOR << "(1) + (vector): " << RESET_COLOR << listPlus1 + vecPlus << "." << std::endl;



    std::cout << std::endl;
    

    listPlus2 = List<int>{5, 9, 8};
    std::cout << INFO_COLOR << "(1) += (2): " << RESET_COLOR << (listPlus1 += listPlus2) << ". " << INFO_COLOR << "Список 1: " << RESET_COLOR << listPlus1 << INFO_COLOR << ". Список 2: " << RESET_COLOR << listPlus2 << ". " << std::endl;
    listPlus1 = List<int>{1, 2, 3};
    std::cout << INFO_COLOR << "(1) += 20: " << RESET_COLOR << (listPlus1 += 20) << ". " << INFO_COLOR << "Список 1: " << RESET_COLOR << listPlus1 << std::endl;
    listPlus1 = List<int>{1, 2, 3};
    std::cout << INFO_COLOR << "(1) += move(2): " << RESET_COLOR << (listPlus1 += std::move(listPlus2)) << ". " << INFO_COLOR << "Список 1: " << RESET_COLOR << listPlus1 << INFO_COLOR << ". Список 2: " << RESET_COLOR << listPlus2 << ". " << std::endl;
    std::cout << std::endl;

    
    // Cmp testing
    List<int> listCmp1{1, 2, 3};
    List<int> listCmp2{2, 2, 3};
    List<int> listCmp3{1, 2, 3, 3};
    std::cout << INFO_COLOR << listCmp1 << " < " << listCmp2 << RESET_COLOR <<  " = " << (listCmp1 < listCmp2) << std::endl;
    std::cout << INFO_COLOR << listCmp1 << " > " << listCmp2 << RESET_COLOR <<  " = " << (listCmp1 > listCmp2) << std::endl;
    std::cout << INFO_COLOR << listCmp1 << " == " << listCmp2 << RESET_COLOR <<  " = " << (listCmp1 == listCmp2) << std::endl;
    std::cout << INFO_COLOR << listCmp1 << " < " << listCmp3 << RESET_COLOR <<  " = " << (listCmp1 < listCmp3) << std::endl;
    std::cout << INFO_COLOR << listCmp1 << " > " << listCmp3 << RESET_COLOR <<  " = " << (listCmp1 > listCmp3) << std::endl;
    std::cout << INFO_COLOR << listCmp1 << " == " << listCmp3 << RESET_COLOR <<  " = " << (listCmp1 == listCmp3) << std::endl;
    std::cout << INFO_COLOR << listCmp2 << " < " << listCmp3 << RESET_COLOR <<  " = " << (listCmp2 < listCmp3) << std::endl;
    std::cout << INFO_COLOR << listCmp2 << " > " << listCmp3 << RESET_COLOR <<  " = " << (listCmp2 > listCmp3) << std::endl;
    std::cout << INFO_COLOR << listCmp2 << " == " << listCmp3 << RESET_COLOR <<  " = " << (listCmp2 == listCmp3) << std::endl;

    // auto it = listCmp1.begin();
    // while (true) {
    //     std::cout << *(it++) << std::endl;
    // }
    // const List<int> list1{1,2, 3, 4, 5};
    // std::cout << INFO_COLOR << *list1.begin() << std::endl;
    // std::cout<< INFO_COLOR <<*(++list1.begin()) << std::endl;

    List<int> a{1, 2, 3, 4, 5, 6, 7};
    std::vector<int> vec(a.begin(), a.end());
    std::cout << "vector: " << vec << std::endl;
    return 0;
}