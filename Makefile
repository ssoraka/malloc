#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssoraka <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/11 12:49:25 by ssoraka           #+#    #+#              #
#    Updated: 2019/03/11 20:57:23 by ssoraka          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

SRCS	=	debug.c free.c from_libft.c main.c malloc.c \
			page.c page_size.c pages.c show_alloc_mem.c store.c test.c

PATH_OBJ	= obj
PATH_SRC	= src
PATH_INC	= includes

NAME		= libft_malloc_$(HOSTTYPE).so
CFLAGS		= -Wall -Wextra -Werror
DLFLAGS		= -shared -fPIC
OBJECTS		= $(patsubst %.c, $(PATH_OBJ)/%.o, $(SRCS))
DEBUG		= -g -O0

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJECTS)
	@gcc $(DLFLAGS) -o $@ $(OBJECTS)
	@rm -f libft_malloc.so
	@ln -s $(NAME) libft_malloc.so
	@echo libft_malloc.so now link to $(NAME)

$(PATH_OBJ)/%.o: $(addprefix $(PATH_SRC)/,%.c)
	@mkdir -p $(PATH_OBJ)
	$(CC) -c -o $@ $(CFLAGS) $^ -O0 -g  -I $(PATH_INC)/

clean:
	@rm -f $(OBJECTS)
	@echo Delete $(words $(OBJECTS)) object file

fclean: clean
	rm -f $(NAME)
	rm -f libft_malloc.so

re: fclean $(NAME)