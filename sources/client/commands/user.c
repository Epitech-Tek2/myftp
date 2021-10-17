/*
** EPITECH PROJECT, 2021
** ftp
** File description:
** user
*/

#include <stdio.h>
#include <string.h>
#include "macro.h"
#include "define.h"
#include "struct.h"

static void connection(client_t *_client)
{
    my_free(_client->_user._username);
    _client->_user._username = strdup(_client->_command._arr[1]);
    client_message(PASSWORD);
}

void user(client_t *_client)
{
    if (COMMAND_EXIST && _client->_is_connected)
        client_message(PERMISSION_DENIED);
    else if (_client->_is_connected)
        client_message(CANT_CHANGE_USER);
    else
        connection(_client);
}