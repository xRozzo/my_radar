/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** Contains the prototypes of all the functions in libmy.a
*/

#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "../../../ObjectecOrientedProgramming/object.h"  
#include "../window/window.h"

#ifndef EVENTS_H_
    #define EVENTS_H_

    // ! can put includes here
    typedef struct s_event {
        Class base;
        sfEvent event;
        WindowClass *window;

        void (*poll)(struct s_event*, struct s_WindowClass*);
    } EventClass;


extern const Class *EventsHandling;


#endif

#define CLOSE_EVENT() (this->event.type == sfEvtClosed \
|| this->event.key.code == sfKeyEscape)
