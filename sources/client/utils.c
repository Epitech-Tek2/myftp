/*
** EPITECH PROJECT, 2021
** ftp
** File description:
** utils
*/

#include "ftp.h"

char *get_ip(arr_const_restrict _arr)
{
    char *string = malloc(ip_get_size(_arr));
    int x = 0;

    if (NULL == string)
        return NULL;
    for (int i = 0, n = 0; _arr[i] && 4 != i; i++, x++) {
        for (n = 0; _arr[i][n]; n++, x++)
            string[x] = _arr[i][n];
        string[x] = '.';
    }
    string[x] = '\0';
    return string;
}

static int open_fd(client_action_t *_new_client, client_t *_client, int _size,
    bool _fopen)
{
    socklen_t size = sizeof(_new_client->_client->_in_client);

    _new_client->_client->_fd = 2 == _client->_mod._passv ? _client->_mod._fd :
        accept(_client->_mod._fd, sizesockadd(_new_client->_client), &size);
    if (-1 == _new_client->_client->_fd) {
        client_message(ERR_CONNECTION);
        return 2;
    }
    (void)(!_fopen && (_new_client->_file._file =
        open(_client->_command._arr[1], STOR_RIGHTS)));
    (void)(_fopen && (_new_client->_file._ffile = popen("ls -l", "r")));
    _new_client->_file._str = malloc(_size);
    if (!_fopen && -1 == _new_client->_file._file)
        return 2;
    return 0;
}

client_action_t *get_new_tmp_client(client_t *_client, int _size, int *_error,
    bool _fopen)
{
    client_action_t *new_client = malloc(sizeof(client_action_t));

    if (NULL == new_client) {
        *_error = 3;
        return NULL;
    }
    new_client->_client = malloc(sizeof(client_t));
    if (NULL == new_client->_client) {
        my_free(new_client);
        *_error = 3;
        return NULL;
    }
    if (2 == open_fd(new_client, _client, _size, _fopen)) {
        my_free(new_client->_client, new_client);
        *_error = 2;
        return NULL;
    }
    return new_client;
}