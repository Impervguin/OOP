#ifndef FIGURE_H__
#define FIGURE_H__

#include <stdio.h>
#include "actions.h"
#include "points.h"
#include "edges.h"
#include "errs.h"

typedef struct figure figure_t;

/**
 * @brief Структура, представляющую 3д фигуру в виде каркаса.
 * 
 */
struct figure {
    points_t points; /// Точки фигуры.
    edges_t edges; /// Ребра фигуры.
};

/**
 * @brief Функция для создания фигуры.
 * Инициализирует весь объект нулями.
 * @return figure_t* - Указатель на созданный объект, NULL - в случае неудачи выделения.
 */
figure_t *init_figure(void);

/**
 * @brief Функция, для очистки фигуры(очищает все вложенные).
 * Не освобождает память из под самой fig.
 * @param fig - Указатель на очищаемую фигуру.
 */
void clear_figure(figure_t *fig);

/**
 * @brief Функция для копирования фигуры.
 * Если points != NULL или edges != NULL у dst, то попытается их очистить.
 * @param src - Указатель на копируюмую фигуру.
 * @param dst - Указатель на место для копирования.
 * @return myerror_t - dst == NULL or src == NULL => ERR_NULL_POINTER, ошибка выделения памяти => ERR_MEMORY, else => OK
 */
myerror_t copy_figure(const figure_t *src, figure_t *dst);


/**
 * @brief Функция для чтения фигуры из файла.
 * Формат файла:
 * n - Число точек
 * Далее n троек вещественных чисел - координат x,y,z i-ой точки
 * m - Число ребер
 * Далее n пар чисел - номеров концов рёбер, начиная с 1.
 * если в fig points != NULL или edges != NULL, попытается их очистить.
 * @param fname - Имя читаемого файла.
 * @param fig - Указатель на записивыемую фигуру.
 * @return myerror_t fname = NULL или не удалось прочитать => ERR_NO_FILE,
 * fig = NULL => ERR_NULL_POINTER,
 * Некорректный формат файла => ERR_FILE_FORMAT,
 * Ошибка выделения памяти => ERR_MEMORY
 * else => OK
 */
myerror_t read_figure(const char *fname, figure_t *fig);

/**
 * @brief Функция для записи фигуры в файл.
 * Формат файла:
 * n - Число точек
 * Далее n троек вещественных чисел - координат x,y,z i-ой точки
 * m - Число ребер
 * Далее n пар чисел - номеров концов рёбер, начиная с 1.
 * 
 * @param fname - Имя файла для записи.
 * @param fig - Указатель на фигуру для записи.
 * @return myerror_t - fname = NULL или не удалось записать => ERR_NO_FILE,
 * fig = NULL => ERR_NULL_POINTER,
 * Ошибка выделения памяти => ERR_MEMORY
 * else => OK
 */
myerror_t write_figure(const char *fname, figure_t *fig);

/**
 * @brief Сдвигает фигуру объектом move_t.
 * 
 * @param fig - Указатель на фигуру.
 * @param move - Указатель на объект сдвига
 * @return myerror_t - fig = NULL или fig->points = NULL или move = NULL => ERR_NULL_POINTER
 * else => OK
 */
myerror_t move_figure(figure_t *fig, move_t *move);

/**
 * @brief Масштабирует фигуру относительно центра координат объектом scale_t.
 * 
 * @param fig - Указатель на фигуру.
 * @param scale - Указатель на объект масштабирования
 * @return myerror_t - fig = NULL или fig->points = NULL или scale = NULL => ERR_NULL_POINTER
 * else => OK
 */
myerror_t scale_figure(figure_t *fig, scale_t *scale);

/**
 * @brief Сдвигает фигуру объектом rotate_t вокруг осей координат.
 * 
 * @param fig - Указатель на фигуру.
 * @param rotate - Указатель на объект поворота.
 * @return myerror_t - fig = NULL или fig->points = NULL или rotate = NULL => ERR_NULL_POINTER
 * else => OK
 */
myerror_t rotate_figure(figure_t *fig, rotate_t *rotate);

#endif // FIGURE_H__
