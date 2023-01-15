/*
** EPITECH PROJECT, 2022
** is_only_num
** File description:
** handle the width
*/


#include "my.h"
#include "limits.h"


int get_sign(char c, int *has_sign, int *has_digit)
{
    if (c == '-') {
        if (*has_sign || *has_digit) {
            return 0;
        }
        *has_sign = 1;
        return -1;
    }
    return 1;
}

int handle_digit(char c, long long *nb, int *has_digit)
{
    if (is_num(c)) {
        *nb = *nb * 10 + (c - '0');
        *has_digit = 1;
        if (*nb > INT_MAX || *nb < INT_MIN) {
            return 0;
        }
        return 1;
    }
    return 0;
}

int handle_space(char c, int has_sign, int has_digit)
{
    if (c == ' ') {
        if (has_sign || has_digit) {
            return 0;
        }
        return 1;
    }
    return 0;
}

int my_getnbr(char const *str)
{
    long long nb = 0;
    int i = 0;
    int sign = 1;
    int has_sign = 0;
    int has_digit = 0;
    while (str[i]) {
        sign = get_sign(str[i], &has_sign, &has_digit);
        if (sign == 0) {
            return 0;
        }
        if (!handle_digit(str[i], &nb, &has_digit) &&
        !handle_space(str[i], has_sign, has_digit)) {
            return 0;
        }
        i++;
    }
    if (!has_digit) {
        return 0;
    }
    return (int)(nb * sign);
}
