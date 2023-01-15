/*
** EPITECH PROJECT, 2022
** my_ulong_long_to_str.c
** File description:
** Converts a int to a string
*/

#include "my.h"

char replace(char *temp_str, char *str, int i, char separator)
{
    int z = 0;
    char *ptr_string = &temp_str[0];
    while (str[i] != separator && str[i] != '\0') {
        ptr_string[z] = str[i];
        i++;
        z++;
    }
    ptr_string[z] = '\0';
    while (str[i] == separator && str[i + 1] != '\0') {
        i ++;
    }
    return i;
}

char **separate_string(char **array, char *str, char separator, int array_len )
{
    int i = 0;
    int j = 0;
    int arguments = 0;
    char* temp_str = malloc(sizeof (char) * (my_strlen(str) + 1));
    array = malloc(sizeof (char*) * (array_len + 1));
    while (str[i] != '\0' && arguments < array_len) {
        i = replace(temp_str, str, i, separator);
        array[j] = malloc(sizeof (char) * (my_strlen(temp_str) + 1));
        my_strcpy(array[j], temp_str);
        j++;
        arguments++;
        free (temp_str);
        temp_str = malloc (sizeof (char) * (my_strlen(str) + 1));
    }
    array[j] = NULL;
    return (array);
}

char **str_split (char const *str, char separator)
{
    char *string = my_strdup(str);
    char **array = NULL;
    int array_len = 0;
    for (int i = 0; i < my_strlen(string); i++) {
        if (string[i] == separator || string[i + 1] == '\0')
            array_len ++;
    }
    array = separate_string(array, string, separator, array_len);
    free(string);
    return (array);
}
