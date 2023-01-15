/*
** EPITECH PROJECT, 2022
** parser.h
** File description:
** clock structure
*/

#include "../../../ObjectecOrientedProgramming/object.h"
#include "../../../lib/my/utils/my.h"
#include "../../props/airplane/airplane.h"
#include "info.h"
#include "../window/window.h"
#include "../scene/scene.h"

#ifndef NODE_H_
    #define NODE_H_

    typedef struct s_Node {
        AirplaneClass *plane;
        struct s_Node *next;
        struct s_Node *previous;
    }Plane_List;

#endif


#ifndef AIRCRAFTS_MANAGER_H_
    #define AIRCRAFTS_MANAGER_H_

    typedef struct s_AircraftsManager {
        Class base;

        AirplaneClass **airplanes_array;
        InfoClass *info;

        void (*init_aircrafts)(struct s_AircraftsManager*);

    }AircraftsManager;

#endif


extern const Class *Aircrafts;
