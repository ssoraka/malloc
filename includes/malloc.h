//
// Created by Suzette Soraka on 10/4/20.
//

#ifndef MALLOC_MALLOC_H
#define MALLOC_MALLOC_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <sys/mman.h>

//enum					e_status
//{
//	FREE,
//	ALLOC
//};

enum					e_type
{
	TINY,
	SMALL,
	LARGE,
	LINKS,
	TYPE_COUNT
}					t_type;

enum					e_size
{
	TINY_SIZE = 1,
	SMALL_SIZE = 8
}					t_size;

/*
** этот список будет сохранять указатели на выделенную память
*/
typedef struct		s_link {
	struct s_link	*next;
	char			*mem;
	size_t			size;
}					t_link;

/*
** одна страница выделенной памяти
*/
typedef struct		s_page {
	char			*mem;
	struct s_page	*next;
	size_t			size;
	size_t			used;
	struct s_link	*links;
}					t_page;

/*
** список страниц выделенной памяти
*/
typedef struct		s_pages {
	struct s_page	*head;
	struct s_page	*last;
	size_t			count;
}					t_pages;

/*
** хранилище выделенной памяти
*/
typedef struct		s_store {
	t_pages			p[TYPE_COUNT];
}					t_store;

typedef struct		s_page {
	char			*mem;
	struct s_page	*next;
	size_t			size;
	size_t			used;
	struct s_link	*links;
}					t_page;

void	*ft_malloc(size_t size);


#endif //MALLOC_MALLOC_H
