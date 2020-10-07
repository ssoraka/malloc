#include "../includes/malloc.h"

int main() {
	char *ptr;
	char *ptr2;

	ptr = ft_malloc(10);
	ft_malloc(10);
	ptr = ft_realloc(ptr, 5);
	ptr = ft_realloc(ptr, 30);

	//ptr2 = ft_malloc(10);
	ft_free(ptr);
	//ptr = ft_malloc(5);

	ft_print_mem();
	return 0;
}
