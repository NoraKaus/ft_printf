#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	int test = -1;
	int tst = 15;
	char *ts = "hjk";
	char *t = NULL;

	ft_printf("%p %p, %p, %p", &test, &tst, ts, t);
	write (1, "\n", 1);
	printf("%p %p, %p, %p", &test, &tst, ts, t);
}
