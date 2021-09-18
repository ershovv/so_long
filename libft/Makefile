# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bshawn <bshawn@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/20 13:08:40 by bshawn            #+#    #+#              #
#    Updated: 2021/09/04 21:17:40 by bshawn           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEAD = libft.h

LIST = 	ft_atoi.c		ft_bzero.c		ft_calloc.c\
		ft_isalnum.c	ft_isalpha.c	ft_isascii.c\
		ft_isdigit.c	ft_isprint.c	ft_memccpy.c\
		ft_memchr.c		ft_memcmp.c		ft_memcpy.c\
		ft_memmove.c	ft_memset.c		ft_putendl_fd.c\
		ft_putnbr_fd.c	ft_putstr_fd.c	ft_strchr.c\
		ft_strdup.c		ft_strlcat.c	ft_strlcpy.c\
		ft_strlen.c		ft_strncmp.c	ft_strnstr.c\
		ft_strrchr.c	ft_substr.c		ft_tolower.c\
		ft_toupper.c	ft_putchar_fd.c	ft_itoa.c\
		ft_strjoin.c	ft_strtrim.c	ft_strmapi.c\
		ft_split.c		get_next_line.c\

OBJS = $(LIST:.c=.o)

BONUS =	ft_lstnew.c		ft_lstadd_front.c	ft_lstsize.c\
		ft_lstlast.c	ft_lstadd_back.c	ft_lstdelone.c\
		ft_lstclear.c	ft_lstiter.c		ft_lstmap.c\
					
BONUS_OBJS	= $(BONUS:.c=.o)

CC = gcc

FLAGS = -Werror -Wextra -Wall

RM = rm -f

NAME = libft.a

all : $(NAME)

$(NAME) : $(OBJS) $(HEAD)
		ar rcs $(NAME) $(OBJS)

%.o : %.c $(HEAD)
		$(CC) $(FLAGS) -o $@ -c $<

clean : 
		$(RM) $(OBJS) $(BONUS_OBJS)

fclean :	clean
		$(RM) $(NAME)
		
bonus: $(BONUS_OBJS)
		ar rcs $(NAME) $(BONUS_OBJS)

re:	fclean $(NAME) clean clean
		
.PHONY : all clean fclean re bonus