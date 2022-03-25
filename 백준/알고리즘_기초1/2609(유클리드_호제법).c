#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int e_gcd(int a, int b)
{
	if (b == 0)
		return a;
	else
		return e_gcd(b, a % b);
}

int main()
{
	int a, b, tmp;

	scanf("%d %d", &a, &b);

	if (a < b) {
		tmp = b;
		b = a;
		a = tmp;
	}

	printf("%d\n%d\n", e_gcd(a, b), (a * b) / e_gcd(a, b));

	return 0;
}
