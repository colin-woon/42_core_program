# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/29 16:26:34 by cwoon             #+#    #+#              #
#    Updated: 2024/09/02 18:52:33 by cwoon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------------------------------------------------------------------------------#
#                                  GENERICS                                    #
#------------------------------------------------------------------------------#

.PHONY: all bonus clean fclean re
# .SILENT

#------------------------------------------------------------------------------#
#                                VARIABLES                                     #
#------------------------------------------------------------------------------#

# Compiler and flags
CC				=	gcc
CFLAGS			=	-Wall -Werror -Wextra -I$(INC_LIBFT) -I$(INC_DIR) -O2 $(DEBUG_FLAGS)
DEBUG_FLAGS		=	-g3 -fsanitize=address
RM				=	rm -rf

# Output file name
NAME			=	push_swap

# Includes are all .h files
INC_LIBFT		=	libft/includes
LIBFT_FLAGS		=	-L$(LIBFT_DIR) -lft
INC_DIR			=	includes/
INC_FILES		=	push_swap.h stack.h

# Sources are all .c files
STACK_DIR		=	stack/
PUSH_SWAP_DIR	=	push_swap_mandatory/

# Objects are all .o files
OBJS_DIR		=	bin/

LIBFT_DIR		= libft

STACK_FILES 	=	stack/operations_1_swap.c \
					stack/operations_2_push.c \
					stack/operations_3_rotate.c \
					stack/operations_4_reverse_rotate.c \
					stack/utils_operations.c \
					stack/utils_stack.c

PUSH_SWAP_FILES	=	push_swap_mandatory/main.c \
					push_swap_mandatory/operations_chunk.c \
					push_swap_mandatory/sort.c \
					push_swap_mandatory/three_way_quick_sort.c \
					push_swap_mandatory/utils_chunk.c \
					push_swap_mandatory/utils_data.c \
					push_swap_mandatory/utils_validate.c

MANDATORY_FILES	=	$(STACK_FILES) $(PUSH_SWAP_FILES)
MANDATORY_OBJS	=	$(patsubst %.c, $(OBJS_DIR)%.o, $(MANDATORY_FILES))

#------------------------------------------------------------------------------#
#                                 TARGETS                                      #
#------------------------------------------------------------------------------#

all: $(NAME)

# Generates output file
$(NAME): $(MANDATORY_OBJS)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(MANDATORY_OBJS) -o $(NAME) $(LIBFT_FLAGS)

# Rule to compile the mandatory object files
$(OBJS_DIR)%.o: %.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to create the object directory if it doesn't exist
$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)$(STACK_DIR)
	mkdir -p $(OBJS_DIR)$(PUSH_SWAP_DIR)

# Removes objects
clean:
	$(RM) $(OBJS_DIR)

# Removes objects and executables
fclean: clean
	$(RM) $(NAME)

# Removes objects and executables and remakes
re: fclean all
