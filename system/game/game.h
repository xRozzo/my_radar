/*
** EPITECH PROJECT, 2022
** game.h
** File description:
** clock structure
*/


#include "../../ObjectecOrientedProgramming/object.h"
#include "./window/window.h"
#include "./scene/scene.h"
#include "../system.h"


#ifndef GAME_H_
    #define GAME_H_

    typedef struct s_GameClass {
        Class base;

        SceneClass *scene;
        WindowClass *Window;
        ClockClass *clock;

        void (*start)(struct s_GameClass*, SystemClass*);

    } GameClass;

    extern const Class *Game;

    #define ELAPSED_TIME() (sfTime_asMilliseconds(\
    sfClock_getElapsedTime(system->clock->clock)) > 100)
    #define INCREMENT_X() system->towers->towers_array[i]->pos.x -\
    ((system->towers->towers_array[i]->radius) - 19);
    #define INCREMENT_Y() system->towers->towers_array[i]->pos.y -\
    ((system->towers->towers_array[i]->radius) - 19);
    #define DELAY_ELAPSED() (sfTime_asSeconds(sfClock_getElapsedTime(this->clock->clock)) >\
    (system->airplanes->airplanes_array[j]->delay))
    #define C_TOWER_TEXTURE() sfTexture_createFromFile\
    (system->towers->towers_array[i]->file_path, NULL);
    #define C_AIRPLANE_TEXTURE() sfTexture_createFromFile(\
    system->airplanes->airplanes_array[j]->file_path, NULL);
    #define DISPLAY_CONDITION() (system->airplanes->airplanes_array[j]->on_air == true\
    && system->airplanes->airplanes_array[j]->landed == false)
    #define DRAW_PLANE() sfRenderWindow_drawSprite(this->Window->window,\
    system->airplanes->airplanes_array[j]->sprite, NULL);
    #define DRAW_HITBOX() sfRenderWindow_drawRectangleShape(\
    this->Window->window, hitbox, NULL);
    #define GET_A_POS() sfSprite_getPosition(\
    system->airplanes->airplanes_array[j]->sprite);
    #define GET_A_ORIGIN() sfText_getOrigin(\
    system->airplanes->airplanes_array[j]->sprite);
    #define IF_COLLITION() (j != z && sfFloatRect_intersects(&bounds1, &bounds2, NULL)\
    && !inside_tower(this, system, j))
    #define GET_HITBOX() sfRectangleShape_getPosition(\
    system->airplanes->airplanes_array[index_plane]->hitbox);

#endif
