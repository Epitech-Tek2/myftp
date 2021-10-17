/*
** EPITECH PROJECT, 2021
** ftp
** File description:
** server_init
*/

#include "ftp.h"

static bool bind_and_listen(bool _is_server, socket_t *_socket)
{
    if (-1 == bind(_socket->_fd, SOCKADDR, SOCKETADD_SIZE)) {
        cErr(strerror(errno));
        if (_is_server && -1 == shutdown(_socket->_fd, 2))
            return false;
        if (_is_server && -1 == close(_socket->_fd))
            return false;
        return false;
    }
    if (-1 == listen(_socket->_fd, 42)) {
        if (_is_server && -1 == close(_socket->_fd))
            return false;
        return false;
    }
    getsockname(_socket->_fd,
    (struct sockaddr *)&_socket->_sockaddr, &_socket->_sock_in_size);
    return true;
}

bool new_socket(bool _is_server, socket_t *_socket, str_const_restrict _port)
{
    _socket->_port = atoi(_port);
    create_socket(_socket->_fd, 0);
    if (_is_server && -1 == _socket->_fd)
        return false;
    _socket->_sock_in_size = sizeof(_socket);
    _socket->_sockaddr.sin_family = AF_INET;
    _socket->_sockaddr.sin_port = htons(_socket->_port);
    _socket->_sockaddr.sin_addr.s_addr = INADDR_ANY;
    return bind_and_listen(true, _socket);
}

static void init_server_values(server_t *_server, str_const_restrict _port,
    str_const_restrict _wdir)
{
    _server->_wdir = _wdir;
    _server->_client_stop = false;
    _server->_socket = malloc(sizeof(socket_t));
    if (NULL == _server->_socket)
        eraise(_server->_socket, _server);
    if (-1 == chdir(_wdir))
        eraise(_server->_socket, _server);
    _server->_socket->_protoent = getprotobyname("TCP");
    if (NULL == _server->_socket->_protoent)
        eraise(_server->_socket, _server);
    if (!issdigit(_port))
        eraise_with_help("Given port must be a number");
}

void server_init(server_t *_server, str_const_restrict _port,
    str_const_restrict _wdir)
{
    init_server_values(_server, _port, _wdir);
    if (!new_socket(true, _server->_socket, _port))
        eraise(_server->_socket, _server);
}