/*
** EPITECH PROJECT, 2022
** clock.h
** File description:
** clock structure
*/

#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include "../../../ObjectecOrientedProgramming/object.h"

#ifndef WINDOW_H_
    #define WINDOW_H_

    typedef struct s_WindowClass {
        Class base;        
        sfVideoMode mode;
        sfRenderWindow* window;
    } WindowClass;

    extern const Class *Window;
#endif
