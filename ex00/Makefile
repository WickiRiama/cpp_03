# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mriant <mriant@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 18:02:56 by mriant            #+#    #+#              #
#    Updated: 2022/11/10 18:13:08 by mriant           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = claptrap

SRCS = ${addprefix srcs/, \
	ClapTrap.cpp \
	main.cpp}

OBJS = ${SRCS:srcs/%.cpp=build/%.o}
DEPS = ${SRCS:srcs/%.cpp=build/%.o}

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -g -std=c++98
IFLAGS = -MMD -I./includes
LFLAGS = 

${NAME}: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o ${NAME} ${IFLAGS}

build/%.o: srcs/%.cpp
	mkdir -p build
	${CXX} ${CXXFLAGS} -c $< -o $@ ${LFLAGS}

.PHONY: all
all: ${NAME}

.PHONY: clean
clean:
	rm -rf build

.PHONY: fclean
fclean: clean
	rm -rf ${NAME}

.PHONY: re
re: fclean
	make -C .

-include ${DEPS}