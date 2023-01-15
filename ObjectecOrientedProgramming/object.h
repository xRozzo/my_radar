/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** Contains the prototypes of all the functions in libmy.a
*/

# include "stdio.h"
# include <sys/types.h>
# include <stdarg.h>
# include <stdbool.h>
# include <string.h>


#ifndef OBJECT_H_
    #define OBJECT_H_


    typedef void (*constructor)(void *this, va_list *args);

    typedef void (*destructor)(void *this);

    typedef struct s_Class {
        const unsigned long size;
        constructor constructor;
        destructor destructor;
    }Class;

    void *new(const Class *_class, ...);

    void delete(void *ptr);

    void Object_free(void *obj);

#endif

extern const Class *s_Class;
