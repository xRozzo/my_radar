/*
** EPITECH PROJECT, 2022
** my_ulong_long_to_str.c
** File description:
** Converts a int to a string
*/

#include "my.h"

float get_signs(const char *str)
{
    if (*str == '\0') {
        return 1;
    }
    if (*str == '-') {
        return -1;
    }
    return 1;
}

float get_values(const char *str)
{
    float value = 0;
    while (*str >= '0' && *str <= '9') {
        value = value * 10 + (*str - '0');
        str++;
    }
    if (*str == '.') {
        str++;
        float fraction = 0.1;
        while (*str >= '0' && *str <= '9') {
            value += (*str - '0') * fraction;
            fraction /= 10;
            str++;
            }
    }
    return value;
}

float string_to_float(const char *str)
{
    return (get_signs(str) * get_values(str));
}
