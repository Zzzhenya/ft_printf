#include <stdio.h>
#include <limits.h>
#include <string.h>
#include "ft_printf.h"

static int tests_without_specifier(void)
{
	printf("\n====== Test without specifier ===========================\n\n");
/*
	//seg fault
	printf("				Test00:	0:\n");
	printf("  Ft: %d\n", ft_printf(0));
	printf("  Or: %d\n", printf(0));
*/
	printf("			Test01:	\"\":");
	if (ft_printf("") == printf(""))
		printf("				= OK =\n");
	else
		printf("					= OO =\n");
	printf("			Test02:	Hello World!:\n");
	if (ft_printf("Hello World!\n") == printf("Hello World!\n"))
		printf("								= OK =\n");
	else
		printf("								= OO =\n");
	printf("			Test03:	\"\\:\n");
	if (ft_printf("\"\\\n") == printf("\"\\\n"))
		printf("								= OK =\n");
	else
		printf("								= OO =\n");
	return (0);
}

static int tests_for_strings(void)
{
	char *s;
	s = 0;

	printf("\n====== Tests for %%s ============================\n\n");

	printf("			Test01: 0:\n");
	if (ft_printf("%s\n", s) == printf("%s\n", s))
		printf("								= OK =\n");
	else
		printf("								= OO =\n");
	printf("			Test02: \"%%s\",\"\":\n");
	if (ft_printf("%s\n", "") == printf("%s\n", ""))
		printf("								= OK =\n");
	else
		printf("								= OO =\n");
	printf("			Test03:	%%s	and %%:\n");
	if ( ft_printf("Hello!%sA%%BB\n", "World!") == printf("Hello!%sA%%BB\n", "World!"))
		printf("								= OK =\n");
	else
		printf("								= OO =\n");
	printf("			Test04: \"{%%s}\", \"\":\n");
	if ( ft_printf("{%s}\n", "") == printf("{%s}\n", ""))
		printf("								= OK =\n");
	else
		printf("								= OO =\n");
	return(0);
}

static int tests_for_chars(void)
{
	// %c
	printf("\n====== Tests for %%c =================================\n\n");

	printf("			Test01: ascii range :\n");
	if ( ft_printf("Hello%c\n", '!') == printf("Hello%c\n", '!'))
		printf("								= OK =\n");
	else
		printf("								= OO =\n");
	printf("			Test02: out of ascii range:\n");
	if ( ft_printf("Hello%c\n", -10) == printf("Hello%c\n", -10))
		printf("								= OK =\n");
	else
		printf("								= OO =\n");

	printf("			Test03: 0 :\n");
	if (  ft_printf("Hello%c\n", 0) == printf("Hello%c\n", 0))
		printf("								= OK =\n");
	else
		printf("								= OO =\n");
	printf("			Test04: string :\n");
	printf("  Ft: %d\n", ft_printf("Hello%c\n", "252"));
	printf("						= Different from printf =\n");
//	printf("  Or: %d\n", printf("Hello%c", "252"));
	return (0);
}

static int tests_for_ints(char *str)
{

	printf("\n==================%%%c%s",str[1],"==================\n\n");

	printf("				Test01: 42:\n");
	if ( ft_printf(str, 42) == printf(str, 42))
		printf("								= OK =\n");
	else
		printf("								= OO =\n");
	printf("				Test02: \"%%d\", 0:\n");
	if (ft_printf(str, 0)  == printf(str, 0))
		printf("								= OK =\n");
	else
		printf("								= OO =\n");
	printf("				Test03: -42:\n");
	if (ft_printf(str, -42) == printf(str, -42))
		printf("								= OK =\n");
	else
		printf("								= OO =\n");
	printf("				Test04: INT_MAX:\n");
	if (ft_printf(str, INT_MAX) == printf(str, INT_MAX))
		printf("								= OK =\n");
	else
		printf("								= OO =\n");
	printf("				Test05: INT_MIN:\n");
	if (ft_printf(str, INT_MIN) == printf(str, INT_MIN))
		printf("								= OK =\n");
	else
		printf("								= OO =\n");
	printf("				Test06: +42:\n");
	if (ft_printf(str, +42) == printf(str, +42))
		printf("								= OK =\n");
	else
		printf("								= OO =\n");
	printf("				Test07: \"Hello%%d\", 0 :\n");
	if (str[1] == 'd')
		if (ft_printf("Hello%d\n", 0) == printf("Hello%d\n", 0))
			printf("								= OK =\n");
		else
			printf("								= OO =\n");
	else
		if (ft_printf("Hello%i\n", 0) == printf("Hello%i\n", 0))
			printf("								= OK =\n");
		else
			printf("								= OO =\n");
	printf("				Test08: Hexa 0x000000a7:\n");
	if (ft_printf(str, 0x000000a7) == printf(str, 0x000000a7))
		printf("								= OK =\n");
	else
		printf("								= OO =\n");
	printf("				Test09: Leading zeros 0000005 :\n");
	if (ft_printf(str, 0000005) == printf(str, 0000005))
		printf("								= OK =\n");
	else
		printf("								= OO =\n");
/*	printf("				Test10: printf(0) :\n");
	printf("  Ft: %d\n", ft_printf(ft_printf(0)));
	printf("  Or: %d\n", printf(printf(0)));
*/	
	return(0);
}

static int tests_for_pointers(void)
{
	/*
	
	int int_min = INT_MIN;
	long long_max = LONG_MAX;
	*/

	// %p
	printf("\n====== Tests for %%p =================================\n\n");

	char a = 'A';
	char *char_ptr;
	char_ptr = malloc(sizeof(char*));

	printf("		  Or Heap :  %d \n", printf("%p", char_ptr));
	printf("		  Ft Heap :  %d \n",ft_printf("%p", char_ptr));
	printf("		  Or Stack : %d \n", printf("%p", &a));
	printf("		  Ft Stack : %d \n",ft_printf("%p", &a));
	printf("		  Or Stack : %d \n", printf("%p", NULL));
	printf("		  Ft Stack : %d \n", ft_printf("%p", NULL));

	free(char_ptr);
/*
	printf("		  Or Char ptr: %d\n", printf("%p\n", &a));
	printf("		  Ft Char ptr: %d\n", ft_printf("%p\n", &a));
	printf("		  Or int ptr: %d\n", printf("%p\n",&int_min));
//	printf("		  Ft int ptr: %d\n", ft_printf("%p\n",&int_min));
	printf("		  Or long ptr: %d\n", printf("%p\n",&long_max));
//	printf("		  Ft long ptr: %d\n", ft_printf("%p\n",&long_max));

	char *char_ptr;
	char_ptr = malloc(sizeof(char*));
	printf("		  Or Char ptr: %d : Heap \n", printf("%p\n", char_ptr));
//	printf("		  Ft Char ptr: %d : Heap \n", ft_printf("%p\n", char_ptr));
	free(char_ptr);
	int *int_ptr;
	int_ptr = malloc(sizeof(int*));
	printf("		  Or Int ptr: %d : Heap \n", printf("%p\n", int_ptr));
//	printf("		  Ft Int ptr: %d : Heap \n", ft_printf("%p\n", int_ptr));
	free(int_ptr);
	long long *long_ptr;
	long_ptr = malloc(sizeof(long long *));
	printf("		  Or long long ptr: %d : Heap \n", printf("%p\n", long_ptr));
//	printf("		  Ft long long ptr: %d : Heap \n", ft_printf("%p\n", long_ptr));
	free(long_ptr);	
*/
	printf("\n\n\n");
	return(0);
}

int main(void)
{
	tests_without_specifier();
	tests_for_strings();
	tests_for_chars();
	printf("\n====== Tests for %%i and %%d ======\n\n");
	tests_for_ints("%d\n");
	tests_for_ints("%i\n");
	tests_for_pointers();

	return (0);
}