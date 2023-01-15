/*
** EPITECH PROJECT, 2022
** printf
** File description:
** printf
*/

#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include<stdarg.h>
#include<stdio.h>
#include "my.h"
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>


char **read_map(int argc, char* argv[], char *buff)
{
    printf("\n READ MAP IS BEING CALLED........\n");
    char **map_char_format;
    int fd = open(argv[argc - 1], O_RDONLY);
    if (fd == -1)
        exit(84);
    int offset = 0;
    int len;
    buff = malloc(sizeof(char) * 10000 + 1);
    buff[0] = '\0';
    if (fd != -1) {
        while ((len = read(fd, buff + offset, 10000 - offset)) > 0)
            offset = offset + len;
        buff[offset] = '\0';
    }
    if (buff != NULL)
        (map_char_format = str_split(buff, '\n'));
    else {
        exit(84);
    }
    return (map_char_format);
}
