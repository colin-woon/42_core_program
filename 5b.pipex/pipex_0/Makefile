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
TEMP	= -Werror
CFLAGS	=	-Wall -Weeror -Wextra -I$(INC_LIBFT) -I$(INC_DIR)
DEBUG	=	-g3 -fsanitize=address 
RM		=	rm -rf

# Output file name
NAME	=	pipex

# Directories
LIBFT_DIR		=	libft
INC_LIBFT		=	libft/includes
INC_DIR			=	includes/
SRCS_DIR		=	srcs/
OBJS_DIR		=	bin/

LIBFT_FLAGS		=	-L$(LIBFT_DIR) -lft

SRCS_FILES		=	srcs/execution.c \
					srcs/main.c \
					srcs/parser.c \
					srcs/utils_cmd_lst.c \
					srcs/utils_error.c \
					srcs/utils_free.c \
					srcs/utils_parser_args.c \
					srcs/utils_parser_cmd.c \
					srcs/utils_parser_files.c \
					srcs/utils_parser_path.c \
					srcs/utils.c
					
OBJS_FILES		=	$(patsubst %.c, $(OBJS_DIR)%.o, $(SRCS_FILES))

#------------------------------------------------------------------------------#
#                                 TARGETS                                      #
#------------------------------------------------------------------------------#

all: $(NAME)

bonus: all

# Generates output file
$(NAME): $(OBJS_FILES)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS_FILES) -o $(NAME) $(LIBFT_FLAGS)

# Rule to compile the mandatory object files
$(OBJS_DIR)%.o: %.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to create the object directory if it doesn't exist
$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)$(SRCS_DIR)

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
