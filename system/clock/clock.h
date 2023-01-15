/*
** EPITECH PROJECT, 2022
** clock.h
** File description:
** clock structure
*/

#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include<stdarg.h>
#include<stdio.h>

#include "../../ObjectecOrientedProgramming/object.h"
#include <SFML/System.h>

#ifndef CLOCK_H_
    #define CLOCK_H_

    typedef struct s_class {
        Class base;

        sfClock *clock;
    } ClockClass;
    
    extern const Class *Clock;

#endif
