/*
** EPITECH PROJECT, 2021
** ftp
** File description:
** process_client
*/

#include "ftp.h"

static char const *requested_functions[16] =
{
    "USER",
    "PASS",
    "PASV",
    "QUIT",
    "CWD",
    "PWD",
    "NOOP",
    "CDUP",
    "STOR",
    "LIST",
    "HELP",
    "DELE",
    "RETR",
    "TYPE",
    "PORT",
    NULL
};

static const void (*functions[15])(client_t *_client) =
{
    &user,
    &pass,
    &passv,
    &quit,
    &cwd,
    &pwd,
    &noop,
    &cdup,
    &stor,
    &list,
    &help,
    &dele,
    &retr,
    &type,
    &port
};

static bool command(client_t *_client)
{
    for (int i = 0; functions[i]; i++)
        if (!strcasecmp(_client->_command._arr[0], requested_functions[i])) {
            functions[i](_client);
            return true;
        }
    return false;
}

void process_client(client_t *_client)
{
    if (!command(_client))
        dprintf(_client->_fd, UNKNOW_COMMAND);
}