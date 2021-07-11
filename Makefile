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

GCC = gcc

SRCS	=	debug.c	print.c	math.c	mutex.c	\
			malloc.c ft_free_realloc.c  ft_malloc.c \
			page.c page_size.c pages.c \
			show_alloc_mem.c store.c store2.c error.c \
			helper.c

HEADERS	=	ft_malloc.h malloc_structs.h

PATH_OBJ	= obj
PATH_SRC	= src
PATH_INC	= includes
PATH_LIB	= libft

SOURCE_HEADERS = $(addprefix ./$(PATH_INC)/,$(HEADERS))
LIB_HEADER = ./$(PATH_LIB)/libft.h

NAME		= libft_malloc_$(HOSTTYPE).so
CFLAGS		= -Wall -Wextra -Werror -fPIC
DLFLAGS		= -shared -Wl -fPIC -Wall -Wextra -Werror
OBJECTS		= $(patsubst %.c, $(PATH_OBJ)/%.o, $(SRCS))
DEBUG		= -g -O0

.PHONY: run all clean fclean re libs_refresh

all: libs_refresh $(NAME)

run: re all
	gcc garbage/main.c -L. -lft_malloc
	./a.out

libs_refresh:
	@make -C ./$(PATH_LIB)/

$(PATH_OBJ)/%.o: $(addprefix $(PATH_SRC)/,%.c) ${SOURCE_HEADERS} $(LIB_HEADER)
	@mkdir -p $(PATH_OBJ)
	$(GCC) $(CFLAGS) -g -c $< -o $@ $(addprefix -I ,${SOURCE_HEADERS}) -I $(LIB_HEADER)

$(NAME): $(OBJECTS) $(PATH_LIB)/libft.a
	$(GCC) $(DLFLAGS) -g -o $@ $(OBJECTS) $(PATH_LIB)/libft.a
	rm -f libft_malloc.so
	ln -s $(NAME) libft_malloc.so
	@echo libft_malloc.so now link to $(NAME)

clean:
	rm -f $(OBJECTS)
	make -C $(PATH_LIB) clean
	@echo Delete $(words $(OBJECTS)) object file

fclean: clean
	rm -f $(NAME)
	make -C $(PATH_LIB) fclean
	rm -f libft_malloc.so

re: fclean all

#gcc ... -Wl,-Bstatic -lfirst -Wl,-Bdynamic -lsecond ...
#gcc ... -Llibrary_path -lfoo -Wl,-rpath=library_path ...
#ar -t libmy_static.a
#ar -x libmy_static.a

#$ git clone https://github.com/hANSIc99/library_sample
#$ cd library_sample/
#$ make
#cc -c main.c -Wall -Werror
#cc -c libmy_static_a.c -o libmy_static_a.o -Wall -Werror
#cc -c libmy_static_b.c -o libmy_static_b.o -Wall -Werror
#ar -rsv libmy_static.a libmy_static_a.o libmy_static_b.o
#ar: creating libmy_static.a
#a - libmy_static_a.o
#a - libmy_static_b.o
#cc -c -fPIC libmy_shared.c -o libmy_shared.o
#cc -shared -o libmy_shared.so libmy_shared.o
#$ make clean
#rm *.o

#    gcc -Wall -fPIC -c *.c
#    gcc -shared -Wl,-soname,libctest.so.1 -o libctest.so.1.0   *.o
#    mv libctest.so.1.0 /opt/lib
#    ln -sf /opt/lib/libctest.so.1.0 /opt/lib/libctest.so.1
#    ln -sf /opt/lib/libctest.so.1.0 /opt/lib/libctest.so

#https://tldp.org/HOWTO/Program-Library-HOWTO/index.html
#http://www.yolinux.com/TUTORIALS/LibraryArchives-StaticAndDynamic.html
#https://opensource.com/article/20/6/linux-libraries
#https://access.redhat.com/documentation/en-us/red_hat_enterprise_linux/8/html/developing_c_and_cpp_applications_in_rhel_8/using-libraries-with-gcc_creating-c-or-c-applications