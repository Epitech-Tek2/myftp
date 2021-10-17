/*
** EPITECH PROJECT, 2021
** ftp
** File description:
** define
*/

#pragma once

#define P_PROTO _server->_socket->_protoent->p_proto

#define SOCKETADD_SIZE sizeof(_socket->_sockaddr)

#define SOCKADDR (struct sockaddr *)&_socket->_sockaddr

#define GET_IP inet_ntoa(_client.sin_addr)

#define DELIM "  \t\n\r"

#define PORT_CALC atoi(_tmp_client->_command._arr[4]) * 256 + \
    atoi(_tmp_client->_command._arr[5])

#define UNKNOW_COMMAND "500 Unknow command.\n"
#define SUCCESS_COMMAND "220 (vsFTPd 3.0.0)\n"
#define NOT_LOGGED "530 You have to login with USER and PASS.\n"
#define PERMISSION_DENIED "530 Permission denied.\n"
#define FAIL_DIRECTORY "550 Failed to change directory.\n"
#define SUCCESS_DIRECTORY "250 Directory successfully changed.\n"
#define CANT_CHANGE_USER "530 Can't change from guest user.\n"
#define PASSWORD "331 You have to specify the password.\n"
#define USER_FIRST "503 You have to use USER first.\n"
#define LOGIN_INCORRECT "530 Login incorrect.\n"
#define LOGIN_SUCCESS "230 Login successful.\n"
#define EXIT "221 Goodbye.\n"
#define PORT_PASV_FIRST "425 You have to use PORT or PASV first.\n"
#define ERR_CONNECTION "425 Connection problem.\n"
#define DIRECTORY_SENT "226 Directory send OK.\n"
#define ILLEGAL_PASSV "500 Illegal PASV\n"
#define ILLEGAL_PORT "500 Illegal PORT\n"
#define PASSIVE_MOD "227 Entering in Passive Mode ("
#define NOOP "200 NOOP ok.\n"
#define OPEN_BINARY "150 Opening BINARY.\n"
#define TRANSFER_COMPLET "226 Transfer complete.\n"
#define FILE_NOT_FOUND "550 File not found.\n"
#define FILE_DELETED "250 File deleted.\n"
#define PORT_SUCCESS "200 PORT success.\n"

#define HELP "214\n"\
"USER <SP> <username> <CRLF>   : Specify user for authentication\n"\
"PASS <SP> <password> <CRLF>   : Specify password for authentication\n\n"\
"CWD  <SP> <pathname> <CRLF>   : Change working directory\n"\
"CDUP <CRLF>                   : Change working directory to parent directory"\
"\n\nQUIT <CRLF>                   : Disconnection\n\n"\
"DELE <SP> <pathname> <CRLF>   : Delete file on the server\n\n"\
"PWD  <CRLF>                   : Print working directory\n\n"\
"PASV <CRLF>                   : Enable 'passive' mode for data transfer\n\n"\
"PORT <SP> <host-port> <CRLF>  : Enable 'active' mode for data transfer\n\n"\
"HELP [<SP> <string>] <CRLF>   : List available commands\n\n"\
"NOOP <CRLF>                   : Do nothing\n\n"\
"(the following are commands using data transfer )\n"\
"RETR <SP> <pathname> <CRLF>   : Download file from server to client\n"\
"STOR <SP> <pathname> <CRLF>   : Upload file from client to server\n"\
"LIST [<SP> <pathname>] <CRLF> : List files in the current working directory\n"

#define STOR_RIGHTS O_CREAT | O_WRONLY | O_TRUNC, 0666

#define PASSV_PORT_CALC _client->_passv_port / 256, _client->_passv_port % 256

#define COMMAND_EXIST my_exist(_client->_command._arr[0]) && \
    !my_exist(_client->_command._arr[1])
