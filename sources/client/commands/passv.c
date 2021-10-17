/*
** EPITECH PROJECT, 2021
** ftp
** File description:
** passv
*/

#include "ftp.h"

static bool passv_mod(client_t *_client, protoent_t *_protoent)
{
    socket_t *socket = malloc(sizeof(socket_t));

    if (-1 != _client->_mod._fd)
        close(_client->_mod._fd);
    socket->_protoent = getprotobyname("TCP");
    if (NULL == socket->_protoent)
        return false;
    if (!new_socket(false, socket, "0\0"))
        return false;
    _client->_passv_port = ntohs(socket->_sockaddr.sin_port);
    _client->_mod._fd = socket->_fd;
    return true;
}

void passv(client_t *_client)
{
    protoent_t *protoent = NULL;
    char **ip_address = NULL;
    char *tmp_ip = NULL;

    check_user_is_connected(_client);
    if (!passv_mod(_client, protoent)) {
        client_message(ILLEGAL_PASSV);
        return;
    }
    tmp_ip = strdup(_client->_user._ip);
    _client->_mod._passv = 1;
    ip_address = my_strtok(tmp_ip, ".");
    my_free(tmp_ip);
    client_message(PASSIVE_MOD);
    for (int i = 0; ip_address[i]; i++)
        dprintf(_client->_fd, "%s,", ip_address[i]);
    dprintf(_client->_fd, "%d,%d).\n", PASSV_PORT_CALC);
    my_free_arr((void **)ip_address);
}