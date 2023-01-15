/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** Contains the prototypes of all the functions in libmy.a
*/



#include "../../../ObjectecOrientedProgramming/object.h"
#include "../events/events.h"
#include "../window/window.h"

#ifndef SCENE_H_
    #define SCENE_H_    
    typedef struct s_SceneClass {
        Class base;

        EventClass *eventhandling;
    } SceneClass;

    extern const Class *Scene;

#endif
