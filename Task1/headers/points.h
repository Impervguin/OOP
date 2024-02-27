#ifndef POINTS_H__
#define POINTS_H__

#include <stdio.h>
#include "points.h"
#include "actions.h"
#include "point.h"
#include "errs.h"


typedef struct points points_t;

/// @brief Множество точек
struct points
{
    size_t size; // Количество точек
    point_t *arr; // Массив точек
};

/**
 * @brief Функция инициализации множества точек, динамически выделяет память под size точек.
 * Не освобождает память из-под выделенного до этого объекта, если она была выделена.
 * @param points - Указатель на инициализируемый объект.
 * @param size - Количество рёбер, под которые выделится память.
 * @return myerror_t - size = 0 => ERR_ARGUMENT, edges = NULL => ERR_NULL_POINTER, ошибка выделения памяти => ERR_MEMORY, else => OK
 */
myerror_t points_init(points_t *points, size_t size);

/**
 * @brief Освобождает память из под массива точек в points и делает его NULL.
 * Также делает size = 0.
 * @param points - Указатель на очищаемый объект.
 */
void clear_points(points_t *points);

/**
 * @brief Копирует точки из src в dst.
 * Если dst.arr != NULL, то попытается его освободить.
 * 
 * @param src - Указатель на копируемый объект.
 * @param dst - Указатель на место копирования.
 * @return myerror_t - dst == NULL or src == NULL => ERR_NULL_POINTER, ошибка выделения памяти => ERR_MEMORY, else => OK
 */
myerror_t copy_points(const points_t *src, points_t *dst);


/**
 * @brief Читает точки из файла в объект.
 * Формат файла:
 * n - Число точек
 * Далее n троек вещественных чисел - координат x,y,z i-ой точки
 * Если points.arr != NULL, попытается его освободить.
 * @param f - Указатель на файловую переменную, откуда читается файл.
 * @param points - Указатель на объект, куда запишутся рёбра из файла.
 * @return myerror_t - f = NULL => ERR_NO_FILE,
 * points = NULL => ERR_NULL_POINTER,
 * Некорректный формат файла или не удалось прочитать => ERR_FILE_FORMAT,
 * Ошибка выделения памяти => ERR_MEMORY
 * else => OK
 */
myerror_t read_points(FILE *f, points_t *points);

/**
 * @brief Функция записывает точки в файл
 * Формат файла:
 * n - Число точек
 * Далее n троек вещественных чисел - координат x,y,z i-ой точки
 * @param f - Указатель на файловую переменная для записи.
 * @param points - Указатель на рёбра.
 * @return myerror_t - f = NULL или не удалось записать => ERR_NO_FILE,
 * points = NULL => ERR_NULL_POINTER,
 * else => OK
 */
myerror_t write_points(FILE *f, points_t *points);

/**
 * @brief Сдвигает все точки объектом move_t.
 * 
 * @param points - Указатель на точки.
 * @param move - Указатель на объект сдвига
 * @return myerror_t - points = NULL или points.arr = NULL или move = NULL => ERR_NULL_POINTER,
 * else => OK
 */
myerror_t move_points(points_t *points, move_t *move);

/**
 * @brief Масштабирует все точки относительно центра координат объектом scale_t.
 * 
 * @param points - Указатель на точки.
 * @param move - Указатель на объект масштабирования
 * @return myerror_t - points = NULL или points.arr = NULL или move = NULL => ERR_NULL_POINTER,
 * else => OK
 */
myerror_t scale_points(points_t *points, scale_t *move);

/**
 * @brief Поворачивает все точки объектом rotate_t вокруг координатных осей.
 * 
 * @param points - Указатель на точки.
 * @param move - Указатель на объект поворота.
 * @return myerror_t - points = NULL или points.arr = NULL или move = NULL => ERR_NULL_POINTER,
 * else => OK
 */
myerror_t rotate_points(points_t *points, rotate_t *move);

#endif // POINTS_H__
