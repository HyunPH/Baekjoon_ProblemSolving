#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_STACK_SIZE 100000 // 문자열의 길이 100000 이하
typedef char element; // 문자를 스택에 넣을 것임
typedef struct {
	element data[MAX_STACK_SIZE + 1];
	int top;
}StadyType; // 스택 구조체

// 초기화
void init_stack(StadyType* q) {
	q->top = -1;
}
// push
void push_stack(StadyType* q, element item) {
	q->data[++q->top] = item;
}
// pop
int pop_stack(StadyType* q) {
	return q->data[q->top--];
}

int main()
{
	char str[MAX_STACK_SIZE + 1], ch; 
	int str_len, tag = 0, word_len = 0;
	StadyType word; // 스택 선언
	init_stack(&word); // 스택 초기화

	scanf("%[^\n]s", str); // 공백포함 문자열 입력.
	str_len = strlen(str); // 문자열 길이
	for (int i = 0; i < str_len; i++)
	{
		ch = str[i]; // 임시 문자
		//printf("%c %d\n", ch, tag);
		if (ch == '<') {
			tag = 1;
		}
		else if (ch == '>') {
			tag = 0;
			printf("%c", ch); // tag를 0으로 만들고 > 기호가 올바르게 출력되기 위함.
			continue;
		}

		// 태그상태일 때
		if (tag == 1) {
			printf("%c", ch);
		}
		// 태그상태 아닐 때
		else if (tag == 0) {
			// ch가 소문자, 숫자일 때
			if ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z')) {
				push_stack(&word, ch);
				word_len++; // 스택에 push하면서 스택의 요소개수 ++
				
				// 단어 다음 문자가 단어의 요소가 아닐 때. 지금까지 push했던 원소들을 pop하며 출력해주기.
				if (str[i + 1] == ' ' || str[i + 1] == '<' || str[i + 1] == 0) {
					for (int j = 0; j < word_len; j++) {
						printf("%c", pop_stack(&word));
					}
					word_len = 0; // pop 한 다음 초기화
				}
			}
			// ch가 공백일 때
			else {
				printf("%c", ch);
			}
		}
	}
	return 0;
}
