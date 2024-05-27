#pragma once
#include "ReaderCreator.h"

template <typename ReaderBase, typename ReaderProd, typename... Args>
requires NotAbstract<ReaderProd> && Derivative<ReaderProd, ReaderBase> && Constructible<ReaderProd, Args...>
std::shared_ptr<ReaderBase> ReaderCreator<ReaderBase, ReaderProd, Args...>::Create(Args&&... args) {
    return std::make_shared<ReaderProd>(args...);
}