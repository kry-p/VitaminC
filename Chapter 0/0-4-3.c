/*
 * 0.4.3 스택
 */

#define STACK_CAPACITY 8

#include <stdio.h>

int stack[STACK_CAPACITY];
int position = -1;

void push(int n) {
    if (position >= STACK_CAPACITY - 1) {
        printf("스택이 꽉 찼습니다.\n");
    } else {
        position += 1;
        stack[position] = n;

        printf("%d (이)가 스택에 들어왔습니다.\n", n);
    }
}

void pop() {
    if (position < 0) {
        printf("스택이 비어 있습니다.\n");
        position = -1;
    } else {
        printf("[%d]이(가) pop 되었습니다.\n", stack[0]);
        stack[0] = 0;
        position -= 1;

        // 빈 첫 번째를 채우기 위해 좌로 1칸씩 이동
        int first = stack[0];
        int i;

        for (i = 0; i < 8; i++) {
            stack[i] = stack[i + 1];
        }

        stack[7] = first;
    }
}

int main() {
    int number;

    do {
        printf("스택에 넣을 자연수를 입력하세요. \n"
               "(0 : pop, -1 : 종료) : ");
        scanf("%d", &number);

        if (number > 0) {
            push(number);
        } else if (number == 0) {
            pop();
        }

        int i;
        for (i = 0; i < 8; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n\n");

    } while (number >= 0);

    return 0;
}