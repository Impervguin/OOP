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
myerror_t read_point(FILE *f, point_t *p);

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
myerror_t move_point(point_t *p, move_t *move);

/**
 * @brief Поворачивает точку объектом rotate_t вокруг осей.
 * 
 * @param p - Указатель на точку.
 * @param move - Указатель на объект поворота.
 * @return myerror_t - p = NULL или rotate = NULL => ERR_NULL_POINTER
 * else => OK
 */
myerror_t rotate_point(point_t *p, rotate_t *rotate);

/**
 * @brief Масштабирует точку относительно центра координат объектом scale_t .
 * 
 * @param p - Указатель на точку.
 * @param move - Указатель на объект масштабирования.
 * @return myerror_t - p = NULL или scale = NULL => ERR_NULL_POINTER
 * else => OK
 */
myerror_t scale_point(point_t *p, scale_t *scale);

#endif // POINT_H__
