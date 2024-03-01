#ifndef EDGES_H__
#define EDGES_H__

#include <stdio.h>
#include "errs.h"

typedef struct edges edges_t;
typedef struct edge edge_t;

/**
 * @brief Структура для хранения множества ребер некоторой трехмерной фигуры.
 */
struct edges
{
    size_t size; // Количество ребёр
    edge_t *arr; // Массив ребёр
};

/**
 * @brief Структура ребра, представляет из себя номера двух точек - концов ребра,
 * сами точки берутся из внешней структуры, зависимо от задачи
 * 
 */
struct edge {
    size_t p1, p2;
};

/**
 * @brief Функция инициализации множества ребёр, динамически выделяет память под size рёбер.
 * Не освобождает память из-под выделенного до этого объекта, если она была выделена.
 * @param edges - Указатель на инициализируемый объект.
 * @param size - Количество рёбер, под которые выделится память.
 * @return myerror_t - size = 0 => ERR_ARGUMENT, edges = NULL => ERR_NULL_POINTER, ошибка выделения памяти => ERR_MEMORY, else => OK
 */
myerror_t edges_init(edges_t *edges, size_t size);

/**
 * @brief Освобождает память из под массива рёбер в edges и делает его NULL.
 * Также делает size = 0.
 * @param edges - Указатель на очищаемый объект.
 */
void clear_edges(edges_t *edges);

/**
 * @brief Копирует рёбра из src в dst.
 * Если dst.arr != NULL, то попытается его освободить.
 * 
 * @param src - Указатель на копируемый объект.
 * @param dst - Указатель на место копирования.
 * @return myerror_t - dst == NULL or src == NULL => ERR_NULL_POINTER, ошибка выделения памяти => ERR_MEMORY, else => OK
 */
myerror_t copy_edges(edges_t *dst, const edges_t *src);

/**
 * @brief Читает ребра из файла в объект.
 * Формат файла:
 * 1-я строка: Число ребер - n
 * Далее n пар чисел - номера концов рёбер, начиная с 1.
 * Если edges.arr != NULL, попытается его освободить.
 * @param f - Указатель на файловую переменную, откуда читается файл.
 * @param edges - Указатель на объект, куда запишутся рёбра из файла.
 * @return myerror_t - f = NULL или не удалось прочитать => ERR_NO_FILE,
 * edges = NULL => ERR_NULL_POINTER,
 * Некорректный формат файла => ERR_FILE_FORMAT,
 * Ошибка выделения памяти => ERR_MEMORY
 * else => OK
 */
myerror_t read_edges(edges_t *edges, FILE *f);

/**
 * @brief Функция записывает ребра в файл
 * Формат файла:
 * 1-я строка: Число ребер - n
 * Далее n пар чисел - номера концов рёбер, начиная с 1.
 * @param f - Указатель на файловую переменная для записи.
 * @param edges - Указатель на рёбра.
 * @return myerror_t - f = NULL или не удалось записать => ERR_NO_FILE,
 * edges = NULL => ERR_NULL_POINTER,
 * else => OK
 */
myerror_t write_edges(FILE *f, edges_t *edges);

/**
 * @brief Функция для чтения ребра из файла.
 * 
 * @param f - Указатель на файловую переменную чтения.
 * @param edge - Указатель на записываемое ребро.
 * 
 * @return myerror_t f = NULL или не удалось прочитать => ERR_NO_FILE,
 * edge = NULL => ERR_NULL_POINTER,
 * Некорректный формат файла => ERR_FILE_FORMAT,
 * Ошибка выделения памяти => ERR_MEMORY
 * else => OK
 */
myerror_t read_edge(edge_t *edge, FILE *f);

/**
 * @brief Функция для записи ребра в файл.
 * 
 * @param f - Указатель на файловую переменная для записи.
 * @param edge - Указатель на ребро.
 * @return myerror_t - f = NULL или не удалось записать => ERR_NO_FILE,
 * edge = NULL => ERR_NULL_POINTER,
 * else => OK 
 */
myerror_t write_edge(FILE *f, edge_t *edge);

#endif // EDGES_H__
