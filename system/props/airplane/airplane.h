/*
** EPITECH PROJECT, 2022
** game.h
** File description:
** clock structure
*/

#include "math.h"
#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>

#include "../../../ObjectecOrientedProgramming/object.h"
#include "../../game/window/window.h"


#include "../../../lib/my/utils/my.h"


#ifndef AIRPLANE_H_
    #define AIRPLANE_H_
    typedef struct s_AirplaneClass {
        Class base;

        sfVector2f departure_pos;
        sfVector2f arrival_pos;
        sfVector2f pos;
        sfVector2f dir;
        size_t velocity;
        size_t delay;
        bool on_air;
        char *file_path;
        sfTexture *texture;
        sfSprite *sprite;
        float angle;
        sfRectangleShape *hitbox;
        bool in_circle;
        bool landed;
        void (*move_plane)(struct s_AirplaneClass*);
    }AirplaneClass;

    extern const Class *Airplane;

    #define CALCULATE_DISTANCE_1() sqrt(pow(this->pos.x\
    - this->departure_pos.x, 2) \
    + pow(this->pos.y - this->departure_pos.y, 2));
    #define CALCULATE_DISTANCE_2() (sqrt(pow(this->arrival_pos.x\
    - this->departure_pos.x, 2) \
    + pow(this->arrival_pos.y - this->departure_pos.y, 2)));

#endif
