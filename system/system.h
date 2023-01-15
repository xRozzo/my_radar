/*
** EPITECH PROJECT, 2022
** clock.h
** File description:
** clock structure
*/



#include "../ObjectecOrientedProgramming/object.h"
#include "../system/clock/clock.h"
#include "./game/info/aircraftsManager.h"
#include "./game/info/towersManager.h"


#ifndef SYSTEM_H_
    #define SYSTEM_H_
    typedef struct s_GameClass GameClass;

    typedef struct s_SystemClass {
        Class base;

        AircraftsManager *airplanes;
        TowersManager *towers;
        ClockClass* clock;
        GameClass * game;
        InfoClass *info;

        int (*run)(struct s_SystemClass*, int, char**);
    } SystemClass;


    extern const Class* System;

#endif
