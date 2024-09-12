# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwoon <cwoon@student.42kl.edu.my>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/29 16:26:34 by cwoon             #+#    #+#              #
#    Updated: 2024/09/12 21:32:26 by cwoon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------------------------------------------------------------------------------#
#                                  GENERICS                                    #
#------------------------------------------------------------------------------#

.PHONY: all bonus clean fclean re
.SILENT:

#------------------------------------------------------------------------------#
#                                VARIABLES                                     #
#------------------------------------------------------------------------------#

# Compiler and flag
CC				=	gcc
CFLAGS			=	-Wall -Werror -Wextra -I$(INC_LIBFT) -I$(INC_DIR)
VALGRIND_FLAGS	=	-ggdb3 -std=c11
DEBUG_FLAGS		=	-g3 -fsanitize=address
RM				=	rm -rf

# Output file name
NAME			=	push_swap
BONUS_NAME		=	checker

# Includes are all .h files
INC_LIBFT		=	libft/includes
LIBFT_FLAGS		=	-L$(LIBFT_DIR) -lft
INC_DIR			=	includes/

# Sources are all .c files
STACK_DIR		=	stack/
PUSH_SWAP_DIR	=	push_swap_mandatory/
CHECKER_DIR		=	checker_bonus/

# Objects are all .o files
OBJS_DIR		=	bin/

LIBFT_DIR		= libft

STACK_FILES 	=	stack/operations_1_swap.c \
					stack/operations_2_push.c \
					stack/operations_3_rotate.c \
					stack/operations_4_reverse_rotate.c \
					stack/utils_operations.c \
					stack/utils_optimization.c \
					stack/utils_stack.c

PUSH_SWAP_FILES	=	push_swap_mandatory/main_push_swap.c \
					push_swap_mandatory/operations_chunk.c \
					push_swap_mandatory/post_sort_optimization.c \
					push_swap_mandatory/sort.c \
					push_swap_mandatory/three_way_quick_sort.c \
					push_swap_mandatory/utils_chunk.c \
					push_swap_mandatory/utils_data.c \
					push_swap_mandatory/utils_validate.c \

CHECKER_FILES	=	checker_bonus/main_checker_bonus.c \
					checker_bonus/utils_checker_bonus.c \
					checker_bonus/utils_data_bonus.c \
					checker_bonus/utils_validate_bonus.c \
					checker_bonus/utils_flag_bonus.c \
					checker_bonus/utils_validate_flag_bonus.c \
					stack/operations_1_swap.c \
					stack/operations_2_push.c \
					stack/operations_3_rotate.c \
					stack/operations_4_reverse_rotate.c \
					stack/utils_operations.c \
					stack/utils_optimization.c \
					stack/utils_stack.c \

MANDATORY_FILES	=	$(STACK_FILES) $(PUSH_SWAP_FILES)
MANDATORY_OBJS	=	$(patsubst %.c, $(OBJS_DIR)%.o, $(MANDATORY_FILES))

BONUS_FILES	=	$(CHECKER_FILES)
BONUS_OBJS	=	$(patsubst %.c, $(OBJS_DIR)%.o, $(BONUS_FILES))

#------------------------------------------------------------------------------#
#                                 TARGETS                                      #
#------------------------------------------------------------------------------#

all: $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME) : $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME) $(LIBFT_FLAGS)

# Generates output file
$(NAME): $(MANDATORY_OBJS)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(MANDATORY_OBJS) -o $(NAME) $(LIBFT_FLAGS)

# Rule to compile the mandatory object files
$(OBJS_DIR)%.o: %.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to create the object directory if it doesn't exist
$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)$(CHECKER_DIR)
	mkdir -p $(OBJS_DIR)$(STACK_DIR)
	mkdir -p $(OBJS_DIR)$(PUSH_SWAP_DIR)

remake_libft:
	make re -C $(LIBFT_DIR)

# Removes objects
clean:
	$(RM) $(OBJS_DIR)
	make clean -C $(LIBFT_DIR)

# Removes objects and executables
fclean: clean
	$(RM) $(NAME)
	$(RM) $(BONUS_NAME)
	make fclean -C $(LIBFT_DIR)

# Removes objects and executables and remakes
re: fclean $(OBJS_DIR) all
