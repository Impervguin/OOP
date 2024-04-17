#include "listnode.hpp"
#include "listiterator.hpp"
#include "constlistiterator.hpp"
#include "list.hpp"
#include <iostream>
#include <vector>
#include <string>

#define INFO_COLOR "\033[36m"
#define RESET_COLOR "\033[0m"

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

    std::cout << std::endl;
    // Gets testing
    List<int> listGets{1, 2, 3, 4, 5, 10, 9, 8, 7, 6, 5};
    size_t index = 5;
    std::cout << INFO_COLOR << "Gets1: " << RESET_COLOR << "Список: " << listGets << " Полученный элемент по индексу " << index << ": " << listGets.Get(index) << std::endl;
    std::cout << INFO_COLOR << "Gets2: " << RESET_COLOR << "Список: " << listGets << " Полученный элемент по итератору + " << index << ": " << listGets.Get(listGets.begin() + index) << std::endl;
    std::cout << INFO_COLOR << "Gets3: " << RESET_COLOR << "Список: " << listGets << " Полученный элемент по константному итератору + " << index << ": " << listGets.Get(listGets.cbegin() + index) << std::endl;
    std::cout << INFO_COLOR << "Gets4: " << RESET_COLOR << "Список: " << listGets << " Полученный элемент по [" << index << "]: " << listGets[index] << std::endl;
    std::cout << INFO_COLOR << "Gets5: " << RESET_COLOR << "Список: " << listGets << " Полученный элемент по [begin() + " << index << "]: " << listGets[listGets.begin() + index] << std::endl;
    std::cout << INFO_COLOR << "Gets6: " << RESET_COLOR << "Список: " << listGets << " Полученный элемент по [cbegin() + " << index << "]: " << listGets[listGets.cbegin() + index] << std::endl;

    std::cout << std::endl;

    // Pops testing
    List<int> listPops{5, 9, 6, 2, 3, 7, 1};
    std::cout << INFO_COLOR << "Pops1: " << RESET_COLOR << "Список: " << listPops << ". Полученный элемент при GetFront: " << listPops.GetFront() << ". Список после: " << listPops << "." << std::endl;
    std::cout << INFO_COLOR << "Pops2: " << RESET_COLOR << "Список: " << listPops << ". Полученный элемент при GetBack: " << listPops.GetBack() << ". Список после: " << listPops << "." << std::endl;
    std::cout << INFO_COLOR << "Pops3: " << RESET_COLOR << "Список: " << listPops << ". Полученный элемент при PopFront: " << listPops.PopFront() << ". Список после: " << listPops << "." << std::endl;
    std::cout << INFO_COLOR << "Pops4: " << RESET_COLOR << "Список: " << listPops << ". Полученный элемент при PopBack: " << listPops.PopBack() << ". Список после: " << listPops << "." << std::endl;

    std::cout << std::endl;

    // Set testing
    List<int> listSets{5, 9, 6, 2, 3, 7, 1};
    size_t setIndex = 2;
    int setValue = 100;
    std::cout << INFO_COLOR << "Sets1: " << RESET_COLOR << "Список: " << listSets << ". Список после изменения элемента [" << setIndex << "]: ";
    listSets.Set(setIndex, setValue);
    std::cout << listSets << "." << std::endl;
    listSets = List<int>{5, 9, 6, 2, 3, 7, 1};
    std::cout << INFO_COLOR << "Sets2: " << RESET_COLOR << "Список: " << listSets << ". Список после изменения элемента [begin() + " << setIndex << "]: ";
    listSets.Set(listSets.begin() + setIndex, setValue);
    std::cout << listSets << "." << std::endl;

    std::cout << std::endl;
    // Removes testing
    List<int> listRemoves{5, 9, 6, 2, 3, 7, 1};
    size_t removeIndex = 2;
    std::cout << INFO_COLOR << "Removes1: " << RESET_COLOR << "Список: " << listRemoves << ". Список после удаления элемента [" << removeIndex << "]: ";
    listRemoves.Remove(removeIndex);
    std::cout << listRemoves << "." << std::endl;

    listRemoves = List<int>{5, 9, 6, 2, 3, 7, 1};
    removeIndex = 6;
    std::cout << INFO_COLOR << "Removes2: " << RESET_COLOR << "Список: " << listRemoves << ". Список после удаления элемента [begin() + " << removeIndex << "]: ";
    listRemoves.Remove(listRemoves.begin() + removeIndex);
    std::cout << listRemoves << "." << std::endl;
    
    listRemoves = List<int>{5, 9, 6, 2, 3, 7, 1};
    removeIndex = 4;
    std::cout << INFO_COLOR << "Removes3: " << RESET_COLOR << "Список: " << listRemoves << ". Список после pop элемента [" << removeIndex << "]: ";
    auto popAns = listRemoves.Pop(removeIndex);
    std::cout << listRemoves << "." << " Элемент: " << popAns << std::endl;

    listRemoves = List<int>{5, 9, 6, 2, 3, 7, 1};
    removeIndex = 0;
    std::cout << INFO_COLOR << "Removes4: " << RESET_COLOR << "Список: " << listRemoves << ". Список после pop элемента [begin() + " << removeIndex << "]: ";
    popAns = listRemoves.Pop(listRemoves.begin() + removeIndex);
    std::cout << listRemoves << "." << " Элемент: " << popAns << std::endl;
    std::cout << std::endl;
    
    // insert testing
    List<int> listInserts = List<int>{1, 2, 3};
    size_t insertIndex = 1;
    int insertValue = 4;
    std::cout << INFO_COLOR << "Inserts1: " << RESET_COLOR << "Список: " << listInserts << ". Список после вставки элемента [" << insertIndex << "]: ";
    listInserts.Insert(insertIndex, insertValue);
    std::cout << listInserts << "." << std::endl;

    listInserts = List<int>{1, 2, 3};
    insertIndex = 0;
    std::cout << INFO_COLOR << "Inserts2: " << RESET_COLOR << "Список: " << listInserts << ". Список после вставки элемента [" << insertIndex << "]: ";
    listInserts.Insert(insertIndex, insertValue);
    std::cout << listInserts << "." << std::endl;

    listInserts = List<int>{1, 2, 3};
    insertIndex = 3;
    std::cout << INFO_COLOR << "Inserts3: " << RESET_COLOR << "Список: " << listInserts << ". Список после вставки элемента [" << insertIndex << "]: ";
    listInserts.Insert(insertIndex, insertValue);
    std::cout << listInserts << "." << std::endl;

    listInserts = List<int>{1, 2, 3};
    insertIndex = 2;
    std::cout << INFO_COLOR << "Inserts4: " << RESET_COLOR << "Список: " << listInserts << ". Список после вставки элемента после [begin() + " << insertIndex << "]: ";
    listInserts.InsertAfter(listInserts.begin() + insertIndex, insertValue);
    std::cout << listInserts << "." << std::endl;
    listInserts = List<int>{1, 2, 3};
    insertIndex = 2;
    std::cout << INFO_COLOR << "Inserts5: " << RESET_COLOR << "Список: " << listInserts << ". Список после вставки элемента перед [begin() + " << insertIndex << "]: ";
    listInserts.InsertBefore(listInserts.begin() + insertIndex, insertValue);
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
    std::cout << INFO_COLOR << "Список 1: " << RESET_COLOR << listPlus1 << INFO_COLOR << ". Список 2: " << RESET_COLOR << listPlus2 << ". " << std::endl;
    std::cout << INFO_COLOR << "(1) + (2): " << RESET_COLOR << listPlus1 + listPlus2 << ". " << INFO_COLOR << "Список 1: " << RESET_COLOR << listPlus1 << INFO_COLOR << ". Список 2: " << RESET_COLOR << listPlus2 << ". " << std::endl;
    std::cout << INFO_COLOR << "(1) + 10: " << RESET_COLOR << listPlus1 + 10 << "." << std::endl;
    std::cout << INFO_COLOR << "(1) + move(2): " << RESET_COLOR << listPlus1 + std::move(listPlus2) << ". " << INFO_COLOR << "Список 1: " << RESET_COLOR << listPlus1 << INFO_COLOR << ". Список 2: " << RESET_COLOR << listPlus2 << ". " << std::endl;

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

    return 0;
}