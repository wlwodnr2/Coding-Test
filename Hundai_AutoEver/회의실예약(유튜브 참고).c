#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> 

typedef struct meetingRoom {
    char meetingRoomName[10];
    int s; //start
    int t; //end
}meetingRoom;

typedef struct availableRoom {
    int time[18];
}availableRoom;

int main(void)
{
    int N, M;
    char roomname[50][10];
    meetingRoom mR[100];
    availableRoom aR[50];

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
            if (strcmp(roomname[parent], roomname[sun]) == -1) { //자식이 더 크면 교환 
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
            if (strcmp(roomname[sun], roomname[sun + 1]) == -1 && sun < i - 1) {
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

    for (int i = 0; i < N; i++) {
        int count = 0;
        for (int j = 0; j < M; j++) {
            if (!strcmp(roomname[i], mR[j].meetingRoomName)) { //이름이 같은 방일 경우
                for (int k = mR[j].s; k < mR[j].t; k++) { //시작  시간부터 끝 시간 -1까지 1로 변경
                    aR[i].time[k] = 1;
                }
            }
        }
        int current = 1;
        int temp[5][2];
        int sTime;
        int fTime;
        for (int z = 9; z < 18; z++) {
            if (current == 1 && aR[i].time[z] != 1) {
                sTime = z;
                current = 0;
            }
            else if (current == 0 && aR[i].time[z] == 1) {
                fTime = z;
                current = 1;
                temp[count][0] = sTime;
                temp[count][1] = fTime;
                count++;
            }
        }
        if (current == 0) {
            temp[count][0] = sTime;
            temp[count][1] = 18;
            count++;
        }
        printf("Room %s:\n", roomname[i]);
        if (count == 0) {
            printf("Not available\n");
        }
        else {
            printf("%d available:\n", count);
            for (int z = 0; z < count; z++) {
                if (temp[z][0] < 10) {
                    printf("0%d-%d\n", temp[z][0], temp[z][1]);
                }
                else {
                    printf("%d-%d\n", temp[z][0], temp[z][1]);
                }
            }
        }
        if (i != N - 1) {
            printf("-----\n");
        }
        
    }

    return 0;
}
