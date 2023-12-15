# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgriblin <tgriblin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 16:05:17 by tgriblin          #+#    #+#              #
#    Updated: 2023/09/12 19:44:49 by tgriblin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXE = bsq
SRC_DIR = srcs/
HEAD_DIR = includes
FLAGS = cc -Wall -Wextra -Werror
FILES = $(addprefix $(SRC_DIR), errors.c get_arg.c main.c utility.c)

all : $(EXE)

$(EXE) :
	$(FLAGS) $(FILES) -I $(HEAD_DIR) -o $(EXE)

clean :

fclean :
	rm -f $(EXE)

re : fclean $(EXE)
