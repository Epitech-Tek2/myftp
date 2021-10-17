/*
** EPITECH PROJECT, 2021
** ftp
** File description:
** inline
*/

#pragma once

#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>
#include "define.h"

static inline void (my_free)(int _count, void *_ptr, ...)
{
    va_list list_ptr;

    free(_ptr);
    for (va_start(list_ptr, _ptr); _count > 0; --_count)
        free(va_arg(list_ptr, void *));
    va_end(list_ptr);
}

static inline void my_free_arr(void **_ptr)
{
    for (int i = 0; _ptr[i]; i++)
        my_free(_ptr[i]);
    my_free(_ptr);
}

static inline bool (my_exist)(int _count, void *_ptr, ...)
{
    va_list list_ptr;

    if (!_ptr)
        return false;
    for (va_start(list_ptr, _ptr); _count > 0; --_count)
        if (!va_arg(list_ptr, void *))
            return false;
    va_end(list_ptr);
    return true;
}