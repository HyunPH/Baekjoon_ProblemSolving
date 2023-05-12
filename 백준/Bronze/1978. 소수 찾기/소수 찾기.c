#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    int T, count = 0;
    scanf("%d", &T);

    while (T--) {
        int n, flag = 1;
        scanf("%d", &n);

        //소수인지 검사
        if (n == 1)
            flag = 0;
        for (int i = 2; i < n; i++) {
            if (n % i == 0) {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
            count++;
    }
    printf("%d\n", count);
    return 0;
}
