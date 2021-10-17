/*
** EPITECH PROJECT, 2021
** ftp
** File description:
** utils
*/

#include "ftp.h"

noreturn bool helper(int const _output)
{
    char *lineptr = NULL;
    size_t i = 500;
    FILE *stream = fopen("./help.txt", "r");

    if (NULL == stream)
        eraise();
    while (-1 != getline(&lineptr, &i, stream) && (printf("%s", lineptr)));
    free(lineptr);
    fclose(stream);
    exit(_output);
}