#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 1000000


// 숫자버튼으로 이동할 수 있는 경우 몇번 눌러야하는지 반환(= 채널의 길이) , 고장난 경우 : 0 , 고장나지 않은 경우 : 1
int isPossible(int *brkBtn, int channel) {
	if (channel == 0) //채널이 0번이면 
		return brkBtn[0] ? 0 : 1;

	int len = 0;
	while (channel > 0) {
		if (brkBtn[channel % 10]) //하나라도 고장나있으면 
			return 0;
		len += 1;
		channel /= 10;
	}
	return len;
}

int main() {
	int N, M, brokeBtn[10] = { 0, }, ch = 100, btnCnt = 0, ans = 0;
	scanf("%d", &N);
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int broke;
		scanf("%d", &broke);
		brokeBtn[broke] = 1; //고장난 버튼
	}

	ans = abs(ch - N); //직접 +-눌러서 만든 횟수

	// 숫자 버튼으로 특정 채널로 이동한 후 +,- 조작 수 확인
	for (int channel = 0; channel < MAX; channel++) {

		// 숫자버튼으로 이동가능한 채널인지 확인
		btnCnt = isPossible(brokeBtn, channel);
		if (btnCnt > 0) {
			// 숫자버튼으로 이동 후 필요한 +,- 버튼 횟수
			btnCnt += abs(N - channel);
			// 기존값과 비교해서 최소 버튼 횟수로 갱신
			ans = ans < btnCnt ? ans : btnCnt;
		}
	}
	printf("%d", ans);
	return 0;
}
