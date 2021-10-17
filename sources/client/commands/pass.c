/*
** EPITECH PROJECT, 2021
** ftp
** File description:
** pass
*/

#include <string.h>
#include "ftp.h"

static void login(client_t *_client)
{
    if (strcmp("Anonymous", _client->_user._username)) {
        client_message(LOGIN_INCORRECT);
        return;
    }
    my_free(_client->_user._password);
    client_message(LOGIN_SUCCESS);
    if (NULL != _client->_command._arr[1])
        _client->_user._password = strdup(_client->_command._arr[1]);
    _client->_is_connected = true;
}

void pass(client_t *_client)
{
    if (_client->_user._username)
        login(_client);
    else
        client_message(USER_FIRST);
}