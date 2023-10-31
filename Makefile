NAME = libft.a
FLAGS = -Wall -Wextra -Werror
SRCS = \
ft_isalpha.c \
ft_isdigit.c \
ft_isalnum.c \
ft_isascii.c \
ft_isprint.c \
ft_strlen.c \
ft_memset.c \
ft_bzero.c \
ft_memcpy.c \
ft_toupper.c \
ft_tolower.c \
ft_memmove.c \
ft_strlcpy.c \
ft_strlcat.c \
ft_atoi.c \
ft_strchr.c \
ft_strrchr.c \
ft_strncmp.c \
ft_memchr.c \
ft_memcmp.c \
ft_strnstr.c \
ft_calloc.c \
ft_strdup.c \
ft_substr.c \
ft_strjoin.c \
ft_strtrim.c \
ft_putstr_fd.c \
ft_putchar_fd.c \
ft_putnbr_fd.c \
ft_putendl_fd.c \
ft_striteri.c \
ft_strmapi.c \
ft_split.c \
ft_itoa.c
BONUS_SRCS = \
ft_lstnew.c \
ft_lstadd_front.c \
ft_lstsize.c \
ft_lstlast.c \
ft_lstadd_back.c
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

.c.o:
	cc ${FLAGS} -c $< -o ${<:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus: $(OBJS) $(BONUS_OBJS)
	ar r $(NAME) $(BONUS_OBJS) $(OBJS)

clean: 
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: all
	cc main.c -o main -L. -lft
	./main


.PHONY: all clean fclean re test bonus