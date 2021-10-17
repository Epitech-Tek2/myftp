/*
** EPITECH PROJECT, 2021
** ftp
** File description:
** quit
*/

#include "macro.h"
#include "struct.h"
#include "define.h"

void quit(client_t *_client)
{
    client_message(EXIT);
    _client->_status = false;
}