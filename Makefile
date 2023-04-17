# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: digil-pa <digil-pa@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/13 15:07:01 by digil-pa          #+#    #+#              #
#    Updated: 2023/04/17 17:34:51 by digil-pa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex.a
HEADER = pipex.h

SRCS	=	libft_utils.c	\
		 	pipex_utils.c	\
		 	pipex.c			\
		 		\
		 		\
		 		\

OBJS	= $(SRCS:.c=.o)

CC	= gcc

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