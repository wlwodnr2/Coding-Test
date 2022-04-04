#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int N, count = 1, plus_count[8] = { 9,90,900,9000,90000,900000,9000000,90000000 }, digit, rest, number = 10, ans = 0;
	scanf("%d", &N);

	while (1) {
		digit = N / number;
		if (digit >= 10) {
			number *= 10; //10 증가
			count++;
		}
		else {
			rest = N % number;
			break;
		}
	}
	if (digit == 0) ans = rest;
	else {
		ans += ((digit-1)*number + rest + 1) * (count + 1);
		while (count != 0) {
			ans += plus_count[--count] * (count + 1);
		}
	}

	printf("%d", ans);
	return 0;
}
