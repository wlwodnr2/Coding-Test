//컴퓨터에서 코드 돌려보면 정답과 같게 나오는데 Softeer 사이트에서 코드 실행 했을 시 순서가 뒤바껴 출력되어 30점의 점수만 획득

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> 

typedef struct meetingRoom {
	char meetingRoomName[10];
	int s; //start
	int t; //end
}meetingRoom;

typedef struct availableRoom {
    int start;
    int end;
}availableRoom;

int main(void)
{
	int N, M;
	char roomname[50][10];
	meetingRoom mR[100];
    availableRoom aR[10];

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%s", &roomname[i]);
	}
	for (int i = 0; i < M; i++) {
		scanf("%s %d %d", &mR[i].meetingRoomName, &mR[i].s, &mR[i].t); 
	}

    //먼저 전체 트리 구조를 최대 힙 구조로 바꿉니다.
    for (int i = 1; i < N; i++) {
        int sun = i;
        do { //일단 부모들이 자식들보다 크게 정렬 
            int parent = (sun - 1) / 2; // 부모 = (자식 -1)/2
            if (strcmp(roomname[parent] , roomname[sun]) == -1) { //자식이 더 크면 교환 
                char temp[50];
                strcpy(temp, roomname[parent]);
                strcpy(roomname[parent], roomname[sun]);
                strcpy(roomname[sun], temp);
            }
            sun = parent; // 자식이 부모로 이동해서 
        } while (sun != 0);
    }

    for (int i = N - 1; i >= 0; i--) {
        char temp[50];
        strcpy(temp, roomname[0]);
        strcpy(roomname[0], roomname[i]);
        strcpy(roomname[i], temp);
        int parent = 0;
        int sun = 1;
        do {
            sun = 2 * parent + 1; //왼쪽 아들은 부모*2 + 1
            //자식 중에 더 큰 값을 찾ㄱ기 (왼쪽 오른쪽 자식 중에)
            if (strcmp(roomname[sun], roomname[sun+1]) == -1 && sun < i - 1) {
                sun++;
            }
            //부모보다 자식이 더 크다면 교환 여기서 다시 Heapify 
            if (strcmp(roomname[parent], roomname[sun]) == -1 && sun < i) {
                char temp[50];
                strcpy(temp, roomname[parent]);
                strcpy(roomname[parent], roomname[sun]);
                strcpy(roomname[sun], temp);
            }
            parent = sun;
        } while (sun < i);
    }
    //여기 까지 낮은 시간 순서대로 정렬 끝 


    //먼저 전체 트리 구조를 최대 힙 구조로 바꿉니다.
    for (int i = 1; i < M; i++) {
        int sun = i;
        do { //일단 부모들이 자식들보다 크게 정렬 
            int parent = (sun - 1) / 2; // 부모 = (자식 -1)/2
            if (mR[parent].s < mR[sun].s) { //자식이 더 크면 교환 
                meetingRoom temp = mR[parent];
                mR[parent] = mR[sun];
                mR[sun] = temp;
            }
            sun = parent; // 자식이 부모로 이동해서 
        } while (sun != 0);
    }

    for (int i = M - 1; i >= 0; i--) {
        meetingRoom temp = mR[0];
        mR[0] = mR[i];
        mR[i] = temp;
        int parent = 0;
        int sun = 1;
        do {
            sun = 2 * parent + 1; //왼쪽 아들은 부모*2 + 1
            //자식 중에 더 큰 값을 찾ㄱ기 (왼쪽 오른쪽 자식 중에)
            if (mR[sun].s < mR[sun + 1].s && sun < i - 1) {
                sun++;
            }
            //부모보다 자식이 더 크다면 교환 여기서 다시 Heapify 
            if (mR[parent].s < mR[sun].s && sun < i) {
                meetingRoom temp = mR[parent];
                mR[parent] = mR[sun];
                mR[sun] = temp;
            }
            parent = sun;
        } while (sun < i);
    }
    //여기 까지 낮은 시간 순서대로 정렬 끝 

    for (int i = 0; i < N; i++) {
        int temp = 9, count = 0;
        for (int j = 0; j < M; j++) {
            if (!strcmp(roomname[i], mR[j].meetingRoomName)) { //미팅룸 이름이 같다면 
                if (mR[j].s - temp >= 1) { // 기준 시간부터 시작 미팅 시간이 1시간 이상이라면 
                    aR[count].start = temp;
                    aR[count].end = mR[j].s;
                    count++;
                }
                temp = mR[j].t; //temp를 끝나는 시간으로 옮기기 
            }
        }
        if (temp < 18) {
            aR[count].start = temp;
            aR[count].end = 18;
            count++;
        }
        printf("Room %s:\n", roomname[i]);
        if (count == 0) {
            printf("Not available\n");
        }
        else {
            printf("%d available:\n", count);
            for (int k = 0; k < count; k++) {
                if (aR[k].start < 10) {
                    printf("0%d-%d\n", aR[k].start, aR[k].end);
                }
                else {
                    printf("%d-%d\n", aR[k].start, aR[k].end);
                }
            }
        }
        if(i != N-1)
            printf("-----\n");
    }

	return 0;
}
