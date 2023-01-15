/*
** EPITECH PROJECT, 2022
** parser.h
** File description:
** clock structure
*/


#include "../../../ObjectecOrientedProgramming/object.h"
#include "../../../lib/my/utils/my.h"
#include "../../props/airplane/airplane.h"
#include "../window/window.h"
#include "../scene/scene.h"


#ifndef INFO_H_
    #define INFO_H_
    typedef struct s_InfoClass {
        Class base;
        char **planes;
        char **towers;
        
        void(*read)(struct s_InfoClass*, char**, int);
    }InfoClass;

    extern const Class *Info;
#endif
