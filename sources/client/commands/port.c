/*
** EPITECH PROJECT, 2021
** ftp
** File description:
** port
*/

#include "ftp.h"

static bool init_port(client_t *_client, client_t *_tmp_client)
{
    socklen_t size = sizeof(_tmp_client->_in_client);

    _tmp_client->_in_client.sin_port = htons(PORT_CALC);
    _tmp_client->_in_client.sin_family = AF_INET;
    _tmp_client->_in_client.sin_addr.s_addr =
        inet_addr(get_ip((arr_const_restrict)_tmp_client->_command._arr));
    if (-1 == connect(_client->_mod._fd, sizesockadd(_tmp_client), size))
        return false;
    my_free_arr((void **)_tmp_client->_command._arr);
    client_message(PORT_SUCCESS);
    _client->_mod._passv = 2;
    return true;
}

static bool port_process(client_t *_client)
{
    client_t *tmp_client = malloc(sizeof(client_t));
    protoent_t *protoent = getprotobyname("TCP");

    if (NULL == tmp_client || NULL == protoent)
        return false;
    tmp_client->_command._arr = my_strtok(_client->_command._arr[1], ",\n");
    for (int i = 0; tmp_client->_command._arr[i]; i++)
        if (!issdigit(tmp_client->_command._arr[i])) {
            client_message(ILLEGAL_PORT);
            return false;
        }
    if (-1 == _client->_mod._fd)
        close(_client->_mod._fd);
    _client->_mod._fd = socket(AF_INET, SOCK_STREAM, protoent->p_proto);
    if (-1 == _client->_mod._fd) {
        return false;
    }
    return init_port(_client, tmp_client);
}

void port(client_t *_client)
{
    check_user_is_connected(_client);
    if (!_client->_command._arr[1]) {
        client_message(ILLEGAL_PORT);
        return;
    }
    if (!port_process(_client))
        client_message(ILLEGAL_PORT);
}