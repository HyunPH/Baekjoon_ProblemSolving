#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
typedef double element;
typedef struct {
	element data[MAX];
	int top;
}StackType;

void init_stack(StackType* s) {
	s->top = -1;
}
void push(StackType* s, element item) {
	if (is_full(s)) return -1;
	s->data[++s->top] = item;
}
element pop(StackType* s) {
	if (is_empty(s)) return -1;
	return s->data[s->top--];
}
int is_empty(StackType* s) {
	return (s->top == -1);
}
int is_full(StackType* s) {
	return (s->top == MAX - 1);
}
int main()
{
	int N;
	scanf(" %d", &N);
	
	// 문자열 선언
	char str[101];
	int len;
	scanf("%s", str);
	len = strlen(str);

	// 피연산자 선언, 입력 (A-0, b-0, ... z-25)
	element operand[26];
	for (int i = 0; i < N; i++){
		scanf(" %lf", &operand[i]);
	}

	// 스택 선언
	StackType S;
	init_stack(&S);

	// 스택활용, 계산.
	for (int i = 0; i < len; i++) {
		//printf("%d\n", i);
		char ch = str[i];

		if (ch >= 'A' && ch <= 'Z') { /*피연산자 알파벳일 때*/
			push(&S, operand[ch - 'A']);
		}
		else { /*사칙연산자일 때*/
			switch (ch)
			{
			case '+': {
				push(&S, pop(&S) + pop(&S));
				break;
			}
			case '-': {
				element n1 = pop(&S);
				element n2 = pop(&S);
				push(&S, n2 - n1);
				break;
			}
			case '*': {
				push(&S, pop(&S) * pop(&S));
				break;
			}
			case '/': {
				element n1 = pop(&S);
				element n2 = pop(&S);
				push(&S, n2 / n1);
				break;
			}
			default:
				break;
			}
		}
	}

	printf("%4.2lf", pop(&S));

	return 0;
}
