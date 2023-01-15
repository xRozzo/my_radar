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

#ifndef TOWER_H_
    #define TOWER_H_
typedef struct s_TowerClass {
    Class base;

    sfVector2f pos;
    int radius;
    char *file_path;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f circle_center;
    sfCircleShape *circle;
} TowerClass;

extern const Class *Tower;

#endif
