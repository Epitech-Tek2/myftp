##
## EPITECH PROJECT, 2021
## ftp [WSL: Ubuntu]
## File description:
## Makefile
##

CC	=	gcc

RM	=	rm -f

PATH_COMMON	=	./sources/
SRC_COMMON	=	ftp.c

PATH_UTILS	=	./sources/utils/
SRC_UTILS	=	helper.c	\
				itoa.c	\
				issdigit.c	\
				getline.c	\
				strtok.c

PATH_SERVER	=	./sources/server/
SRC_SERVER	=	server_init.c

PATH_CLIENT	=	./sources/client/
SRC_CLIENT	=	client.c	\
				process_client.c	\
				utils.c

PATH_CLIENT_COMMAND	=	./sources/client/commands/
SRC_CLIENT_COMMAND	=	cdup.c	\
						cwd.c	\
						help.c	\
						pass.c	\
						quit.c	\
						user.c	\
						list.c	\
						noop.c	\
						stor.c	\
						dele.c	\
						port.c	\
						retr.c	\
						type.c	\
						passv.c	\
						pwd.c

SRC	=	sources/main.c	\
		$(addprefix $(PATH_COMMON), $(SRC_COMMON))	\
		$(addprefix $(PATH_UTILS), $(SRC_UTILS))	\
		$(addprefix $(PATH_SERVER), $(SRC_SERVER))	\
		$(addprefix $(PATH_CLIENT), $(SRC_CLIENT))	\
		$(addprefix $(PATH_CLIENT_COMMAND), $(SRC_CLIENT_COMMAND))

SRC_TESTS = $(addprefix $(PATH_COMMON), $(SRC_COMMON))	\
		$(addprefix $(PATH_UTILS), $(SRC_UTILS))	\
		$(addprefix $(PATH_SERVER), $(SRC_SERVER))	\
		$(addprefix $(PATH_CLIENT), $(SRC_CLIENT))	\
		$(addprefix $(PATH_CLIENT_COMMAND), $(SRC_CLIENT_COMMAND))

NAME	=	myftp

CFLAGS	=	-I./includes -lm -g

OBJS	=	$(SRC:.c=.o)
OBJS_TESTS	=	$(SRC_TESTS:.c=.o)

all: $(NAME)

$(NAME): lib $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS) $(LBLIBS)

tests_run:
	gcc $(SRC_TESTS) tests/*.c -o unit_tests --coverage -lcriterion -Iincludes/
	- ./unit_tests

lib:

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
