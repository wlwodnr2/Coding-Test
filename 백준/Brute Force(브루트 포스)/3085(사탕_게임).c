#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 51
int CandyCount(char arr[MAX][MAX], int size) {
	int row_max_count = 0, column_max_count = 0;
	for (int i = 0; i < size; i++) { //횡 최대 값 찾기
		int count = 1;
		for (int j = 0; j < size; j++) {
			if ((j != 0) && (arr[i][j] == arr[i][j - 1])) {
				count++;
				row_max_count = row_max_count > count ? row_max_count : count;
			}
			else {
				count = 1;
			}
		}
	}

	for (int i = 0; i < size; i++) { //종 최대 값 찾기
		int count = 1;
		for (int j = 0; j < size; j++) {
			if ((j != 0) && (arr[j][i] == arr[j - 1][i])) {
				count++;
				column_max_count = column_max_count > count ? column_max_count : count;
			}
			else {
				count = 1;
			}
		}
	}
	
	return ((row_max_count > column_max_count) ? row_max_count : column_max_count);

}

int main() {
	int N, maxCount = 0;
	char board[MAX][MAX];

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s", &board[i]);
	}

	for (int i = 0; i < N; i++) {
		
		for (int j = 1; j < N; j++) { //왼쪽 오른쪽 교체 
			maxCount = maxCount > CandyCount(board, N) ? maxCount : CandyCount(board, N); //정상 값 
				
			//오른쪽 값과 교체
			char temp = board[i][j];
			board[i][j] = board[i][j + 1];
			board[i][j + 1] = temp; //오른쪽이랑 교체 완료
			maxCount = maxCount > CandyCount(board, N) ? maxCount : CandyCount(board, N);
			board[i][j + 1] = board[i][j];
			board[i][j] = temp; //원위치
		
			//왼쪽 값과 교체
			board[i][j] = board[i][j - 1];
			board[i][j - 1] = temp; //왼쪽이랑 교체 완료
			maxCount = maxCount > CandyCount(board, N) ? maxCount : CandyCount(board, N);
			board[i][j - 1] = board[i][j];
			board[i][j] = temp; //원위치

			//위쪽 값과 교체
			temp = board[j][i];
			board[j][i] = board[j - 1][i];
			board[j - 1][i] = temp; //왼쪽이랑 교체 완료
			maxCount = maxCount > CandyCount(board, N) ? maxCount : CandyCount(board, N);
			board[j - 1][i] = board[j][i];
			board[j][i] = temp; //원위치

			//아래쪽 값과 교체
			board[j][i] = board[j + 1][i];
			board[j + 1][i] = temp; //왼쪽이랑 교체 완료
			maxCount = maxCount > CandyCount(board, N) ? maxCount : CandyCount(board, N);
			board[j + 1][i] = board[j][i];
			board[j][i] = temp; //원위치
		}
	}
	printf("%d", maxCount);

	return 0;
}
