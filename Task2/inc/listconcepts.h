#ifndef LISTCONCEPTS_H__
#define LISTCONCEPTS_H__

#include <concepts>
#include <iterator>

template <typename From, typename To>
concept Convertible = requires(From from){ To(from);};

template <typename T>
concept Comparable = requires(T t, T u){
    {t > u} -> std::same_as<bool>;
    {t < u} -> std::same_as<bool>;
    {t <= u} -> std::same_as<bool>;
    {t >= u} -> std::same_as<bool>;
    {t == u} -> std::same_as<bool>;
    {t != u}-> std::same_as<bool>;
    {u > t} -> std::same_as<bool>;
    {u < t} -> std::same_as<bool>;
    {u <= t} -> std::same_as<bool>;
    {u >= t} -> std::same_as<bool>;
    {u == t} -> std::same_as<bool>;
    {u != t}-> std::same_as<bool>;
};

template <typename T>
concept Assignable = requires(T &t, T &t2) {t = t2;};

template <typename T>
concept Copyable = requires(T &t) {T(t);};

template <typename container>
concept Container = requires(container c)
{ 
    typename container::value_type;
    typename container::iterator;
    typename container::const_iterator;
    typename container::size_type;

    { c.begin() } noexcept -> std::same_as<typename container::iterator>;
    { c.end() } noexcept -> std::same_as<typename container::iterator>;
    { c.cbegin() } noexcept -> std::same_as<typename container::const_iterator>;
    { c.cend() } noexcept -> std::same_as<typename container::const_iterator>;
    { c.size() } noexcept -> std::same_as<typename container::size_type>;
};

template <typename container, typename T>
concept ConvertibleContainer = Container<container> && Convertible<typename container::value_type, T>;


template <typename T>
concept Iterator = requires() 
{
    typename T::value_type;
    typename T::pointer;
    typename T::reference;
    typename T::difference_type;
};

template <typename T, typename U>
concept DerivedFrom = std::is_base_of<U, T>::value;

template<typename T, typename U>
concept EquillityComparable = requires(T t, U u) {
    { t == u } -> std::same_as<bool>;
    { u == t } -> std::same_as<bool>;
    { t != u } -> std::same_as<bool>;
    { u != t } -> std::same_as<bool>;
};


template<typename T>
concept InputIterator = requires() { typename T::iterator_category; } &&
EquillityComparable<T, T> &&
Iterator<T> &&
DerivedFrom<typename T::iterator_category, std::input_iterator_tag>;


template<typename T>
concept Incrementable = requires(T t) {
    { ++t } -> std::same_as<T&>;
    { t++ } -> std::same_as<T>;
};

template <typename T>
concept ForwardIterator = InputIterator<T> && Incrementable<T> && DerivedFrom<typename T::iterator_category, std::forward_iterator_tag>;


template <InputIterator Iter>
typename Iter::difference_type distance(const Iter &first, const Iter &last)
{
    typename Iter::difference_type count = 0;
    for (Iter current = first; current != last; ++current, ++count);

    return count;
}


template <typename T>
concept IncrementableandComparable = Incrementable<T> && Comparable<T>;

template <typename Iter, typename T>
concept ConvertibleForwardIterator = ForwardIterator<Iter> && Convertible<typename Iter::value_type, T>;
#endif // LISTCONCEPTS_H__
