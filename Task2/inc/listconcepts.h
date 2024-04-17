#ifndef LISTCONCEPTS_H__
#define LISTCONCEPTS_H__

#include <concepts>

template <typename From, typename To>
concept Convertible = requires(From from){ To(from);};

#endif // LISTCONCEPTS_H__
