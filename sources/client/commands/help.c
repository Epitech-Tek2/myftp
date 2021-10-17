/*
** EPITECH PROJECT, 2021
** ftp
** File description:
** help
*/

#include "macro.h"
#include "struct.h"

void help(client_t *_client)
{
    check_user_is_connected(_client);
    client_message(HELP);
    client_message("214 Help.\n");
}