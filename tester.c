#include <stdio.h>
#include <limits.h>
#include <string.h>
#include "ft_printf.h"

static void test_passed(void)
{
    printf("								= OK =\n");
}

static void test_failed(void)
{
    printf("								= OOOOOOOOOOOOOO =\n");
}

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
		test_passed();
	else
		test_failed();
	printf("			Test03:	\"\\:\n");
	if (ft_printf("\"\\\n") == printf("\"\\\n"))
		test_passed();
	else
		test_failed();
	return (0);
}

static int tests_for_strings(void)
{
	char *s;
	s = 0;

	printf("\n====== Tests for %%s ============================\n\n");

	printf("			Test01: 0:\n");
	if (ft_printf("%s\n", s) == printf("%s\n", s))
		test_passed();
	else
		test_failed();
	printf("			Test02: \"%%s\",\"\":\n");
	if (ft_printf("%s\n", "") == printf("%s\n", ""))
		test_passed();
	else
		test_failed();
	printf("			Test03:	%%s	and %%:\n");
	if ( ft_printf("Hello!%sA%%BB\n", "World!") == printf("Hello!%sA%%BB\n", "World!"))
		test_passed();
	else
		test_failed();
	printf("			Test04: \"{%%s}\", \"\":\n");
	if ( ft_printf("{%s}\n", "") == printf("{%s}\n", ""))
		test_passed();
	else
		test_failed();
	return(0);
}

static int tests_for_chars(void)
{
	// %c
	printf("\n====== Tests for %%c =================================\n\n");

	printf("			Test01: ascii range :\n");
	if ( ft_printf("Hello%c\n", '!') == printf("Hello%c\n", '!'))
		test_passed();
	else
		test_failed();
	printf("			Test02: out of ascii range:\n");
	if ( ft_printf("Hello%c\n", -10) == printf("Hello%c\n", -10))
		test_passed();
	else
		test_failed();

	printf("			Test03: 0 :\n");
	if (  ft_printf("Hello%c\n", 0) == printf("Hello%c\n", 0))
		test_passed();
	else
		test_failed();
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
		test_passed();
	else
		test_failed();
	printf("				Test02: \"%%d\", 0:\n");
	if (ft_printf(str, 0)  == printf(str, 0))
		test_passed();
	else
		test_failed();
	printf("				Test03: -42:\n");
	if (ft_printf(str, -42) == printf(str, -42))
		test_passed();
	else
		test_failed();
	printf("				Test04: INT_MAX:\n");
	if (ft_printf(str, INT_MAX) == printf(str, INT_MAX))
		test_passed();
	else
		test_failed();
	printf("				Test05: INT_MIN:\n");
	if (ft_printf(str, INT_MIN) == printf(str, INT_MIN))
		test_passed();
	else
		test_failed();
	printf("				Test06: +42:\n");
	if (ft_printf(str, +42) == printf(str, +42))
		test_passed();
	else
		test_failed();
	printf("				Test07: \"Hello%%d\", 0 :\n");
	if (str[1] == 'd')
		if (ft_printf("Hello%d\n", 0) == printf("Hello%d\n", 0))
			test_passed();
		else
			test_failed();
	else
		if (ft_printf("Hello%i\n", 0) == printf("Hello%i\n", 0))
			test_passed();
		else
			test_failed();
	printf("				Test08: ptr 0x000000a7:\n");
	if (ft_printf(str, 0x000000a7) == printf(str, 0x000000a7))
		test_passed();
	else
		test_failed();
	printf("				Test09: Leading zeros 0000005 :\n");
	if (ft_printf(str, 0000005) == printf(str, 0000005))
		test_passed();
	else
		test_failed();

/*	printf("				Test10: printf(0) :\n");
	printf("  Ft: %d\n", ft_printf(ft_printf(0)));
	printf("  Or: %d\n", printf(printf(0)));
*/	
	return(0);
}

static int tests_for_pointers(char *str)
{
	printf("\n====== Tests for %% %c =================================\n\n", str[1]);

	printf("				Test01: 0:\n");
	if (ft_printf(str, 0) == printf(str, 0))
		test_passed();
	else
		test_failed();
	printf("				Test02: 42:\n");
	if (ft_printf(str, 42) == printf(str, 42))
		test_passed();
	else
		test_failed();
	printf("				Test03: :\"\"\n");
	if (ft_printf(str, "") == printf(str, ""))
		test_passed();
	else
		test_failed();
	printf("				Test04: -42:\n");
	if (ft_printf(str, -42) == printf(str, -42))
		test_passed();
	else
		test_failed();
	printf("				Test05: \'a\':\n");
	if (ft_printf(str, 'a') == printf(str, 'a'))
		test_passed();
	else
		test_failed();
	printf("				Test06: \'a\':\n");
	if (ft_printf(str, 'a') == printf(str, 'a'))
		test_passed();
	else
		test_failed();
	printf("				Test07: \"Hello\":\n");
	if (ft_printf(str, "Hello") == printf(str, "Hello"))
		test_passed();
	else
		test_failed();
	char    *ptr;
	printf("				Test08: uninitialized stack ptr:\n");
	if (ft_printf(str, ptr) == printf(str, ptr))
		test_passed();
	else
		test_failed();
	ptr = malloc(sizeof(char));
	printf("				Test09: heap ptr:\n");
	if (ft_printf(str, ptr) == printf(str, ptr))
		test_passed();
	else
		test_failed();
	printf("				Test10: INT_MAX:\n");
	if (ft_printf(str, INT_MAX) == printf(str, INT_MAX))
		test_passed();
	else
		test_failed();
	printf("				Test11: INT_MIN:\n");
	if (ft_printf(str, INT_MIN) == printf(str, INT_MIN))
		test_passed();
	else
		test_failed();
	printf("				Test12: LONG_MIN:\n");
	if (ft_printf(str, LONG_MIN) == printf(str, LONG_MIN))
		test_passed();
	else
		test_failed();
	printf("				Test13: LONG_MAX:\n");
	if (ft_printf(str, LONG_MAX) == printf(str, LONG_MAX))
		test_passed();
	else
		test_failed();
	printf("				Test14: ULONG_MAX:\n");
	if (ft_printf(str, ULONG_MAX) == printf(str, ULONG_MAX))
		test_passed();
	else
		test_failed();
		printf("				Test14: 5000:\n");
	if (ft_printf(str, -5000) == printf(str, -5000))
		test_passed();
	else
		test_failed();
	/*
	printf("				Test15: \"%%p%%p%%p\\n\", ptr, 0, ptr:\n");
	if (ft_printf("%p%p%p\n", ptr, 0, ptr) == printf("%p\n", ptr, 0, ptr))
		test_passed();
	else
		test_failed();
	printf("				Test15: \"%%p%%p%%p\\n\", 0, ptr, ptr:\n");
	if (ft_printf("%p%p%p\n", 0, ptr, ptr) == printf("%p\n", 0, ptr, ptr))
		test_passed();
	else
		test_failed();
	printf("				Test15: \"%%p%%p%%p\\n\", ptr, ptr, 0:\n");
	if (ft_printf("%p%p%p\n", ptr, ptr, 0) == printf("%p\n", ptr, ptr, 0))
		test_passed();
	else
		test_failed();
    */

	printf("\n\n\n");
	free(ptr);
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
	tests_for_pointers("%p\n");
	tests_for_pointers("%x\n");
	tests_for_pointers("%X\n");
	tests_for_pointers("%u\n");

	return (0);
}