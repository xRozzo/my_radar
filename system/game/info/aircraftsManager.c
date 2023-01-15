/*
** EPITECH PROJECT, 2022
** printf
** File description:
** printf
*/

#include "aircraftsManager.h"
#include "../../system.h"
#include "math.h"

static void aircrafts_constructor(AircraftsManager *this, va_list *args)
{
    (void)(this);
    (void)(args);
    my_putstr("crating aircrafts...");
}

static void init_aircrafts(AircraftsManager *this)
{
    char **arguments = NULL;
    int num_airplanes = 0;
    int i = 0;
    while(this->info->planes[num_airplanes] != NULL) {
        num_airplanes ++;
    }
    this->airplanes_array = malloc(sizeof(AirplaneClass *) * (num_airplanes + 1));
    while (this->info->planes[i] != NULL) {
        arguments = str_split(this->info->planes[i], ' ');
        this->airplanes_array[i] = new(Airplane);
        this->airplanes_array[i]->departure_pos.x = string_to_float(arguments[1]);
        this->airplanes_array[i]->departure_pos.y = string_to_float(arguments[2]);
        this->airplanes_array[i]->pos.x = string_to_float(arguments[1]);
        this->airplanes_array[i]->pos.y = string_to_float(arguments[2]);
        this->airplanes_array[i]->arrival_pos.x = string_to_float(arguments[3]);
        this->airplanes_array[i]->arrival_pos.y = string_to_float(arguments[4]);
        this->airplanes_array[i]->velocity = my_getnbr(arguments[5]);
        this->airplanes_array[i]->delay = my_getnbr(arguments[6]);
        this->airplanes_array[i]->file_path = "imgs/plane.png";
        this->airplanes_array[i]->on_air = false;
        this->airplanes_array[i]->hitbox = malloc(sizeof(sfRectangleShape *));
        this->airplanes_array[i]->hitbox = sfRectangleShape_create();
        i++;
    }
    this->airplanes_array[i] = NULL;
}

static void aircrafts_list_destructor(AircraftsManager *this)
{
    free(this->airplanes_array);
}

static const AircraftsManager descritpion = {
    {
        .size = sizeof(AircraftsManager),
        .constructor = (constructor)&aircrafts_constructor,
        .destructor = (destructor)&aircrafts_list_destructor
    },
    .airplanes_array = NULL,
    .init_aircrafts = &init_aircrafts,
    .info = NULL
};

const Class *Aircrafts = (const Class *)&descritpion;
