/*
** EPITECH PROJECT, 2021
** ftp
** File description:
** client
*/

#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include "ftp.h"

static client_t *create_new_client(server_t *_server, int const _client_fd,
    str_const_restrict _ip)
{
    client_t *client = malloc(sizeof(client_t));

    if (NULL == client)
        return NULL;
    client->_fd = _client_fd;
    client->_command._line = NULL;
    init_client_user(client, _ip);
    init_client_mod(client);
    client->_is_connected = false;
    client->_status = true;
    return client;
}

static void handle_file(client_t *_client)
{
    if (NULL == _client->_command._line)
        return;
    if (strlen(_client->_command._line)) {
        _client->_command._arr = my_strtok(_client->_command._line, DELIM);
        if (NULL != _client->_command._arr) {
            process_client(_client);
            my_free_arr((void **)_client->_command._arr);
        } else
            dprintf(_client->_fd, UNKNOW_COMMAND);
    }
}

static bool new_client(server_t *_server, int const _client_fd,
    str_const_restrict _ip)
{
    client_t *client = create_new_client(_server, _client_fd, _ip);

    if (NULL == client)
        return false;
    dprintf(client->_fd, SUCCESS_COMMAND);
    while (true) {
        client->_command._line = my_getline(client->_fd);
        if (NULL != client->_command._line && NULL != client->_command._line) {
            handle_file(client);
            free(client->_command._line);
        }
        if (!client->_status) {
            _server->_client_stop = true;
            break;
        }
    }
    my_free(client->_user._username, client);
    return true;
}

static void client_init(server_t *_server, sockadd_in_t _client)
{
    if (-1 == _server->_socket->_fd)
        eraise(_server->_socket, _server, _client);
    if (fork() == 0) {
        if (!new_client(_server, _server->_client_fd, GET_IP))
            eraise(_server->_socket, _server);
        close(_server->_socket->_fd);
        exit(0);
    } else
        close(_server->_client_fd);
}

void client(server_t *_server)
{
    sockadd_in_t client;

    while (!_server->_client_stop) {
        _server->_client_fd = accept(_server->_socket->_fd,
            (struct sockaddr *)&client, &_server->_socket->_sock_in_size);
        if (-1 != _server->_client_fd)
            client_init(_server, client);
    }
    close(_server->_client_fd);
}