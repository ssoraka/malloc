#include "../includes/malloc.h"

int main() {
	char *ptr;
	char *ptr2;

	ptr = ft_malloc(10);
	ptr2 = ft_malloc(10);
	ft_free(ptr);
	ptr2 = ft_malloc(5);
	return 0;
}
