/*
** EPITECH PROJECT, 2022
** printf
** File description:
** printf
*/

#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include<stdio.h>
#include <stdarg.h>
#include "object.h"
#include "../lib/my/utils/my.h"

void *va_new(const Class *class, va_list *pa)
{
    Class *object;
    if (class == NULL)
        return (NULL);
    if (class->size < sizeof(*class))
        return (NULL);
    object = malloc(class->size);
    my_memcpy(object, class, class->size);
    if (object->constructor != NULL)
        object->constructor(object, pa);
    return (object);
}

void delete(void *ptr)
{
    Class *object = (Class *)ptr;
    if (object != NULL && object->destructor != NULL) {
        object->destructor(object);
    }
    free(object);
}

void *new(const Class *class, ...)
{
    va_list ap;
    void *object;

    va_start(ap, class);
    object = va_new(class, &ap);
    va_end(ap);
    return (object);
}
