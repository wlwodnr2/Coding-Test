#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> 
#include <math.h>

int ft_intlength(int number)
{
	int count;

	count = 0;
	while (number / 10 != 0)
	{
		number /= 10;
		++count;
	}
	return (count);
}

void intoArray(int *ptr, int number, int len) {
	for (int i = 0; i < 5 - len; i++) {
		ptr[i] = 10;
	}
	for (int i = 5 - len; i < 5; i++) {
		if (i == 4) {
			ptr[i] = number;
		}
		else {
			ptr[i] = number / pow(10, 4 - i);
			number -= ptr[i] * pow(10, 4 - i);
		}
	}
}

int main(void)
{
	int A, B, T, A1[5], B1[5];

	int ledBtn[11][7] = { {1,1,1,1,1,1,0},
						{0,1,1,0,0,0,0}, 
						{1,1,0,1,1,0,1}, 
						{1,1,1,1,0,0,1}, 
						{0,1,1,0,0,1,1},
						{1,0,1,1,0,1,1}, 
						{1,0,1,1,1,1,1},
						{1,1,1,0,0,1,0}, 
						{1,1,1,1,1,1,1}, 
						{1,1,1,1,0,1,1}, 
						{0,0,0,0,0,0,0}};

	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		scanf("%d %d", &A, &B);

		//ft_intlength(A); //A 자릿수
		//ft_intlength(B); //B 자릿수

		intoArray(&A1, A, ft_intlength(A)+1);
		intoArray(&B1, B, ft_intlength(B)+1);

		int count = 0;

		for (int j = 0; j < 5; j++) { //5자리
			for (int k = 0; k < 7; k++) {
				count += ledBtn[A1[j]][k] != ledBtn[B1[j]][k];
			}
		}
		printf("%d\n", count);
	}

	return 0;
}
