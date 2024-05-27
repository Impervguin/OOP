#pragma once


class Point {
    public:
        Point() = default;
        Point(double x, double y, double z);

        explicit Point(const Point &p) = default;
        Point(Point &&p) noexcept = default;

        Point &operator=(const Point &p) = default;
        Point &operator=(Point &&p) noexcept = default;

        ~Point() = default;

        double GetX() const;
        double GetY() const;
        double GetZ() const;
        void SetX(double x);
        void SetY(double y);
        void SetZ(double z);
        void Set(const Point &p);
        void Set(double x, double y, double z);

        bool operator==(const Point &p) const;
        bool operator!=(const Point &p) const;
        bool IsEqual(const Point &p) const;
        bool IsNotEqual(const Point &p) const;
    
    private:
        double _x, _y, _z;
};