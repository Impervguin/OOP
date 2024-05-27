#pragma once
#include <cstddef>

class Edge {
    public:
        Edge() = default;
        Edge(size_t first, size_t second);
        explicit Edge(const Edge& other) = default;
        Edge(Edge&& other) = default;

        Edge& operator=(const Edge& other) = default;
        Edge& operator=(Edge&& other) = default;

        size_t GetFirst() const;
        size_t GetSecond() const;
        void SetFirst(size_t first);
        void SetSecond(size_t second);
        void Set(const Edge& other);
        void Set(size_t first, size_t second);

        bool operator==(const Edge& other) const;
        bool operator!=(const Edge& other) const;
        bool IsEqual(const Edge& other) const;
        bool IsNotEqual(const Edge& other) const;

    private:
        size_t _first;
        size_t _second;
};