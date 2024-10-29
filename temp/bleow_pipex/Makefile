# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bleow <bleow@student.42kl.edu.my>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/25 00:56:19 by bleow             #+#    #+#              #
#    Updated: 2024/10/28 21:22:07 by bleow            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = clang
CFLAGS = -Wall -Wextra -Werror -gdwarf-4 -std=c89
DEBUG_FLAGS = -gdwarf-4
SANITIZE_FLAGS = -fsanitize=address

LIBFT_DIR = libft
PIPEX_DIR = srcs
INCLUDE_DIRS = includes $(LIBFT_DIR)/includes
INCLUDES = $(addprefix -I, $(INCLUDE_DIRS))

PIPEX_SRCS = srcs/pipex.c \
			 srcs/pipex_parser.c \
			 srcs/pipex_cleanup.c \
			 srcs/pipex_builder.c

PIPEX_OBJS_DIR = objects

PIPEX_OBJS = $(PIPEX_SRCS:srcs/%.c=$(PIPEX_OBJS_DIR)/%.o)

OBJS = $(PIPEX_OBJS)

all: $(NAME)

$(NAME): $(LIBFT_DIR)/libft.a $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

$(PIPEX_OBJS_DIR)/%.o: srcs/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT_DIR)/libft.a:
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -rf objects
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

debug: CFLAGS += $(DEBUG_FLAGS)
debug: re

sanitize: CFLAGS += $(SANITIZE_FLAGS)
sanitize: re

valgrind: debug
	valgrind --leak-check=full --track-origins=yes ./$(NAME)

.PHONY: all clean fclean re debug sanitize valgrind