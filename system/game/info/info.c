/*
** EPITECH PROJECT, 2022
** parser.c
** File description:
** clock structure
*/

#include "../../../lib/my/utils/my.h"
#include "info.h"

static void read(InfoClass *this, char **argv, int argc) // should be void
{
    int i = 0;
    int j = 0;
    int planes_cnt = 0;
    int towers_cnt = 0;
    char *buff = NULL;
    char **file_content = read_map(argc, argv, buff);
    int num_planes = 0;
    int num_towers = 0;
    while (file_content[j] != NULL) {
        if (file_content[j][0] == 'A') {
            num_planes++;
        }
        if (file_content[j][0] == 'T') {
            num_towers++;
        }
        j++;
    }
    this->planes = malloc(sizeof(char *) * (num_planes + 1));
    this->towers = malloc(sizeof(char *) * (num_towers + 1));
    while (file_content[i] != NULL) {
        if(file_content[i][0] == 'A') {
            this->planes[planes_cnt] = malloc(sizeof(char) * my_strlen(file_content[i]) + 1);
            my_strcpy(this->planes[planes_cnt], file_content[i]);
            planes_cnt ++;
        }
        if (file_content[i][0] == 'T') {
            this->towers[towers_cnt] = malloc(sizeof(char) * my_strlen(file_content[i]) + 1);
            my_strcpy(this->towers[towers_cnt], file_content[i]);
            towers_cnt++;
        }
        i ++;
        }
        this->planes[planes_cnt] = NULL;
        this->towers[towers_cnt] = NULL;
}

static const InfoClass description = {
    {
        .size = sizeof(InfoClass),
        .constructor = NULL,
        .destructor = NULL,
    },
    .read = &read,
    .planes = NULL,
    .towers = NULL
};

const Class *Info = (const Class *)&description;
