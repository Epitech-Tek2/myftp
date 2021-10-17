/*
** EPITECH PROJECT, 2021
** ftp
** File description:
** cdup
*/

#include "ftp.h"
#include "define.h"
#include "struct.h"

void cdup(client_t *_client)
{
    check_user_is_connected(_client);
    if (-1 == chdir("../"))
        client_message(FAIL_DIRECTORY);
    else
        client_message(SUCCESS_DIRECTORY);
}