/*
** EPITECH PROJECT, 2021
** ftp
** File description:
** stor
*/

#include "ftp.h"

static void open_process(client_action_t *_tmp_client, client_t *_client)
{
    for (int i = 0; true;) {
        i = read(_tmp_client->_client->_fd, _tmp_client->_file._str, 2047);
        if (i <= 0)
            break;
        _tmp_client->_file._str[i] = '\0';
        dprintf(_tmp_client->_file._file, "%s", _tmp_client->_file._str);
    }
    client_message(TRANSFER_COMPLET);
    close(_client->_mod._fd);
    _client->_mod._passv = 0;
    close(_tmp_client->_file._file);
}

static bool process_stor(client_t *_client)
{
    int e = 0;
    client_action_t *tmp_client = get_new_tmp_client(_client, 2048, &e, false);

    if (NULL == tmp_client)
        return false;
    open_process(tmp_client, _client);
    return true;
}

void stor(client_t *_client)
{
    check_user_is_connected(_client);
    if (!_client->_mod._passv) {
        client_message(PORT_PASV_FIRST);
        return;
    }
    client_message(OPEN_BINARY);
    process_stor(_client);
}