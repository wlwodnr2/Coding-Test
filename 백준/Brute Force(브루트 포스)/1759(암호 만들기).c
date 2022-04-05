#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char password[16];

void heap(char *arr, int number) {
	for (int i = 1; i < number; i++) {
		int child = i;
		do {
			int parent = (child - 1) / 2;
			if (arr[parent] < arr[child]) {
				char temp = arr[parent];
				arr[parent] = arr[child];
				arr[child] = temp;
			}
			child = parent;
		} while (child != 0);
	}
}

void makePassword(char arr[], int visited[], int password_size, int set_size, int consonant_count, int vowel_count, int number, int start) {
	if (number == password_size) {
		if (consonant_count >= 2 && vowel_count >= 1) {
			for (int i = 0; i < password_size; i++) printf("%c", password[i]);
			printf("\n");
		}
		return;
	}

	for (int i = start; i < set_size; i++) {
		if (visited[i] == 0) {
			visited[i] = 1;
			password[number] = arr[i];
			switch (arr[i]) {
				case 'a':
				case 'e':
				case 'i':
				case 'o':
				case 'u': //모음
					vowel_count++;
					makePassword(arr, visited, password_size, set_size, consonant_count, vowel_count, number + 1, i + 1);
					vowel_count--;
					break;
				default: //자음
					consonant_count++;
					makePassword(arr, visited, password_size, set_size, consonant_count, vowel_count, number + 1, i + 1);
					consonant_count--;
					break;
			}	
			visited[i] = 0;
		}
	}
}

int main() {
	int L, C, check[16] = {0, };
	char str[16];
	scanf("%d %d", &L, &C);
	for (int i = 0; i < C; i++) scanf(" %c", &str[i]);

	heap(str, C);
	for (int i = C - 1; i >= 0; i--) {
		char temp = str[0];
		str[0] = str[i];
		str[i] = temp;

		heap(str, i);
	}

	makePassword(str,check,L,C,0,0,0,0);

	return 0;
}
