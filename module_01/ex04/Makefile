# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/09 19:56:06 by edpaulin          #+#    #+#              #
#    Updated: 2023/05/01 20:05:14 by edpaulin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL = all

NAME = sifl

SRC = main.cpp FileReader.cpp FileWriter.cpp Replacer.cpp

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.cpp=.o))

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

ARG1 = main.cpp
ARG2 = a
ARG3 = iai

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

# call with args example:
# make ARG1='test.txt' ARG2='ello world' ARG3='i mars' test
test: $(NAME)
	./$(NAME) $(ARG1) '$(ARG2)' '$(ARG3)'
	sed 's/$(ARG2)/$(ARG3)/g' $(ARG1) > $(ARG1).replace.sed
	diff $(ARG1).replace $(ARG1).replace.sed

.PHONY: all clean fclean re test
