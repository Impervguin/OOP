#ifndef ERRS_H__
#define ERRS_H__


/// @brief Тип ошибок
typedef enum {
    OK = 0, // Успех
    ERR_NO_FILE, // Системная ошибка с файлом(не удалось открыть, прочитать, записать)
    ERR_FILE_FORMAT, // Некорректный формат в файле
    ERR_NULL_POINTER, // Передан пустой указатель на объект
    ERR_MEMORY, // Ошибка работы с памятью(выделение)
    ERR_ARGUMENTS, // Некорректный аргумент(вне области определения функции)
    ERR_EMPTY,
    ERR_NO_SCENE,
    ERR_UNKNOWN_ACTION
} myerror_t;

/**
 * @brief Функция возвращает сообщение об ошибке по коду.
 * 
 * @param err - Код ошибки.
 * @return const char* - Сообщение ошибки.
 */
const char *err_message(myerror_t err);

#endif // ERRS_H__
