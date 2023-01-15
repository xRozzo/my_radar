/*
** EPITECH PROJECT, 2022
** printf
** File description:
** printf
*/

#include "towersManager.h"

static void TowerConstructor(TowersManager *this, va_list *args)
{
    (void)(this);
    (void)(args);
    my_putstr("crating towers..");
}

static void init_towers(TowersManager *this)
{
    int num_towers = 0;
    while (this->info->towers[num_towers] != NULL) {
        num_towers++;
    }
    int i = 0;
    char **arguments = NULL;
    this->towers_array = malloc(sizeof(TowerClass *) * (num_towers + 1));
    while (this->info->towers[i] != NULL) {
        arguments = str_split(this->info->towers[i], ' ');
        this->towers_array[i] = new(Tower);
        this->towers_array[i]->pos.x = string_to_float(arguments[1]);
        this->towers_array[i]->pos.y = string_to_float(arguments[2]);
        this->towers_array[i]->radius = my_getnbr(arguments[3]) * 1920 / 100;
        this->towers_array[i]->file_path = "imgs/tower.png";
        this->towers_array[i]->circle = malloc(sizeof(sfCircleShape *));
        this->towers_array[i]->circle = sfCircleShape_create();
        i++;
    }
    this->towers_array[i] = NULL;
}

static void destructorTowers(TowersManager *this)
{
    printf("destroyig....");
    free(this->towers_array);
}

static const TowersManager description = {
    {
        .size = sizeof(TowersManager),
        .constructor = (constructor)&TowerConstructor,
        .destructor = (destructor)&destructorTowers,

    },
    .towers_array = NULL,
    .init_towers = &init_towers,
    .info = NULL
};

const Class *Towers = (const Class *)&description;
