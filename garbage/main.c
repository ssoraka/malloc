/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoraka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 10:41:12 by ssoraka           #+#    #+#             */
/*   Updated: 2019/04/20 11:33:44 by ssoraka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"

void test();

int test2() {
	return -1;
}

/*
 * todo так, ну вставка кадров идет в порядке возрастания адресов
 * надо проверить работу с пустыми областями,
 * без маллока
 * разбить по файлам
 * вынести в глобалку хранилище кадров
 */

int main() {

//	test();
//	return 0;

	char *ptr;
	char *ptr1;
	char *ptr2;
	char *ptr3;

	ptr = malloc(1);
//	ptr = malloc(15);
//	char *ptr1 = malloc(20);
//	free(ptr);
//	free(ptr1);

	show_alloc_mem();

//	ft_print_mem();
	return (0);
	char *p1 = ft_malloc(0);
//	free(p1);



	ptr = ft_malloc(0);
	ptr1 = ft_malloc(0);

	ptr1 = ft_realloc(ptr1, 1);
	ptr = ft_realloc(ptr, 1);
	ptr = ft_realloc(ptr, 0);
//	ft_realloc(ptr, 5);
	ft_print_mem();
	return 0;


//	free(ptr);
	ptr2 = calloc(12, 1);
	ptr3 = malloc(20);

	malloc(20000);

	char *a[50];
	for(int i = 0; i < 30; i++) {
		a[i] = malloc(30);
		a[i + 1] = NULL;
	}
	malloc(20000);
	for(int i = 0; i < 25; i++) {
		free(a[i]);
	}
	malloc(20000);
	for(int i = 0; i < 25; i++) {
		a[i] = malloc(30);
	}
	malloc(20000);
//	ptr = malloc(120);
//	ptr = malloc(120);
//	ft_memcpy(ptr, "aaaaaaaaaaaaaaa", 16);
//	ptr = malloc(15);
//	ft_memcpy(ptr, "bbbbbbb", 7);
//	char *ptr1 = malloc(20);
//	ft_memcpy(ptr1, "ZZZZZZZZZZZZZZZZZZZZZZZ", 24);
//	ft_print_mem();
//	free(ptr);
//	free(ptr1);
//	free(ptr2);

//	char *ptr4 = malloc(100);
//	char *ptr5 = malloc(100);


//	malloc(170);
//	ft_memcpy(ptr, "b", 2);

//	free(ptr);
//	free(ptr1);
//	free(ptr2);
//	free(ptr3);
//	free(ptr4);
//	free(ptr5);

//	ft_print_mem();
	show_alloc_mem();

//	char *a = test2;
//	for (int i = 0; i < 20; i++) {
//		printf("%02hhx ", *a);
//		a++;
//	}
//
//	ft_memcpy(ptr1, test2, 24);
//
//	int (*f)(void) = ptr1;
//
//	printf("\n%d\n", f());
//	print_store();

	return (0);


	printf("%p\n", ft_malloc(3));
	char *p = ft_malloc(30);
	printf("%p\n", p);
	char *p2 = ft_malloc(30);
	printf("%p\n", p2);
	printf("%p\n", ft_malloc(1));

	char *p3 = ft_malloc(10000000);
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
//	realloc(ptr, 6);
//	ft_print_mem();
//	realloc(ptr, 30);
//	ft_print_mem();
//	malloc(3);
//	malloc(1);
//	calloc(10);
//	ptr2 = malloc(10000);
//	ptr3 = malloc(100000);
//	free(ptr2);
//	ptr = realloc(ptr, 5);
//	ptr = realloc(ptr, 30);

	//ptr2 = malloc(10);
	//free(ptr);
	//ptr = malloc(5);

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
