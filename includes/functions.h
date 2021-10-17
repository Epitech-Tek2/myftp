/*
** EPITECH PROJECT, 2021
** ftp
** File description:
** functions
*/

#pragma once

#include <stdbool.h>
#include <stdnoreturn.h>

void ftp(int const _ac, arr_const_restrict _av);

void server_init(server_t *_server, str_const_restrict _port,
    str_const_restrict _wdir);

void client(server_t *_server);

noreturn bool helper(int const _output);

char *my_itoa(int number);

bool issdigit(char const *restrict string);

char *my_getline(int const _fd);

char **my_strtok(str_const_restrict _string, str_const_restrict _delim);

void process_client(client_t *_client);

bool new_socket(bool _is_server, socket_t *_socket, str_const_restrict _port);

char *get_ip(arr_const_restrict _arr);

client_action_t *get_new_tmp_client(client_t *_client, int _size, int *_error,
    bool _fopen);

void cwd(client_t *_client);

void cdup(client_t *_client);

void help_cmd(client_t *_client);

void pass(client_t *_client);

void quit(client_t *_client);

void user(client_t *_client);

void list(client_t *_client);

void passv(client_t *_client);

void pwd(client_t *_client);

void noop(client_t *_client);

void stor(client_t *_client);

void dele(client_t *_client);

void retr(client_t *_client);

void type(client_t *_client);

void help(client_t *_client);

void port(client_t *_client);