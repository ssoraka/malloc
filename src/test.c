//
// Created by Suzette Soraka on 5/29/21.
//

#include "../includes/malloc.h"

typedef struct		s_chunk {
	void			*ptr;
	size_t			used;
}					t_chunk;

typedef struct		s_page2 {
	struct s_page	*prev;
	struct s_page	*next;
	size_t			size;
	size_t			empty;
	size_t			end;
	size_t			alloc_count;
	struct s_chunk	*chunks;
}					t_page2;




void	*alloc_mem2(t_page2 *page, size_t size) {
	t_chunk *chunk;
	void *ptr;

	chunk = page->chunks + page->alloc_count;
	chunk->used = size;

	page->end -= size;
	page->empty -= sizeof(t_chunk) - size;
	page->alloc_count++;

	chunk->ptr = (char *)page + page->end;
	ptr = chunk->ptr;
	return ptr;
}

int		is_mem2(void *ptr, t_page2 *page)
{
	if (ptr < (void *)(page + 1))
		return (PAGE);
	if (ptr < (void *)(page->chunks + page->alloc_count))
		return (BLOCK);
	if (ptr >= (void *)((char *)page + page->end))
		return (ALLOC);
	return (FREE);
}

void	ft_print_char(unsigned char chr, int is_mem);
void	ft_print_chars(char *ptr, int count);

void	ft_print_page_lines2(t_page2 *page, char *chr, int count)
{
	int i;

	ft_print_addres(chr, 1);
	ft_putstr("  ");
	i = -1;
	while (++i < count)
		ft_print_char(chr[i], is_mem2(chr + i, page));
	while (++i <= BYTES_IN_LINE)
		ft_putstr("   ");
	ft_print_chars(chr, count);
	ft_putstr("\n");
}

void	print_page2(t_page2 *page) {
	int i;
	char *chr;
	int count;

	chr = (char *)(page);
	i = 0;
	while (i < page->size)
	{
		count = BYTES_IN_LINE;
		if (i + BYTES_IN_LINE > page->size)
			count = page->size % BYTES_IN_LINE;
		ft_print_page_lines2(page, chr + i, count);
		i += BYTES_IN_LINE;
	}
	ft_putstr("\n");
}


t_page2 *init_page(void *ptr, size_t size) {
	t_page2 *page = ptr;

	ft_memset(ptr, size, 0);
	page->size = size;
	page->end = size;
	page->empty = size - sizeof(t_page2);
	page->chunks = (void *)(page + 1);
	return page;
}


void test() {
	char *ptr;
	char arr[1000];
	t_page2 *page = init_page(arr, 256);

	ptr = alloc_mem2(page, 16);
	ft_memcpy(ptr, "AAAAAAAAAAAAAAA", 16);
	ptr = alloc_mem2(page, 8);
	ft_memcpy(ptr, "XXXXXXX", 8);
	ptr = alloc_mem2(page, 24);
	ft_memcpy(ptr, "ZZZZZZZZZZZZZZZZZZZZZZZ", 24);
	print_page2(page);
}