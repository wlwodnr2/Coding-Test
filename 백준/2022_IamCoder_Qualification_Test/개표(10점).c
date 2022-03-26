#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int N, Q, vote[100001] = {0,}, number, paper_count, candidate;
	scanf("%d %d", &N, &Q);

	for (int i = 0; i < Q; i++) {
		int max = 0, biggerThanMe = 0;
		scanf("%d %d %d", &number, &paper_count, &candidate);
		if(number == 1){
			vote[candidate] += paper_count; //투표 수 추가 
		}
		else if (number == 2) {
			for (int j = 1; j <= N; j++) {
				max += (vote[N + 1] + paper_count - vote[j] - 1);
				if ((vote[N + 1] + paper_count) <= vote[j]) {
					biggerThanMe = 1;
					break;
				}
			}
			if (max < candidate || biggerThanMe == 1) printf("NO\n");
			else printf("YES\n");
			
		}
	}

	return 0;
}
