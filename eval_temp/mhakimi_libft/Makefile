NAME = libft.a

Files = ft_atoi \
	ft_bzero \
	ft_calloc \
	ft_isalnum \
	ft_isalpha \
	ft_isascii \
	ft_isdigit \
	ft_isprint \
	ft_itoa \
	ft_memchr \
	ft_memcmp \
	ft_memcpy \
	ft_memmove \
	ft_memset \
	ft_putchar_fd \
	ft_putendl_fd \
	ft_putnbr_fd \
	ft_putstr_fd \
	ft_split \
	ft_strchr \
	ft_strdup \
	ft_striteri \
	ft_strjoin \
	ft_strlcat \
	ft_strlcpy \
	ft_strlen \
	ft_strmapi \
	ft_strncmp \
	ft_strnstr \
	ft_strrchr \
	ft_strtrim \
	ft_substr \
	ft_tolower \
	ft_toupper

Bonus_Files = ft_lstnew \
	ft_lstadd_front \
	ft_lstadd_back \
	ft_lstdelone \
	ft_lstclear \
	ft_lstiter \
	ft_lstlast \
	ft_lstmap \
	ft_lstsize

Compiler = cc
Compiler_Flags = -Wall -Wextra -Werror

C_Files	= $(Files:%=%.c)
O_Files	= $(Files:%=%.o)
Bonus_C_Files = $(Bonus_Files:%=%.c)
Bonus_O_Files = $(Bonus_Files:%=%.o)

%.o: %.c
	$(Compiler) $(Compiler_Flags) -c $< -o $@

$(NAME): $(O_Files)
	ar -rc $(NAME) $(O_Files)

all: $(NAME)

bonus: $(NAME) $(Bonus_O_Files)
	ar -rc $(NAME) $(O_Files) $(Bonus_O_Files)

clean:
	rm -f $(O_Files) $(Bonus_O_Files)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
