#include "../../inc/objects/Edge.h"


Edge::Edge(size_t first, size_t second) : _first(first), _second(second) {};

size_t Edge::GetFirst() const { return _first; }

size_t Edge::GetSecond() const { return _second; }

void Edge::SetFirst(size_t first) { _first = first; }

void Edge::SetSecond(size_t second) { _second = second; }

void Edge::Set(size_t first, size_t second) { _first = first; _second = second; }

void Edge::Set(const Edge& other) { _first = other._first; _second = other._second; }

bool Edge::IsEqual(const Edge& other) const {
    return (_first == other._first && _second == other._second) || (_first == other._second && _second == other._first);
}

bool Edge::operator==(const Edge& other) const { return IsEqual(other); }

bool Edge::IsNotEqual(const Edge &other) const { return !IsEqual(other); }

bool Edge::operator!=(const Edge& other) const { return IsNotEqual(other); }


