#ifndef ACTIONS_H__
#define ACTIONS_H__

typedef struct move move_t;
typedef struct scale scale_t;
typedef struct rotate rotate_t;

/**
 * @brief Объект содержащий данные для перемещения некоторого объекта в пространстве.
 * 
 */
struct move {
    double x, y, z;
};

/**
 * @brief Объект содержащий данные для масштабирования некоторого объекта в пространстве относительно центра координат. 
 * 
 */
struct scale {
    double x, y, z;
};

/**
 * @brief Объект содержащий данные для масштабирования некоторого объекта в пространстве относительно каждой из осей(по отдельности). 
 * Угол считается по повороту против часовой стрелки.
 */
struct rotate {
    double ox, oy, oz;
};

/**
 * @brief Функция перевода угла в градусах в радианы.
 * 
 * @param [in] deg - Угол в градусах.
 * @return double - Угол в радианах.
 */
double degrees_to_radians(double deg);

#endif // ACTIONS_H__
