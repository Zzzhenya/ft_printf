#include <stdio.h>
#include <limits.h>
#include "libftprintf.h"
//int ft_printf(const char *str, ...);

int main(void)
{
	char *s;
	s = 0;
	printf("\n====== Test without specifier ======\n\n");

	printf("				Test01:	basic \"\":\n");
	printf("  Ft: %d\n", ft_printf(""));
	printf("  Or: %d\n", printf(""));
	printf("				Test02: 0:\n");
	printf("  Or: %d\n",printf("%s", s));
	printf("  Ft: %d\n",ft_printf("%s", s));
	printf("				Test03:	basic Hello World!:\n");
	printf("  Ft: %d\n", ft_printf("Hello World!"));
	printf("  Or: %d\n", printf("Hello World!"));
	printf("				Test04:	%%s	and %%:\n");
	printf("  Ft: %d\n", ft_printf("Hello!%sA%%BB", "World!"));
	printf("  Or: %d\n", printf("Hello!%sA%%BB", "World!"));
// %c
	printf("\n====== Tests for %%c ======\n\n");

	printf("				Test01: ascii range :\n");
	printf("  Ft: %d\n", ft_printf("Hello%c", '!'));
	printf("  Or: %d\n", printf("Hello%c", '!'));
	printf("				Test02: out of ascii range:\n");
	printf("  Ft: %d\n", ft_printf("Hello%c", -10));
	printf("  Or: %d\n", printf("Hello%c", -10));
	printf("				Test03: 0 :\n");
	printf("  Ft: %d\n", ft_printf("Hello%c", 0));
	printf("  Or: %d\n", printf("Hello%c", 0));;
	printf("				Test04: string :\n");
	printf("  Ft: %d\n", ft_printf("Hello%c", "252"));
//	printf("  Or: %d\n", printf("Hello%c", "252"));

// %d
	printf("\n====== Tests for %%d ======\n\n");

	printf("				Test01: 42:\n");
	printf("  Ft: %d\n", ft_printf("%d", 42));
	printf("  Or: %d\n", printf("%d", 42));
	printf("				Test02: 0:\n");
	printf("  Ft: %d\n", ft_printf("%d", 0));
	printf("  Or: %d\n", printf("%d", 0));
	printf("				Test03: -42:\n");
	printf("  Ft: %d\n", ft_printf("%d", -42));
	printf("  Or: %d\n", printf("%d", -42));
	printf("				Test04: INT_MAX:\n");
	printf("  Ft: %d\n", ft_printf("%d", INT_MAX));
	printf("  Or: %d\n", printf("%d", INT_MAX));
	printf("				Test05: INT_MIN:\n");
	printf("  Ft: %d\n", ft_printf("%d", INT_MIN));
	printf("  Or: %d\n", printf("%d", INT_MIN));
	printf("				Test06: +42:\n");
	printf("  Ft: %d\n", ft_printf("%d", +42));
	printf("  Or: %d\n", printf("%d", +42));
	printf("				Test07: 0 :\n");
	printf("  Ft: %d\n", ft_printf("Hello%d", 0));
	printf("  Or: %d\n", printf("Hello%d", 0));
	printf("				Test08: Hexa 0x000000a7:\n");
	printf("  Ft: %d\n", ft_printf("%d", 0x000000a7));
	printf("  Or: %d\n", printf("%d", 0x000000a7));
	printf("				Test09: Leading zeros 0000005 :\n");
	printf("  Ft: %d\n", ft_printf("%d", 0000005));
	printf("  Or: %d\n", printf("%d", 0000005));

	printf("\n====== Tests for %%i ======\n\n");

	printf("				Test01: 42:\n");
	printf("  Ft: %d\n", ft_printf("%i", 42));
	printf("  Or: %d\n", printf("%i", 42));
	printf("				Test02: 0:\n");
	printf("  Ft: %d\n", ft_printf("%i", 0));
	printf("  Or: %d\n", printf("%i", 0));
	printf("				Test03: -42:\n");
	printf("  Ft: %d\n", ft_printf("%i", -42));
	printf("  Or: %d\n", printf("%i", -42));
	printf("				Test04: INT_MAX:\n");
	printf("  Ft: %d\n", ft_printf("%i", INT_MAX));
	printf("  Or: %d\n", printf("%i", INT_MAX));
	printf("				Test05: INT_MIN:\n");
	printf("  Ft: %d\n", ft_printf("%i", INT_MIN));
	printf("  Or: %d\n", printf("%i", INT_MIN));
	printf("				Test06: +42:\n");
	printf("  Ft: %d\n", ft_printf("%i", +42));
	printf("  Or: %d\n", printf("%i", +42));
	printf("				Test07: 0 :\n");
	printf("  Ft: %d\n", ft_printf("Hello%i", 0));
	printf("  Or: %d\n", printf("Hello%i", 0));
	printf("				Test08: Hexa 0x000000a7:\n");
	printf("  Ft: %d\n", ft_printf("%i", 0x000000a7));
	printf("  Or: %d\n", printf("%i", 0x000000a7));
	printf("				Test09: Leading zeros 0000005 :\n");
	printf("  Ft: %d\n", ft_printf("%i", 0000005));
	printf("  Or: %d\n", printf("%i", 0000005));
//	int width = 5;
//	int num = 10;
//	printf("%*d\n", width, num);
//	printf("%2$*1$d\n", width, num);
	return (0);
}