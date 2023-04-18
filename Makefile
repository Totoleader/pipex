# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: macote <macote@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/10 10:34:58 by macote            #+#    #+#              #
#    Updated: 2023/04/18 09:40:38 by macote           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= pipex
CFLAGS	:= -Wall -Wextra -Werror

HEADERS	:= -I ./include
LIBFT 	:= ./libft
LIBS 	:= $(LIBFT)/libft.a
SRCS	:= src/main/main.c \
			src/parsing/find_path.c \
			src/parsing/parse.c \
			src/utils/free.c \
			src/utils/function_check2.c \
			src/utils/function_check.c \
			src/main/commands.c \

OBJS	:= ${SRCS:.c=.o}

all: lib $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

lib:
	@make -C $(LIBFT) all
	
$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME) $(CFLAGS)

clean:
	@rm -f $(OBJS)
	@rm -f $(OBJSLIB)
	@rm -f $(LIBS)

fclean: clean
	@rm -f $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx