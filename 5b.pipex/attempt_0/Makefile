#------------------------------------------------------------------------------#
#                                  GENERICS                                    #
#------------------------------------------------------------------------------#

.PHONY: all bonus clean fclean re
# .SILENT:

#------------------------------------------------------------------------------#
#                                VARIABLES                                     #
#------------------------------------------------------------------------------#

# Compiler and flags
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra -I$(INC_LIBFT) -I$(INC_DIR) $(DEBUG)
DEBUG	=	-g3 -fsanitize=address
RM		=	rm -rf

# Output file name
NAME	=	pipex

# Directories
LIBFT_DIR		=	libft
INC_LIBFT		=	libft/includes
INC_DIR			=	includes/
MANDATORY_DIR	=	srcs_mandatory/
OBJS_DIR		=	bin/

LIBFT_FLAGS		=	-L$(LIBFT_DIR) -lft

PIPEX_MANDATORY	=	srcs_mandatory/pipex.c \
					srcs_mandatory/utils.c

MANDATORY_FILES	=	$(PIPEX_MANDATORY)
MANDATORY_OBJS	=	$(patsubst %.c, $(OBJS_DIR)%.o, $(MANDATORY_FILES))
#------------------------------------------------------------------------------#
#                                 TARGETS                                      #
#------------------------------------------------------------------------------#

all: $(NAME)

# bonus: $(BONUS_NAME)

# $(BONUS_NAME) : $(BONUS_OBJS)
# 	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME) $(LIBFT_FLAGS)

# Generates output file
$(NAME): $(MANDATORY_OBJS)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(MANDATORY_OBJS) -o $(NAME) $(LIBFT_FLAGS)

# Rule to compile the mandatory object files
$(OBJS_DIR)%.o: %.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to create the object directory if it doesn't exist
$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)$(MANDATORY_DIR)

remake_libft:
	make re -C $(LIBFT_DIR)

# Removes objects
clean:
	$(RM) $(OBJS_DIR)
	make clean -C $(LIBFT_DIR)

# Removes objects and executables
# $(RM) $(BONUS_NAME)
fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_DIR)

# Removes objects and executables and remakes
re: fclean $(OBJS_DIR) all
