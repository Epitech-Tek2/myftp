/*
** EPITECH PROJECT, 2021
** ftp
** File description:
** retr
*/

#include "ftp.h"

static void process(client_action_t *_tmp_client, client_t *_client)
{
    _tmp_client->_file._ffile = fopen(_client->_command._arr[1], "r+");
    _tmp_client->_file._str = malloc(4096);
    if (NULL == _tmp_client->_file._ffile) {
        close(_tmp_client->_client->_fd);
        fclose(_tmp_client->_file._ffile);
        client_message("550 This file doesn't exist.\n");
        return;
    }
    while (fgets(_tmp_client->_file._str, 4096, _tmp_client->_file._ffile))
        dprintf(_tmp_client->_client->_fd, "%s", _tmp_client->_file._str);
    fclose(_tmp_client->_file._ffile);
    client_message(TRANSFER_COMPLET);
    close(_tmp_client->_client->_fd);
    _client->_mod._passv = 0;
}

static bool process_retr(client_t *_client)
{
    int e = 0;
    client_action_t *tmp_client = get_new_tmp_client(_client, 4096, &e, true);

    if (NULL == tmp_client)
        return false;
    process(tmp_client, _client);
}

void retr(client_t *_client)
{
    check_user_is_connected(_client);
    if (!_client->_mod._passv) {
        client_message(PORT_PASV_FIRST);
        return;
    }
    client_message(OPEN_BINARY);
    process_retr(_client);
}