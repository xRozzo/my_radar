/*
** EPITECH PROJECT, 2022
** game.h
** File description:
** clock structure
*/

#include "math.h"
#include "stdlib.h"
#include "../../../ObjectecOrientedProgramming/object.h"
#include "../../../lib/my/utils/my.h"
#include "airplane.h"
#include "stdbool.h"


static void move_airplane(AirplaneClass *this)
{
    float vector_x = 0;
    float vector_y = 0;
    float modulus = 0;
    vector_x = this->arrival_pos.x - this->departure_pos.x;
    vector_y = this->arrival_pos.y - this->departure_pos.y;
    modulus = sqrt(pow(vector_x, 2) + pow(vector_y, 2));
    float cos = vector_x / modulus;
    float sin = vector_y / modulus;
    float angle_atan2 = atan2(vector_y, vector_x) * 180 / M_PI;
    this->angle = angle_atan2;
    this->pos.x = this->pos.x + (this->velocity * cos);
    this->pos.y = this->pos.y + (this->velocity * sin);
    int moudle_pos = CALCULATE_DISTANCE_1()
    int moudle_land_pos = CALCULATE_DISTANCE_2();
    if (moudle_pos > moudle_land_pos){
        this->landed = true;
        return;
    }
}

static const AirplaneClass description = {
    {
        .size = sizeof(AirplaneClass),
        .constructor = NULL,
        .destructor = NULL
    },
    .departure_pos = {0, 0},
    .arrival_pos = {0, 0},
    .on_air = false,
    .pos = {0, 0},
    .dir = {0, 0},
    .velocity = 0,
    .move_plane = &move_airplane,
    .file_path = NULL,
    .texture = NULL,
    .sprite = NULL,
    .angle = 0,
    .in_circle = false,
    .landed = false,
};

const Class *Airplane = (const Class *)&description;
