#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
    int N,top = 0;
    char arr[1001], stack[1001];

    scanf("%d ", &N);
    for (int i = 0;i < N; i++) //반복문 실행
    {
        fgets(arr, 1001, stdin); //문장입력받기
        for (int j = 0;j < strlen(arr) - 1;j++)
        {
            if (arr[j] != ' ')
            {
                stack[top++] = arr[j];
            }

            if (arr[j] == ' ' || j == strlen(arr) - 2)
            {
                for (int z = top - 1;z >= 0;z--)
                    printf("%c", stack[z]);
                printf(" ");
                top = 0;
            }
        }
        printf("\n");
    }
    return 0;
}
