# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rade-sar <rade-sar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/13 22:50:47 by rade-sar          #+#    #+#              #
#    Updated: 2022/09/13 22:50:47 by rade-sar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

########## 		   NAMES 		##########

NAME = pipex

########## 		  SOURCES 		##########

SRC_PATH = ./src/

SRC = ${SRC_PATH}main.c		\
	${SRC_PATH}check.c	\
	${SRC_PATH}error_msg.c	\
	${SRC_PATH}process_pipe.c	\
	${SRC_PATH}get_cmds.c

########## 		  INCLUDES 		##########

HEAD = ./include

########## 		   LIBFT 		##########

LIBFT = libft

LIBFT_PATH = ./include/libft/

########## 		COMPILATION 	##########

OBJ = ${SRC:.c=.o}

OBJB = ${BNS:.c=.o}

CC = gcc

########## 		   FLAGS 		##########

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

########## 		   COLORS 		##########

GREEN		=	\033[0;32m
YELLOW		=	\033[0;33m
RED			=	\033[0;31m
RESET		=	\033[0m

########## 		  COMMANDS		##########

MAKE_LIBFT = cd ${LIBFT_PATH} && make all

CLEAN_LIBFT = cd ${LIBFT_PATH} && make clean -s

FCLEAN_LIBFT = cd ${LIBFT_PATH} && make fclean -s

RM = rm -f

########## 		  MESSAGES 		##########

CREATE_PROJ_MSG = @echo "\n<========== $(GREEN)$(NAME) created$(RESET) ==========>\n"

REMOVED_MSG = @echo "\n<========== $(RED)$(NAME) removed$(RESET) ==========>\n"

NORM_LIBFT_MSG = @echo "\n<========== $(YELLOW)Norm $(LIBFT)$(RESET) ==========>\n"

NORM_PROJ_MSG = @echo "\n<========== $(YELLOW)Norm $(NAME)$(RESET) ==========>\n"

########## 		  TARGETS 		##########

${NAME}: ${OBJ} 
	${MAKE_LIBFT} -s
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L $(LIBFT_PATH) -lft

########## 		   RULES 		##########

all: ${NAME} 
	${CREATE_PROJ_MSG}

clean:
	${CLEAN_LIBFT}
	${RM} ${OBJ}

fclean: clean 
	${FCLEAN_LIBFT}
	${RM} ${NAME} ${BONUS}
	${REMOVED_MSG}

re: fclean all

norm:
	@cd ${LIBFT_PATH} && make norm
	${NORM_PROJ_MSG}
	@cd ./src && norminette -R CheckForbiddenSourceHeader *.c && cd ../include && norminette -R CheckDefine *.h

commit:
	git add .
	git commit -m "update"
	git push

.PHONY: all clean fclean re norm commit
