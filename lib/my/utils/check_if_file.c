/*
** EPITECH PROJECT, 2022
** is_float
** File description:
** handle the precision
*/

int check_if_file(char *argv[])
{
    int i = 1;
    while (argv[i]) {
        if (argv[i][0] != '-')
            return (0);
        i++;
    }
    return (1);
}
