#pragma once
#include "DirectorCreator.h"

template <typename DirectorBase, typename DirectorProd, typename... Args>
requires NotAbstract<DirectorProd> && Derivative<DirectorProd, DirectorBase> && Constructible<DirectorProd, Args...>
std::shared_ptr<DirectorBase> DirectorCreator<DirectorBase, DirectorProd, Args...>::Create(Args&&... args) {
    return std::make_shared<DirectorProd>(args...);
}