/*
** EPITECH PROJECT, 2021
** ftp
** File description:
** ftp
*/

#include "ftp.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <math.h>
#include <string.h>

void ftp(int const _ac, arr_const_restrict _av)
{
    server_t *server = NULL;

    errno = 0;
    if (2 == _ac && !strcmp(_av[1], "-help"))
        helper(0);
    if (3 != _ac)
        eraise_with_help("Expected 3 arguments");
    server = malloc(sizeof(server_t));
    if (NULL == server)
        eraise();
    server_init(server, _av[1], _av[2]);
    client(server);
    my_free(server->_socket, server);
}