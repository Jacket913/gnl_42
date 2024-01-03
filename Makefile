# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jacket <jacket@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/03 10:54:10 by jacket            #+#    #+#              #
#    Updated: 2024/01/03 14:49:16 by jacket           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= get_next_line

CC			= cc

CFLAGS		= -Werror -Wextra -Wall

SRC			= get_next_line_utils.c get_next_line.c

BONUS		= get_next_line_utils_bonus.c get_next_line_bonus.c

INCLUDE		= -I ./get_next_line

OBJ			= $(SRC:.c=.o)

BONUS_OBJ	= $(BONUS:.c=.o)

#COLORS
C_GOOD		=	"\033[32mSUCCESS"
C_ORAN		=	"\033[33mCleaning "
C_RED		=	"\033[31mDelete   "
C_WHIT		=	"\033[0m [$(NAME)]"
C_BLUE		=	"\033[34;1mCompiling"

$(NAME) :	$(OBJ)
				@$(CC) $(CFLAGS) -c $(SRC) $(INCLUDE)
				@ar rc $(NAME).a $(OBJ)
				@ranlib $(NAME)
				@echo $(C_BLUE) $(C_WHIT) $(C_GOOD)

all:		$(NAME)

bonus:		$(BONUS_OBJ)
				@$(CC) $(CFLAGS) -c $(BONUS) $(INCLUDE)
				@ar rc $(NAME)_bonus.a $(BONUS_OBJ)
				@ranlib $(NAME)
				@echo $(C_BLUE) $(C_WHIT) $(C_GOOD)

clean:
				@rm -f $(OBJ) $(BONUS_OBJ)

fclean:	clean
				@rm -f $(NAME).a $(NAME)_bonus.a

re: 		fclean all
