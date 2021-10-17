/*
** EPITECH PROJECT, 2021
** ftp
** File description:
** cwd
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "struct.h"
#include "macro.h"
#include "define.h"

void cwd(client_t *_client)
{
    check_user_is_connected(_client);
    if (check_cwd_error(_client))
        client_message(FAIL_DIRECTORY);
    else
        client_message(SUCCESS_DIRECTORY);
}