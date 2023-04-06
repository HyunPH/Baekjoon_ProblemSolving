#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int *stack;
    int size;
}IntStack;

void push(IntStack *s, int a) {
    s->stack[s->size++] = a;
}

int pop(IntStack *s) {
    return s->stack[--s->size];
}

int top(IntStack *s) {
    return s->stack[s->size - 1];
}

int IsEmpty(IntStack *s) {
    return (s->size == 0);
}



int N;
int *arr;
int *ans;

int main() {
    IntStack stk;

    scanf("%d", &N);
    stk.stack = calloc(N, sizeof(int));
    stk.size = 0;

    arr = calloc(N, sizeof(int));
    ans = calloc(N, sizeof(int));


    for(int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
        ans[i] = -1; // 초기화 여기서 같이.
    }


    for(int i = 0; i < N; i++) {

        while(!IsEmpty(&stk) && arr[top(&stk)] < arr[i]) {
            ans[pop(&stk)] = arr[i];
        }

        push(&stk, i);

    }

    for(int i = 0; i < N; i++) {
        printf("%d ", ans[i]);
    }
    
    free(arr);
    free(ans);
}
