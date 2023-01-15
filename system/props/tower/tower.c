/*
** EPITECH PROJECT, 2022
** game.h
** File description:
** clock structure
*/

#include <string.h>
#include "../../../ObjectecOrientedProgramming/object.h"
#include "tower.h"
#include "../../../lib/my/utils/my.h"


static const TowerClass description = {
    {
        .size = sizeof(TowerClass),
        .constructor = NULL,
        .destructor = NULL
    },
    .pos = {0, 0},
    .radius = 0,
    .file_path = NULL,
    .texture = NULL,
    .sprite = NULL,
};

const Class *Tower = (Class *)&description;
