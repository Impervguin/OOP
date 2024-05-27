#include "TransformAction.h"
#include "SquareMatrix.h"
#include "Point.h"

class ScaleAction : public TransformAction {
    public:
        ScaleAction(double mx, double my, double mz);
        ScaleAction(const Point &p, double mx, double my, double mz);
        ScaleAction(double m);
        ScaleAction(const Point& center, double m);
        virtual ~ScaleAction() = default;
};