/*
** EPITECH PROJECT, 2022
** printf
** File description:
** printf
*/


#include "../../../ObjectecOrientedProgramming/object.h"
#include "scene.h"

static void Scene_constructor(SceneClass *this, va_list *args)
{
    (void)(args);
    this->eventhandling = new(EventsHandling);
}

static void Scene_destructor(SceneClass *this)
{
    delete(this->eventhandling);
}

static const SceneClass _description = {
    {
        .size = sizeof(SceneClass),
        .constructor = (constructor)&Scene_constructor,
        .destructor = (destructor)&Scene_destructor
    },
    .eventhandling = NULL
};


const Class *Scene = (const Class *)(&_description);
