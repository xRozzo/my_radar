/*
** EPITECH PROJECT, 2022
** clock.h
** File description:
** clock structure
*/

#include "../../ObjectecOrientedProgramming/object.h"
#include "./window/window.h"
#include "game.h"
#include "time.h"
#include "../props/airplane/airplane.h"
#include "../props/tower/tower.h"

static bool game_over(GameClass *this, SystemClass *system)
{
    int i = 0;
    int plane_cnt = 0;
    int landed = 0;
    while (system->airplanes->airplanes_array[plane_cnt] != NULL) {
        plane_cnt++;
    }
    while (system->airplanes->airplanes_array[i] != NULL) {
        if (system->airplanes->airplanes_array[i]->landed == true) {
            landed ++;
        }
        i++;
    }
    if (landed == plane_cnt) {
        return (true);
    } else {
        return (false);
    }
}

static bool inside_tower(GameClass *this, SystemClass *system, int index_plane)
{
    int j = 0;
    float radius;
    sfVector2f position;
    sfVector2f rect_position;
    sfVector2f vectore_plane_circle;
    float modulus;
    while (system->towers->towers_array[j] != NULL)  {
        radius = system->towers->towers_array[j]->radius;
        position = system->towers->towers_array[j]->pos;
        rect_position = GET_HITBOX()
        vectore_plane_circle.x = (rect_position.x + 20) - position.x;
        vectore_plane_circle.y = (rect_position.y  + 20 )- position.y;
        modulus = sqrt(pow(vectore_plane_circle.x, 2)
        + pow(vectore_plane_circle.y, 2));
        if (modulus <= radius)
            return (true);
    j++;
    }
    return (false);
}

static void check_collition(GameClass *this, SystemClass *system, int j)
{
    int z = 0;
    while(system->airplanes->airplanes_array[z] != NULL) {
        sfFloatRect bounds1 = (sfFloatRect){
            sfRectangleShape_getPosition(system->airplanes->airplanes_array[z]->hitbox).x,
            sfRectangleShape_getPosition(system->airplanes->airplanes_array[z]->hitbox).y,
            sfRectangleShape_getSize(system->airplanes->airplanes_array[z]->hitbox).x,
            sfRectangleShape_getSize(system->airplanes->airplanes_array[z]->hitbox).y
        };
        sfFloatRect bounds2 = (sfFloatRect){
            sfRectangleShape_getPosition(system->airplanes->airplanes_array[j]->hitbox).x,
            sfRectangleShape_getPosition(system->airplanes->airplanes_array[j]->hitbox).y,
            sfRectangleShape_getSize(system->airplanes->airplanes_array[j]->hitbox).x,
            sfRectangleShape_getSize(system->airplanes->airplanes_array[j]->hitbox).y
        };
        if IF_COLLITION() {
            system->airplanes->airplanes_array[j]->landed = true;
            system->airplanes->airplanes_array[z]->landed = true;
        }     
        z++;
    }
}

static void create_hitbox(GameClass *this, SystemClass *system, int j)
{
    sfRectangleShape *hitbox = sfRectangleShape_create();
    sfVector2f size;
    size.x = 20;
    size.y = 20;
    sfVector2f origin = GET_A_ORIGIN()
    sfVector2f position_hitbox = GET_A_POS()
    sfRectangleShape_setSize(hitbox, size);
    sfRectangleShape_setOrigin(hitbox, origin);
    sfRectangleShape_setPosition(hitbox, position_hitbox);
    sfRectangleShape_setFillColor(hitbox, sfTransparent);
    sfRectangleShape_setOutlineColor(hitbox, sfWhite);
    sfRectangleShape_setOutlineThickness(hitbox, 1.0);
    sfRectangleShape_rotate(hitbox,
    system->airplanes->airplanes_array[j]->angle);
    system->airplanes->airplanes_array[j]->hitbox = hitbox;
    if DISPLAY_CONDITION() {
        DRAW_PLANE()
        DRAW_HITBOX()
    }
}

static void display_plane(GameClass *this, SystemClass *system, sfVector2f scale_factor, int j)
{
    int num_of_planes = 0;
    while(system->airplanes->airplanes_array[num_of_planes] != NULL) {
        num_of_planes++;
    }
    system->airplanes->airplanes_array[j]->texture = C_AIRPLANE_TEXTURE()
    system->airplanes->airplanes_array[j]->sprite = sfSprite_create();
    sfSprite_setTexture(system->airplanes->airplanes_array[j]->sprite,
    system->airplanes->airplanes_array[j]->texture, sfTrue);
    sfSprite_setPosition(system->airplanes->airplanes_array[j]->sprite,
    system->airplanes->airplanes_array[j]->pos);
    sfSprite_scale(system->airplanes->airplanes_array[j]->sprite, scale_factor);
    sfSprite_rotate(system->airplanes->airplanes_array[j]->sprite,
    system->airplanes->airplanes_array[j]->angle);
    create_hitbox(this, system, j);
    if (game_over(this, system) == true) {
        sfWindow_close(this->Window->window);
    }
    check_collition(this, system, j);
}

static void Game_action(GameClass *this, SystemClass *system)
{
    (void)(this);
    int i = 0;
    while(system->airplanes->airplanes_array[i] != NULL) {
        if (system->airplanes->airplanes_array[i]->on_air == true) {
            system->airplanes->airplanes_array[i]->move_plane(system->airplanes->airplanes_array[i]);
        }
        i++;
    }
}

static void display_tower(GameClass *this, SystemClass *system, int i)
{
    sfVector2f scale_factor;
    scale_factor.x = 0.075;
    scale_factor.y = 0.075;
    system->towers->towers_array[i]->texture = C_TOWER_TEXTURE()
    system->towers->towers_array[i]->sprite = sfSprite_create();
    sfSprite_setTexture(system->towers->towers_array[i]->sprite,
    system->towers->towers_array[i]->texture, sfTrue);
    sfSprite_setPosition(system->towers->towers_array[i]->sprite,
    system->towers->towers_array[i]->pos);
    sfSprite_scale(system->towers->towers_array[i]->sprite, scale_factor);
    sfRenderWindow_drawSprite(this->Window->window,
    system->towers->towers_array[i]->sprite, NULL);

}

static void trigger_plane_display(GameClass *this, SystemClass *system)
{
    sfVector2f scale_factor;
    scale_factor.x = 0.075;
    scale_factor.y = 0.075;
    int j = 0;
     while (system->airplanes->airplanes_array[j] != NULL) {
        if DELAY_ELAPSED() {
            system->airplanes->airplanes_array[j]->on_air = true;
            display_plane(this, system, scale_factor, j);
        }
        j++;
    }
}

static void Game_display(GameClass *this, SystemClass *system)
{
    int i = 0;
    sfVector2f increment;
    sfColor transparent = {0, 0, 0, 0};
    while(system->towers->towers_array[i] != NULL) {
        display_tower(this, system, i);
        sfCircleShape *circle = sfCircleShape_create();
        increment.x = INCREMENT_X()
        increment.y = INCREMENT_Y()
        system->towers->towers_array[i]->circle_center = increment;
        sfCircleShape_setRadius(circle, system->towers->towers_array[i]->radius);
        sfCircleShape_setPosition(circle, increment);
        sfCircleShape_setOutlineColor(circle, sfWhite);
        sfCircleShape_setFillColor(circle, transparent);
        sfCircleShape_setOutlineThickness(circle, 3.0);
        sfRenderWindow_drawCircleShape(this->Window->window, circle, NULL);
        system->towers->towers_array[i]->circle = circle;
        i++;
    }
    trigger_plane_display(this, system);
    sfRenderWindow_display(this->Window->window);
}

static void Start_Game(GameClass *this, SystemClass *system)
{
    while (sfRenderWindow_isOpen(this->Window->window)) {
        sfRenderWindow_clear(this->Window->window, sfBlack);
        this->scene->eventhandling->poll(this->scene->eventhandling,
        this->Window);
        if ELAPSED_TIME() {
            Game_action(this, system);
            Game_display(this, system);
            sfClock_restart(system->clock->clock);
        }
    }
}

static void Game_creator(GameClass *this, va_list *args)
{
    (void)(args);
    this->scene = new(Scene);
    this->Window = new(Window);
    this->clock = new(Clock);
}

static void Game_destructor(GameClass *this)
{
    delete(this->scene);
    delete(this->Window);
}

static const GameClass description = {
    {
        .size = sizeof(GameClass),
        .constructor = (constructor)&Game_creator,
        .destructor = (destructor)&Game_destructor
    },
    .scene = NULL,
    .Window = NULL,
    .start = &Start_Game
};

const Class *Game = (const Class *)&description;
