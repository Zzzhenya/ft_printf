#include <stdio.h>
#include <limits.h>
#include "libftprintf.h"
//int ft_printf(const char *str, ...);

int main(void)
{
	printf("\n====== Test without specifier ======\n\n");

	printf("				Test01:	basic """":\n");
	printf("  Ft: %d\n", ft_printf(""));
	printf("  Or: %d\n", printf(""));
	printf("				Test02:	basic Hello World!:\n");
	printf("  Ft: %d\n", ft_printf("Hello World!"));
	printf("  Or: %d\n", printf("Hello World!"));
	printf("				Test03:	%%s	and %%:\n");
	printf("  Ft: %d\n", ft_printf("Hello!%sA%%BB", "World!"));
	printf("  Or: %d\n", printf("Hello!%sA%%BB", "World!"));
// %c
	printf("\n====== Tests for %%c ======\n\n");

	printf("				Test01:	%%c ascii range :\n");
	printf("  Ft: %d\n", ft_printf("Hello%c", '!'));
	printf("  Or: %d\n", printf("Hello%c", '!'));
	printf("				Test02:	%%c out of ascii range:\n");
	printf("  Ft: %d\n", ft_printf("Hello%c", -10));
	printf("  Or: %d\n", printf("Hello%c", -10));
	printf("				Test03:	%%c string :\n");
	printf("  Ft: %d\n", ft_printf("Hello%c", "252"));
//	printf("  Or: %d\n", printf("Hello%c", "252"));

// %d
	printf("\n====== Tests for %%d ======\n\n");

	printf("				Test01:	%%d 42:\n");
	printf("  Ft: %d\n", ft_printf("Positive %d", 42));
	printf("  Or: %d\n", printf("Positive %d", 42));
	printf("				Test02:	%%d 0:\n");
	printf("  Ft: %d\n", ft_printf("Zero %d", 0));
	printf("  Or: %d\n", printf("Zero %d", 0));
	printf("				Test03:	%%d -42:\n");
	printf("  Ft: %d\n", ft_printf("Negative %d", -42));
	printf("  Or: %d\n", printf("Negative %d", -42));
	printf("				Test04:	%%d INT_MAX:\n");
	printf("  Ft: %d\n", ft_printf("Int Max %d", INT_MAX));
	printf("  Or: %d\n", printf("Int Max %d", INT_MAX));
	printf("				Test05:	%%d INT_MIN:\n");
	printf("  Ft: %d\n", ft_printf("Int Min %d", INT_MIN));
	printf("  Or: %d\n", printf("Int Min %d", INT_MIN));
	printf("				Test06:	%%d +42:\n");
	printf("  Ft: %d\n", ft_printf("With + %d", +42));
	printf("  Or: %d\n", printf("With + %d", +42));

	printf("\n====== Tests for %%i ======\n\n");
//	int width = 5;
//	int num = 10;
//	printf("%*d\n", width, num);
//	printf("%2$*1$d\n", width, num);
	return (0);
}