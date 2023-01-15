/*
** EPITECH PROJECT, 2022
** window.h
** File description:
** printf
*/

# include <stdio.h>
# include <stdlib.h>
#include "window.h"


static void Window_creator(WindowClass *this, va_list *args)
{
    (void)(args);
    this->mode = (sfVideoMode){1920, 1080, 32};
    this->window = sfRenderWindow_create(this->mode, "My_Radar", sfClose, NULL);    
    sfRenderWindow_setMouseCursorVisible(this->window, sfFalse);
    sfRenderWindow_setFramerateLimit(this->window, 60);
}

static void Window_destructor(WindowClass *this)
{
    if (this->window)
        sfRenderWindow_destroy(this->window);
}


static const WindowClass description = {
    {
        .size = sizeof(WindowClass),
        .destructor = (destructor)&Window_destructor,
        .constructor = (constructor)&Window_creator
    },

    .window = NULL

};

const Class *Window = (const Class *)&description;
