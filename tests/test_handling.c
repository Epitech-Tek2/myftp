/*
** EPITECH PROJECT, 2021
** ftp
** File description:
** test_handling
*/

#include <criterion/criterion.h>
#include "ftp.h"

Test(basic_test, ftp_exit, .exit_code=84)
{
    char **arr = malloc(sizeof(char *) * 2);

    arr[0] = "./myftp";
    arr[1] = NULL;
    ftp(1, (arr_const_restrict)arr);
    my_free_arr((void **)arr);
}

Test(server_init_test, ftp_exit, .exit_code=84)
{
    server_t *server = NULL;

    server = malloc(sizeof(server_t));
    server_init(server, "8000", "includes/");
}

Test(client_cdup, ftp_exit, .exit_code=0)
{
    client_t client;

    client._is_connected = true;
    cdup(&client);
}

Test(client_cwd, ftp_exit, .exit_code=0)
{
    client_t client;
    char **arr = malloc(sizeof(char *) * 4);

    client._is_connected = true;
    arr[0] = "./myftp";
    arr[1] = "cwd";
    arr[2] = "hello";
    arr[3] = NULL;
    client._command._arr = arr;
    cwd(&client);
}

Test(client_help, ftp_exit, .exit_code=0)
{
    client_t client;

    client._is_connected = true;
    help(&client);
}

Test(client_noop, ftp_exit, .exit_code=0)
{
    client_t client;

    client._is_connected = true;
    noop(&client);
}

Test(client_pass, ftp_exit, .exit_code=0)
{
    client_t client;
    char **arr = malloc(sizeof(char *) * 3);

    arr[0] = strdup("pass");
    arr[1] = strdup("");
    arr[2] = NULL;
    client._is_connected = true;
    client._user._username = "Anonymous";
    client._user._password = strdup("");
    client._command._arr = arr;
    pass(&client);
    my_free_arr((void **)arr);
}

Test(client_pwd, ftp_exit, .exit_code=0)
{
    client_t client;

    client._is_connected = true;
    pwd(&client);
}

Test(client_quit, ftp_exit, .exit_code=0)
{
    client_t client;

    client._is_connected = true;
    quit(&client);
}

Test(client_type, ftp_exit, .exit_code=0)
{
    client_t client;

    type(&client);
}

Test(client_user, ftp_exit, .exit_code=0)
{
    client_t client;
    char **arr = malloc(sizeof(char *) * 3);

    arr[0] = strdup("user");
    arr[1] = strdup("test new user name");
    arr[2] = NULL;
    client._is_connected = true;
    client._user._username = strdup("Anonymous");
    client._command._arr = arr;
    user(&client);
}

Test(client_stor_in_active_mod, ftp_exit, .exit_code=0)
{
    client_t client;

    client._is_connected = true;
    client._mod._passv = false;
    stor(&client);
}

Test(client_retr_in_active_mod, ftp_exit, .exit_code=0)
{
    client_t client;

    client._is_connected = true;
    client._mod._passv = false;
    retr(&client);
}

Test(client_list_in_active_mod, ftp_exit, .exit_code=0)
{
    client_t client;

    client._is_connected = true;
    client._mod._fd = 3;
    client._mod._passv = true;
    list(&client);
}

// Test(client_port, ftp_exit, .exit_code=0)
// {
//     client_t client;
//     char **arr = malloc(sizeof(char *) * 7);

//     arr[0] = strdup("port");
//     arr[1] = strdup("127.0.0.1");
//     arr[2] = strdup("127");
//     arr[3] = strdup("0");
//     arr[4] = strdup("0");
//     arr[5] = strdup("1");
//     arr[6] = NULL;
//     client._is_connected = true;
//     client._mod._fd = -1;
//     client._mod._passv = true;
//     client._command._arr = arr;
//     port(&client);
// }

Test(client_passv, ftp_exit, .exit_code=0)
{
    client_t client;

    client._is_connected = true;
    client._mod._passv = false;
    client._mod._fd = -1;
    client._user._ip = strdup("127.0.0.1");
    passv(&client);
}

Test(test_helper, ftp_exit, .exit_code=0)
{
    char **arr = malloc(sizeof(char *) * 3);

    arr[0] = "./myftp";
    arr[1] = "-help";
    arr[2] = NULL;
    ftp(2, (arr_const_restrict)arr);
}

Test(test_itoa, ftp_exit, .exit_code=0)
{
    my_itoa(40);
}

Test(test_getline, ftp_exit, .exit_code=0)
{
    int fd = open("./help.txt", O_RDONLY);

    my_getline(fd);
    my_getline(-1);
}

Test(test_getip, ftp_exit, .exit_code=0)
{
    char **arr = malloc(sizeof(char *) * 5);

    arr[0] = strdup("127");
    arr[1] = strdup("0");
    arr[2] = strdup("0");
    arr[3] = strdup("1");
    arr[4] = NULL;
    get_ip((arr_const_restrict)arr);
}

Test(test_get_tmp_client, ftp_exit, .exit_code=0)
{
    client_t client;
    char **arr = malloc(sizeof(char *) * 5);
    int e = 0;

    arr[0] = strdup("127");
    arr[1] = strdup("0");
    arr[2] = strdup("0");
    arr[3] = strdup("1");
    arr[4] = NULL;
    get_new_tmp_client(&client, 4096, &e, false);
    get_new_tmp_client(&client, 4096, &e, true);
}