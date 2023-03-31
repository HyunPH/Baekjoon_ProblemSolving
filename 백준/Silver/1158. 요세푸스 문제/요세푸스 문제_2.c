#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
    int N, K, check[5002] = { 0, }, cur;
    scanf("%d %d", &N, &K);

    cur = K;
    printf("<%d", cur);
    check[cur] = 1; // cur번째는 1로 처리하여, 뺀것으로 간주.
    for (int i = 0; i < N - 1; i++) { // N-1번 출력하기위해 N-1번 반복문
        for (int j = 0; j < K; j++) { // K번 옆으로 옯겨가서 검사하기 위해.
            while (1) {
                cur++;
                //printf("\ni:%d j:%d cur:%d check:%d\n", i, j, cur, !check[cur]);
                if (cur > N) cur = 1; // 사이클을 돌기위해. 8 --> 1
                if (!check[cur]) break; // 이미 뺀 것이면, 반복 중단
            }
        }
        printf(", %d", cur);
        check[cur] = 1;
    }
    printf(">");
}
