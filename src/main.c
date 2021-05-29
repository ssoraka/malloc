#include "../includes/malloc.h"


int ret()
{
	return -2;
}

int main() {
	char *ptr;
	char *ptr2;
	void *ptr3;

	ptr = ft_malloc(10);
	ft_memcpy(ptr, "aaaaa", 5);
	ft_print_mem();
	ft_malloc(10);
	ft_print_mem();
	ft_realloc(ptr, 6);
	ft_print_mem();
	ft_realloc(ptr, 30);
	ft_print_mem();
	ft_malloc(3);
//	ft_malloc(1);
//	ft_calloc(10);
//	ptr2 = ft_malloc(10000);
//	ptr3 = ft_malloc(100000);
//	ft_free(ptr2);
//	ptr = ft_realloc(ptr, 5);
//	ptr = ft_realloc(ptr, 30);

	//ptr2 = ft_malloc(10);
	//ft_free(ptr);
	//ptr = ft_malloc(5);

	ft_print_mem();
//	show_alloc_mem();

//	t_store	*store = get_store();
//
//
//	store_to_string(store);


//	int a = -1;
//	char chr[8] = {'1','5','3','4'};
//
//
//	char *ptr = (char *)&a - 4;
//
//	int i = 0;
//	while (i < 100) {
//		printf("%02hhx  ", ptr[i]);
//		i++;
//	}
//	printf("\n%d\n", *((int *)(chr - 8)));
//
//
//	i = 0;
//	ptr = (char *)((void *)ret);
//	while (i < 100) {
//		printf("%02hhx  ", ptr[i]);
//		i++;
//	}
//
////	*(ptr + 6) = '0';
//	printf("\n%d\n", ret());
	return 0;
}
