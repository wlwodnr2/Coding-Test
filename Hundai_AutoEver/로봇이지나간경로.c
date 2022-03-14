//Running Time : 2h over

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int H,W, start_end[2][2], check[26][26]={0, };
char arr[26][26], direction;

void Robot_Route(int X, int Y) {
	check[X][Y] = 1; //지나간 곳이다. 

	switch (direction) {
		case '^':
			if (arr[X][Y - 1] == '#' && check[X][Y-1] == 0) { //왼쪽에 #이면 방향 꺾고 돌진 
				printf("L");
				direction = '<';
				check[X][Y - 1] = 1; //지나간다.
				printf("A");
				Robot_Route(X, Y - 2); //2칸 이동
			}
			else if (arr[X][Y + 1] == '#' && check[X][Y + 1] == 0) { //오른쪽에 #이면 방향 꺾도 돌진
				printf("R");
				direction = '>';
				check[X][Y + 1] = 1; //지나간다.
				printf("A");
				Robot_Route(X, Y + 2);
			}
			else if (arr[X - 1][Y] == '#' && check[X - 1][Y] == 0) { //똑같이 위쪽 #이면 돌진
				printf("A");
				check[X - 1][Y] = 1;
				Robot_Route(X - 2, Y);
			}
			break;
		case 'v':
			if (arr[X][Y - 1] == '#' && check[X][Y - 1] == 0) { //왼쪽에 #이면 방향 꺾고 돌진 
				printf("R");
				direction = '<';
				check[X][Y - 1] = 1; //지나간다.
				printf("A");
				Robot_Route(X, Y - 2); //2칸 이동
			}
			else if (arr[X][Y + 1] == '#' && check[X][Y + 1] == 0) { //오른쪽에 #이면 방향 꺾도 돌진
				printf("L");
				direction = '>';
				check[X][Y + 1] = 1; //지나간다.
				printf("A");
				Robot_Route(X, Y + 2);
			}
			else if (arr[X + 1][Y] == '#' && check[X + 1][Y] == 0) { //똑같이 아래쪽 #이면 돌진
				printf("A");
				check[X + 1][Y] = 1;
				Robot_Route(X + 2, Y);
			}
			break;
		case '<':
			if (arr[X - 1][Y] == '#' && check[X - 1][Y] == 0) { //위쪽에 #이면 방향 꺾고 돌진 
				printf("R");
				direction = '^';
				check[X - 1][Y] = 1; //지나간다.
				printf("A");
				Robot_Route(X - 2, Y); //2칸 이동
			}
			else if (arr[X + 1][Y] == '#' && check[X + 1][Y] == 0) { //아래쪽에 #이면 방향 꺾고 돌진 
				printf("L");
				direction = 'v';
				check[X + 1][Y] = 1; //지나간다.
				printf("A");
				Robot_Route(X + 2, Y);
			}
			else if (arr[X][Y - 1] == '#' && check[X][Y - 1] == 0) { //똑같이 왼쪽 #이면 돌진
				printf("A");
				check[X][Y - 1] = 1;
				Robot_Route(X, Y - 2);
			}
			break;
		case '>':
			if (arr[X - 1][Y] == '#' && check[X - 1][Y] == 0) { //위쪽에 #이면 방향 꺾고 돌진 
				printf("L");
				direction = '^';
				check[X - 1][Y] = 1; //지나간다.
				printf("A");
				Robot_Route(X - 2, Y); //2칸 이동
			}
			else if (arr[X + 1][Y] == '#' && check[X + 1][Y] == 0) { //아래쪽에 #이면 방향 꺾고 돌진 
				printf("R");
				direction = 'v';
				check[X + 1][Y] = 1; //지나간다.
				printf("A");
				Robot_Route(X + 2, Y);
			}
			else if (arr[X][Y + 1] == '#' && check[X][Y + 1] == 0) { //똑같이 오른쪽 #이면 돌진 
				printf("A");
				check[X][Y + 1] = 1;
				Robot_Route(X, Y + 2);
			}
			break;
	}
	return;
}

int main(void)
{
	int count[26][26] = {0,}, startIndex=0;
	scanf("%d %d", &H, &W);
	for (int i = 1; i <= H; i++) {
		scanf("%s", &arr[i][1]);
	}

	for (int i = 1; i <= H; i++) { //시작점 찾기
		for (int j = 1; j <= W; j++) {
			if (arr[i][j] == '#') {
				if (i - 1 < 1 || arr[i - 1][j] == '.') {
					count[i][j]++;
				}
				if (i + 1 > H || arr[i + 1][j] == '.') {
					count[i][j]++;
				}
				if (j - 1 < 1 || arr[i][j - 1] == '.') {
					count[i][j]++;
				}
				if (j + 1 > W || arr[i][j + 1] == '.') {
					count[i][j]++;
				}
			}
			if (count[i][j] == 3) {
				start_end[startIndex][0] = i;
				start_end[startIndex][1] = j;
				startIndex++;
			}
		}
	}
	if (arr[start_end[0][0] - 1][start_end[0][1]] == '#') {
		direction = '^'; //Up
	}
	else if (arr[start_end[0][0] + 1][start_end[0][1]] == '#') {
		direction = 'v'; //Down
	}
	else if (arr[start_end[0][0]][start_end[0][1] - 1] == '#') {
		direction = '<'; //Left
	}
	else if (arr[start_end[0][0]][start_end[0][1] + 1] == '#') {
		direction = '>'; //Right
	}

	printf("%d %d\n", start_end[0][0], start_end[0][1]);
	printf("%c\n", direction);
	Robot_Route(start_end[0][0], start_end[0][1]);

	return 0;
}
