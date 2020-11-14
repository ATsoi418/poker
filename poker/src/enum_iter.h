#pragma once
#include <iostream>
#include <string>
#include <vector>

template <class E>
    E value;
class enum_iter {
private:
    typedef typename std::underlying_type<E>::type under;
public:
    typedef std::size_t size_type;
    typedef std::ptrdiff_t difference_type;
    typedef E value_type;
    typedef E reference;
    typedef E* pointer;
    typedef std::random_access_iterator_tag iterator_category;

    constexpr enum_iter() :value() {}
    constexpr enum_iter(const enum_iter& rhs) noexcept(true) :value(rhs.value) {}
    constexpr explicit enum_iter(E value_) noexcept(true) :value(value_) {}
    ~enum_iter() noexcept(true) {}
    enum_iter& operator=(const enum_iter& rhs) noexcept(true) { value = rhs.value; return *this; }
    enum_iter& operator++() noexcept(true) { value = (E)(under(value) + 1); return *this; }
    enum_iter operator++(int) noexcept(true) { enum_iter r(*this); ++* this; return r; }
    enum_iter& operator+=(size_type o) noexcept(true) { value = (E)(under(value) + o); return *this; }
    friend constexpr enum_iter operator+(const enum_iter& it, size_type o) noexcept(true) { return enum_iter((E)(under(it) + o)); }
    friend constexpr enum_iter operator+(size_type o, const enum_iter& it) noexcept(true) { return enum_iter((E)(under(it) + o)); }
    enum_iter& operator--() noexcept(true) { value = (E)(under(value) - 1); return *this; }
    enum_iter operator--(int) noexcept(true) { enum_iter r(*this); --* this; return r; }
    enum_iter& operator-=(size_type o) noexcept(true) { value = (E)(under(value) + o); return *this; }
    friend constexpr enum_iter operator-(const enum_iter& it, size_type o) noexcept(true) { return enum_iter((E)(under(it) - o)); }
    friend constexpr difference_type operator-(enum_iter lhs, enum_iter rhs) noexcept(true) { return under(lhs.value) - under(rhs.value); }
    constexpr reference operator*() const noexcept(true) { return value; }
    constexpr reference operator[](size_type o) const noexcept(true) { return (E)(under(value) + o); }
    constexpr const E* operator->() const noexcept(true) { return &value; }
    constexpr friend bool operator==(const enum_iter& lhs, const enum_iter& rhs) noexcept(true) { return lhs.value == rhs.value; }
    constexpr friend bool operator!=(const enum_iter& lhs, const enum_iter& rhs) noexcept(true) { return lhs.value != rhs.value; }
    constexpr friend bool operator<(const enum_iter& lhs, const enum_iter& rhs) noexcept(true) { return lhs.value < rhs.value; }
    constexpr friend bool operator>(const enum_iter& lhs, const enum_iter& rhs) noexcept(true) { return lhs.value > rhs.value; }
    constexpr friend bool operator<=(const enum_iter& lhs, const enum_iter& rhs) noexcept(true) { return lhs.value <= rhs.value; }
    constexpr friend bool operator>=(const enum_iter& lhs, const enum_iter& rhs) noexcept(true) { return lhs.value >= rhs.value; }

    friend void swap(const enum_iter& lhs, const enum_iter& rhs) noexcept(true) { std::swap(lhs.value, rhs.value); }
};

template<class E> constexpr boost::iterator_range<enum_iter<E>> get_range() noexcept(true)
{
    return boost::make_iterator_range(enum_iterator<E>(E::First), enum_iter<E>(E::Last));
}