/*
 * 0.4.1 은행 대기번호 관리
 * circular queue 를 사용하도록 수정
 */

#define QUEUE_CAPACITY 8

#include <stdio.h>

int queue[QUEUE_CAPACITY];
int head = 0;
int tail = -1;
int queue_size = 0;

void enqueue(int n) {
    if (queue_size == QUEUE_CAPACITY) {
        printf("큐가 꽉 찼습니다.\n");
    } else {
        tail = (tail + 1) % QUEUE_CAPACITY;
        queue_size += 1;
        queue[tail] = n;
        printf("%d (이)가 큐에 들어왔습니다.\n", n);
    }
}

void dequeue() {
    if (queue_size == 0) {
        printf("큐가 비어 있습니다.\n");
    } else {
        printf("[%d]이 dequeue 되었습니다.\n", queue[head]);
        queue[head] = 0;
        head = (head + 1) % QUEUE_CAPACITY;
        queue_size -= 1;
    }
}

int main() {
    int number;

    do {
        printf("큐에 넣을 자연수를 입력하세요. \n"
               "(0 : dequeue, -1 : 종료) : ");
        scanf("%d", &number);

        if (number > 0) {
            enqueue(number);
        } else if (number == 0) {
            dequeue();
        }

    } while (number >= 0);

    return 0;
}