/*
** EPITECH PROJECT, 2022
** printf.c
** File description:
** printf
*/


#include "../../../ObjectecOrientedProgramming/object.h"
#include "events.h"
#include "../../system.h"
#include "../game.h"


static void Event_handle(EventClass *this, WindowClass *window)
{
    while (sfRenderWindow_pollEvent(window->window, &(this->event))) {
        if CLOSE_EVENT() {
            sfRenderWindow_close(window->window);
        }
    }
}

static const EventClass description = {  
    {
        .size = sizeof(EventClass),
        .constructor = NULL,
        .destructor = NULL,
    },
    .poll = &Event_handle
};

const Class *EventsHandling = (const Class *)(&description);
