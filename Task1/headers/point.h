#ifndef POINT_H__
#define POINT_H__

#include <stdio.h>
#include "errs.h"
#include "actions.h"

typedef struct point point_t;

/// Точка в пространстве.
struct point
{
    double x, y, z;
};

void point_init(point_t *point);

/**
 * @brief Функция для чтения точки из файла
 * Читает первые 3 вещественных числа - x,y,z.
 * @param f - Указатель на файловую переменную.
 * @param p - Указатель на записываемую точку
 * @return myerror_t f = NULL => ERR_NO_FILE
 * p = NULL => ERR_NULL_POINTER
 * некорректный формат файла или не удалось прочитать => ERR_FILE_FORMAT
 * else => OK
 */
myerror_t read_point(point_t *p, FILE *f);

/**
 * @brief Функция для записи точки в файл.
 * 
 * @param f - Указатель на файловую переменную.
 * @param p - Указатель на точку.
 * @return myerror_t f = NULL или не удалось записать => ERR_NO_FILE
 * p = NULL => ERR_NULL_POINTER
 * else => OK
 */
myerror_t write_point(FILE *f, point_t *p);

/**
 * @brief Сдвигает точку объектом move_t.
 * 
 * @param p - Указатель на точку.
 * @param move - Указатель на сдвиг.
 * @return myerror_t - p = NULL или move = NULL => ERR_NULL_POINTER
 * else => OK
 */
myerror_t move_point(point_t *p, const move_t *move);

myerror_t rotate_point(point_t *point, const rotate_t *rotate, const point_t *center);

myerror_t scale_point(point_t *point, const scale_t *scale, const point_t *center);

point_t max_point(point_t p1, point_t p2);
point_t min_point(point_t p1, point_t p2);
point_t rect_center(point_t min, point_t max);

#endif // POINT_H__
