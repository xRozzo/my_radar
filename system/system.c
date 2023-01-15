/*
** EPITECH PROJECT, 2022
** window.h
** File description:
** printf
*/

#include "./game/window/window.h"
#include "./game/scene/scene.h"
#include "./props/airplane/airplane.h"
#include "./props/tower/tower.h"
#include "system.h"
#include "./game/game.h"


static int run_System(SystemClass *this, int argc, char** argv)
{
    this->airplanes = new(Aircrafts);
    this->towers = new(Towers);
    this->airplanes->info = new(Info);
    this->towers->info = new(Info);
    this->airplanes->info->read(this->airplanes->info, argv, argc);
    this->towers->info->read(this->towers->info,argv, argc);
    my_putstr("\nPARSING DONE..........\n");
    this->airplanes->init_aircrafts(this->airplanes);
    this->towers->init_towers(this->towers);
    my_putstr("\nAIRPLANES INIT DONE..........\n");
    this->game = new(Game);
    this->game->start(this->game, this);
    my_putstr("\nGAME STARTED OK\n");
    delete(this->game);
    delete(this->info);
    return (0);
}

static void System_creator(SystemClass *this, va_list *args)
{
    (void)(args);
    this->clock = new(Clock);
}

static void System_destructor(SystemClass *this)
{
    delete(this->airplanes);
    delete(this->towers);
    delete(this->clock);
}

static const SystemClass description = {
    {
        .size = sizeof(SystemClass),
        .constructor = (constructor)&System_creator,
        .destructor = (destructor)&System_destructor
    },
    .run = &run_System,
    .game = NULL,
    .info = NULL,
    .towers = NULL,
    .airplanes = NULL,
    .clock = NULL
};

const Class *System = (const Class*)&description;
