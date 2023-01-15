/*
** EPITECH PROJECT, 2022
** is_float
** File description:
** handle the precision
*/
#include <stdlib.h>
void display_usage_radar(void)
{
    my_putstr("\"Air traffic simulation panel\n"
    "\"USAGE\n"
    "\"     ./my_radar [OPTIONS] path_to_script\n"
    "\"     path_to_script The path to the script file.\n"
    "\"OPTIONS\n"
    "\"     -h print the usage and quit.\n"
    "\"USER INTERACTIONS\n"
    "\"     ‘L’ key enable/disable hitboxes and areas.\n"
    "\"     ‘S’ key enable/disable sprites.\n"
    "\"ENJOY!!\n");
    my_putstr("\033[0m");
    exit(0);
}
