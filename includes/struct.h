/*
** EPITECH PROJECT, 2021
** ftp
** File description:
** struct
*/

#pragma once

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdbool.h>

typedef struct server_s server_t;
typedef struct client_s client_t;
typedef struct socket_s socket_t;
typedef struct protoent protoent_t;
typedef struct sockaddr_in sockadd_in_t;
typedef struct user_s user_t;
typedef struct command_s command_t;
typedef struct mod_s mod_t;
typedef struct getline_s getline_t;
typedef struct client_action_s client_action_t;
typedef struct file_s file_t;

typedef char const *restrict str_const_restrict;

struct socket_s
{
    int _fd;
    int _port;
    protoent_t *_protoent;
    sockadd_in_t _sockaddr;
    socklen_t _sock_in_size;
};

struct user_s
{
    char *_username;
    char *_password;
    str_const_restrict _ip;
};

struct command_s
{
    char **_arr;
    char *_line;
    size_t _size;
};

struct mod_s
{
    int _passv;
    int _fd;
};

struct client_s
{
    command_t _command;
    user_t _user;
    sockadd_in_t _in_client;
    mod_t _mod;
    int _fd;
    int _passv_port;
    bool _is_connected;
    bool _status;
};

struct server_s
{
    str_const_restrict _wdir;
    socket_t *_socket;
    int _client_fd;
    bool _client_stop;
};

struct getline_s
{
    int _read;
    int _size;
    int _comp;
    char _save[6];
    char *_line;
};

struct file_s
{
    FILE *_ffile;
    int _file;
    char *_str;
};

struct client_action_s
{
    client_t *_client;
    file_t _file;
};