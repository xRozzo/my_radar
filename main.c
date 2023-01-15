/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** printf
*/

#include "lib/my/utils/my.h"
#include "./ObjectecOrientedProgramming/object.h"
#include "system/system.h"
#include <unistd.h>


int main(int ac, char **av)
{
    if (my_strcmp(av[ac - 1], "-h") == 0) {
        display_usage_radar();
    }
    if (ac != 2) {
        my_putstr("arguments incorrect");
        return 0;
    }
    SystemClass* system = new(System);

    int returnv = system->run(system, ac, av);

    my_putstr("\nSYSTEM OK\n");

    delete(system);
    return (returnv);
}
