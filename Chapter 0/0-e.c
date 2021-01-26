/*
 * 0-e. 두 개의 스택을 이용한 큐 구현
 *
 * 두 개의 스택을 준비한다. 두 스택은 각각 A, B라고 가정하며, A는 enqueue 전용, B는 dequeue 전용이다.
 *
 * 우선 enqueue 할 때의 상황이다. 모든 내용은 A에 push 한다.
 * 이 때 스택 A에 1, 2, 3, 4를 차례대로 push 하였다면 내용물은 [4, 3, 2, 1] 가 된다.
 *
 * 그러면 dequeue 할 때의 상황이다. A의 내용을 그대로 pop 하면 순서는 반전된 상태이므로 A에서 pop 한 직후 B에 모두 바로 push 한다.
 * 이 때 스택 B는 비어 있어야 하며 비어있지 않을 경우 순서가 꼬이게 된다.
 *
 * 따라서 dequeue 정책은 'dequeue 를 시작하기 전에 입력했던 모든 내용을 출력해야 한다' 가 된다.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int data = 1;

struct node_t {
    int key;
    struct node_t *next;
};

node_t *enqueueStackHead = NULL;
node_t *dequeueStackHead = NULL;

// enqueue
void enqueue() {

    // dequeue 전용 스택이 비어 있지 않으면 enqueue 금지
    if (dequeueStackHead != NULL) {
        printf("Violation : dequeue 스택이 비지 않아 enqueue 를 할 수 없습니다.");
        return;
    }

    // 노드 동적 할당
    node_t *new_node = (node_t *) malloc(sizeof(node_t));

    // 구조체 포인터로 선언된 노드의 key 와 다음 노드 (next) 를 지정
    // 추가된 노드는 첫 번째 노드이므로 다음 노드 주소는 head
    new_node->key = data;
    new_node->next = NULL;

    if (enqueueStackHead == NULL) {

        // head 노드가 없을 경우 새로 만들어진 노드를 head 노드에 대응

        enqueueStackHead = new_node;
    } else {

        // head 노드가 있으면 새로 추가된 노드의 next 에 기존 head 의 주소를 저장
        // 추가된 노드는 head 노드가 됨

        new_node->next = enqueueStackHead;
        enqueueStackHead = new_node;
    }

    printf("대기순번은 %d 번입니다.", data);
    data += 1;
}

void push_into_dequeue() {
    node_t *node;

    // dequeue 스택이 비었는지 판정
    // 비었으면 enqueue 스택의 내용이 빌 때까지 모두 dequeue 스택에 전달
    if (dequeueStackHead != NULL)
        return;
    else {
        while (enqueueStackHead != NULL) {
            node = enqueueStackHead;
            enqueueStackHead = enqueueStackHead->next;

            if (dequeueStackHead == NULL) {
                node->next = NULL;
            } else {
                node->next = dequeueStackHead;
            }

            dequeueStackHead = node;
        }
    }
}

int pop_from_dequeue() {

    node_t *node;
    int r;

    // dequeue 스택이 비었는지 확인
    if (dequeueStackHead == NULL) {
        printf("Violation : dequeue 스택이 비어 있습니다.\n");
        return -1;
    }

    node = dequeueStackHead; // 제거 대상 노드 지정
    dequeueStackHead = dequeueStackHead->next; // head 노드를 다음 노드로 변경

    r = node->key; // 제거 대상에 있던 key 값을 가져옴
    free(node); // 메모리 반환

    return r;
}


int main() {
    int number;
    bool isEnd = false;

    do {
        printf("순번 큐입니다.\n"
               "(0 : 원소 추가, 1 : 원소 제거, -1 : 종료) : ");
        scanf("%d", &number);

        if (number == 0) {
            enqueue();
        } else if (number == 1) {
            push_into_dequeue();
            int delete_node_result = pop_from_dequeue();

            if (delete_node_result != -1) {
                printf("%d번 원소가 dequeue 되었습니다.\n", delete_node_result);
                printf("주의 : 정책상 dequeue 스택이 비지 않은 상태에서 추가로 enqueue 를 할 수 없습니다.");
            } else printf("큐가 비어 있습니다.");

        } else if (number == -1) isEnd = true;
        else printf("잘못 입력하였습니다. 다시 입력하세요.");

        printf("\n\n");
    } while (!isEnd);

    return 0;
}