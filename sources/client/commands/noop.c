/*
** EPITECH PROJECT, 2021
** ftp
** File description:
** noop
*/

#include "ftp.h"

void noop(client_t *_client)
{
    check_user_is_connected(_client);
    client_message(NOOP);
}