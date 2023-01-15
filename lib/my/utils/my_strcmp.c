/*
** EPITECH PROJECT, 2022
** my_strcmp
** File description:
** reporduce the behaviour of the strcmp function
*/

int string_length_strcmp(char const *str)
{
    int i = 0;
    while (str[i]) {
        i++;
    }
    return (i);
}

int my_strcmp(char const *s1, char const *s2)
{
    int s2_len = string_length_strcmp(s2);
    int count_s1 = 0;
    int count_s2 = 0;

    while (s1[count_s1] == s2[count_s2]) {
        count_s1 ++;
        count_s2 ++;
    }
    if (count_s1 - 1 == s2_len) {
        return (0);
    }

    if ((s1[count_s1] - s2[count_s2]) < 0) {
        return (-1);
    }

    if ((s1[count_s1] - s2[count_s2]) > 0) {
        return (1);
    }
    return (0);
}
