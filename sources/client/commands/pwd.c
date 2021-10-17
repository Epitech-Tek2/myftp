/*
** EPITECH PROJECT, 2021
** ftp
** File description:
** pwd
*/

#include <unistd.h>
#include "ftp.h"

void pwd(client_t *_client)
{
    char *path = NULL;

    check_user_is_connected(_client);
    path = getcwd(path, 100);
    dprintf(_client->_fd, "257 \"%s\"\n", path);
    my_free(path);
}