#------------------------------------------------------------------------------#
#                                VARIABLES                                     #
#------------------------------------------------------------------------------#

# Compiler and flags
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
RM		=	rm -f

# Output file name
NAME	=	libftprintf.a

SRCDIR	=	src/
OBJDIR	=	bin/
INCDIR	=	-Iinclude

SRCS_FILES	=	ft_print_char			\
				ft_print_address 		\
				ft_print_hexa 			\
				ft_print_nbr 			\
				ft_print_string 		\
				ft_print_unsigned_nbr	\
				ft_printf				\

SRCS	=	$(addprefix $(SRCDIR), $(addsuffix .c, $(SRCS_FILES)))
OBJS	=	$(addprefix $(OBJDIR), $(addsuffix .o, $(SRCS_FILES)))

#------------------------------------------------------------------------------#
#                                 TARGETS                                      #
#------------------------------------------------------------------------------#

all: $(NAME)

# Generates output file
$(NAME): $(OBJS)
	ar rcs $@ $^

# Compiles sources into objects
$(OBJDIR)%.o : $(SRCDIR)%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INCDIR) -c $< -o $@

# Removes objects
clean:
	$(RM) $(OBJS)

# Removes objects and executables
fclean: clean
	$(RM) $(NAME)

# Removes objects and executables and remakes
re: fclean all
