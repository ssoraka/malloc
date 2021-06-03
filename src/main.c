#include "../includes/malloc.h"

void test();


int main() {

//	test();
//	return 0;

//	char *ptr;
//	ptr = ft_malloc(10);
//	ptr = ft_malloc(15);
//	char *ptr1 = ft_malloc(20);
//	ft_free(ptr);
//	ft_free(ptr1);



	char *ptr;
	char *ptr1;
	char *ptr2;

	ptr = ft_malloc(30);
	ptr1 = ft_malloc(40);
	ptr2 = ft_malloc(48);


//	ptr = ft_malloc(120);
//	ptr = ft_malloc(120);
//	ft_memcpy(ptr, "aaaaaaaaaaaaaaa", 16);
//	ptr = ft_malloc(15);
//	ft_memcpy(ptr, "bbbbbbb", 7);
//	char *ptr1 = ft_malloc(20);
//	ft_memcpy(ptr1, "ZZZZZZZZZZZZZZZZZZZZZZZ", 24);
//	ft_print_mem();
	ft_free(ptr);
	ft_free(ptr1);
	ft_free(ptr2);


//	ft_malloc(170);
//	ft_memcpy(ptr, "b", 2);


//	ft_print_mem();

	print_store();

	return (0);


	printf("%p\n", malloc(3));
	char *p = malloc(30);
	printf("%p\n", p);
	char *p2 = malloc(30);
	printf("%p\n", p2);
	printf("%p\n", malloc(1));

	char *p3 = malloc(10000000);
	printf("%p\n", p3);

	//printf("%c\n", p[-1600]);

	p -= 1600;


	for(int i = 0; i < 1600; i++) {
		printf("%c", p[i]) ;
		if (!(i % 160) && i > 0) {
			printf("\n");
		}
	}

//	printf("\n______________________________\n");
//
//	p2 -= 10768;
//	for(int i = 0; i < 10768; i++) {
//		printf("%c", p2[i]) ;
//		if (!(i % 160) && i > 0) {
//			printf("\n");
//		}
//	}

	printf("\n______________________________\n");

	p3[0] = '_';

	printf("%p\n", p3);
	p3 -= 4096;

	printf("%p\n", p3);
	for(int i = 0; i < 20; i++) {
		printf("%02hhx ", p3[i]) ;
		if (!(i % 160) && i > 0) {
			printf("\n");
		}
	}
	printf("\n");

	for(int i = 0; i < 5000; i++) {
		printf("%c", p3[i]) ;
		if (!(i % 160) && i > 0) {
			printf("\n");
		}
	}

	printf("\n______________________________\n");

	char *p4 = *((char **)p3);

	printf("%p\n", p4);
	p4 -= 4096;
	p4 -= 4096;
	p4 -= 4096;
	p4 -= 4096;
	p4 -= 4096;
	printf("%p\n", p4);
	for(int i = 0; i < 20000; i++) {
		printf("%c", p4[i]) ;
		if (!(i % 160) && i > 0) {
			printf("\n");
		}
	}

//	00 70 ac 00 01 00
//	00 70 e3 02 01 00
//	00 90 56 07 01 00
//	00 90 6e 01 01 00
//	00 b0 93 05 01 00
//	ft_print_mem();
//	ft_realloc(ptr, 6);
//	ft_print_mem();
//	ft_realloc(ptr, 30);
//	ft_print_mem();
//	ft_malloc(3);
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

//	ft_print_mem();
//	show_alloc_mem();

//	t_store	*store = get_store();
//
//
//	print_store(store);


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
