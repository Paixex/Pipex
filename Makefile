# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: digil-pa <digil-pa@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/13 15:07:01 by digil-pa          #+#    #+#              #
#    Updated: 2023/05/07 17:10:04 by digil-pa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex.a
HEADER = pipex.h

SRCS	=	ft_split.c
			libft_utils.c	\
		 	pipex_utils.c	\
		 	pipex.c			\

OBJS	= $(SRCS:.c=.o)

CC	= cc

RM	= rm -f

CFLAGS	= -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re