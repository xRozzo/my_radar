/*
** EPITECH PROJECT, 2022
** my_memcopy
** File description:
** Converts a int to a string
*/

#include <stdlib.h>
// destination and source are pointers to the memory locations to be copied
void *my_memcpy(void *destination, const void *source, size_t num_bytes)
{
    char *dst = (char*) destination;
    const char *src = (const char*) source;

    for (size_t i = 0; i < num_bytes; i++) {
        dst[i] = src[i];
    }
    return destination;
}
