/*
** EPITECH PROJECT, 2022
** printf
** File description:
** printf
*/

#include "../../../ObjectecOrientedProgramming/object.h"
#include "../../../lib/my/utils/my.h"
#include "../../props/airplane/airplane.h"
#include "info.h"
#include "../window/window.h"
#include "../scene/scene.h"
#include "../../props/tower/tower.h"

#ifndef TOWERS_H_
    #define TOWERS_H_

    typedef struct s_TowersManager {
        Class base;

        TowerClass **towers_array;
        InfoClass *info;

        void (*init_towers)(struct s_TowersManager*);
    }TowersManager;

#endif

extern const Class *Towers;
