#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	long long K, P, N, mod = 1000000007;

	scanf("%lld %lld %lld", &K, &P, &N);

	while (N--) K = (K * P) % mod; //여기서 왜 자꾸 mod 해줘야되는지 모르겠다. 문제에서는 최종 결과에서 나머지를 구하라 되어있다. 

	printf("%lld\n", K);
	return 0;
}
