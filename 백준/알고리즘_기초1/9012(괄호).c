#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	int N;
	char VPS[50];

	scanf("%d ", &N);
	for (int i = 0; i < N; i++) {
		int position = 0;
		scanf("%s",&VPS[0]); //문장입력받기
		for (int j = 0; j < strlen(VPS); j++) {
			if (VPS[j] == '(') {
				position++;
			}
			else if (VPS[j] == ')') {
				if (position == 0) {
					position = -1;
					break;
				}
				position--;
				
			}
		}
		if (position == 0) printf("YES\n");
		else printf("NO\n");
	}

}
