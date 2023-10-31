/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmyshko <vmyshko@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:57:50 by vmyshko           #+#    #+#             */
/*   Updated: 2023/10/31 11:55:30 by vmyshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static void test_is_____()
{
    printf("%d\n", ft_isdigit('3'));
    printf("%d\n", ft_isalpha('1'));
    printf("%d\n", ft_isalnum('%'));
    printf("%d\n", ft_isascii(105));
    printf("%d\n", ft_isprint(50));
    printf("%c\n", ft_toupper('b'));
    printf("%c\n", ft_tolower('B'));
    printf("%zu\n", ft_strlen("Hello, my first library"));
    printf("%d\n", ft_atoi(" -525 60 hello"));
}

static  void test_mem_and_bzero()
{
   char string_1[] = "Hello, memset!";
    ft_memset(string_1, 'A', 5);
    printf("%s\n", string_1);
    
    ft_bzero(string_1, 2);
    // string_1[0] = '0';
    // string_1[1] = '0';
    int i;
    i = 2;
    while (string_1[i])
    {
        printf("%c", string_1[i++]); 
    }
    printf("\n");
    char *some_str = "sahofhsaf";
    char a[20] = {};
    char b[20] = {};
    memcpy(a, some_str, strlen(some_str) + 1);
    ft_memcpy(b, some_str, strlen(some_str) + 1);
    printf("%d\n", memcmp(a, b, 20));
}
static void test_mem_move()
{
    char src[100] = "HelloMem_move";
	char src_1[100] = "HelloMem_move";
    ft_memmove(src+7, src, strlen(src)+1);
	memmove(src_1+7, src_1, strlen(src_1)+1);
	printf("%s\n%s\n", src, src_1);

}
static void test_strlcpy()
{
	char src[] = "Do you like C? Don't lie! I know you do";
	char dest[45]; //buffer big enough to hold our full string if necessary
	size_t result_size;
	size_t result_size_1;
	
	result_size = ft_strlcpy(dest, src, sizeof(dest));
	printf("Copied %zu characters: %s\n", result_size, dest);
	// result_size_1 = strlcpy(dest, src, sizeof(dest));
	// printf("Copied %zu characters: %s\n", result_size_1, dest);

}
static void test_strlcat()
{
    char dst1[20] = "Bla-la-la-la ";//mine
	// char dst2[] = "";//original
	const char *src = "Hello, my stl_copy";
	size_t size = sizeof(dst1);


	// size_t original = strlcat(dst2, src, size);
	size_t result = ft_strlcat(dst1, src, size);
	printf("%s\n length: %zu\n", dst1, result);
	// printf("%s\n length: %zu\n", dst2, original);

}

static int test_strchr()
{
	char test_string[] = "Hello abc, abc";
	char *test = test_string;
	int c = 'b';
	char *result = ft_strchr(test, c);
	if (result)
	{ printf("character %c found at position %p\n", c, result);}
	else
	{ printf("character %c NOT found\n", c);}
	char *result_1 = strchr(test, c);
	if (result)
	{ printf("character %c found at position %p\n", c, result_1); }
	else { printf("character %c NOT found\n", c);}

	char *result_2 = ft_strrchr(test, c);
	if (result_2)
	{ printf("character %c found at position %p\n", c, result_2); }
	else
	{
		printf("character %c NOT found\n", c);
	}
	char *result_3 = strrchr(test, c);
	if (result)
	{ printf("character %c found at position %p\n", c, result_3);}
	else
	{ printf("character %c NOT found\n", c);}
	return (0);
}
 static int test_strn_cmp()
{
	char string_1[] = "It is the same string";
	char string_2[] = "It is zzzz NOT the same string";
	char string_3[] = "It is the same string";
	char string_4[] = "It is";
    unsigned int n = 8;
	
	int result_0 = ft_strncmp(string_1, string_4, 0);// must return 0
	printf("Compare case on n == 0: %d\n", result_0);
	int result_1 = ft_strncmp(string_1, string_2, n);// must return -
	int result_2 = ft_strncmp(string_1, string_3, n); // should return 0 - SAME
	int result_3 = ft_strncmp(string_1, string_4, n);// ++ (short is first)
	printf("Compare case on n == 0: %d\n", result_0);
	printf("Compare 1 and 2 different strings: %d\n", result_1);
	printf("Compare 1 and 3 SAME strings: %d\n", result_2);
	printf("Compare 1 and 4 short and long strings: %d\n", result_3);

	char s[] = {-128, 0, 127, 0};
	char sCpy[] = {-128, 0, 127, 0};
	char s2[] = {0, 0, 127, 0};
	char s3[] = {0, 0, 42, 0};

	int result_00 = ft_memcmp(s, sCpy, 0);// must return 0 
	int result_001 = ft_memcmp(s, sCpy, 3);// must return 0 the same

	int result_01 = ft_memcmp(s, s2, 2);// must return +
	int result_02 = ft_memcmp(s2, s, 2); // must return -
	int result_03 = ft_memcmp(s2, s3, 4);// ++ (short is first)
	printf("Compare case on n == 0: %d\n", result_00);
	printf("Compare SAME: %d\n", result_001);
	printf("Compare different (+): %d\n", result_01);
	printf("Compare previous reverse (-): %d\n", result_02);
	printf("Compare 127-42: %d\n", result_03);
	return(0);
}
static void test_mem_chr ()
{

	int intArray[] = {1, 2, 3, 4, 5};
	void *result = memchr(intArray, 2, 5);//sizeof(intArray)//????
	if (result != NULL) {
        // Calculate the position in the array
		size_t position = ((char *)result - (char *)intArray) / sizeof(int);
		printf("Found %d at position %zu\n", 2, position);//Found 2 at position 1
	}      
	else 
	 printf("%d not found in the array.\n", 2);
}
static void test_strnstr ()
{
char string_1[] = "It is the same string";
	char string_2[] = "same";
	
	char *result_0 = ft_strnstr(string_1, string_2, 5);
	char *result_1 = ft_strnstr(string_1, string_2, 20);
	// char *result_00 = strnstr(string_1, string_2, 5);
	// char *result_11 = strnstr(string_1, string_2, 20);
	printf("NOT found %p\n", ( void*)result_0);
	printf("FOUND %p\n", ( void*)result_1);
	// printf("NOT found %p\n", ( void*)result_00);
	// printf("FOUND %p\n", ( void*)result_11);
}

static void test_calloc()
{
int *arr_calloc = (int *)ft_calloc(5, sizeof(int));
for(int i = 0; i<5; i++)
printf("%d", arr_calloc[i]);
printf("\n");
free(arr_calloc);
}

static void test_strdup()
{
	char src[] = "Hello, strdup!";
	char *result_1 = ft_strdup(src);
	char *result_2 = strdup(src);
	printf("Start string: %s\n", src);
	printf("My strdup: %s\n", result_1);
	printf("Original strdup: %s\n", result_2);
	free(result_1);
	free(result_2);
}
static void test_substr()
{
	char src[] = "Do you like C? Don't lie! I know you do";
	char *result;
	result = ft_substr(src, 7, 13);
	printf("made substr from %s TO THE: %s\n", src, result);
	free(result);
}
static void test_strjoin()
{
	char string1[] = "Do you";
	char string2[] = " like C?";
	char *joined = ft_strjoin(string1, string2);
	printf("Joined string is: %s\n", joined);
	free(joined);
}
static void test_str_trim ()
{
	char string1[] = "liDo you like C?ke";
	char string2[] = "like";
	char *trimmed = ft_strtrim(string1, string2);
	printf("Trimmed string is: %s\n", trimmed);
	free(trimmed);
}
static void new_test_striteri (unsigned int i, char *str)
{
	i = 0;
	str[i] = ft_toupper((unsigned char)str[i]);
}

static void test_put_fd()
{
	char a[] = "Hello, I am a happy healthy string! Who are you?\n";
	ft_putstr_fd(a, 2);
	ft_putendl_fd(a, 1);
	ft_striteri(a, new_test_striteri);
	printf("New string: %s\n", a);
}

static void	test_split()
{
	char	str[] = "Hello, World ,,,!";
	char	c = ' ';
	char	**spt = ft_split(str, c);
	int	i = 0;
	while (spt[i] != 0)
	{
		ft_putstr_fd(spt[i], 1);
		free(spt[i]);
		i++;
	}
	ft_putchar_fd('\n', 1); 
	free(spt);
}

static int bonus_add_front_and_count()
{
	char	*str;
	char	*str2;
	
	t_list	*head;
	t_list	*new_head;
	t_list	*result;

	str = "This is head NOW at the start";
	head = ft_lstnew((void *)str);
	printf("Starting head node is: %s\n", (char *)head->content);
	str2 = "This NEW is UPDATED head";
	new_head = ft_lstnew((void *)str2);
	ft_lstadd_front(&head, new_head);
	printf("Updated head node is: %s\n", (char *)new_head->content);
	printf("Old node is: %s\n", (char *)new_head->next->content);
	printf("%d\n", ft_lstsize(new_head));
	result = ft_lstlast(new_head);
	printf("Old node is LAST: %s\n", (char *)result->content);
	free(new_head->next);
	free(new_head);
	return (0);
}


int main()
{
    test_is_____();
    test_mem_and_bzero();
    test_mem_move();
    test_strlcpy();
    test_strlcat();
    test_strchr();
	test_strn_cmp ();
	test_mem_chr ();
	test_strnstr();
	test_calloc();
	test_strdup();
	test_substr();
	test_strjoin();
	test_str_trim();
	test_put_fd();
	ft_putnbr_fd(-2147483648, 1);
	test_split();
	bonus_add_front_and_count();

    return(0);
  
}