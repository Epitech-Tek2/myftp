/*
** EPITECH PROJECT, 2021
** ftp
** File description:
** list
*/

#include "ftp.h"

static void process_list(client_t *_client)
{
    client_t *new_client = malloc(sizeof(client_t));
    socklen_t size = sizeof(new_client);
    FILE *file;
    char string[4096];

    new_client->_fd = 2 == _client->_mod._passv ? _client->_mod._fd :
        accept(_client->_mod._fd, sizesockadd(new_client), &size);
    if (-1 == new_client->_fd) {
        client_message(ERR_CONNECTION);
        return;
    }
    file = popen("ls -l", "r");
    while (fgets(string, 4096, file))
        dprintf(new_client->_fd, "%s", string);
    fclose(file);
    close(_client->_mod._fd);
    close(new_client->_fd);
    _client->_mod._fd = -1;
    client_message(DIRECTORY_SENT);
}

void list(client_t *_client)
{
    check_user_is_connected(_client);
    if (!_client->_mod._passv)
        client_message(PORT_PASV_FIRST);
    else {
        process_list(_client);
    }
}