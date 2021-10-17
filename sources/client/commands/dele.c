/*
** EPITECH PROJECT, 2021
** ftp
** File description:
** dele
*/

#include "ftp.h"

void dele(client_t *_client)
{
    check_user_is_connected(_client);
    if (_client->_command._arr[1] && 0 == remove(_client->_command._arr[1])) {
        client_message(FILE_DELETED);
        return;
    }
    client_message(FILE_NOT_FOUND);
}