/*
** EPITECH PROJECT, 2022
** printf
** File description:
** printf
*/

#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include<stdarg.h>
#include<stdio.h>

#include "clock.h"
#include <SFML/System.h>

static void Clock_Constructor(ClockClass *this, va_list *args)
{
    (void)(args);
    this->clock = sfClock_create();

}

static void Clock_Destructor(ClockClass *this)
{
    sfClock_destroy(this->clock);
}

static const ClockClass descripiton = {
    {
        .size = sizeof(ClockClass),
        .constructor = (constructor)&Clock_Constructor,
        .destructor = (destructor)&Clock_Destructor,
    },
    .clock = NULL
};

const Class *Clock = (const Class *)&descripiton;
