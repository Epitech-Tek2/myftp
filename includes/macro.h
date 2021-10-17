/*
** EPITECH PROJECT, 2021
** ftp
** File description:
** macro
*/

#pragma once

#define _N__ARG(...) _N__ARGS(, ##__VA_ARGS__, 6, 5, 4, 3, 2, 1, 0)
#define _N__ARGS(z, a, b, c, d, e, f, cnt, ...) cnt

#define my_free(ptr, ...) my_free(_N__ARG(__VA_ARGS__), ptr, ##__VA_ARGS__)

#include <stdio.h>
#include "inline.h"

#define my_exist(ptr, ...) my_exist(_N__ARG(__VA_ARGS__), ptr, ##__VA_ARGS__)

#define cOut(message) printf("%s\n", message)
#define cErr(message) fprintf(stderr, "%s\n", message)
#define client_message(message) dprintf(_client->_fd, message)

#define ip_get_size(arr) (strlen(arr[0]) + strlen(arr[1]) + \
    strlen(arr[2]) + strlen(arr[3]) + 5)

#define eraise(...) ({ \
    cErr(strerror(errno)); \
    my_free(NULL, ##__VA_ARGS__); \
    exit(84); \
})

#define eraise_with_help(message) ({ \
    cErr(message); \
    helper(84); \
})

#define check_cwd_error(client) (NULL == client->_command._arr[1] || \
    my_exist(client->_command._arr[1], client->_command._arr[2]) || \
    !my_exist(realpath(client->_command._arr[1], NULL)) || \
    -1 == chdir(client->_command._arr[1]))

#define create_socket(fd, proto) fd = socket(AF_INET, SOCK_STREAM, proto)

#define check_user_is_connected(client) ({ \
    if (!_client->_is_connected) { \
        client_message(NOT_LOGGED); \
        return; \
    } \
})

#define init_client_user(client, ip) ({ \
    client->_user._ip = ip; \
    client->_user._username = NULL; \
    client->_user._password = NULL; \
})

#define init_client_mod(client) ({ \
    client->_mod._fd = -1; \
    client->_mod._passv = 0; \
})

#define sizesockadd(client) (struct sockaddr *)&client->_in_client
